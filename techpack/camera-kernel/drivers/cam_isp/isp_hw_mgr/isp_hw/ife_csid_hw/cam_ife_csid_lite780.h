/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2020-2021, The Linux Foundation. All rights reserved.
 * Copyright (C) 2021 XiaoMi, Inc.
 */

#ifndef _CAM_IFE_CSID_LITE_780_H_
#define _CAM_IFE_CSID_LITE_780_H_

#include "cam_ife_csid_common.h"
#include "cam_ife_csid_dev.h"
#include "cam_ife_csid_hw_ver2.h"
#include "cam_irq_controller.h"
#include "cam_isp_hw_mgr_intf.h"

static const struct cam_ife_csid_irq_desc cam_ife_csid_lite_780_rx_irq_desc[] = {
	{
		.bitmask = BIT(0),
		.desc = "DL0_EOT",
	},
	{
		.bitmask = BIT(1),
		.desc = "DL1_EOT",
	},
	{
		.bitmask = BIT(2),
		.desc = "DL2_EOT",
	},
	{
		.bitmask = BIT(3),
		.desc = "DL3_EOT",
	},
	{
		.bitmask = BIT(4),
		.desc = "DL0_SOT",
	},
	{
		.bitmask = BIT(5),
		.desc = "DL1_SOT",
	},
	{
		.bitmask = BIT(6),
		.desc = "DL2_SOT",
	},
	{
		.bitmask = BIT(7),
		.desc = "DL3_SOT",
	},
	{
		.bitmask = BIT(8),
		.desc = "LONG_PKT",
	},
	{
		.bitmask = BIT(9),
		.desc = "SHORT_PKT",
	},
	{
		.bitmask = BIT(10),
		.desc = "CPHY_PKT_HDR",
	},
	{
		.bitmask = BIT(11),
		.desc = "ERROR_CPHY_EOT_RECEPTION",
	},
	{
		.bitmask = BIT(12),
		.desc = "ERROR_CPHY_SOT_RECEPTION",
	},
	{
		.bitmask = BIT(13),
		.desc = "ERROR_CPHY_PH_CRC",
	},
	{
		.bitmask = BIT(14),
		.desc = "WARNING_ECC",
	},
	{
		.bitmask = BIT(15),
		.desc = "ERROR_LANE0_FIFO_OVERFLOW",
	},
	{
		.bitmask = BIT(16),
		.desc = "ERROR_LANE1_FIFO_OVERFLOW",
	},
	{
		.bitmask = BIT(17),
		.desc = "ERROR_LANE2_FIFO_OVERFLOW",
	},
	{
		.bitmask = BIT(18),
		.desc = "ERROR_LANE3_FIFO_OVERFLOW",
	},
	{
		.bitmask = BIT(19),
		.desc = "ERROR_CRC",
	},
	{
		.bitmask = BIT(20),
		.desc = "ERROR_ECC",
	},
	{
		.bitmask = BIT(21),
		.desc = "ERROR_MMAPPED_VC_DT",
	},
	{
		.bitmask = BIT(22),
		.desc = "ERROR_UNMAPPED_VC_DT",
	},
	{
		.bitmask = BIT(23),
		.desc = "ERROR_STREAM_UNDERFLOW",
	},
	{
		.bitmask = BIT(24),
		.desc = "ERROR_UNBOUNDED_FRAME",
	},
};

static const struct cam_ife_csid_irq_desc cam_ife_csid_lite_780_path_irq_desc[] = {
	{
		.bitmask = BIT(0),
		.desc = "ILLEGAL_PROGRAMMING",
	},
	{
		.bitmask = BIT(1),
		.desc = "EROOR_MSG_FIFO_OVERFLOW",
	},
	{
		.bitmask = BIT(2),
		.desc = "ERROR_FIFO_OVERFLOW",
	},
	{
		.bitmask = BIT(3),
		.desc = "CAMIF_EOF",
	},
	{
		.bitmask = BIT(4),
		.desc = "CAMIF_SOF",
	},
	{
		.bitmask = BIT(5),
		.desc = "FRAME_DROP_EOF",
	},
	{
		.bitmask = BIT(6),
		.desc = "FRAME_DROP_EOL",
	},
	{
		.bitmask = BIT(7),
		.desc = "FRAME_DROP_SOL",
	},
	{
		.bitmask = BIT(8),
		.desc = "FRAME_DROP_SOF",
	},
	{
		.bitmask = BIT(9),
		.desc = "INFO_INPUT_EOF",
	},
	{
		.bitmask = BIT(10),
		.desc = "INFO_INPUT_EOL",
	},
	{
		.bitmask = BIT(11),
		.desc = "INFO_INPUT_SOL",
	},
	{
		.bitmask = BIT(12),
		.desc = "INFO_INPUT_SOF",
	},
	{
		.bitmask = BIT(13),
		.desc = "ERROR_PIX_COUNT",
	},
	{
		.bitmask = BIT(14),
		.desc = "ERROR_LINE_COUNT",
	},
	{
		.bitmask = BIT(15),
		.desc = "VCDT_GRP0_SEL",
	},
	{
		.bitmask = BIT(16),
		.desc = "VCDT_GRP1_SEL",
	},
	{
		.bitmask = BIT(17),
		.desc = "VCDT_GRP_CHANGE",
	},
	{
		.bitmask = BIT(18),
		.desc = "FRAME_DROP",
	},
	{
		.bitmask = BIT(19),
		.desc = "OVERFLOW_RECOVERY: Back pressure/output fifo ovrfl",
	},
	{
		.bitmask = BIT(20),
		.desc = "ERROR_REC_CCIF_VIOLATION From Camif",
	},
	{
		.bitmask = BIT(21),
		.desc = "CAMIF_EPOCH0",
	},
	{
		.bitmask = BIT(22),
		.desc = "CAMIF_EPOCH1",
	},
	{
		.bitmask = BIT(23),
		.desc = "RUP_DONE",
	},
	{
		.bitmask = BIT(24),
		.desc = "ILLEGAL_BATCH_ID",
	},
	{
		.bitmask = BIT(25),
		.desc = "BATCH_END_MISSING_VIOLATION",
	},
	{
		.bitmask = BIT(26),
		.desc = "HEIGHT_VIOLATION",
	},
	{
		.bitmask = BIT(27),
		.desc = "WIDTH_VIOLATION",
	},
	{
		.bitmask = BIT(28),
		.desc = "SENSOR_SWITCH_OUT_OF_SYNC_FRAME_DROP",
	},
	{
		.bitmask = BIT(29),
		.desc = "CCIF_VIOLATION: Bad frame timings",
	},
};

