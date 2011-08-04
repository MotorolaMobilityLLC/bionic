/****************************************************************************
 ****************************************************************************
 ***
 ***   This header was automatically generated from a Linux kernel header
 ***   of the same name, to make information necessary for userspace to
 ***   call into the kernel available to libc.  It contains only constants,
 ***   structures, and macros generated from the original header, and thus,
 ***   contains no copyrightable information.
 ***
 ***   To edit the content of this header, modify the corresponding
 ***   source file (e.g. under external/kernel-headers/original/) then
 ***   run bionic/libc/kernel/tools/update_all.py
 ***
 ***   Any manual change here will be lost the next time this script will
 ***   be run. You've been warned!
 ***
 ****************************************************************************
 ****************************************************************************/
#ifndef _LINUX_DSSCOMP_H
#define _LINUX_DSSCOMP_H
enum omap_plane {
 OMAP_DSS_GFX = 0,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 OMAP_DSS_VIDEO1 = 1,
 OMAP_DSS_VIDEO2 = 2,
 OMAP_DSS_VIDEO3 = 3,
 OMAP_DSS_WB = 4,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
enum omap_channel {
 OMAP_DSS_CHANNEL_LCD = 0,
 OMAP_DSS_CHANNEL_DIGIT = 1,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 OMAP_DSS_CHANNEL_LCD2 = 2,
};
enum omap_color_mode {
 OMAP_DSS_COLOR_CLUT1 = 1 << 0,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 OMAP_DSS_COLOR_CLUT2 = 1 << 1,
 OMAP_DSS_COLOR_CLUT4 = 1 << 2,
 OMAP_DSS_COLOR_CLUT8 = 1 << 3,
 OMAP_DSS_COLOR_RGB12U = 1 << 4,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 OMAP_DSS_COLOR_ARGB16 = 1 << 5,
 OMAP_DSS_COLOR_RGB16 = 1 << 6,
 OMAP_DSS_COLOR_RGB24U = 1 << 7,
 OMAP_DSS_COLOR_RGB24P = 1 << 8,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 OMAP_DSS_COLOR_YUV2 = 1 << 9,
 OMAP_DSS_COLOR_UYVY = 1 << 10,
 OMAP_DSS_COLOR_ARGB32 = 1 << 11,
 OMAP_DSS_COLOR_RGBA32 = 1 << 12,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 OMAP_DSS_COLOR_RGBX24 = 1 << 13,
 OMAP_DSS_COLOR_RGBX32 = 1 << 13,
 OMAP_DSS_COLOR_NV12 = 1 << 14,
 OMAP_DSS_COLOR_RGBA16 = 1 << 15,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 OMAP_DSS_COLOR_RGBX12 = 1 << 16,
 OMAP_DSS_COLOR_RGBX16 = 1 << 16,
 OMAP_DSS_COLOR_ARGB16_1555 = 1 << 17,
 OMAP_DSS_COLOR_XRGB15 = 1 << 18,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 OMAP_DSS_COLOR_XRGB16_1555 = 1 << 18,
};
enum omap_dss_trans_key_type {
 OMAP_DSS_COLOR_KEY_GFX_DST = 0,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 OMAP_DSS_COLOR_KEY_VID_SRC = 1,
};
enum omap_dss_display_state {
 OMAP_DSS_DISPLAY_DISABLED = 0,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 OMAP_DSS_DISPLAY_ACTIVE,
 OMAP_DSS_DISPLAY_SUSPENDED,
 OMAP_DSS_DISPLAY_TRANSITION,
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct omap_video_timings {
 __u16 x_res;
 __u16 y_res;
 __u32 pixel_clock;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u16 hsw;
 __u16 hfp;
 __u16 hbp;
 __u16 vsw;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u16 vfp;
 __u16 vbp;
};
struct omap_dss_cconv_coefs {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __s16 ry, rcr, rcb;
 __s16 gy, gcr, gcb;
 __s16 by, bcr, bcb;
 __u16 full_range;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
} __attribute__ ((aligned(4)));
struct omap_dss_cpr_coefs {
 __s16 rr, rg, rb;
 __s16 gr, gg, gb;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __s16 br, bg, bb;
};
enum s3d_disp_type {
 S3D_DISP_NONE = 0,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 S3D_DISP_FRAME_SEQ,
 S3D_DISP_ROW_IL,
 S3D_DISP_COL_IL,
 S3D_DISP_PIX_IL,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 S3D_DISP_CHECKB,
 S3D_DISP_OVERUNDER,
 S3D_DISP_SIDEBYSIDE,
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
enum s3d_disp_sub_sampling {
 S3D_DISP_SUB_SAMPLE_NONE = 0,
 S3D_DISP_SUB_SAMPLE_V,
 S3D_DISP_SUB_SAMPLE_H,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
enum s3d_disp_order {
 S3D_DISP_ORDER_L = 0,
 S3D_DISP_ORDER_R = 1,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
enum s3d_disp_view {
 S3D_DISP_VIEW_L = 0,
 S3D_DISP_VIEW_R,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct s3d_disp_info {
 enum s3d_disp_type type;
 enum s3d_disp_sub_sampling sub_samp;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 enum s3d_disp_order order;
 unsigned int gap;
};
enum omap_dss_ilace_mode {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 OMAP_DSS_ILACE = (1 << 0),
 OMAP_DSS_ILACE_SEQ = (1 << 1),
 OMAP_DSS_ILACE_SWAP = (1 << 2),
 OMAP_DSS_ILACE_NONE = 0,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 OMAP_DSS_ILACE_IL_TB = OMAP_DSS_ILACE,
 OMAP_DSS_ILACE_IL_BT = OMAP_DSS_ILACE | OMAP_DSS_ILACE_SWAP,
 OMAP_DSS_ILACE_SEQ_TB = OMAP_DSS_ILACE_IL_TB | OMAP_DSS_ILACE_SEQ,
 OMAP_DSS_ILACE_SEQ_BT = OMAP_DSS_ILACE_IL_BT | OMAP_DSS_ILACE_SEQ,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct dss2_vc1_range_map_info {
 __u8 enable;
 __u8 range_y;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u8 range_uv;
} __attribute__ ((aligned(4)));
struct dss2_rect_t {
 __s32 x;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __s32 y;
 __u32 w;
 __u32 h;
} __attribute__ ((aligned(4)));
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct dss2_decim {
 __u8 min_x;
 __u8 max_x;
 __u8 min_y;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u8 max_y;
} __attribute__ ((aligned(4)));
struct dss2_ovl_cfg {
 __u16 width;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u16 height;
 __u32 stride;
 enum omap_color_mode color_mode;
 __u8 pre_mult_alpha;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u8 global_alpha;
 __u8 rotation;
 __u8 mirror;
 enum omap_dss_ilace_mode ilace;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 struct dss2_rect_t win;
 struct dss2_rect_t crop;
 struct dss2_decim decim;
 struct omap_dss_cconv_coefs cconv;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 struct dss2_vc1_range_map_info vc1;
 __u8 ix;
 __u8 zorder;
 __u8 enabled;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u8 zonly;
} __attribute__ ((aligned(4)));
enum omapdss_buffer_type {
 OMAP_DSS_BUFTYPE_SDMA,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 OMAP_DSS_BUFTYPE_TILER_8BIT,
 OMAP_DSS_BUFTYPE_TILER_16BIT,
 OMAP_DSS_BUFTYPE_TILER_32BIT,
 OMAP_DSS_BUFTYPE_TILER_PAGE,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct dss2_ovl_info {
 struct dss2_ovl_cfg cfg;
 union {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 struct {
 void *address;
 __u16 ba_type;
 __u16 uv_type;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 };
 struct {
 __u32 ba;
 __u32 uv;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 };
 };
};
struct dss2_mgr_info {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 ix;
 __u32 default_color;
 enum omap_dss_trans_key_type trans_key_type;
 __u32 trans_key;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 struct omap_dss_cpr_coefs cpr_coefs;
 __u8 trans_enabled;
 __u8 interlaced;
 __u8 alpha_blending;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u8 cpr_enabled;
 __u8 swap_rb;
} __attribute__ ((aligned(4)));
enum dsscomp_setup_mode {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 DSSCOMP_SETUP_MODE_APPLY = (1 << 0),
 DSSCOMP_SETUP_MODE_DISPLAY = (1 << 1),
 DSSCOMP_SETUP_MODE_CAPTURE = (1 << 2),
 DSSCOMP_SETUP_APPLY = DSSCOMP_SETUP_MODE_APPLY,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 DSSCOMP_SETUP_DISPLAY =
 DSSCOMP_SETUP_MODE_APPLY | DSSCOMP_SETUP_MODE_DISPLAY,
 DSSCOMP_SETUP_CAPTURE =
 DSSCOMP_SETUP_MODE_APPLY | DSSCOMP_SETUP_MODE_CAPTURE,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 DSSCOMP_SETUP_DISPLAY_CAPTURE =
 DSSCOMP_SETUP_DISPLAY | DSSCOMP_SETUP_CAPTURE,
};
struct dsscomp_setup_mgr_data {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 sync_id;
 struct dss2_rect_t win;
 enum dsscomp_setup_mode mode;
 __u16 num_ovls;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u16 get_sync_obj;
 struct dss2_mgr_info mgr;
 struct dss2_ovl_info ovls[0];
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct dsscomp_check_ovl_data {
 enum dsscomp_setup_mode mode;
 struct dss2_mgr_info mgr;
 struct dss2_ovl_info ovl;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct dsscomp_wb_copy_data {
 struct dss2_ovl_info ovl, wb;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct dsscomp_display_info {
 __u32 ix;
 __u32 overlays_available;
 __u32 overlays_owned;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 enum omap_channel channel;
 enum omap_dss_display_state state;
 __u8 enabled;
 struct omap_video_timings timings;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 struct s3d_disp_info s3d_info;
 struct dss2_mgr_info mgr;
};
enum dsscomp_wait_phase {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 DSSCOMP_WAIT_PROGRAMMED = 1,
 DSSCOMP_WAIT_DISPLAYED,
 DSSCOMP_WAIT_RELEASED,
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct dsscomp_wait_data {
 __u32 timeout_us;
 enum dsscomp_wait_phase phase;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define DSSCOMP_SETUP_MGR _IOW('O', 128, struct dsscomp_setup_mgr_data)
#define DSSCOMP_CHECK_OVL _IOWR('O', 129, struct dsscomp_check_ovl_data)
#define DSSCOMP_WB_COPY _IOW('O', 130, struct dsscomp_wb_copy_data)
#define DSSCOMP_QUERY_DISPLAY _IOWR('O', 131, struct dsscomp_display_info)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define DSSCOMP_WAIT _IOW('O', 132, struct dsscomp_wait_data)
#define DSSCOMP_SETUP_MGR_G _IOW('O', 127, struct dsscomp_setup_mgr_data)
#endif

