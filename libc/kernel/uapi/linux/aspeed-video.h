/*
 * This file is auto-generated. Modifications will be lost.
 *
 * See https://android.googlesource.com/platform/bionic/+/master/libc/kernel/
 * for more information.
 */
#ifndef _UAPI_LINUX_ASPEED_VIDEO_H
#define _UAPI_LINUX_ASPEED_VIDEO_H
#include <linux/v4l2-controls.h>
enum aspeed_video_input {
  VIDEO_INPUT_VGA = 0,
  VIDEO_INPUT_GFX,
  VIDEO_INPUT_MAX
};
#define V4L2_CID_ASPEED_HQ_MODE (V4L2_CID_USER_ASPEED_BASE + 1)
#define V4L2_CID_ASPEED_HQ_JPEG_QUALITY (V4L2_CID_USER_ASPEED_BASE + 2)
#endif
