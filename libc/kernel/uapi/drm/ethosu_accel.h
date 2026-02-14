/*
 * This file is auto-generated. Modifications will be lost.
 *
 * See https://android.googlesource.com/platform/bionic/+/master/libc/kernel/
 * for more information.
 */
#ifndef _ETHOSU_DRM_H_
#define _ETHOSU_DRM_H_
#include "drm.h"
#ifdef __cplusplus
extern "C" {
#endif
enum drm_ethosu_ioctl_id {
  DRM_ETHOSU_DEV_QUERY = 0,
  DRM_ETHOSU_BO_CREATE,
  DRM_ETHOSU_BO_WAIT,
  DRM_ETHOSU_BO_MMAP_OFFSET,
  DRM_ETHOSU_CMDSTREAM_BO_CREATE,
  DRM_ETHOSU_SUBMIT,
};
enum drm_ethosu_dev_query_type {
  DRM_ETHOSU_DEV_QUERY_NPU_INFO = 0,
};
struct drm_ethosu_npu_info {
  __u32 id;
#define DRM_ETHOSU_ARCH_MAJOR(x) ((x) >> 28)
#define DRM_ETHOSU_ARCH_MINOR(x) (((x) >> 20) & 0xff)
#define DRM_ETHOSU_ARCH_PATCH(x) (((x) >> 16) & 0xf)
#define DRM_ETHOSU_PRODUCT_MAJOR(x) (((x) >> 12) & 0xf)
#define DRM_ETHOSU_VERSION_MAJOR(x) (((x) >> 8) & 0xf)
#define DRM_ETHOSU_VERSION_MINOR(x) (((x) >> 4) & 0xff)
#define DRM_ETHOSU_VERSION_STATUS(x) ((x) & 0xf)
  __u32 config;
  __u32 sram_size;
};
struct drm_ethosu_dev_query {
  __u32 type;
  __u32 size;
  __u64 pointer;
};
enum drm_ethosu_bo_flags {
  DRM_ETHOSU_BO_NO_MMAP = (1 << 0),
};
struct drm_ethosu_bo_create {
  __u64 size;
  __u32 flags;
  __u32 handle;
};
struct drm_ethosu_bo_mmap_offset {
  __u32 handle;
  __u32 pad;
  __u64 offset;
};
struct drm_ethosu_bo_wait {
  __u32 handle;
  __u32 pad;
  __s64 timeout_ns;
};
struct drm_ethosu_cmdstream_bo_create {
  __u32 size;
  __u32 flags;
  __u64 data;
  __u32 handle;
  __u32 pad;
};
struct drm_ethosu_job {
  __u32 cmd_bo;
  __u32 sram_size;
#define ETHOSU_MAX_REGIONS 8
  __u32 region_bo_handles[ETHOSU_MAX_REGIONS];
};
struct drm_ethosu_submit {
  __u64 jobs;
  __u32 job_count;
  __u32 pad;
};
#define DRM_IOCTL_ETHOSU(__access,__id,__type) DRM_IO ##__access(DRM_COMMAND_BASE + DRM_ETHOSU_ ##__id, struct drm_ethosu_ ##__type)
enum {
  DRM_IOCTL_ETHOSU_DEV_QUERY = DRM_IOCTL_ETHOSU(WR, DEV_QUERY, dev_query),
  DRM_IOCTL_ETHOSU_BO_CREATE = DRM_IOCTL_ETHOSU(WR, BO_CREATE, bo_create),
  DRM_IOCTL_ETHOSU_BO_WAIT = DRM_IOCTL_ETHOSU(WR, BO_WAIT, bo_wait),
  DRM_IOCTL_ETHOSU_BO_MMAP_OFFSET = DRM_IOCTL_ETHOSU(WR, BO_MMAP_OFFSET, bo_mmap_offset),
  DRM_IOCTL_ETHOSU_CMDSTREAM_BO_CREATE = DRM_IOCTL_ETHOSU(WR, CMDSTREAM_BO_CREATE, cmdstream_bo_create),
  DRM_IOCTL_ETHOSU_SUBMIT = DRM_IOCTL_ETHOSU(WR, SUBMIT, submit),
};
#ifdef __cplusplus
}
#endif
#endif
