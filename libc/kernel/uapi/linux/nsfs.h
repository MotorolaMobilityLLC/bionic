/*
 * This file is auto-generated. Modifications will be lost.
 *
 * See https://android.googlesource.com/platform/bionic/+/master/libc/kernel/
 * for more information.
 */
#ifndef __LINUX_NSFS_H
#define __LINUX_NSFS_H
#include <linux/ioctl.h>
#include <linux/types.h>
#define NSIO 0xb7
#define NS_GET_USERNS _IO(NSIO, 0x1)
#define NS_GET_PARENT _IO(NSIO, 0x2)
#define NS_GET_NSTYPE _IO(NSIO, 0x3)
#define NS_GET_OWNER_UID _IO(NSIO, 0x4)
#define NS_GET_PID_FROM_PIDNS _IOR(NSIO, 0x6, int)
#define NS_GET_TGID_FROM_PIDNS _IOR(NSIO, 0x7, int)
#define NS_GET_PID_IN_PIDNS _IOR(NSIO, 0x8, int)
#define NS_GET_TGID_IN_PIDNS _IOR(NSIO, 0x9, int)
struct mnt_ns_info {
  __u32 size;
  __u32 nr_mounts;
  __u64 mnt_ns_id;
};
#define MNT_NS_INFO_SIZE_VER0 16
#define NS_MNT_GET_INFO _IOR(NSIO, 10, struct mnt_ns_info)
#define NS_MNT_GET_NEXT _IOR(NSIO, 11, struct mnt_ns_info)
#define NS_MNT_GET_PREV _IOR(NSIO, 12, struct mnt_ns_info)
#define NS_GET_MNTNS_ID _IOR(NSIO, 5, __u64)
#define NS_GET_ID _IOR(NSIO, 13, __u64)
enum init_ns_ino {
  IPC_NS_INIT_INO = 0xEFFFFFFFU,
  UTS_NS_INIT_INO = 0xEFFFFFFEU,
  USER_NS_INIT_INO = 0xEFFFFFFDU,
  PID_NS_INIT_INO = 0xEFFFFFFCU,
  CGROUP_NS_INIT_INO = 0xEFFFFFFBU,
  TIME_NS_INIT_INO = 0xEFFFFFFAU,
  NET_NS_INIT_INO = 0xEFFFFFF9U,
  MNT_NS_INIT_INO = 0xEFFFFFF8U,
};
struct nsfs_file_handle {
  __u64 ns_id;
  __u32 ns_type;
  __u32 ns_inum;
};
#define NSFS_FILE_HANDLE_SIZE_VER0 16
#define NSFS_FILE_HANDLE_SIZE_LATEST sizeof(struct nsfs_file_handle)
enum init_ns_id {
  IPC_NS_INIT_ID = 1ULL,
  UTS_NS_INIT_ID = 2ULL,
  USER_NS_INIT_ID = 3ULL,
  PID_NS_INIT_ID = 4ULL,
  CGROUP_NS_INIT_ID = 5ULL,
  TIME_NS_INIT_ID = 6ULL,
  NET_NS_INIT_ID = 7ULL,
  MNT_NS_INIT_ID = 8ULL,
};
enum ns_type {
  TIME_NS = (1ULL << 7),
  MNT_NS = (1ULL << 17),
  CGROUP_NS = (1ULL << 25),
  UTS_NS = (1ULL << 26),
  IPC_NS = (1ULL << 27),
  USER_NS = (1ULL << 28),
  PID_NS = (1ULL << 29),
  NET_NS = (1ULL << 30),
};
struct ns_id_req {
  __u32 size;
  __u32 spare;
  __u64 ns_id;
  struct {
    __u32 ns_type;
    __u32 spare2;
    __u64 user_ns_id;
  };
};
#define LISTNS_CURRENT_USER 0xffffffffffffffff
#define NS_ID_REQ_SIZE_VER0 32
#endif
