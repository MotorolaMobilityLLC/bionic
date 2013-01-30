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
#ifndef __LINUX_V4L2_MEDIABUS_H
#define __LINUX_V4L2_MEDIABUS_H
#include <linux/types.h>
#include <linux/videodev2.h>
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
enum v4l2_mbus_pixelcode {
 V4L2_MBUS_FMT_FIXED = 0x0001,
 V4L2_MBUS_FMT_RGB444_2X8_PADHI_BE = 0x1001,
 V4L2_MBUS_FMT_RGB444_2X8_PADHI_LE = 0x1002,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 V4L2_MBUS_FMT_RGB555_2X8_PADHI_BE = 0x1003,
 V4L2_MBUS_FMT_RGB555_2X8_PADHI_LE = 0x1004,
 V4L2_MBUS_FMT_BGR565_2X8_BE = 0x1005,
 V4L2_MBUS_FMT_BGR565_2X8_LE = 0x1006,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 V4L2_MBUS_FMT_RGB565_2X8_BE = 0x1007,
 V4L2_MBUS_FMT_RGB565_2X8_LE = 0x1008,
 V4L2_MBUS_FMT_Y8_1X8 = 0x2001,
 V4L2_MBUS_FMT_UYVY8_1_5X8 = 0x2002,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 V4L2_MBUS_FMT_VYUY8_1_5X8 = 0x2003,
 V4L2_MBUS_FMT_YUYV8_1_5X8 = 0x2004,
 V4L2_MBUS_FMT_YVYU8_1_5X8 = 0x2005,
 V4L2_MBUS_FMT_UYVY8_2X8 = 0x2006,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 V4L2_MBUS_FMT_VYUY8_2X8 = 0x2007,
 V4L2_MBUS_FMT_YUYV8_2X8 = 0x2008,
 V4L2_MBUS_FMT_YVYU8_2X8 = 0x2009,
 V4L2_MBUS_FMT_Y10_1X10 = 0x200a,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 V4L2_MBUS_FMT_YUYV10_2X10 = 0x200b,
 V4L2_MBUS_FMT_YVYU10_2X10 = 0x200c,
 V4L2_MBUS_FMT_Y12_1X12 = 0x2013,
 V4L2_MBUS_FMT_UYVY8_1X16 = 0x200f,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 V4L2_MBUS_FMT_VYUY8_1X16 = 0x2010,
 V4L2_MBUS_FMT_YUYV8_1X16 = 0x2011,
 V4L2_MBUS_FMT_YVYU8_1X16 = 0x2012,
 V4L2_MBUS_FMT_YUYV10_1X20 = 0x200d,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 V4L2_MBUS_FMT_YVYU10_1X20 = 0x200e,
 V4L2_MBUS_FMT_SBGGR8_1X8 = 0x3001,
 V4L2_MBUS_FMT_SGBRG8_1X8 = 0x3013,
 V4L2_MBUS_FMT_SGRBG8_1X8 = 0x3002,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 V4L2_MBUS_FMT_SRGGB8_1X8 = 0x3014,
 V4L2_MBUS_FMT_SBGGR10_DPCM8_1X8 = 0x300b,
 V4L2_MBUS_FMT_SGBRG10_DPCM8_1X8 = 0x300c,
 V4L2_MBUS_FMT_SGRBG10_DPCM8_1X8 = 0x3009,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 V4L2_MBUS_FMT_SRGGB10_DPCM8_1X8 = 0x300d,
 V4L2_MBUS_FMT_SBGGR10_2X8_PADHI_BE = 0x3003,
 V4L2_MBUS_FMT_SBGGR10_2X8_PADHI_LE = 0x3004,
 V4L2_MBUS_FMT_SBGGR10_2X8_PADLO_BE = 0x3005,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 V4L2_MBUS_FMT_SBGGR10_2X8_PADLO_LE = 0x3006,
 V4L2_MBUS_FMT_SBGGR10_1X10 = 0x3007,
 V4L2_MBUS_FMT_SGBRG10_1X10 = 0x300e,
 V4L2_MBUS_FMT_SGRBG10_1X10 = 0x300a,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 V4L2_MBUS_FMT_SRGGB10_1X10 = 0x300f,
 V4L2_MBUS_FMT_SBGGR12_1X12 = 0x3008,
 V4L2_MBUS_FMT_SGBRG12_1X12 = 0x3010,
 V4L2_MBUS_FMT_SGRBG12_1X12 = 0x3011,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 V4L2_MBUS_FMT_SRGGB12_1X12 = 0x3012,
 V4L2_MBUS_FMT_JPEG_1X8 = 0x4001,
};
struct v4l2_mbus_framefmt {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 width;
 __u32 height;
 __u32 code;
 __u32 field;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 colorspace;
 __u32 reserved[7];
};
#endif
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
