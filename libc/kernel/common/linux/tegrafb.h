/****************************************************************************
 ****************************************************************************
 ***
 ***   This header was automatically generated from a Linux kernel header
 ***   of the same name, to make information necessary for userspace to
 ***   call into the kernel available to libc.  It contains only constants,
 ***   structures, and macros generated from the original header, and thus,
 ***   contains no copyrightable information.
 ***
 ****************************************************************************
 ****************************************************************************/
#ifndef _LINUX_TEGRAFB_H_
#define _LINUX_TEGRAFB_H_

#include <linux/fb.h>
#include <linux/types.h>
#include <asm/ioctl.h>

#define TEGRA_FB_WIN_FMT_P1 0
#define TEGRA_FB_WIN_FMT_P2 1
#define TEGRA_FB_WIN_FMT_P4 2
#define TEGRA_FB_WIN_FMT_P8 3
#define TEGRA_FB_WIN_FMT_B4G4R4A4 4
#define TEGRA_FB_WIN_FMT_B5G5R5A 5
#define TEGRA_FB_WIN_FMT_B5G6R5 6
#define TEGRA_FB_WIN_FMT_AB5G5R5 7
#define TEGRA_FB_WIN_FMT_B8G8R8A8 12
#define TEGRA_FB_WIN_FMT_R8G8B8A8 13
#define TEGRA_FB_WIN_FMT_B6x2G6x2R6x2A8 14
#define TEGRA_FB_WIN_FMT_R6x2G6x2B6x2A8 15
#define TEGRA_FB_WIN_FMT_YCbCr422 16
#define TEGRA_FB_WIN_FMT_YUV422 17
#define TEGRA_FB_WIN_FMT_YCbCr420P 18
#define TEGRA_FB_WIN_FMT_YUV420P 19
#define TEGRA_FB_WIN_FMT_YCbCr422P 20
#define TEGRA_FB_WIN_FMT_YUV422P 21
#define TEGRA_FB_WIN_FMT_YCbCr422R 22
#define TEGRA_FB_WIN_FMT_YUV422R 23
#define TEGRA_FB_WIN_FMT_YCbCr422RA 24
#define TEGRA_FB_WIN_FMT_YUV422RA 25

#define TEGRA_FB_WIN_BLEND_NONE 0
#define TEGRA_FB_WIN_BLEND_PREMULT 1
#define TEGRA_FB_WIN_BLEND_COVERAGE 2

struct tegra_fb_windowattr {
 __s32 index;
 __u32 buff_id;
 __u32 blend;
 __u32 offset;
 __u32 offset_u;
 __u32 offset_v;
 __u32 stride;
 __u32 stride_uv;
 __u32 pixformat;
 __u32 x;
 __u32 y;
 __u32 w;
 __u32 h;
 __u32 out_x;
 __u32 out_y;
 __u32 out_w;
 __u32 out_h;
 __u32 z;
 __u32 pre_syncpt_id;
 __u32 pre_syncpt_val;
};

#define TEGRA_FB_FLIP_N_WINDOWS 3

struct tegra_fb_flip_args {
 struct tegra_fb_windowattr win[TEGRA_FB_FLIP_N_WINDOWS];
 __u32 post_syncpt_id;
 __u32 post_syncpt_val;
};

struct tegra_fb_modedb {
 struct fb_var_screeninfo *modedb;
 __u32 modedb_len;
};

#define FBIO_TEGRA_SET_NVMAP_FD _IOW('F', 0x40, __u32)
#define FBIO_TEGRA_FLIP _IOW('F', 0x41, struct tegra_fb_flip_args)
#define FBIO_TEGRA_GET_MODEDB _IOWR('F', 0x42, struct tegra_fb_modedb)

#endif

