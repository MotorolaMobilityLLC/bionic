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
#ifndef _UAPI_GENERIC_STATFS_H
#define _UAPI_GENERIC_STATFS_H
#include <linux/types.h>
#ifndef __statfs_word
#if __BITS_PER_LONG == 64
#define __statfs_word __kernel_long_t
#else
#define __statfs_word __u32
#endif
#endif
struct statfs {
  __statfs_word f_type;
  __statfs_word f_bsize;
  __statfs_word f_blocks;
  __statfs_word f_bfree;
  __statfs_word f_bavail;
  __statfs_word f_files;
  __statfs_word f_ffree;
  __kernel_fsid_t f_fsid;
  __statfs_word f_namelen;
  __statfs_word f_frsize;
  __statfs_word f_flags;
  __statfs_word f_spare[4];
};
#ifndef ARCH_PACK_STATFS64
#define ARCH_PACK_STATFS64
#endif
struct statfs64 {
  __statfs_word f_type;
  __statfs_word f_bsize;
  __u64 f_blocks;
  __u64 f_bfree;
  __u64 f_bavail;
  __u64 f_files;
  __u64 f_ffree;
  __kernel_fsid_t f_fsid;
  __statfs_word f_namelen;
  __statfs_word f_frsize;
  __statfs_word f_flags;
  __statfs_word f_spare[4];
} ARCH_PACK_STATFS64;
#ifndef ARCH_PACK_COMPAT_STATFS64
#define ARCH_PACK_COMPAT_STATFS64
#endif
struct compat_statfs64 {
  __u32 f_type;
  __u32 f_bsize;
  __u64 f_blocks;
  __u64 f_bfree;
  __u64 f_bavail;
  __u64 f_files;
  __u64 f_ffree;
  __kernel_fsid_t f_fsid;
  __u32 f_namelen;
  __u32 f_frsize;
  __u32 f_flags;
  __u32 f_spare[4];
} ARCH_PACK_COMPAT_STATFS64;
#endif
