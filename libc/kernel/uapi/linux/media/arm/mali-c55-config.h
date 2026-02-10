/*
 * This file is auto-generated. Modifications will be lost.
 *
 * See https://android.googlesource.com/platform/bionic/+/master/libc/kernel/
 * for more information.
 */
#ifndef __UAPI_MALI_C55_CONFIG_H
#define __UAPI_MALI_C55_CONFIG_H
#include <linux/types.h>
#include <linux/v4l2-controls.h>
#include <linux/media/v4l2-isp.h>
#define V4L2_CID_MALI_C55_CAPABILITIES (V4L2_CID_USER_MALI_C55_BASE + 0x0)
#define MALI_C55_GPS_PONG (1U << 0)
#define MALI_C55_GPS_WDR (1U << 1)
#define MALI_C55_GPS_COMPRESSION (1U << 2)
#define MALI_C55_GPS_TEMPER (1U << 3)
#define MALI_C55_GPS_SINTER_LITE (1U << 4)
#define MALI_C55_GPS_SINTER (1U << 5)
#define MALI_C55_GPS_IRIDIX_LTM (1U << 6)
#define MALI_C55_GPS_IRIDIX_GTM (1U << 7)
#define MALI_C55_GPS_CNR (1U << 8)
#define MALI_C55_GPS_FRSCALER (1U << 9)
#define MALI_C55_GPS_DS_PIPE (1U << 10)
#define MALI_C55_MAX_ZONES (15 * 15)
struct mali_c55_ae_1024bin_hist {
  __u16 bins[1024];
} __attribute__((packed));
struct mali_c55_ae_5bin_hist {
  __u16 hist0;
  __u16 hist1;
  __u16 hist3;
  __u16 hist4;
} __attribute__((packed));
struct mali_c55_awb_average_ratios {
  __u16 avg_rg_gr;
  __u16 avg_bg_br;
  __u32 num_pixels;
} __attribute__((packed));
struct mali_c55_af_statistics {
  __u16 intensity_stats;
  __u16 edge_stats;
} __attribute__((packed));
struct mali_c55_stats_buffer {
  struct mali_c55_ae_1024bin_hist ae_1024bin_hist;
  struct mali_c55_ae_1024bin_hist iridix_1024bin_hist;
  struct mali_c55_ae_5bin_hist ae_5bin_hists[MALI_C55_MAX_ZONES];
  __u32 reserved1[14];
  struct mali_c55_awb_average_ratios awb_ratios[MALI_C55_MAX_ZONES];
  __u32 reserved2[14];
  struct mali_c55_af_statistics af_statistics[MALI_C55_MAX_ZONES];
  __u32 reserved3[15];
} __attribute__((packed));
enum mali_c55_param_block_type {
  MALI_C55_PARAM_BLOCK_SENSOR_OFFS,
  MALI_C55_PARAM_BLOCK_AEXP_HIST,
  MALI_C55_PARAM_BLOCK_AEXP_IHIST,
  MALI_C55_PARAM_BLOCK_AEXP_HIST_WEIGHTS,
  MALI_C55_PARAM_BLOCK_AEXP_IHIST_WEIGHTS,
  MALI_C55_PARAM_BLOCK_DIGITAL_GAIN,
  MALI_C55_PARAM_BLOCK_AWB_GAINS,
  MALI_C55_PARAM_BLOCK_AWB_CONFIG,
  MALI_C55_PARAM_BLOCK_AWB_GAINS_AEXP,
  MALI_C55_PARAM_MESH_SHADING_CONFIG,
  MALI_C55_PARAM_MESH_SHADING_SELECTION,
};
struct mali_c55_params_sensor_off_preshading {
  struct v4l2_isp_params_block_header header;
  __u32 chan00;
  __u32 chan01;
  __u32 chan10;
  __u32 chan11;
};
enum mali_c55_aexp_hist_tap_points {
  MALI_C55_AEXP_HIST_TAP_WB = 0,
  MALI_C55_AEXP_HIST_TAP_FS,
  MALI_C55_AEXP_HIST_TAP_TPG,
};
enum mali_c55_aexp_skip_x {
  MALI_C55_AEXP_SKIP_X_EVERY_2ND,
  MALI_C55_AEXP_SKIP_X_EVERY_3RD,
  MALI_C55_AEXP_SKIP_X_EVERY_4TH,
  MALI_C55_AEXP_SKIP_X_EVERY_5TH,
  MALI_C55_AEXP_SKIP_X_EVERY_8TH,
  MALI_C55_AEXP_SKIP_X_EVERY_9TH
};
enum mali_c55_aexp_skip_y {
  MALI_C55_AEXP_SKIP_Y_ALL,
  MALI_C55_AEXP_SKIP_Y_EVERY_2ND,
  MALI_C55_AEXP_SKIP_Y_EVERY_3RD,
  MALI_C55_AEXP_SKIP_Y_EVERY_4TH,
  MALI_C55_AEXP_SKIP_Y_EVERY_5TH,
  MALI_C55_AEXP_SKIP_Y_EVERY_8TH,
  MALI_C55_AEXP_SKIP_Y_EVERY_9TH
};
enum mali_c55_aexp_row_column_offset {
  MALI_C55_AEXP_FIRST_ROW_OR_COL = 1,
  MALI_C55_AEXP_SECOND_ROW_OR_COL = 2,
};
enum mali_c55_aexp_hist_plane_mode {
  MALI_C55_AEXP_HIST_COMBINED = 0,
  MALI_C55_AEXP_HIST_SEPARATE = 1,
  MALI_C55_AEXP_HIST_FOCUS_00 = 4,
  MALI_C55_AEXP_HIST_FOCUS_01 = 5,
  MALI_C55_AEXP_HIST_FOCUS_10 = 6,
  MALI_C55_AEXP_HIST_FOCUS_11 = 7,
};
struct mali_c55_params_aexp_hist {
  struct v4l2_isp_params_block_header header;
  __u8 skip_x;
  __u8 offset_x;
  __u8 skip_y;
  __u8 offset_y;
  __u8 scale_bottom;
  __u8 scale_top;
  __u8 plane_mode;
  __u8 tap_point;
};
struct mali_c55_params_aexp_weights {
  struct v4l2_isp_params_block_header header;
  __u8 nodes_used_horiz;
  __u8 nodes_used_vert;
  __u8 zone_weights[MALI_C55_MAX_ZONES];
};
struct mali_c55_params_digital_gain {
  struct v4l2_isp_params_block_header header;
  __u16 gain;
};
enum mali_c55_awb_stats_mode {
  MALI_C55_AWB_MODE_GRBR = 0,
  MALI_C55_AWB_MODE_RGBG,
};
struct mali_c55_params_awb_gains {
  struct v4l2_isp_params_block_header header;
  __u16 gain00;
  __u16 gain01;
  __u16 gain10;
  __u16 gain11;
};
enum mali_c55_params_awb_tap_points {
  MALI_C55_AWB_STATS_TAP_PF = 0,
  MALI_C55_AWB_STATS_TAP_CNR,
};
struct mali_c55_params_awb_config {
  struct v4l2_isp_params_block_header header;
  __u8 tap_point;
  __u8 stats_mode;
  __u16 white_level;
  __u16 black_level;
  __u16 cr_max;
  __u16 cr_min;
  __u16 cb_max;
  __u16 cb_min;
  __u8 nodes_used_horiz;
  __u8 nodes_used_vert;
  __u16 cr_high;
  __u16 cr_low;
  __u16 cb_high;
  __u16 cb_low;
};
#define MALI_C55_NUM_MESH_SHADING_ELEMENTS 3072
struct mali_c55_params_mesh_shading_config {
  struct v4l2_isp_params_block_header header;
  __u8 mesh_show;
  __u8 mesh_scale;
  __u8 mesh_page_r;
  __u8 mesh_page_g;
  __u8 mesh_page_b;
  __u8 mesh_width;
  __u8 mesh_height;
  __u32 mesh[MALI_C55_NUM_MESH_SHADING_ELEMENTS];
};
enum mali_c55_params_mesh_alpha_bank {
  MALI_C55_MESH_ALPHA_BANK_LS0_AND_LS1 = 0,
  MALI_C55_MESH_ALPHA_BANK_LS1_AND_LS2 = 1,
  MALI_C55_MESH_ALPHA_BANK_LS0_AND_LS2 = 4
};
struct mali_c55_params_mesh_shading_selection {
  struct v4l2_isp_params_block_header header;
  __u8 mesh_alpha_bank_r;
  __u8 mesh_alpha_bank_g;
  __u8 mesh_alpha_bank_b;
  __u8 mesh_alpha_r;
  __u8 mesh_alpha_g;
  __u8 mesh_alpha_b;
  __u16 mesh_strength;
};
#define MALI_C55_PARAMS_MAX_SIZE (sizeof(struct mali_c55_params_sensor_off_preshading) + sizeof(struct mali_c55_params_aexp_hist) + sizeof(struct mali_c55_params_aexp_weights) + sizeof(struct mali_c55_params_aexp_hist) + sizeof(struct mali_c55_params_aexp_weights) + sizeof(struct mali_c55_params_digital_gain) + sizeof(struct mali_c55_params_awb_gains) + sizeof(struct mali_c55_params_awb_config) + sizeof(struct mali_c55_params_awb_gains) + sizeof(struct mali_c55_params_mesh_shading_config) + sizeof(struct mali_c55_params_mesh_shading_selection))
#endif
