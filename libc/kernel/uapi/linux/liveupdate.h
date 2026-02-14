/*
 * This file is auto-generated. Modifications will be lost.
 *
 * See https://android.googlesource.com/platform/bionic/+/master/libc/kernel/
 * for more information.
 */
#ifndef _UAPI_LIVEUPDATE_H
#define _UAPI_LIVEUPDATE_H
#include <linux/ioctl.h>
#include <linux/types.h>
#define LIVEUPDATE_IOCTL_TYPE 0xBA
#define LIVEUPDATE_SESSION_NAME_LENGTH 64
enum {
  LIVEUPDATE_CMD_BASE = 0x00,
  LIVEUPDATE_CMD_CREATE_SESSION = LIVEUPDATE_CMD_BASE,
  LIVEUPDATE_CMD_RETRIEVE_SESSION = 0x01,
};
enum {
  LIVEUPDATE_CMD_SESSION_BASE = 0x40,
  LIVEUPDATE_CMD_SESSION_PRESERVE_FD = LIVEUPDATE_CMD_SESSION_BASE,
  LIVEUPDATE_CMD_SESSION_RETRIEVE_FD = 0x41,
  LIVEUPDATE_CMD_SESSION_FINISH = 0x42,
};
struct liveupdate_ioctl_create_session {
  __u32 size;
  __s32 fd;
  __u8 name[LIVEUPDATE_SESSION_NAME_LENGTH];
};
#define LIVEUPDATE_IOCTL_CREATE_SESSION _IO(LIVEUPDATE_IOCTL_TYPE, LIVEUPDATE_CMD_CREATE_SESSION)
struct liveupdate_ioctl_retrieve_session {
  __u32 size;
  __s32 fd;
  __u8 name[LIVEUPDATE_SESSION_NAME_LENGTH];
};
#define LIVEUPDATE_IOCTL_RETRIEVE_SESSION _IO(LIVEUPDATE_IOCTL_TYPE, LIVEUPDATE_CMD_RETRIEVE_SESSION)
struct liveupdate_session_preserve_fd {
  __u32 size;
  __s32 fd;
  __aligned_u64 token;
};
#define LIVEUPDATE_SESSION_PRESERVE_FD _IO(LIVEUPDATE_IOCTL_TYPE, LIVEUPDATE_CMD_SESSION_PRESERVE_FD)
struct liveupdate_session_retrieve_fd {
  __u32 size;
  __s32 fd;
  __aligned_u64 token;
};
#define LIVEUPDATE_SESSION_RETRIEVE_FD _IO(LIVEUPDATE_IOCTL_TYPE, LIVEUPDATE_CMD_SESSION_RETRIEVE_FD)
struct liveupdate_session_finish {
  __u32 size;
  __u32 reserved;
};
#define LIVEUPDATE_SESSION_FINISH _IO(LIVEUPDATE_IOCTL_TYPE, LIVEUPDATE_CMD_SESSION_FINISH)
#endif
