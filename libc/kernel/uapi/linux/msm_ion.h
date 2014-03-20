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
#ifndef _LINUX_MSM_ION_H
#define _LINUX_MSM_ION_H
#include <uapi/linux/msm_ion.h>
enum ion_permission_type {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 IPT_TYPE_MM_CARVEOUT = 0,
 IPT_TYPE_MFC_SHAREDMEM = 1,
 IPT_TYPE_MDP_WRITEBACK = 2,
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define ION_IOMMU_UNMAP_DELAYED 1
#define ION_UNSECURE_DELAYED 1
struct ion_cp_heap_pdata {
 enum ion_permission_type permission_type;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 unsigned int align;
 ion_phys_addr_t secure_base;
 size_t secure_size;
 int is_cma;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 enum ion_fixed_position fixed_position;
 int iommu_map_all;
 int iommu_2x_map_domain;
 int (*request_region)(void *);
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 int (*release_region)(void *);
 void *(*setup_region)(void);
 int allow_nonsecure_alloc;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct ion_co_heap_pdata {
 int adjacent_mem_id;
 unsigned int align;
 enum ion_fixed_position fixed_position;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 int (*request_region)(void *);
 int (*release_region)(void *);
 void *(*setup_region)(void);
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct ion_cma_pdata {
 unsigned long default_prefetch_size;
};
#endif
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */

