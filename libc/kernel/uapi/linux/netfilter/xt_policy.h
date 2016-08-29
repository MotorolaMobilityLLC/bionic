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
#ifndef _XT_POLICY_H
#define _XT_POLICY_H
#include <linux/types.h>
#include <linux/in.h>
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#include <linux/in6.h>
#define XT_POLICY_MAX_ELEM 4
enum xt_policy_flags {
  XT_POLICY_MATCH_IN = 0x1,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  XT_POLICY_MATCH_OUT = 0x2,
  XT_POLICY_MATCH_NONE = 0x4,
  XT_POLICY_MATCH_STRICT = 0x8,
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
enum xt_policy_modes {
  XT_POLICY_MODE_TRANSPORT,
  XT_POLICY_MODE_TUNNEL
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct xt_policy_spec {
  __u8 saddr : 1, daddr : 1, proto : 1, mode : 1, spi : 1, reqid : 1;
};
union xt_policy_addr {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  struct in_addr a4;
  struct in6_addr a6;
};
struct xt_policy_elem {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  union {
    struct {
      union xt_policy_addr saddr;
      union xt_policy_addr smask;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
      union xt_policy_addr daddr;
      union xt_policy_addr dmask;
    };
  };
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __be32 spi;
  __u32 reqid;
  __u8 proto;
  __u8 mode;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  struct xt_policy_spec match;
  struct xt_policy_spec invert;
};
struct xt_policy_info {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  struct xt_policy_elem pol[XT_POLICY_MAX_ELEM];
  __u16 flags;
  __u16 len;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#endif
