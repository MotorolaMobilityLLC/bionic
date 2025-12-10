/*
 * This file is auto-generated. Modifications will be lost.
 *
 * See https://android.googlesource.com/platform/bionic/+/master/libc/kernel/
 * for more information.
 */
#ifndef __PSP_SFS_USER_H__
#define __PSP_SFS_USER_H__
#include <linux/types.h>
#define PAYLOAD_NAME_SIZE 64
#define TEE_EXT_CMD_BUFFER_SIZE 4096
struct sfs_user_get_fw_versions {
  __u8 blob[TEE_EXT_CMD_BUFFER_SIZE];
  __u32 sfs_status;
  __u32 sfs_extended_status;
} __attribute__((__packed__));
struct sfs_user_update_package {
  char payload_name[PAYLOAD_NAME_SIZE];
  __u32 sfs_status;
  __u32 sfs_extended_status;
} __attribute__((__packed__));
#define SFS_IOC_TYPE 'S'
#define SFSIOCFWVERS _IOWR(SFS_IOC_TYPE, 0x1, struct sfs_user_get_fw_versions)
#define SFSIOCUPDATEPKG _IOWR(SFS_IOC_TYPE, 0x2, struct sfs_user_update_package)
#endif