static const struct cam_ife_csid_top_irq_desc cam_ife_csid_lite_780_top_irq_desc[] = {
	{
		.bitmask  = BIT(1),
		.err_type = CAM_ISP_HW_ERROR_CSID_FATAL,
		.err_name = "FATAL_SENSOR_SWITCHING_IRQ",
		.desc = "Fatal Error duirng dynamically switching between 2 sensors",
	},
	{
		.bitmask  = BIT(18),
		.err_type = CAM_ISP_HW_ERROR_RECOVERY_OVERFLOW,
		.err_name = "ERROR_NO_VOTE_DN",
		.desc = "vote_up is asserted before IDLE is encountered in a frame",
	},
	{
		.bitmask  = BIT(19),
		.err_type = CAM_ISP_HW_ERROR_RECOVERY_OVERFLOW,
		.err_name = "ERROR_VOTE_UP_LATE",
		.desc = "vote_up is asserted at the same time as an SOF",
	},
	{
		.bitmask  = BIT(20),
		.err_type = CAM_ISP_HW_ERROR_CSID_FIFO_OVERFLOW,
		.err_name = "ERROR_RDI_LINE_BUFFER_CONFLICT",
		.desc = "Two or more RDIs programmed to access the shared line buffer",
	},
};

static struct cam_irq_register_set cam_ife_csid_lite_780_irq_reg_set[7] = {
	/* Top */
	{
		.mask_reg_offset   = 0x00000080,
		.clear_reg_offset  = 0x00000084,
		.status_reg_offset = 0x0000007C,
	},
	/* RX */
	{
		.mask_reg_offset   = 0x000000A0,
		.clear_reg_offset  = 0x000000A4,
		.status_reg_offset = 0x0000009C,
	},
	/* RDI0 */
	{
		.mask_reg_offset   = 0x000000F0,
		.clear_reg_offset  = 0x000000F4,
		.status_reg_offset = 0x000000EC,
	},
	/* RDI1 */
	{
		.mask_reg_offset   = 0x00000100,
		.clear_reg_offset  = 0x00000104,
		.status_reg_offset = 0x000000FC,
	},
	/* RDI2 */
	{
		.mask_reg_offset   = 0x00000110,
		.clear_reg_offset  = 0x00000114,
		.status_reg_offset = 0x0000010C,
	},
	/* RDI3 */
	{
		.mask_reg_offset   = 0x00000120,
		.clear_reg_offset  = 0x00000124,
		.status_reg_offset = 0x0000011C,
	},
	/* IPP */
	{
		.mask_reg_offset   = 0x000000B0,
		.clear_reg_offset  = 0x000000B4,
		.status_reg_offset = 0x000000AC,
	},
};

static struct cam_irq_controller_reg_info cam_ife_csid_lite_780_irq_reg_info = {
	.num_registers = 7,
	.irq_reg_set = cam_ife_csid_lite_780_irq_reg_set,
	.global_clear_offset  = 0x00000014,
	.global_clear_bitmask = 0x00000001,
	.clear_all_bitmask = 0xFFFFFFFF,
};

static struct cam_irq_register_set cam_ife_csid_lite_780_buf_done_irq_reg_set[1] = {
	{
		.mask_reg_offset   = 0x00000090,
		.clear_reg_offset  = 0x00000094,
		.status_reg_offset = 0x0000008C,
	},
};

static struct cam_irq_controller_reg_info
	cam_ife_csid_lite_780_buf_done_irq_reg_info = {
	.num_registers = 1,
	.irq_reg_set = cam_ife_csid_lite_780_buf_done_irq_reg_set,
	.global_clear_offset  = 0, /* intentionally set to zero */
};

