/*
 * This file is auto-generated. Modifications will be lost.
 *
 * See https://android.googlesource.com/platform/bionic/+/master/libc/kernel/
 * for more information.
 */
#ifndef _UAPI_LINUX_ZRAM_IOCTL_H
#define _UAPI_LINUX_ZRAM_IOCTL_H
#include <linux/types.h>
#include <linux/ioctl.h>
struct zram_android_ioc_data_process_writeback {
  __aligned_u64 pidfd;
  __u64 written_bytes;
};
struct zram_android_ioc_data {
  union {
    struct zram_android_ioc_data_process_writeback process_writeback;
  } data;
};
#define ZRAM_ANDROID_IOC_MAGIC 0xBB
#define ZRAM_ANDROID_IOC_PROCESS_WRITEBACK _IOWR(ZRAM_ANDROID_IOC_MAGIC, 1, struct zram_android_ioc_data)
#endif
