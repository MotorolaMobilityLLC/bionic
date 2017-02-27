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
#ifndef _UAPI_INET_DIAG_H_
#define _UAPI_INET_DIAG_H_
#include <linux/types.h>
#define TCPDIAG_GETSOCK 18
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define DCCPDIAG_GETSOCK 19
#define INET_DIAG_GETSOCK_MAX 24
struct inet_diag_sockid {
  __be16 idiag_sport;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __be16 idiag_dport;
  __be32 idiag_src[4];
  __be32 idiag_dst[4];
  __u32 idiag_if;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u32 idiag_cookie[2];
#define INET_DIAG_NOCOOKIE (~0U)
};
struct inet_diag_req {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u8 idiag_family;
  __u8 idiag_src_len;
  __u8 idiag_dst_len;
  __u8 idiag_ext;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  struct inet_diag_sockid id;
  __u32 idiag_states;
  __u32 idiag_dbs;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct inet_diag_req_v2 {
  __u8 sdiag_family;
  __u8 sdiag_protocol;
  __u8 idiag_ext;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u8 pad;
  __u32 idiag_states;
  struct inet_diag_sockid id;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct inet_diag_req_raw {
  __u8 sdiag_family;
  __u8 sdiag_protocol;
  __u8 idiag_ext;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u8 sdiag_raw_protocol;
  __u32 idiag_states;
  struct inet_diag_sockid id;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
enum {
  INET_DIAG_REQ_NONE,
  INET_DIAG_REQ_BYTECODE,
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define INET_DIAG_REQ_MAX INET_DIAG_REQ_BYTECODE
struct inet_diag_bc_op {
  unsigned char code;
  unsigned char yes;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  unsigned short no;
};
enum {
  INET_DIAG_BC_NOP,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  INET_DIAG_BC_JMP,
  INET_DIAG_BC_S_GE,
  INET_DIAG_BC_S_LE,
  INET_DIAG_BC_D_GE,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  INET_DIAG_BC_D_LE,
  INET_DIAG_BC_AUTO,
  INET_DIAG_BC_S_COND,
  INET_DIAG_BC_D_COND,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  INET_DIAG_BC_DEV_COND,
  INET_DIAG_BC_MARK_COND,
};
struct inet_diag_hostcond {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u8 family;
  __u8 prefix_len;
  int port;
  __be32 addr[0];
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct inet_diag_markcond {
  __u32 mark;
  __u32 mask;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct inet_diag_msg {
  __u8 idiag_family;
  __u8 idiag_state;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u8 idiag_timer;
  __u8 idiag_retrans;
  struct inet_diag_sockid id;
  __u32 idiag_expires;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u32 idiag_rqueue;
  __u32 idiag_wqueue;
  __u32 idiag_uid;
  __u32 idiag_inode;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
enum {
  INET_DIAG_NONE,
  INET_DIAG_MEMINFO,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  INET_DIAG_INFO,
  INET_DIAG_VEGASINFO,
  INET_DIAG_CONG,
  INET_DIAG_TOS,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  INET_DIAG_TCLASS,
  INET_DIAG_SKMEMINFO,
  INET_DIAG_SHUTDOWN,
  INET_DIAG_DCTCPINFO,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  INET_DIAG_PROTOCOL,
  INET_DIAG_SKV6ONLY,
  INET_DIAG_LOCALS,
  INET_DIAG_PEERS,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  INET_DIAG_PAD,
  INET_DIAG_MARK,
  INET_DIAG_BBRINFO,
  __INET_DIAG_MAX,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
#define INET_DIAG_MAX (__INET_DIAG_MAX - 1)
struct inet_diag_meminfo {
  __u32 idiag_rmem;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u32 idiag_wmem;
  __u32 idiag_fmem;
  __u32 idiag_tmem;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct tcpvegas_info {
  __u32 tcpv_enabled;
  __u32 tcpv_rttcnt;
  __u32 tcpv_rtt;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u32 tcpv_minrtt;
};
struct tcp_dctcp_info {
  __u16 dctcp_enabled;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u16 dctcp_ce_state;
  __u32 dctcp_alpha;
  __u32 dctcp_ab_ecn;
  __u32 dctcp_ab_tot;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct tcp_bbr_info {
  __u32 bbr_bw_lo;
  __u32 bbr_bw_hi;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u32 bbr_min_rtt;
  __u32 bbr_pacing_gain;
  __u32 bbr_cwnd_gain;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
union tcp_cc_info {
  struct tcpvegas_info vegas;
  struct tcp_dctcp_info dctcp;
  struct tcp_bbr_info bbr;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
#endif