static struct cam_ife_csid_ver2_common_reg_info
			cam_ife_csid_lite_780_cmn_reg_info = {
	.hw_version_addr                              = 0x0,
	.cfg0_addr                                    = 0x4,
	.global_cmd_addr                              = 0x8,
	.reset_cfg_addr                               = 0xc,
	.reset_cmd_addr                               = 0x10,
	.irq_cmd_addr                                 = 0x14,
	.rup_aup_cmd_addr                             = 0x18,
	.offline_cmd_addr                             = 0x1C,
	.shdr_master_slave_cfg_addr                   = 0x20,
	.top_irq_status_addr                          = 0x7C,
	.top_irq_mask_addr                            = 0x80,
	.top_irq_clear_addr                           = 0x84,
	.top_irq_set_addr                             = 0x88,
	.buf_done_irq_status_addr                     = 0x8C,
	.buf_done_irq_mask_addr                       = 0x90,
	.buf_done_irq_clear_addr                      = 0x94,
	.buf_done_irq_set_addr                        = 0x98,

	/*configurations */
	.major_version                                = 6,
	.minor_version                                = 8,
	.version_incr                                 = 0,
	.num_rdis                                     = 4,
	.num_pix                                      = 1,
	.num_ppp                                      = 0,
	.rst_done_shift_val                           = 1,
	.path_en_shift_val                            = 31,
	.dt_id_shift_val                              = 27,
	.vc_shift_val                                 = 22,
	.vc_mask                                      = 0x1F,
	.dt_shift_val                                 = 16,
	.dt_mask                                      = 0x3F,
	.crop_shift_val                               = 16,
	.decode_format_shift_val                      = 12,
	.decode_format1_shift_val                     = 16,
	.decode_format_mask                           = 0xF,
	.decode_format1_supported                     = true,
	.frame_id_decode_en_shift_val                 = 1,
	.multi_vcdt_vc1_shift_val                     = 2,
	.multi_vcdt_dt1_shift_val                     = 7,
	.multi_vcdt_en_shift_val                      = 0,
	.timestamp_stb_sel_shift_val                  = 8,
	.vfr_en_shift_val                             = 0,
	.early_eof_supported                          = 1,
	.vfr_supported                                = 1,
	.multi_vcdt_supported                         = 1,
	.frame_id_dec_supported                       = 1,
	.measure_en_hbi_vbi_cnt_mask                  = 0xc,
	.measure_pixel_line_en_mask                   = 0x3,
	.crop_pix_start_mask                          = 0x3fff,
	.crop_pix_end_mask                            = 0xffff,
	.crop_line_start_mask                         = 0x3fff,
	.crop_line_end_mask                           = 0xffff,
	.drop_supported                               = 1,
	.ipp_irq_mask_all                             = 0x7FFF,
	.rdi_irq_mask_all                             = 0x7FFF,
	.rst_loc_path_only_val                        = 0x0,
	.rst_location_shift_val                       = 4,
	.rst_loc_complete_csid_val                    = 0x1,
	.rst_mode_frame_boundary_val                  = 0x0,
	.rst_mode_immediate_val                       = 0x1,
	.rst_cmd_hw_reset_complete_val                = 0x1,
	.rst_cmd_sw_reset_complete_val                = 0x2,
	.rst_cmd_irq_ctrl_only_val                    = 0x4,
	.timestamp_strobe_val                         = 0x2,
	.global_reset                                 = 1,
	.rup_supported                                = 1,
	.only_master_rup                              = 1,
	.top_reset_irq_mask                           = 0x1,
	.top_buf_done_irq_mask                        = 0x2000,
	.decode_format_payload_only                   = 0xF,
	.timestamp_enabled_in_cfg0                    = true,
};

static struct cam_ife_csid_csi2_rx_reg_info
	cam_ife_csid_lite_780_csi2_reg_info = {
		.irq_status_addr                      = 0x9C,
		.irq_mask_addr                        = 0xA0,
		.irq_clear_addr                       = 0xA4,
		.irq_set_addr                         = 0xA8,
		/*CSI2 rx control */
		.cfg0_addr                            = 0x200,
		.cfg1_addr                            = 0x204,
		.capture_ctrl_addr                    = 0x208,
		.rst_strobes_addr                     = 0x20C,
		.cap_unmap_long_pkt_hdr_0_addr        = 0x210,
		.cap_unmap_long_pkt_hdr_1_addr        = 0x214,
		.captured_short_pkt_0_addr            = 0x218,
		.captured_short_pkt_1_addr            = 0x21c,
		.captured_long_pkt_0_addr             = 0x220,
		.captured_long_pkt_1_addr             = 0x224,
		.captured_long_pkt_ftr_addr           = 0x228,
		.captured_cphy_pkt_hdr_addr           = 0x22c,
		.lane0_misr_addr                      = 0x230,
		.lane1_misr_addr                      = 0x234,
		.lane2_misr_addr                      = 0x238,
		.lane3_misr_addr                      = 0x23c,
		.total_pkts_rcvd_addr                 = 0x240,
		.stats_ecc_addr                       = 0x244,
		.total_crc_err_addr                   = 0x248,
		.de_scramble_type3_cfg0_addr          = 0x24C,
		.de_scramble_type3_cfg1_addr          = 0x250,
		.de_scramble_type2_cfg0_addr          = 0x254,
		.de_scramble_type2_cfg1_addr          = 0x258,
		.de_scramble_type1_cfg0_addr          = 0x25C,
		.de_scramble_type1_cfg1_addr          = 0x260,
		.de_scramble_type0_cfg0_addr          = 0x264,
		.de_scramble_type0_cfg1_addr          = 0x268,

		.rst_done_shift_val                   = 27,
		.irq_mask_all                         = 0xFFFFFFF,
		.misr_enable_shift_val                = 6,
		.vc_mode_shift_val                    = 2,
		.capture_long_pkt_en_shift            = 0,
		.capture_short_pkt_en_shift           = 1,
		.capture_cphy_pkt_en_shift            = 2,
		.capture_long_pkt_dt_shift            = 4,
		.capture_long_pkt_vc_shift            = 10,
		.capture_short_pkt_vc_shift           = 15,
		.capture_cphy_pkt_dt_shift            = 20,
		.capture_cphy_pkt_vc_shift            = 26,
		.phy_num_mask                         = 0xf,
		.vc_mask                              = 0x7C00000,
		.dt_mask                              = 0x3f0000,
		.wc_mask                              = 0xffff0000,
		.calc_crc_mask                        = 0xffff,
		.expected_crc_mask                    = 0xffff,
		.ecc_correction_shift_en              = 0,
		.lane_num_shift                       = 0,
		.lane_cfg_shift                       = 4,
		.phy_type_shift                       = 24,
		.phy_num_shift                        = 20,
		.tpg_mux_en_shift                     = 27,
		.tpg_num_sel_shift                    = 28,
		.phy_bist_shift_en                    = 7,
		.epd_mode_shift_en                    = 8,
		.eotp_shift_en                        = 9,
		.dyn_sensor_switch_shift_en           = 10,
		.fatal_err_mask                       = 0x78000,
		.part_fatal_err_mask                  = 0x1801800,
		.non_fatal_err_mask                   = 0x380000,
};

