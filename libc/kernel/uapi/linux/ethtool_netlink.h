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
#ifndef _UAPI_LINUX_ETHTOOL_NETLINK_H_
#define _UAPI_LINUX_ETHTOOL_NETLINK_H_
#include <linux/ethtool.h>
enum {
  ETHTOOL_MSG_USER_NONE,
  ETHTOOL_MSG_STRSET_GET,
  ETHTOOL_MSG_LINKINFO_GET,
  ETHTOOL_MSG_LINKINFO_SET,
  ETHTOOL_MSG_LINKMODES_GET,
  ETHTOOL_MSG_LINKMODES_SET,
  ETHTOOL_MSG_LINKSTATE_GET,
  ETHTOOL_MSG_DEBUG_GET,
  ETHTOOL_MSG_DEBUG_SET,
  ETHTOOL_MSG_WOL_GET,
  ETHTOOL_MSG_WOL_SET,
  __ETHTOOL_MSG_USER_CNT,
  ETHTOOL_MSG_USER_MAX = __ETHTOOL_MSG_USER_CNT - 1
};
enum {
  ETHTOOL_MSG_KERNEL_NONE,
  ETHTOOL_MSG_STRSET_GET_REPLY,
  ETHTOOL_MSG_LINKINFO_GET_REPLY,
  ETHTOOL_MSG_LINKINFO_NTF,
  ETHTOOL_MSG_LINKMODES_GET_REPLY,
  ETHTOOL_MSG_LINKMODES_NTF,
  ETHTOOL_MSG_LINKSTATE_GET_REPLY,
  ETHTOOL_MSG_DEBUG_GET_REPLY,
  ETHTOOL_MSG_DEBUG_NTF,
  ETHTOOL_MSG_WOL_GET_REPLY,
  ETHTOOL_MSG_WOL_NTF,
  __ETHTOOL_MSG_KERNEL_CNT,
  ETHTOOL_MSG_KERNEL_MAX = __ETHTOOL_MSG_KERNEL_CNT - 1
};
#define ETHTOOL_FLAG_COMPACT_BITSETS (1 << 0)
#define ETHTOOL_FLAG_OMIT_REPLY (1 << 1)
#define ETHTOOL_FLAG_ALL (ETHTOOL_FLAG_COMPACT_BITSETS | ETHTOOL_FLAG_OMIT_REPLY)
enum {
  ETHTOOL_A_HEADER_UNSPEC,
  ETHTOOL_A_HEADER_DEV_INDEX,
  ETHTOOL_A_HEADER_DEV_NAME,
  ETHTOOL_A_HEADER_FLAGS,
  __ETHTOOL_A_HEADER_CNT,
  ETHTOOL_A_HEADER_MAX = __ETHTOOL_A_HEADER_CNT - 1
};
enum {
  ETHTOOL_A_BITSET_BIT_UNSPEC,
  ETHTOOL_A_BITSET_BIT_INDEX,
  ETHTOOL_A_BITSET_BIT_NAME,
  ETHTOOL_A_BITSET_BIT_VALUE,
  __ETHTOOL_A_BITSET_BIT_CNT,
  ETHTOOL_A_BITSET_BIT_MAX = __ETHTOOL_A_BITSET_BIT_CNT - 1
};
enum {
  ETHTOOL_A_BITSET_BITS_UNSPEC,
  ETHTOOL_A_BITSET_BITS_BIT,
  __ETHTOOL_A_BITSET_BITS_CNT,
  ETHTOOL_A_BITSET_BITS_MAX = __ETHTOOL_A_BITSET_BITS_CNT - 1
};
enum {
  ETHTOOL_A_BITSET_UNSPEC,
  ETHTOOL_A_BITSET_NOMASK,
  ETHTOOL_A_BITSET_SIZE,
  ETHTOOL_A_BITSET_BITS,
  ETHTOOL_A_BITSET_VALUE,
  ETHTOOL_A_BITSET_MASK,
  __ETHTOOL_A_BITSET_CNT,
  ETHTOOL_A_BITSET_MAX = __ETHTOOL_A_BITSET_CNT - 1
};
enum {
  ETHTOOL_A_STRING_UNSPEC,
  ETHTOOL_A_STRING_INDEX,
  ETHTOOL_A_STRING_VALUE,
  __ETHTOOL_A_STRING_CNT,
  ETHTOOL_A_STRING_MAX = __ETHTOOL_A_STRING_CNT - 1
};
enum {
  ETHTOOL_A_STRINGS_UNSPEC,
  ETHTOOL_A_STRINGS_STRING,
  __ETHTOOL_A_STRINGS_CNT,
  ETHTOOL_A_STRINGS_MAX = __ETHTOOL_A_STRINGS_CNT - 1
};
enum {
  ETHTOOL_A_STRINGSET_UNSPEC,
  ETHTOOL_A_STRINGSET_ID,
  ETHTOOL_A_STRINGSET_COUNT,
  ETHTOOL_A_STRINGSET_STRINGS,
  __ETHTOOL_A_STRINGSET_CNT,
  ETHTOOL_A_STRINGSET_MAX = __ETHTOOL_A_STRINGSET_CNT - 1
};
enum {
  ETHTOOL_A_STRINGSETS_UNSPEC,
  ETHTOOL_A_STRINGSETS_STRINGSET,
  __ETHTOOL_A_STRINGSETS_CNT,
  ETHTOOL_A_STRINGSETS_MAX = __ETHTOOL_A_STRINGSETS_CNT - 1
};
enum {
  ETHTOOL_A_STRSET_UNSPEC,
  ETHTOOL_A_STRSET_HEADER,
  ETHTOOL_A_STRSET_STRINGSETS,
  ETHTOOL_A_STRSET_COUNTS_ONLY,
  __ETHTOOL_A_STRSET_CNT,
  ETHTOOL_A_STRSET_MAX = __ETHTOOL_A_STRSET_CNT - 1
};
enum {
  ETHTOOL_A_LINKINFO_UNSPEC,
  ETHTOOL_A_LINKINFO_HEADER,
  ETHTOOL_A_LINKINFO_PORT,
  ETHTOOL_A_LINKINFO_PHYADDR,
  ETHTOOL_A_LINKINFO_TP_MDIX,
  ETHTOOL_A_LINKINFO_TP_MDIX_CTRL,
  ETHTOOL_A_LINKINFO_TRANSCEIVER,
  __ETHTOOL_A_LINKINFO_CNT,
  ETHTOOL_A_LINKINFO_MAX = __ETHTOOL_A_LINKINFO_CNT - 1
};
enum {
  ETHTOOL_A_LINKMODES_UNSPEC,
  ETHTOOL_A_LINKMODES_HEADER,
  ETHTOOL_A_LINKMODES_AUTONEG,
  ETHTOOL_A_LINKMODES_OURS,
  ETHTOOL_A_LINKMODES_PEER,
  ETHTOOL_A_LINKMODES_SPEED,
  ETHTOOL_A_LINKMODES_DUPLEX,
  __ETHTOOL_A_LINKMODES_CNT,
  ETHTOOL_A_LINKMODES_MAX = __ETHTOOL_A_LINKMODES_CNT - 1
};
enum {
  ETHTOOL_A_LINKSTATE_UNSPEC,
  ETHTOOL_A_LINKSTATE_HEADER,
  ETHTOOL_A_LINKSTATE_LINK,
  __ETHTOOL_A_LINKSTATE_CNT,
  ETHTOOL_A_LINKSTATE_MAX = __ETHTOOL_A_LINKSTATE_CNT - 1
};
enum {
  ETHTOOL_A_DEBUG_UNSPEC,
  ETHTOOL_A_DEBUG_HEADER,
  ETHTOOL_A_DEBUG_MSGMASK,
  __ETHTOOL_A_DEBUG_CNT,
  ETHTOOL_A_DEBUG_MAX = __ETHTOOL_A_DEBUG_CNT - 1
};
enum {
  ETHTOOL_A_WOL_UNSPEC,
  ETHTOOL_A_WOL_HEADER,
  ETHTOOL_A_WOL_MODES,
  ETHTOOL_A_WOL_SOPASS,
  __ETHTOOL_A_WOL_CNT,
  ETHTOOL_A_WOL_MAX = __ETHTOOL_A_WOL_CNT - 1
};
#define ETHTOOL_GENL_NAME "ethtool"
#define ETHTOOL_GENL_VERSION 1
#define ETHTOOL_MCGRP_MONITOR_NAME "monitor"
#endif
