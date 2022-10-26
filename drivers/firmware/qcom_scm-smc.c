// SPDX-License-Identifier: GPL-2.0-only
/* Copyright (c) 2015,2019 The Linux Foundation. All rights reserved.
 */

#include <linux/io.h>
#include <linux/errno.h>
#include <linux/delay.h>
#include <linux/mutex.h>
#include <linux/slab.h>
#include <linux/types.h>
#include <linux/qcom_scm.h>
#include <linux/arm-smccc.h>
#include <linux/dma-mapping.h>
#include <linux/qtee_shmbridge.h>

#include "qcom_scm.h"

/**
 * struct arm_smccc_args
 * @args:	The array of values used in registers in smc instruction
 */
struct arm_smccc_args {
	unsigned long args[8];
};

static DEFINE_MUTEX(qcom_scm_lock);

#define QCOM_SCM_EBUSY_WAIT_MS 30
#define QCOM_SCM_EBUSY_MAX_RETRY 20

#define SCM_SMC_N_REG_ARGS	4
#define SCM_SMC_FIRST_EXT_IDX	(SCM_SMC_N_REG_ARGS - 1)
#define SCM_SMC_N_EXT_ARGS	(MAX_QCOM_SCM_ARGS - SCM_SMC_N_REG_ARGS + 1)
#define SCM_SMC_FIRST_REG_IDX	2
#define SCM_SMC_LAST_REG_IDX	(SCM_SMC_FIRST_REG_IDX + SCM_SMC_N_REG_ARGS - 1)

static void __scm_smc_do_quirk(const struct arm_smccc_args *smc,
			       struct arm_smccc_res *res)
{
	unsigned long a0 = smc->args[0];
	struct arm_smccc_quirk quirk = { .id = ARM_SMCCC_QUIRK_QCOM_A6 };

	quirk.state.a6 = 0;

	do {
		arm_smccc_smc_quirk(a0, smc->args[1], smc->args[2],
				    smc->args[3], smc->args[4], smc->args[5],
				    quirk.state.a6, smc->args[7], res, &quirk);

		if (res->a0 == QCOM_SCM_INTERRUPTED)
			a0 = res->a0;

	} while (res->a0 == QCOM_SCM_INTERRUPTED);
}

static void __scm_smc_do(const struct arm_smccc_args *smc,
			 struct arm_smccc_res *res,
			 enum qcom_scm_call_type call_type)
{
	int retry_count = 0;

	if (call_type == QCOM_SCM_CALL_ATOMIC) {
		__scm_smc_do_quirk(smc, res);
		return;
	}

	do {
		mutex_lock(&qcom_scm_lock);

		__scm_smc_do_quirk(smc, res);

		mutex_unlock(&qcom_scm_lock);

		if (res->a0 == QCOM_SCM_V2_EBUSY) {
			if (retry_count++ > QCOM_SCM_EBUSY_MAX_RETRY ||
				(call_type == QCOM_SCM_CALL_NORETRY))
				break;
			msleep(QCOM_SCM_EBUSY_WAIT_MS);
		}
	}  while (res->a0 == QCOM_SCM_V2_EBUSY);
}

int __scm_smc_call(struct device *dev, const struct qcom_scm_desc *desc,
		   enum qcom_scm_convention qcom_convention,
		   struct qcom_scm_res *res, enum qcom_scm_call_type call_type)
{
	int arglen = desc->arginfo & 0xf;
	int i, ret;
	struct qtee_shm shm = {0};
	bool use_qtee_shmbridge;
	size_t alloc_len;
	const bool atomic = (call_type == QCOM_SCM_CALL_ATOMIC);
	gfp_t flag = atomic ? GFP_ATOMIC : GFP_NOIO;
	u32 smccc_call_type = atomic ? ARM_SMCCC_FAST_CALL : ARM_SMCCC_STD_CALL;
	u32 qcom_smccc_convention = (qcom_convention == SMC_CONVENTION_ARM_32) ?
				    ARM_SMCCC_SMC_32 : ARM_SMCCC_SMC_64;
	struct arm_smccc_res smc_res;
	struct arm_smccc_args smc = {0};
	struct qcom_scm_res wait_res;

	smc.args[0] = ARM_SMCCC_CALL_VAL(
		smccc_call_type,
		qcom_smccc_convention,
		desc->owner,
		SCM_SMC_FNID(desc->svc, desc->cmd));
	smc.args[1] = desc->arginfo;
	for (i = 0; i < SCM_SMC_N_REG_ARGS; i++)
		smc.args[i + SCM_SMC_FIRST_REG_IDX] = desc->args[i];

	if (unlikely(arglen > SCM_SMC_N_REG_ARGS)) {
		if (!dev)
			return -EPROBE_DEFER;

		alloc_len = SCM_SMC_N_EXT_ARGS * sizeof(u64);
		use_qtee_shmbridge = qtee_shmbridge_is_enabled();
		if (use_qtee_shmbridge) {
			ret = qtee_shmbridge_allocate_shm(alloc_len, &shm);
			if (ret)
				return ret;
		} else {
			shm.vaddr = kzalloc(PAGE_ALIGN(alloc_len), flag);
			if (!shm.vaddr)
				return -ENOMEM;
		}


		if (qcom_smccc_convention == ARM_SMCCC_SMC_32) {
			__le32 *args = shm.vaddr;

			for (i = 0; i < SCM_SMC_N_EXT_ARGS; i++)
				args[i] = cpu_to_le32(desc->args[i +
						      SCM_SMC_FIRST_EXT_IDX]);
		} else {
			__le64 *args = shm.vaddr;

			for (i = 0; i < SCM_SMC_N_EXT_ARGS; i++)
				args[i] = cpu_to_le64(desc->args[i +
						      SCM_SMC_FIRST_EXT_IDX]);
		}

		shm.paddr = dma_map_single(dev, shm.vaddr, alloc_len,
					   DMA_TO_DEVICE);

		if (dma_mapping_error(dev, shm.paddr)) {
			if (use_qtee_shmbridge)
				qtee_shmbridge_free_shm(&shm);
			else
				kfree(shm.vaddr);
			return -ENOMEM;
		}

		smc.args[SCM_SMC_LAST_REG_IDX] = shm.paddr;
	}

	__scm_smc_do(&smc, &smc_res, call_type);

	if (shm.vaddr) {
		dma_unmap_single(dev, shm.paddr, alloc_len, DMA_TO_DEVICE);
		if (use_qtee_shmbridge)
			qtee_shmbridge_free_shm(&shm);
		else
			kfree(shm.vaddr);
	}

	if (smc_res.a0 == QCOM_SCM_WAITQ_SLEEP ||
			smc_res.a0 == QCOM_SCM_WAITQ_WAKE) {
		/* Atomic calls should not wait */
		BUG_ON(call_type == QCOM_SCM_CALL_ATOMIC);

		if (!dev)
			return -EPROBE_DEFER;

		wait_res.result[0] = smc_res.a1;
		wait_res.result[1] = smc_res.a2;
		wait_res.result[2] = smc_res.a3;

		ret = qcom_scm_handle_wait(dev, smc_res.a0, &wait_res);

		if (res)
			*res = wait_res;
	} else {
		if (res) {
			res->result[0] = smc_res.a1;
			res->result[1] = smc_res.a2;
			res->result[2] = smc_res.a3;
		}

		ret = (long)smc_res.a0 ? qcom_scm_remap_error(smc_res.a0) : 0;
	}

	return ret;
}