static struct cam_ife_csid_ver2_path_reg_info
	cam_ife_csid_lite_780_ipp_reg_info = {
		.irq_status_addr                      = 0xAC,
		.irq_mask_addr                        = 0xB0,
		.irq_clear_addr                       = 0xB4,
		.irq_set_addr                         = 0xB8,
		.cfg0_addr                            = 0x300,
		.ctrl_addr                            = 0x304,
		.debug_clr_cmd_addr                   = 0x308,
		.multi_vcdt_cfg0_addr                 = 0x30c,
		.cfg1_addr                            = 0x310,
		.err_recovery_cfg0_addr               = 0x318,
		.err_recovery_cfg1_addr               = 0x31C,
		.err_recovery_cfg2_addr               = 0x320,
		.camif_frame_cfg_addr                 = 0x330,
		.epoch_irq_cfg_addr                   = 0x334,
		.epoch0_subsample_ptrn_addr           = 0x338,
		.epoch1_subsample_ptrn_addr           = 0x33C,
		.debug_camif_1_addr                   = 0x340,
		.debug_camif_0_addr                   = 0x344,
		.debug_halt_status_addr               = 0x348,
		.debug_misr_val0_addr                 = 0x34C,
		.debug_misr_val1_addr                 = 0x350,
		.debug_misr_val2_addr                 = 0x354,
		.debug_misr_val3_addr                 = 0x358,
		.hcrop_addr                           = 0x35c,
		.vcrop_addr                           = 0x360,
		.pix_drop_pattern_addr                = 0x364,
		.pix_drop_period_addr                 = 0x368,
		.line_drop_pattern_addr               = 0x36C,
		.line_drop_period_addr                = 0x370,
		.frm_drop_pattern_addr                = 0x374,
		.frm_drop_period_addr                 = 0x378,
		.irq_subsample_pattern_addr           = 0x37C,
		.irq_subsample_period_addr            = 0x380,
		.format_measure_cfg0_addr             = 0x384,
		.format_measure_cfg1_addr             = 0x388,
		.format_measure0_addr                 = 0x38C,
		.format_measure1_addr                 = 0x390,
		.format_measure2_addr                 = 0x394,
		.timestamp_curr0_sof_addr             = 0x398,
		.timestamp_curr1_sof_addr             = 0x39C,
		.timestamp_perv0_sof_addr             = 0x3A0,
		.timestamp_perv1_sof_addr             = 0x3A4,
		.timestamp_curr0_eof_addr             = 0x3A8,
		.timestamp_curr1_eof_addr             = 0x3AC,
		.timestamp_perv0_eof_addr             = 0x3B0,
		.timestamp_perv1_eof_addr             = 0x3B4,
		.batch_period_cfg_addr                = 0x3C4,
		.batch_stream_id_cfg_addr             = 0x3C8,
		.epoch0_cfg_batch_id0_addr            = 0x3CC,
		.epoch1_cfg_batch_id0_addr            = 0x3D0,
		.epoch0_cfg_batch_id1_addr            = 0x3D4,
		.epoch1_cfg_batch_id1_addr            = 0x3D8,
		.epoch0_cfg_batch_id2_addr            = 0x3DC,
		.epoch1_cfg_batch_id2_addr            = 0x3E0,
		.epoch0_cfg_batch_id3_addr            = 0x3E4,
		.epoch1_cfg_batch_id3_addr            = 0x3E8,
		.epoch0_cfg_batch_id4_addr            = 0x3EC,
		.epoch1_cfg_batch_id4_addr            = 0x3F0,
		.epoch0_cfg_batch_id5_addr            = 0x3F4,
		.epoch1_cfg_batch_id5_addr            = 0x3F8,

		/* configurations */
		.start_mode_internal                  = 0x0,
		.start_mode_global                    = 0x1,
		.start_mode_master                    = 0x2,
		.start_mode_slave                     = 0x3,
		.start_mode_shift                     = 2,
		.start_master_sel_val                 = 0,
		.start_master_sel_shift               = 4,
		.resume_frame_boundary                = 1,
		.crop_v_en_shift_val                  = 13,
		.crop_h_en_shift_val                  = 12,
		.drop_v_en_shift_val                  = 11,
		.drop_h_en_shift_val                  = 10,
		.pix_store_en_shift_val               = 14,
		.early_eof_en_shift_val               = 16,
		.format_measure_en_shift_val          = 8,
		.timestamp_en_shift_val               = 6,
		.overflow_ctrl_en                     = 1,
		.overflow_ctrl_mode_val               = 0x8,
		.min_hbi_shift_val                    = 4,
		.start_master_sel_shift_val           = 4,
		.fatal_err_mask                       = 0x7,
		.non_fatal_err_mask                   = 0x10080000,
		.camif_irq_mask                       = 0x800000,
		.rup_aup_mask                         = 0x10001,
		.top_irq_mask                         = 0x10,
};

