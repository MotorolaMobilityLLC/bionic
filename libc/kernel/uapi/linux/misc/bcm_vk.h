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
#ifndef __UAPI_LINUX_MISC_BCM_VK_H
#define __UAPI_LINUX_MISC_BCM_VK_H
#include <linux/ioctl.h>
#include <linux/types.h>
#define BCM_VK_MAX_FILENAME 64
struct vk_image {
  __u32 type;
#define VK_IMAGE_TYPE_BOOT1 1
#define VK_IMAGE_TYPE_BOOT2 2
  __u8 filename[BCM_VK_MAX_FILENAME];
};
struct vk_reset {
  __u32 arg1;
  __u32 arg2;
};
#define VK_MAGIC 0x5e
#define VK_IOCTL_LOAD_IMAGE _IOW(VK_MAGIC, 0x2, struct vk_image)
#define VK_IOCTL_RESET _IOW(VK_MAGIC, 0x4, struct vk_reset)
#define VK_BAR_FWSTS 0x41c
#define VK_BAR_COP_FWSTS 0x428
#define VK_FWSTS_RELOCATION_ENTRY (1UL << 0)
#define VK_FWSTS_RELOCATION_EXIT (1UL << 1)
#define VK_FWSTS_INIT_START (1UL << 2)
#define VK_FWSTS_ARCH_INIT_DONE (1UL << 3)
#define VK_FWSTS_PRE_KNL1_INIT_DONE (1UL << 4)
#define VK_FWSTS_PRE_KNL2_INIT_DONE (1UL << 5)
#define VK_FWSTS_POST_KNL_INIT_DONE (1UL << 6)
#define VK_FWSTS_INIT_DONE (1UL << 7)
#define VK_FWSTS_APP_INIT_START (1UL << 8)
#define VK_FWSTS_APP_INIT_DONE (1UL << 9)
#define VK_FWSTS_MASK 0xffffffff
#define VK_FWSTS_READY (VK_FWSTS_INIT_START | VK_FWSTS_ARCH_INIT_DONE | VK_FWSTS_PRE_KNL1_INIT_DONE | VK_FWSTS_PRE_KNL2_INIT_DONE | VK_FWSTS_POST_KNL_INIT_DONE | VK_FWSTS_INIT_DONE | VK_FWSTS_APP_INIT_START | VK_FWSTS_APP_INIT_DONE)
#define VK_FWSTS_APP_DEINIT_START (1UL << 23)
#define VK_FWSTS_APP_DEINIT_DONE (1UL << 24)
#define VK_FWSTS_DRV_DEINIT_START (1UL << 25)
#define VK_FWSTS_DRV_DEINIT_DONE (1UL << 26)
#define VK_FWSTS_RESET_DONE (1UL << 27)
#define VK_FWSTS_DEINIT_TRIGGERED (VK_FWSTS_APP_DEINIT_START | VK_FWSTS_APP_DEINIT_DONE | VK_FWSTS_DRV_DEINIT_START | VK_FWSTS_DRV_DEINIT_DONE)
#define VK_FWSTS_RESET_REASON_SHIFT 28
#define VK_FWSTS_RESET_REASON_MASK (0xf << VK_FWSTS_RESET_REASON_SHIFT)
#define VK_FWSTS_RESET_SYS_PWRUP (0x0 << VK_FWSTS_RESET_REASON_SHIFT)
#define VK_FWSTS_RESET_MBOX_DB (0x1 << VK_FWSTS_RESET_REASON_SHIFT)
#define VK_FWSTS_RESET_M7_WDOG (0x2 << VK_FWSTS_RESET_REASON_SHIFT)
#define VK_FWSTS_RESET_TEMP (0x3 << VK_FWSTS_RESET_REASON_SHIFT)
#define VK_FWSTS_RESET_PCI_FLR (0x4 << VK_FWSTS_RESET_REASON_SHIFT)
#define VK_FWSTS_RESET_PCI_HOT (0x5 << VK_FWSTS_RESET_REASON_SHIFT)
#define VK_FWSTS_RESET_PCI_WARM (0x6 << VK_FWSTS_RESET_REASON_SHIFT)
#define VK_FWSTS_RESET_PCI_COLD (0x7 << VK_FWSTS_RESET_REASON_SHIFT)
#define VK_FWSTS_RESET_L1 (0x8 << VK_FWSTS_RESET_REASON_SHIFT)
#define VK_FWSTS_RESET_L0 (0x9 << VK_FWSTS_RESET_REASON_SHIFT)
#define VK_FWSTS_RESET_UNKNOWN (0xf << VK_FWSTS_RESET_REASON_SHIFT)
#endif
