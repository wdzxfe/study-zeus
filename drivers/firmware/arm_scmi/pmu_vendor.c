// SPDX-License-Identifier: GPL-2.0-only
/*
 * Copyright (c) 2021, The Linux Foundation. All rights reserved.
 */

#include "common.h"
#include <linux/scmi_pmu.h>

#define SET_PMU_MAP		11

struct pmu_map_msg {
	uint8_t hw_cntrs[MAX_NUM_CPUS][MAX_CPUCP_EVT];
};

static int scmi_send_pmu_map(const struct scmi_protocol_handle *ph,
				     void *buf, u32 msg_id)
{
	int ret, i, j;
	struct scmi_xfer *t;
	struct pmu_map_msg *msg;
	uint8_t *src = buf;

	ret = ph->xops->xfer_get_init(ph, msg_id, sizeof(*msg), sizeof(*msg),
				      &t);
	if (ret)
		return ret;

	msg = t->tx.buf;

	for (i = 0; i < MAX_NUM_CPUS; i++)
		for (j = 0; j < MAX_CPUCP_EVT; j++)
			msg->hw_cntrs[i][j] = *((src + i * MAX_NUM_CPUS) + j);

	ret = ph->xops->do_xfer(ph, t);
	ph->xops->xfer_put(ph, t);
	return ret;
}

static int scmi_pmu_map(const struct scmi_protocol_handle *ph, void *buf)
{
	return scmi_send_pmu_map(ph, buf, SET_PMU_MAP);
}

static struct scmi_pmu_vendor_ops pmu_config_ops = {
	.set_pmu_map = scmi_pmu_map,
};

static int scmi_pmu_protocol_init(const struct scmi_protocol_handle *ph)
{
	u32 version;

	ph->xops->version_get(ph, &version);

	dev_dbg(ph->dev, "version %d.%d\n",
		PROTOCOL_REV_MAJOR(version), PROTOCOL_REV_MINOR(version));

	return 0;
}

static const struct scmi_protocol scmi_pmu = {
	.id = SCMI_PMU_PROTOCOL,
	.owner = THIS_MODULE,
	.init_instance = &scmi_pmu_protocol_init,
	.ops = &pmu_config_ops,
};
module_scmi_protocol(scmi_pmu);

MODULE_DESCRIPTION("SCMI PMU vendor Protocol");
MODULE_LICENSE("GPL v2");