static struct cam_ife_csid_ver2_path_reg_info
	cam_ife_csid_lite_780_rdi_0_reg_info = {
		.irq_status_addr                     = 0xEC,
		.irq_mask_addr                       = 0xF0,
		.irq_clear_addr                      = 0xF4,
		.irq_set_addr                        = 0xF8,
		.cfg0_addr                           = 0x500,
		.ctrl_addr                           = 0x504,
		.debug_clr_cmd_addr                  = 0x508,
		.multi_vcdt_cfg0_addr                = 0x50c,
		.cfg1_addr                           = 0x510,
		.err_recovery_cfg0_addr              = 0x514,
		.err_recovery_cfg1_addr              = 0x518,
		.err_recovery_cfg2_addr              = 0x51C,
		.debug_byte_cntr_ping_addr           = 0x520,
		.debug_byte_cntr_pong_addr           = 0x524,
		.camif_frame_cfg_addr                = 0x528,
		.epoch_irq_cfg_addr                  = 0x52C,
		.epoch0_subsample_ptrn_addr          = 0x530,
		.epoch1_subsample_ptrn_addr          = 0x534,
		.debug_camif_1_addr                  = 0x538,
		.debug_camif_0_addr                  = 0x53C,
		.frm_drop_pattern_addr               = 0x540,
		.frm_drop_period_addr                = 0x540,
		.irq_subsample_pattern_addr          = 0x548,
		.irq_subsample_period_addr           = 0x54C,
		.hcrop_addr                          = 0x550,
		.vcrop_addr                          = 0x554,
		.pix_drop_pattern_addr               = 0x558,
		.pix_drop_period_addr                = 0x55C,
		.line_drop_pattern_addr              = 0x560,
		.line_drop_period_addr               = 0x564,
		.debug_halt_status_addr              = 0x568,
		.debug_misr_val0_addr                = 0x570,
		.debug_misr_val1_addr                = 0x574,
		.debug_misr_val2_addr                = 0x578,
		.debug_misr_val3_addr                = 0x57C,
		.format_measure_cfg0_addr            = 0x580,
		.format_measure_cfg1_addr            = 0x584,
		.format_measure0_addr                = 0x588,
		.format_measure1_addr                = 0x58C,
		.format_measure2_addr                = 0x590,
		.timestamp_curr0_sof_addr            = 0x594,
		.timestamp_curr1_sof_addr            = 0x598,
		.timestamp_perv0_sof_addr            = 0x59C,
		.timestamp_perv1_sof_addr            = 0x5A0,
		.timestamp_curr0_eof_addr            = 0x5A4,
		.timestamp_curr1_eof_addr            = 0x5A8,
		.timestamp_perv0_eof_addr            = 0x5AC,
		.timestamp_perv1_eof_addr            = 0x5B0,
		.batch_period_cfg_addr               = 0x5BC,
		.batch_stream_id_cfg_addr            = 0x5C0,
		.epoch0_cfg_batch_id0_addr           = 0x5C4,
		.epoch1_cfg_batch_id0_addr           = 0x5C8,
		.epoch0_cfg_batch_id1_addr           = 0x5CC,
		.epoch1_cfg_batch_id1_addr           = 0x5D0,
		.epoch0_cfg_batch_id2_addr           = 0x5D4,
		.epoch1_cfg_batch_id2_addr           = 0x5D8,
		.epoch0_cfg_batch_id3_addr           = 0x5DC,
		.epoch1_cfg_batch_id3_addr           = 0x5E0,
		.epoch0_cfg_batch_id4_addr           = 0x5E4,
		.epoch1_cfg_batch_id4_addr           = 0x5E8,
		.epoch0_cfg_batch_id5_addr           = 0x5EC,
		.epoch1_cfg_batch_id5_addr           = 0x5F0,
		/* configurations */
		.resume_frame_boundary               = 1,
		.overflow_ctrl_en                    = 1,
		.overflow_ctrl_mode_val              = 0x8,
		.mipi_pack_supported                 = 1,
		.packing_fmt_shift_val               = 15,
		.plain_alignment_shift_val           = 11,
		.plain_fmt_shift_val                 = 12,
		.crop_v_en_shift_val                 = 8,
		.crop_h_en_shift_val                 = 7,
		.drop_v_en_shift_val                 = 6,
		.drop_h_en_shift_val                 = 5,
		.early_eof_en_shift_val              = 14,
		.format_measure_en_shift_val         = 3,
		.timestamp_en_shift_val              = 6,
		.debug_byte_cntr_rst_shift_val       = 2,
		.ccif_violation_en                   = 1,
		.fatal_err_mask                      = 0x5,
		.non_fatal_err_mask                  = 0x10080000,
		.camif_irq_mask                      = 0x800000,
		.rup_aup_mask                        = 0x100010,
		.top_irq_mask                        = 0x100,
};

