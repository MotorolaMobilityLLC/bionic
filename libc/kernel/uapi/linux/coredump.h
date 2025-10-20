/*
 * This file is auto-generated. Modifications will be lost.
 *
 * See https://android.googlesource.com/platform/bionic/+/master/libc/kernel/
 * for more information.
 */
#ifndef _UAPI_LINUX_COREDUMP_H
#define _UAPI_LINUX_COREDUMP_H
#include <linux/types.h>
enum {
  COREDUMP_KERNEL = (1ULL << 0),
  COREDUMP_USERSPACE = (1ULL << 1),
  COREDUMP_REJECT = (1ULL << 2),
  COREDUMP_WAIT = (1ULL << 3),
};
struct coredump_req {
  __u32 size;
  __u32 size_ack;
  __u64 mask;
};
enum {
  COREDUMP_REQ_SIZE_VER0 = 16U,
};
struct coredump_ack {
  __u32 size;
  __u32 spare;
  __u64 mask;
};
enum {
  COREDUMP_ACK_SIZE_VER0 = 16U,
};
enum coredump_mark {
  COREDUMP_MARK_REQACK = 0U,
  COREDUMP_MARK_MINSIZE = 1U,
  COREDUMP_MARK_MAXSIZE = 2U,
  COREDUMP_MARK_UNSUPPORTED = 3U,
  COREDUMP_MARK_CONFLICTING = 4U,
  __COREDUMP_MARK_MAX = (1U << 31),
};
#endif
