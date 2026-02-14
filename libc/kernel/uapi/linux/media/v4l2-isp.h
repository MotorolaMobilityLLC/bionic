/*
 * This file is auto-generated. Modifications will be lost.
 *
 * See https://android.googlesource.com/platform/bionic/+/master/libc/kernel/
 * for more information.
 */
#ifndef _UAPI_V4L2_ISP_H_
#define _UAPI_V4L2_ISP_H_
#include <linux/stddef.h>
#include <linux/types.h>
enum v4l2_isp_params_version {
  V4L2_ISP_PARAMS_VERSION_V0 = 0,
  V4L2_ISP_PARAMS_VERSION_V1
};
#define V4L2_ISP_PARAMS_FL_BLOCK_DISABLE (1U << 0)
#define V4L2_ISP_PARAMS_FL_BLOCK_ENABLE (1U << 1)
#define V4L2_ISP_PARAMS_FL_DRIVER_FLAGS(n) ((n) + 8)
struct v4l2_isp_params_block_header {
  __u16 type;
  __u16 flags;
  __u32 size;
} __attribute__((aligned(8)));
struct v4l2_isp_params_buffer {
  __u32 version;
  __u32 data_size;
  __u8 data[] __counted_by(data_size);
};
#endif