static struct cam_ife_csid_ver2_path_reg_info
	cam_ife_csid_lite_780_rdi_1_reg_info = {
		.irq_status_addr                     = 0xFC,
		.irq_mask_addr                       = 0x100,
		.irq_clear_addr                      = 0x104,
		.irq_set_addr                        = 0x108,
		.cfg0_addr                           = 0x600,
		.ctrl_addr                           = 0x604,
		.debug_clr_cmd_addr                  = 0x608,
		.multi_vcdt_cfg0_addr                = 0x60c,
		.cfg1_addr                           = 0x610,
		.err_recovery_cfg0_addr              = 0x614,
		.err_recovery_cfg1_addr              = 0x618,
		.err_recovery_cfg2_addr              = 0x61C,
		.debug_byte_cntr_ping_addr           = 0x620,
		.debug_byte_cntr_pong_addr           = 0x624,
		.camif_frame_cfg_addr                = 0x628,
		.epoch_irq_cfg_addr                  = 0x62C,
		.epoch0_subsample_ptrn_addr          = 0x630,
		.epoch1_subsample_ptrn_addr          = 0x634,
		.debug_camif_1_addr                  = 0x638,
		.debug_camif_0_addr                  = 0x63C,
		.frm_drop_pattern_addr               = 0x640,
		.frm_drop_period_addr                = 0x644,
		.irq_subsample_pattern_addr          = 0x648,
		.irq_subsample_period_addr           = 0x64C,
		.hcrop_addr                          = 0x650,
		.vcrop_addr                          = 0x654,
		.pix_drop_pattern_addr               = 0x658,
		.pix_drop_period_addr                = 0x65C,
		.line_drop_pattern_addr              = 0x660,
		.line_drop_period_addr               = 0x664,
		.debug_halt_status_addr              = 0x66C,
		.debug_misr_val0_addr                = 0x670,
		.debug_misr_val1_addr                = 0x674,
		.debug_misr_val2_addr                = 0x678,
		.debug_misr_val3_addr                = 0x67C,
		.format_measure_cfg0_addr            = 0x680,
		.format_measure_cfg1_addr            = 0x684,
		.format_measure0_addr                = 0x688,
		.format_measure1_addr                = 0x68C,
		.format_measure2_addr                = 0x690,
		.timestamp_curr0_sof_addr            = 0x694,
		.timestamp_curr1_sof_addr            = 0x698,
		.timestamp_perv0_sof_addr            = 0x69C,
		.timestamp_perv1_sof_addr            = 0x6A0,
		.timestamp_curr0_eof_addr            = 0x6A4,
		.timestamp_curr1_eof_addr            = 0x6A8,
		.timestamp_perv0_eof_addr            = 0x6AC,
		.timestamp_perv1_eof_addr            = 0x6B0,
		.batch_period_cfg_addr               = 0x6BC,
		.batch_stream_id_cfg_addr            = 0x6C0,
		.epoch0_cfg_batch_id0_addr           = 0x6C4,
		.epoch1_cfg_batch_id0_addr           = 0x6C8,
		.epoch0_cfg_batch_id1_addr           = 0x6CC,
		.epoch1_cfg_batch_id1_addr           = 0x6D0,
		.epoch0_cfg_batch_id2_addr           = 0x6D4,
		.epoch1_cfg_batch_id2_addr           = 0x6D8,
		.epoch0_cfg_batch_id3_addr           = 0x6DC,
		.epoch1_cfg_batch_id3_addr           = 0x6E0,
		.epoch0_cfg_batch_id4_addr           = 0x6E4,
		.epoch1_cfg_batch_id4_addr           = 0x6E8,
		.epoch0_cfg_batch_id5_addr           = 0x6EC,
		.epoch1_cfg_batch_id5_addr           = 0x6F0,
		/* configurations */
		.resume_frame_boundary               = 1,
		.overflow_ctrl_en                    = 1,
		.overflow_ctrl_mode_val              = 0x8,
		.packing_fmt_shift_val               = 15,
		.plain_alignment_shift_val           = 11,
		.plain_fmt_shift_val                 = 12,
		.crop_v_en_shift_val                 = 8,
		.crop_h_en_shift_val                 = 7,
		.drop_v_en_shift_val                 = 6,
		.drop_h_en_shift_val                 = 5,
		.early_eof_en_shift_val              = 14,
		.format_measure_en_shift_val         = 3,
		.timestamp_en_shift_val              = 6,
		.debug_byte_cntr_rst_shift_val       = 2,
		.ccif_violation_en                   = 1,
		.fatal_err_mask                      = 0x5,
		.non_fatal_err_mask                  = 0x10080000,
		.camif_irq_mask                      = 0x800000,
		.rup_aup_mask                        = 0x200020,
		.top_irq_mask                        = 0x200,
};

