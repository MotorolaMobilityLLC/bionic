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
#ifndef _ASM_LINUX_DMA_MAPPING_H
#define _ASM_LINUX_DMA_MAPPING_H
#include <linux/device.h>
#include <linux/err.h>
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
enum dma_data_direction {
 DMA_BIDIRECTIONAL = 0,
 DMA_TO_DEVICE = 1,
 DMA_FROM_DEVICE = 2,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 DMA_NONE = 3,
};
#define DMA_64BIT_MASK 0xffffffffffffffffULL
#define DMA_48BIT_MASK 0x0000ffffffffffffULL
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define DMA_40BIT_MASK 0x000000ffffffffffULL
#define DMA_39BIT_MASK 0x0000007fffffffffULL
#define DMA_32BIT_MASK 0x00000000ffffffffULL
#define DMA_31BIT_MASK 0x000000007fffffffULL
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define DMA_30BIT_MASK 0x000000003fffffffULL
#define DMA_29BIT_MASK 0x000000001fffffffULL
#define DMA_28BIT_MASK 0x000000000fffffffULL
#define DMA_24BIT_MASK 0x0000000000ffffffULL
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#include <asm/dma-mapping.h>
#define dma_sync_single dma_sync_single_for_cpu
#define dma_sync_sg dma_sync_sg_for_cpu
#define DMA_MEMORY_MAP 0x01
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define DMA_MEMORY_IO 0x02
#define DMA_MEMORY_INCLUDES_CHILDREN 0x04
#define DMA_MEMORY_EXCLUSIVE 0x08
#ifndef ARCH_HAS_DMA_DECLARE_COHERENT_MEMORY
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#endif
#endif
