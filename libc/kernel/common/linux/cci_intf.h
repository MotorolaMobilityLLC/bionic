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
#ifndef _CCI_INTF_H_
#define _CCI_INTF_H_
#include <linux/ioctl.h>
#include <linux/videodev2.h>
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSM_CCI_INTF_MAX_XFER 256
struct msm_cci_intf_register {
 unsigned short width;
 unsigned short addr;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct msm_cci_intf_data {
 unsigned short count;
 unsigned char buf[MSM_CCI_INTF_MAX_XFER];
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct msm_cci_intf_xfer {
 unsigned short cci_bus;
 unsigned short slave_addr;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 struct msm_cci_intf_register reg;
 struct msm_cci_intf_data data;
};
#define MSM_CCI_INTF_READ   _IOWR('X', BASE_VIDIOC_PRIVATE + 50, struct msm_cci_intf_xfer)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSM_CCI_INTF_WRITE   _IOWR('X', BASE_VIDIOC_PRIVATE + 51, struct msm_cci_intf_xfer)
#endif