static struct cam_ife_csid_ver2_path_reg_info
	cam_ife_csid_lite_780_rdi_2_reg_info = {
		.irq_status_addr                     = 0x10C,
		.irq_mask_addr                       = 0x110,
		.irq_clear_addr                      = 0x114,
		.irq_set_addr                        = 0x118,
		.cfg0_addr                           = 0x700,
		.ctrl_addr                           = 0x704,
		.debug_clr_cmd_addr                  = 0x708,
		.multi_vcdt_cfg0_addr                = 0x70c,
		.cfg1_addr                           = 0x710,
		.err_recovery_cfg0_addr              = 0x714,
		.err_recovery_cfg1_addr              = 0x718,
		.err_recovery_cfg2_addr              = 0x71C,
		.debug_byte_cntr_ping_addr           = 0x720,
		.debug_byte_cntr_pong_addr           = 0x724,
		.camif_frame_cfg_addr                = 0x728,
		.epoch_irq_cfg_addr                  = 0x72C,
		.epoch0_subsample_ptrn_addr          = 0x730,
		.epoch1_subsample_ptrn_addr          = 0x734,
		.debug_camif_1_addr                  = 0x738,
		.debug_camif_0_addr                  = 0x73C,
		.frm_drop_pattern_addr               = 0x740,
		.frm_drop_period_addr                = 0x744,
		.irq_subsample_pattern_addr          = 0x748,
		.irq_subsample_period_addr           = 0x74C,
		.hcrop_addr                          = 0x750,
		.vcrop_addr                          = 0x754,
		.pix_drop_pattern_addr               = 0x758,
		.pix_drop_period_addr                = 0x75C,
		.line_drop_pattern_addr              = 0x760,
		.line_drop_period_addr               = 0x764,
		.debug_halt_status_addr              = 0x76C,
		.debug_misr_val0_addr                = 0x770,
		.debug_misr_val1_addr                = 0x774,
		.debug_misr_val2_addr                = 0x778,
		.debug_misr_val3_addr                = 0x77C,
		.format_measure_cfg0_addr            = 0x780,
		.format_measure_cfg1_addr            = 0x784,
		.format_measure0_addr                = 0x788,
		.format_measure1_addr                = 0x78C,
		.format_measure2_addr                = 0x790,
		.timestamp_curr0_sof_addr            = 0x794,
		.timestamp_curr1_sof_addr            = 0x798,
		.timestamp_perv0_sof_addr            = 0x79C,
		.timestamp_perv1_sof_addr            = 0x7A0,
		.timestamp_curr0_eof_addr            = 0x7A4,
		.timestamp_curr1_eof_addr            = 0x7A8,
		.timestamp_perv0_eof_addr            = 0x7AC,
		.timestamp_perv1_eof_addr            = 0x7B0,
		.batch_period_cfg_addr               = 0x7BC,
		.batch_stream_id_cfg_addr            = 0x7C0,
		.epoch0_cfg_batch_id0_addr           = 0x7C4,
		.epoch1_cfg_batch_id0_addr           = 0x7C8,
		.epoch0_cfg_batch_id1_addr           = 0x7CC,
		.epoch1_cfg_batch_id1_addr           = 0x7D0,
		.epoch0_cfg_batch_id2_addr           = 0x7D4,
		.epoch1_cfg_batch_id2_addr           = 0x7D8,
		.epoch0_cfg_batch_id3_addr           = 0x7DC,
		.epoch1_cfg_batch_id3_addr           = 0x7E0,
		.epoch0_cfg_batch_id4_addr           = 0x7E4,
		.epoch1_cfg_batch_id4_addr           = 0x7E8,
		.epoch0_cfg_batch_id5_addr           = 0x7EC,
		.epoch1_cfg_batch_id5_addr           = 0x7F0,
		/* configurations */
		.resume_frame_boundary               = 1,
		.overflow_ctrl_en                    = 1,
		.overflow_ctrl_mode_val              = 0x8,
		.packing_fmt_shift_val               = 15,
		.plain_alignment_shift_val           = 11,
		.plain_fmt_shift_val                 = 12,
		.crop_v_en_shift_val                 = 8,
		.crop_h_en_shift_val                 = 7,
		.drop_v_en_shift_val                 = 6,
		.drop_h_en_shift_val                 = 5,
		.early_eof_en_shift_val              = 14,
		.format_measure_en_shift_val         = 3,
		.timestamp_en_shift_val              = 6,
		.debug_byte_cntr_rst_shift_val       = 2,
		.ccif_violation_en                   = 1,
		.fatal_err_mask                      = 0x5,
		.non_fatal_err_mask                  = 0x10080000,
		.camif_irq_mask                      = 0x800000,
		.rup_aup_mask                        = 0x400040,
		.top_irq_mask                        = 0x400,
};

