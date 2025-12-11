/*
 * This file is auto-generated. Modifications will be lost.
 *
 * See https://android.googlesource.com/platform/bionic/+/master/libc/kernel/
 * for more information.
 */
#ifndef _UAPI_LINUX_ANDROID_BINDER_NETLINK_H
#define _UAPI_LINUX_ANDROID_BINDER_NETLINK_H
#define BINDER_FAMILY_NAME "binder"
#define BINDER_FAMILY_VERSION 1
enum {
  BINDER_A_REPORT_ERROR = 1,
  BINDER_A_REPORT_CONTEXT,
  BINDER_A_REPORT_FROM_PID,
  BINDER_A_REPORT_FROM_TID,
  BINDER_A_REPORT_TO_PID,
  BINDER_A_REPORT_TO_TID,
  BINDER_A_REPORT_IS_REPLY,
  BINDER_A_REPORT_FLAGS,
  BINDER_A_REPORT_CODE,
  BINDER_A_REPORT_DATA_SIZE,
  __BINDER_A_REPORT_MAX,
  BINDER_A_REPORT_MAX = (__BINDER_A_REPORT_MAX - 1)
};
enum {
  BINDER_CMD_REPORT = 1,
  __BINDER_CMD_MAX,
  BINDER_CMD_MAX = (__BINDER_CMD_MAX - 1)
};
#define BINDER_MCGRP_REPORT "report"
#endif
