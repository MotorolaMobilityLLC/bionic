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
#ifndef _UAPI_SCTP_H
#define _UAPI_SCTP_H
#include <linux/types.h>
#include <linux/socket.h>
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
typedef __s32 sctp_assoc_t;
#define SCTP_RTOINFO 0
#define SCTP_ASSOCINFO 1
#define SCTP_INITMSG 2
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SCTP_NODELAY 3
#define SCTP_AUTOCLOSE 4
#define SCTP_SET_PEER_PRIMARY_ADDR 5
#define SCTP_PRIMARY_ADDR 6
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SCTP_ADAPTATION_LAYER 7
#define SCTP_DISABLE_FRAGMENTS 8
#define SCTP_PEER_ADDR_PARAMS 9
#define SCTP_DEFAULT_SEND_PARAM 10
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SCTP_EVENTS 11
#define SCTP_I_WANT_MAPPED_V4_ADDR 12
#define SCTP_MAXSEG 13
#define SCTP_STATUS 14
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SCTP_GET_PEER_ADDR_INFO 15
#define SCTP_DELAYED_ACK_TIME 16
#define SCTP_DELAYED_ACK SCTP_DELAYED_ACK_TIME
#define SCTP_DELAYED_SACK SCTP_DELAYED_ACK_TIME
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SCTP_CONTEXT 17
#define SCTP_FRAGMENT_INTERLEAVE 18
#define SCTP_PARTIAL_DELIVERY_POINT 19
#define SCTP_MAX_BURST 20
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SCTP_AUTH_CHUNK 21
#define SCTP_HMAC_IDENT 22
#define SCTP_AUTH_KEY 23
#define SCTP_AUTH_ACTIVE_KEY 24
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SCTP_AUTH_DELETE_KEY 25
#define SCTP_PEER_AUTH_CHUNKS 26
#define SCTP_LOCAL_AUTH_CHUNKS 27
#define SCTP_GET_ASSOC_NUMBER 28
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SCTP_GET_ASSOC_ID_LIST 29
#define SCTP_AUTO_ASCONF 30
#define SCTP_PEER_ADDR_THLDS 31
#define SCTP_RECVRCVINFO 32
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SCTP_RECVNXTINFO 33
#define SCTP_DEFAULT_SNDINFO 34
#define SCTP_SOCKOPT_BINDX_ADD 100
#define SCTP_SOCKOPT_BINDX_REM 101
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SCTP_SOCKOPT_PEELOFF 102
#define SCTP_SOCKOPT_CONNECTX_OLD 107
#define SCTP_GET_PEER_ADDRS 108
#define SCTP_GET_LOCAL_ADDRS 109
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SCTP_SOCKOPT_CONNECTX 110
#define SCTP_SOCKOPT_CONNECTX3 111
#define SCTP_GET_ASSOC_STATS 112
#define SCTP_PR_SUPPORTED 113
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SCTP_DEFAULT_PRINFO 114
#define SCTP_PR_ASSOC_STATUS 115
#define SCTP_PR_SCTP_NONE 0x0000
#define SCTP_PR_SCTP_TTL 0x0010
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SCTP_PR_SCTP_RTX 0x0020
#define SCTP_PR_SCTP_PRIO 0x0030
#define SCTP_PR_SCTP_MAX SCTP_PR_SCTP_PRIO
#define SCTP_PR_SCTP_MASK 0x0030
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __SCTP_PR_INDEX(x) ((x >> 4) - 1)
#define SCTP_PR_INDEX(x) __SCTP_PR_INDEX(SCTP_PR_SCTP_ ##x)
#define SCTP_PR_POLICY(x) ((x) & SCTP_PR_SCTP_MASK)
#define SCTP_PR_SET_POLICY(flags,x) do { flags &= ~SCTP_PR_SCTP_MASK; flags |= x; } while(0)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SCTP_PR_TTL_ENABLED(x) (SCTP_PR_POLICY(x) == SCTP_PR_SCTP_TTL)
#define SCTP_PR_RTX_ENABLED(x) (SCTP_PR_POLICY(x) == SCTP_PR_SCTP_RTX)
#define SCTP_PR_PRIO_ENABLED(x) (SCTP_PR_POLICY(x) == SCTP_PR_SCTP_PRIO)
enum sctp_msg_flags {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  MSG_NOTIFICATION = 0x8000,
#define MSG_NOTIFICATION MSG_NOTIFICATION
};
struct sctp_initmsg {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u16 sinit_num_ostreams;
  __u16 sinit_max_instreams;
  __u16 sinit_max_attempts;
  __u16 sinit_max_init_timeo;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct sctp_sndrcvinfo {
  __u16 sinfo_stream;
  __u16 sinfo_ssn;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u16 sinfo_flags;
  __u32 sinfo_ppid;
  __u32 sinfo_context;
  __u32 sinfo_timetolive;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u32 sinfo_tsn;
  __u32 sinfo_cumtsn;
  sctp_assoc_t sinfo_assoc_id;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct sctp_sndinfo {
  __u16 snd_sid;
  __u16 snd_flags;
  __u32 snd_ppid;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u32 snd_context;
  sctp_assoc_t snd_assoc_id;
};
struct sctp_rcvinfo {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u16 rcv_sid;
  __u16 rcv_ssn;
  __u16 rcv_flags;
  __u32 rcv_ppid;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u32 rcv_tsn;
  __u32 rcv_cumtsn;
  __u32 rcv_context;
  sctp_assoc_t rcv_assoc_id;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct sctp_nxtinfo {
  __u16 nxt_sid;
  __u16 nxt_flags;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u32 nxt_ppid;
  __u32 nxt_length;
  sctp_assoc_t nxt_assoc_id;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
enum sctp_sinfo_flags {
  SCTP_UNORDERED = (1 << 0),
  SCTP_ADDR_OVER = (1 << 1),
  SCTP_ABORT = (1 << 2),
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  SCTP_SACK_IMMEDIATELY = (1 << 3),
  SCTP_NOTIFICATION = MSG_NOTIFICATION,
  SCTP_EOF = MSG_FIN,
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
typedef union {
  __u8 raw;
  struct sctp_initmsg init;
  struct sctp_sndrcvinfo sndrcv;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
} sctp_cmsg_data_t;
typedef enum sctp_cmsg_type {
  SCTP_INIT,
#define SCTP_INIT SCTP_INIT
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  SCTP_SNDRCV,
#define SCTP_SNDRCV SCTP_SNDRCV
  SCTP_SNDINFO,
#define SCTP_SNDINFO SCTP_SNDINFO
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  SCTP_RCVINFO,
#define SCTP_RCVINFO SCTP_RCVINFO
  SCTP_NXTINFO,
#define SCTP_NXTINFO SCTP_NXTINFO
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
} sctp_cmsg_t;
struct sctp_assoc_change {
  __u16 sac_type;
  __u16 sac_flags;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u32 sac_length;
  __u16 sac_state;
  __u16 sac_error;
  __u16 sac_outbound_streams;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u16 sac_inbound_streams;
  sctp_assoc_t sac_assoc_id;
  __u8 sac_info[0];
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
enum sctp_sac_state {
  SCTP_COMM_UP,
  SCTP_COMM_LOST,
  SCTP_RESTART,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  SCTP_SHUTDOWN_COMP,
  SCTP_CANT_STR_ASSOC,
};
struct sctp_paddr_change {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u16 spc_type;
  __u16 spc_flags;
  __u32 spc_length;
  struct sockaddr_storage spc_aaddr;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  int spc_state;
  int spc_error;
  sctp_assoc_t spc_assoc_id;
} __attribute__((packed, aligned(4)));
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
enum sctp_spc_state {
  SCTP_ADDR_AVAILABLE,
  SCTP_ADDR_UNREACHABLE,
  SCTP_ADDR_REMOVED,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  SCTP_ADDR_ADDED,
  SCTP_ADDR_MADE_PRIM,
  SCTP_ADDR_CONFIRMED,
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct sctp_remote_error {
  __u16 sre_type;
  __u16 sre_flags;
  __u32 sre_length;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u16 sre_error;
  sctp_assoc_t sre_assoc_id;
  __u8 sre_data[0];
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct sctp_send_failed {
  __u16 ssf_type;
  __u16 ssf_flags;
  __u32 ssf_length;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u32 ssf_error;
  struct sctp_sndrcvinfo ssf_info;
  sctp_assoc_t ssf_assoc_id;
  __u8 ssf_data[0];
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
enum sctp_ssf_flags {
  SCTP_DATA_UNSENT,
  SCTP_DATA_SENT,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct sctp_shutdown_event {
  __u16 sse_type;
  __u16 sse_flags;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u32 sse_length;
  sctp_assoc_t sse_assoc_id;
};
struct sctp_adaptation_event {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u16 sai_type;
  __u16 sai_flags;
  __u32 sai_length;
  __u32 sai_adaptation_ind;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  sctp_assoc_t sai_assoc_id;
};
struct sctp_pdapi_event {
  __u16 pdapi_type;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u16 pdapi_flags;
  __u32 pdapi_length;
  __u32 pdapi_indication;
  sctp_assoc_t pdapi_assoc_id;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
enum {
  SCTP_PARTIAL_DELIVERY_ABORTED = 0,
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct sctp_authkey_event {
  __u16 auth_type;
  __u16 auth_flags;
  __u32 auth_length;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u16 auth_keynumber;
  __u16 auth_altkeynumber;
  __u32 auth_indication;
  sctp_assoc_t auth_assoc_id;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
enum {
  SCTP_AUTH_NEWKEY = 0,
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct sctp_sender_dry_event {
  __u16 sender_dry_type;
  __u16 sender_dry_flags;
  __u32 sender_dry_length;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  sctp_assoc_t sender_dry_assoc_id;
};
struct sctp_event_subscribe {
  __u8 sctp_data_io_event;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u8 sctp_association_event;
  __u8 sctp_address_event;
  __u8 sctp_send_failure_event;
  __u8 sctp_peer_error_event;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u8 sctp_shutdown_event;
  __u8 sctp_partial_delivery_event;
  __u8 sctp_adaptation_layer_event;
  __u8 sctp_authentication_event;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u8 sctp_sender_dry_event;
};
union sctp_notification {
  struct {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
    __u16 sn_type;
    __u16 sn_flags;
    __u32 sn_length;
  } sn_header;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  struct sctp_assoc_change sn_assoc_change;
  struct sctp_paddr_change sn_paddr_change;
  struct sctp_remote_error sn_remote_error;
  struct sctp_send_failed sn_send_failed;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  struct sctp_shutdown_event sn_shutdown_event;
  struct sctp_adaptation_event sn_adaptation_event;
  struct sctp_pdapi_event sn_pdapi_event;
  struct sctp_authkey_event sn_authkey_event;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  struct sctp_sender_dry_event sn_sender_dry_event;
};
enum sctp_sn_type {
  SCTP_SN_TYPE_BASE = (1 << 15),
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  SCTP_ASSOC_CHANGE,
#define SCTP_ASSOC_CHANGE SCTP_ASSOC_CHANGE
  SCTP_PEER_ADDR_CHANGE,
#define SCTP_PEER_ADDR_CHANGE SCTP_PEER_ADDR_CHANGE
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  SCTP_SEND_FAILED,
#define SCTP_SEND_FAILED SCTP_SEND_FAILED
  SCTP_REMOTE_ERROR,
#define SCTP_REMOTE_ERROR SCTP_REMOTE_ERROR
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  SCTP_SHUTDOWN_EVENT,
#define SCTP_SHUTDOWN_EVENT SCTP_SHUTDOWN_EVENT
  SCTP_PARTIAL_DELIVERY_EVENT,
#define SCTP_PARTIAL_DELIVERY_EVENT SCTP_PARTIAL_DELIVERY_EVENT
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  SCTP_ADAPTATION_INDICATION,
#define SCTP_ADAPTATION_INDICATION SCTP_ADAPTATION_INDICATION
  SCTP_AUTHENTICATION_EVENT,
#define SCTP_AUTHENTICATION_INDICATION SCTP_AUTHENTICATION_EVENT
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  SCTP_SENDER_DRY_EVENT,
#define SCTP_SENDER_DRY_EVENT SCTP_SENDER_DRY_EVENT
};
typedef enum sctp_sn_error {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  SCTP_FAILED_THRESHOLD,
  SCTP_RECEIVED_SACK,
  SCTP_HEARTBEAT_SUCCESS,
  SCTP_RESPONSE_TO_USER_REQ,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  SCTP_INTERNAL_ERROR,
  SCTP_SHUTDOWN_GUARD_EXPIRES,
  SCTP_PEER_FAULTY,
} sctp_sn_error_t;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct sctp_rtoinfo {
  sctp_assoc_t srto_assoc_id;
  __u32 srto_initial;
  __u32 srto_max;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u32 srto_min;
};
struct sctp_assocparams {
  sctp_assoc_t sasoc_assoc_id;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u16 sasoc_asocmaxrxt;
  __u16 sasoc_number_peer_destinations;
  __u32 sasoc_peer_rwnd;
  __u32 sasoc_local_rwnd;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u32 sasoc_cookie_life;
};
struct sctp_setpeerprim {
  sctp_assoc_t sspp_assoc_id;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  struct sockaddr_storage sspp_addr;
} __attribute__((packed, aligned(4)));
struct sctp_prim {
  sctp_assoc_t ssp_assoc_id;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  struct sockaddr_storage ssp_addr;
} __attribute__((packed, aligned(4)));
#define sctp_setprim sctp_prim
struct sctp_setadaptation {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u32 ssb_adaptation_ind;
};
enum sctp_spp_flags {
  SPP_HB_ENABLE = 1 << 0,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  SPP_HB_DISABLE = 1 << 1,
  SPP_HB = SPP_HB_ENABLE | SPP_HB_DISABLE,
  SPP_HB_DEMAND = 1 << 2,
  SPP_PMTUD_ENABLE = 1 << 3,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  SPP_PMTUD_DISABLE = 1 << 4,
  SPP_PMTUD = SPP_PMTUD_ENABLE | SPP_PMTUD_DISABLE,
  SPP_SACKDELAY_ENABLE = 1 << 5,
  SPP_SACKDELAY_DISABLE = 1 << 6,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  SPP_SACKDELAY = SPP_SACKDELAY_ENABLE | SPP_SACKDELAY_DISABLE,
  SPP_HB_TIME_IS_ZERO = 1 << 7,
};
struct sctp_paddrparams {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  sctp_assoc_t spp_assoc_id;
  struct sockaddr_storage spp_address;
  __u32 spp_hbinterval;
  __u16 spp_pathmaxrxt;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u32 spp_pathmtu;
  __u32 spp_sackdelay;
  __u32 spp_flags;
} __attribute__((packed, aligned(4)));
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct sctp_authchunk {
  __u8 sauth_chunk;
};
enum {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  SCTP_AUTH_HMAC_ID_SHA1 = 1,
  SCTP_AUTH_HMAC_ID_SHA256 = 3,
};
struct sctp_hmacalgo {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u32 shmac_num_idents;
  __u16 shmac_idents[];
};
#define shmac_number_of_idents shmac_num_idents
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct sctp_authkey {
  sctp_assoc_t sca_assoc_id;
  __u16 sca_keynumber;
  __u16 sca_keylength;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u8 sca_key[];
};
struct sctp_authkeyid {
  sctp_assoc_t scact_assoc_id;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u16 scact_keynumber;
};
struct sctp_sack_info {
  sctp_assoc_t sack_assoc_id;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  uint32_t sack_delay;
  uint32_t sack_freq;
};
struct sctp_assoc_value {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  sctp_assoc_t assoc_id;
  uint32_t assoc_value;
};
struct sctp_paddrinfo {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  sctp_assoc_t spinfo_assoc_id;
  struct sockaddr_storage spinfo_address;
  __s32 spinfo_state;
  __u32 spinfo_cwnd;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u32 spinfo_srtt;
  __u32 spinfo_rto;
  __u32 spinfo_mtu;
} __attribute__((packed, aligned(4)));
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
enum sctp_spinfo_state {
  SCTP_INACTIVE,
  SCTP_PF,
  SCTP_ACTIVE,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  SCTP_UNCONFIRMED,
  SCTP_UNKNOWN = 0xffff
};
struct sctp_status {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  sctp_assoc_t sstat_assoc_id;
  __s32 sstat_state;
  __u32 sstat_rwnd;
  __u16 sstat_unackdata;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u16 sstat_penddata;
  __u16 sstat_instrms;
  __u16 sstat_outstrms;
  __u32 sstat_fragmentation_point;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  struct sctp_paddrinfo sstat_primary;
};
struct sctp_authchunks {
  sctp_assoc_t gauth_assoc_id;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u32 gauth_number_of_chunks;
  uint8_t gauth_chunks[];
};
#define guth_number_of_chunks gauth_number_of_chunks
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
enum sctp_sstat_state {
  SCTP_EMPTY = 0,
  SCTP_CLOSED = 1,
  SCTP_COOKIE_WAIT = 2,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  SCTP_COOKIE_ECHOED = 3,
  SCTP_ESTABLISHED = 4,
  SCTP_SHUTDOWN_PENDING = 5,
  SCTP_SHUTDOWN_SENT = 6,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  SCTP_SHUTDOWN_RECEIVED = 7,
  SCTP_SHUTDOWN_ACK_SENT = 8,
};
struct sctp_assoc_ids {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u32 gaids_number_of_ids;
  sctp_assoc_t gaids_assoc_id[];
};
struct sctp_getaddrs_old {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  sctp_assoc_t assoc_id;
  int addr_num;
  struct sockaddr * addrs;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct sctp_getaddrs {
  sctp_assoc_t assoc_id;
  __u32 addr_num;
  __u8 addrs[0];
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct sctp_assoc_stats {
  sctp_assoc_t sas_assoc_id;
  struct sockaddr_storage sas_obs_rto_ipaddr;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u64 sas_maxrto;
  __u64 sas_isacks;
  __u64 sas_osacks;
  __u64 sas_opackets;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u64 sas_ipackets;
  __u64 sas_rtxchunks;
  __u64 sas_outofseqtsns;
  __u64 sas_idupchunks;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u64 sas_gapcnt;
  __u64 sas_ouodchunks;
  __u64 sas_iuodchunks;
  __u64 sas_oodchunks;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u64 sas_iodchunks;
  __u64 sas_octrlchunks;
  __u64 sas_ictrlchunks;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SCTP_BINDX_ADD_ADDR 0x01
#define SCTP_BINDX_REM_ADDR 0x02
typedef struct {
  sctp_assoc_t associd;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  int sd;
} sctp_peeloff_arg_t;
struct sctp_paddrthlds {
  sctp_assoc_t spt_assoc_id;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  struct sockaddr_storage spt_address;
  __u16 spt_pathmaxrxt;
  __u16 spt_pathpfthld;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct sctp_prstatus {
  sctp_assoc_t sprstat_assoc_id;
  __u16 sprstat_sid;
  __u16 sprstat_policy;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u64 sprstat_abandoned_unsent;
  __u64 sprstat_abandoned_sent;
};
struct sctp_default_prinfo {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  sctp_assoc_t pr_assoc_id;
  __u32 pr_value;
  __u16 pr_policy;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct sctp_info {
  __u32 sctpi_tag;
  __u32 sctpi_state;
  __u32 sctpi_rwnd;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u16 sctpi_unackdata;
  __u16 sctpi_penddata;
  __u16 sctpi_instrms;
  __u16 sctpi_outstrms;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u32 sctpi_fragmentation_point;
  __u32 sctpi_inqueue;
  __u32 sctpi_outqueue;
  __u32 sctpi_overall_error;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u32 sctpi_max_burst;
  __u32 sctpi_maxseg;
  __u32 sctpi_peer_rwnd;
  __u32 sctpi_peer_tag;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u8 sctpi_peer_capable;
  __u8 sctpi_peer_sack;
  __u16 __reserved1;
  __u64 sctpi_isacks;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u64 sctpi_osacks;
  __u64 sctpi_opackets;
  __u64 sctpi_ipackets;
  __u64 sctpi_rtxchunks;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u64 sctpi_outofseqtsns;
  __u64 sctpi_idupchunks;
  __u64 sctpi_gapcnt;
  __u64 sctpi_ouodchunks;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u64 sctpi_iuodchunks;
  __u64 sctpi_oodchunks;
  __u64 sctpi_iodchunks;
  __u64 sctpi_octrlchunks;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u64 sctpi_ictrlchunks;
  struct sockaddr_storage sctpi_p_address;
  __s32 sctpi_p_state;
  __u32 sctpi_p_cwnd;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u32 sctpi_p_srtt;
  __u32 sctpi_p_rto;
  __u32 sctpi_p_hbinterval;
  __u32 sctpi_p_pathmaxrxt;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u32 sctpi_p_sackdelay;
  __u32 sctpi_p_sackfreq;
  __u32 sctpi_p_ssthresh;
  __u32 sctpi_p_partial_bytes_acked;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u32 sctpi_p_flight_size;
  __u16 sctpi_p_error;
  __u16 __reserved2;
  __u32 sctpi_s_autoclose;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u32 sctpi_s_adaptation_ind;
  __u32 sctpi_s_pd_point;
  __u8 sctpi_s_nodelay;
  __u8 sctpi_s_disable_fragments;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u8 sctpi_s_v4mapped;
  __u8 sctpi_s_frag_interleave;
  __u32 sctpi_s_type;
  __u32 __reserved3;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
#endif
