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
#ifndef _UAPI_MSM_ION_H
#define _UAPI_MSM_ION_H
#include <linux/ion.h>
enum msm_ion_heap_types {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 ION_HEAP_TYPE_MSM_START = ION_HEAP_TYPE_CUSTOM + 1,
 ION_HEAP_TYPE_DMA = ION_HEAP_TYPE_MSM_START,
 ION_HEAP_TYPE_CP,
 ION_HEAP_TYPE_SECURE_DMA,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 ION_HEAP_TYPE_REMOVED,
};
enum ion_heap_ids {
 INVALID_HEAP_ID = -1,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 ION_CP_MM_HEAP_ID = 8,
 ION_CP_MFC_HEAP_ID = 12,
 ION_CP_WB_HEAP_ID = 16,
 ION_CAMERA_HEAP_ID = 20,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 ION_SYSTEM_CONTIG_HEAP_ID = 21,
 ION_ADSP_HEAP_ID = 22,
 ION_PIL1_HEAP_ID = 23,
 ION_SF_HEAP_ID = 24,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 ION_SYSTEM_HEAP_ID = 25,
 ION_PIL2_HEAP_ID = 26,
 ION_QSECOM_HEAP_ID = 27,
 ION_AUDIO_HEAP_ID = 28,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 ION_MM_FIRMWARE_HEAP_ID = 29,
 ION_HEAP_ID_RESERVED = 31
};
#define ION_IOMMU_HEAP_ID ION_SYSTEM_HEAP_ID
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define ION_HEAP_TYPE_IOMMU ION_HEAP_TYPE_SYSTEM
enum ion_fixed_position {
 NOT_FIXED,
 FIXED_LOW,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 FIXED_MIDDLE,
 FIXED_HIGH,
};
enum cp_mem_usage {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 VIDEO_BITSTREAM = 0x1,
 VIDEO_PIXEL = 0x2,
 VIDEO_NONPIXEL = 0x3,
 MAX_USAGE = 0x4,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 UNKNOWN = 0x7FFFFFFF,
};
#define ION_HEAP_CP_MASK (1 << ION_HEAP_TYPE_CP)
#define ION_HEAP_TYPE_DMA_MASK (1 << ION_HEAP_TYPE_DMA)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define ION_FLAG_SECURE (1 << ION_HEAP_ID_RESERVED)
#define ION_FLAG_FORCE_CONTIGUOUS (1 << 30)
#define ION_FLAG_POOL_FORCE_ALLOC (1 << 16)
#define ION_SECURE ION_FLAG_SECURE
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define ION_FORCE_CONTIGUOUS ION_FLAG_FORCE_CONTIGUOUS
#define ION_HEAP(bit) (1 << (bit))
#define ION_ADSP_HEAP_NAME "adsp"
#define ION_SYSTEM_HEAP_NAME "system"
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define ION_VMALLOC_HEAP_NAME ION_SYSTEM_HEAP_NAME
#define ION_KMALLOC_HEAP_NAME "kmalloc"
#define ION_AUDIO_HEAP_NAME "audio"
#define ION_SF_HEAP_NAME "sf"
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define ION_MM_HEAP_NAME "mm"
#define ION_CAMERA_HEAP_NAME "camera_preview"
#define ION_IOMMU_HEAP_NAME "iommu"
#define ION_MFC_HEAP_NAME "mfc"
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define ION_WB_HEAP_NAME "wb"
#define ION_MM_FIRMWARE_HEAP_NAME "mm_fw"
#define ION_PIL1_HEAP_NAME "pil_1"
#define ION_PIL2_HEAP_NAME "pil_2"
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define ION_QSECOM_HEAP_NAME "qsecom"
#define ION_SET_CACHED(__cache) (__cache | ION_FLAG_CACHED)
#define ION_SET_UNCACHED(__cache) (__cache & ~ION_FLAG_CACHED)
#define ION_IS_CACHED(__flags) ((__flags) & ION_FLAG_CACHED)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct ion_flush_data {
 struct ion_handle *handle;
 int fd;
 void *vaddr;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int offset;
 unsigned int length;
};
struct ion_prefetch_data {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 int heap_id;
 unsigned long len;
};
#define ION_IOC_MSM_MAGIC 'M'
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define ION_IOC_CLEAN_CACHES _IOWR(ION_IOC_MSM_MAGIC, 0,   struct ion_flush_data)
#define ION_IOC_INV_CACHES _IOWR(ION_IOC_MSM_MAGIC, 1,   struct ion_flush_data)
#define ION_IOC_CLEAN_INV_CACHES _IOWR(ION_IOC_MSM_MAGIC, 2,   struct ion_flush_data)
#define ION_IOC_PREFETCH _IOWR(ION_IOC_MSM_MAGIC, 3,   struct ion_prefetch_data)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define ION_IOC_DRAIN _IOWR(ION_IOC_MSM_MAGIC, 4,   struct ion_prefetch_data)
#endif