static struct cam_ife_csid_ver2_path_reg_info
	cam_ife_csid_lite_780_rdi_3_reg_info = {
		.irq_status_addr                     = 0x11C,
		.irq_mask_addr                       = 0x120,
		.irq_clear_addr                      = 0x124,
		.irq_set_addr                        = 0x128,
		.cfg0_addr                           = 0x800,
		.ctrl_addr                           = 0x804,
		.debug_clr_cmd_addr                  = 0x808,
		.multi_vcdt_cfg0_addr                = 0x80c,
		.cfg1_addr                           = 0x810,
		.err_recovery_cfg0_addr              = 0x814,
		.err_recovery_cfg1_addr              = 0x818,
		.err_recovery_cfg2_addr              = 0x81C,
		.debug_byte_cntr_ping_addr           = 0x820,
		.debug_byte_cntr_pong_addr           = 0x824,
		.camif_frame_cfg_addr                = 0x828,
		.epoch_irq_cfg_addr                  = 0x82C,
		.epoch0_subsample_ptrn_addr          = 0x830,
		.epoch1_subsample_ptrn_addr          = 0x834,
		.debug_camif_1_addr                  = 0x838,
		.debug_camif_0_addr                  = 0x83C,
		.frm_drop_pattern_addr               = 0x840,
		.frm_drop_period_addr                = 0x840,
		.irq_subsample_pattern_addr          = 0x848,
		.irq_subsample_period_addr           = 0x84C,
		.hcrop_addr                          = 0x850,
		.vcrop_addr                          = 0x854,
		.pix_drop_pattern_addr               = 0x858,
		.pix_drop_period_addr                = 0x85C,
		.line_drop_pattern_addr              = 0x860,
		.line_drop_period_addr               = 0x864,
		.debug_halt_status_addr              = 0x868,
		.debug_misr_val0_addr                = 0x870,
		.debug_misr_val1_addr                = 0x874,
		.debug_misr_val2_addr                = 0x878,
		.debug_misr_val3_addr                = 0x87C,
		.format_measure_cfg0_addr            = 0x880,
		.format_measure_cfg1_addr            = 0x884,
		.format_measure0_addr                = 0x888,
		.format_measure1_addr                = 0x88C,
		.format_measure2_addr                = 0x890,
		.timestamp_curr0_sof_addr            = 0x894,
		.timestamp_curr1_sof_addr            = 0x898,
		.timestamp_perv0_sof_addr            = 0x89C,
		.timestamp_perv1_sof_addr            = 0x8A0,
		.timestamp_curr0_eof_addr            = 0x8A4,
		.timestamp_curr1_eof_addr            = 0x8A8,
		.timestamp_perv0_eof_addr            = 0x8AC,
		.timestamp_perv1_eof_addr            = 0x8B0,
		.batch_period_cfg_addr               = 0x8BC,
		.batch_stream_id_cfg_addr            = 0x8C0,
		.epoch0_cfg_batch_id0_addr           = 0x8C4,
		.epoch1_cfg_batch_id0_addr           = 0x8C8,
		.epoch0_cfg_batch_id1_addr           = 0x8CC,
		.epoch1_cfg_batch_id1_addr           = 0x8D0,
		.epoch0_cfg_batch_id2_addr           = 0x8D4,
		.epoch1_cfg_batch_id2_addr           = 0x8D8,
		.epoch0_cfg_batch_id3_addr           = 0x8DC,
		.epoch1_cfg_batch_id3_addr           = 0x8E0,
		.epoch0_cfg_batch_id4_addr           = 0x8E4,
		.epoch1_cfg_batch_id4_addr           = 0x8E8,
		.epoch0_cfg_batch_id5_addr           = 0x8EC,
		.epoch1_cfg_batch_id5_addr           = 0x8F0,
		/* configurations */
		.resume_frame_boundary               = 1,
		.overflow_ctrl_en                    = 1,
		.overflow_ctrl_mode_val              = 0x8,
		.packing_fmt_shift_val               = 15,
		.plain_alignment_shift_val           = 11,
		.plain_fmt_shift_val                 = 12,
		.crop_v_en_shift_val                 = 8,
		.crop_h_en_shift_val                 = 7,
		.drop_v_en_shift_val                 = 6,
		.drop_h_en_shift_val                 = 5,
		.early_eof_en_shift_val              = 14,
		.format_measure_en_shift_val         = 3,
		.timestamp_en_shift_val              = 6,
		.debug_byte_cntr_rst_shift_val       = 2,
		.ccif_violation_en                   = 1,
		.fatal_err_mask                      = 0x5,
		.non_fatal_err_mask                  = 0x10080000,
		.camif_irq_mask                      = 0x800000,
		.rup_aup_mask                        = 0x800080,
		.top_irq_mask                        = 0x800,
};

static struct cam_ife_csid_ver2_reg_info cam_ife_csid_lite_780_reg_info = {
	.irq_reg_info          = &cam_ife_csid_lite_780_irq_reg_info,
	.cmn_reg               = &cam_ife_csid_lite_780_cmn_reg_info,
	.csi2_reg              = &cam_ife_csid_lite_780_csi2_reg_info,
	.buf_done_irq_reg_info = &cam_ife_csid_lite_780_buf_done_irq_reg_info,
	.path_reg[CAM_IFE_PIX_PATH_RES_IPP]   = &cam_ife_csid_lite_780_ipp_reg_info,
	.path_reg[CAM_IFE_PIX_PATH_RES_PPP]   = NULL,
	.path_reg[CAM_IFE_PIX_PATH_RES_RDI_0] = &cam_ife_csid_lite_780_rdi_0_reg_info,
	.path_reg[CAM_IFE_PIX_PATH_RES_RDI_1] = &cam_ife_csid_lite_780_rdi_1_reg_info,
	.path_reg[CAM_IFE_PIX_PATH_RES_RDI_2] = &cam_ife_csid_lite_780_rdi_2_reg_info,
	.path_reg[CAM_IFE_PIX_PATH_RES_RDI_3] = &cam_ife_csid_lite_780_rdi_3_reg_info,
	.need_top_cfg = 0,
	.rx_irq_desc        = cam_ife_csid_lite_780_rx_irq_desc,
	.path_irq_desc      = cam_ife_csid_lite_780_path_irq_desc,
	.top_irq_desc       = cam_ife_csid_lite_780_top_irq_desc,
	.num_top_err_irqs   = ARRAY_SIZE(cam_ife_csid_lite_780_top_irq_desc),
};
#endif /* _CAM_IFE_CSID_LITE_780_H_ */
