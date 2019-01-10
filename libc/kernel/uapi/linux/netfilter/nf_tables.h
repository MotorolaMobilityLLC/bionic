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
#ifndef _LINUX_NF_TABLES_H
#define _LINUX_NF_TABLES_H
#define NFT_NAME_MAXLEN 256
#define NFT_TABLE_MAXNAMELEN NFT_NAME_MAXLEN
#define NFT_CHAIN_MAXNAMELEN NFT_NAME_MAXLEN
#define NFT_SET_MAXNAMELEN NFT_NAME_MAXLEN
#define NFT_OBJ_MAXNAMELEN NFT_NAME_MAXLEN
#define NFT_USERDATA_MAXLEN 256
#define NFT_OSF_MAXGENRELEN 16
enum nft_registers {
  NFT_REG_VERDICT,
  NFT_REG_1,
  NFT_REG_2,
  NFT_REG_3,
  NFT_REG_4,
  __NFT_REG_MAX,
  NFT_REG32_00 = 8,
  NFT_REG32_01,
  NFT_REG32_02,
  NFT_REG32_03,
  NFT_REG32_04,
  NFT_REG32_05,
  NFT_REG32_06,
  NFT_REG32_07,
  NFT_REG32_08,
  NFT_REG32_09,
  NFT_REG32_10,
  NFT_REG32_11,
  NFT_REG32_12,
  NFT_REG32_13,
  NFT_REG32_14,
  NFT_REG32_15,
};
#define NFT_REG_MAX (__NFT_REG_MAX - 1)
#define NFT_REG_SIZE 16
#define NFT_REG32_SIZE 4
enum nft_verdicts {
  NFT_CONTINUE = - 1,
  NFT_BREAK = - 2,
  NFT_JUMP = - 3,
  NFT_GOTO = - 4,
  NFT_RETURN = - 5,
};
enum nf_tables_msg_types {
  NFT_MSG_NEWTABLE,
  NFT_MSG_GETTABLE,
  NFT_MSG_DELTABLE,
  NFT_MSG_NEWCHAIN,
  NFT_MSG_GETCHAIN,
  NFT_MSG_DELCHAIN,
  NFT_MSG_NEWRULE,
  NFT_MSG_GETRULE,
  NFT_MSG_DELRULE,
  NFT_MSG_NEWSET,
  NFT_MSG_GETSET,
  NFT_MSG_DELSET,
  NFT_MSG_NEWSETELEM,
  NFT_MSG_GETSETELEM,
  NFT_MSG_DELSETELEM,
  NFT_MSG_NEWGEN,
  NFT_MSG_GETGEN,
  NFT_MSG_TRACE,
  NFT_MSG_NEWOBJ,
  NFT_MSG_GETOBJ,
  NFT_MSG_DELOBJ,
  NFT_MSG_GETOBJ_RESET,
  NFT_MSG_NEWFLOWTABLE,
  NFT_MSG_GETFLOWTABLE,
  NFT_MSG_DELFLOWTABLE,
  NFT_MSG_MAX,
};
enum nft_list_attributes {
  NFTA_LIST_UNPEC,
  NFTA_LIST_ELEM,
  __NFTA_LIST_MAX
};
#define NFTA_LIST_MAX (__NFTA_LIST_MAX - 1)
enum nft_hook_attributes {
  NFTA_HOOK_UNSPEC,
  NFTA_HOOK_HOOKNUM,
  NFTA_HOOK_PRIORITY,
  NFTA_HOOK_DEV,
  __NFTA_HOOK_MAX
};
#define NFTA_HOOK_MAX (__NFTA_HOOK_MAX - 1)
enum nft_table_flags {
  NFT_TABLE_F_DORMANT = 0x1,
};
enum nft_table_attributes {
  NFTA_TABLE_UNSPEC,
  NFTA_TABLE_NAME,
  NFTA_TABLE_FLAGS,
  NFTA_TABLE_USE,
  NFTA_TABLE_HANDLE,
  NFTA_TABLE_PAD,
  __NFTA_TABLE_MAX
};
#define NFTA_TABLE_MAX (__NFTA_TABLE_MAX - 1)
enum nft_chain_attributes {
  NFTA_CHAIN_UNSPEC,
  NFTA_CHAIN_TABLE,
  NFTA_CHAIN_HANDLE,
  NFTA_CHAIN_NAME,
  NFTA_CHAIN_HOOK,
  NFTA_CHAIN_POLICY,
  NFTA_CHAIN_USE,
  NFTA_CHAIN_TYPE,
  NFTA_CHAIN_COUNTERS,
  NFTA_CHAIN_PAD,
  __NFTA_CHAIN_MAX
};
#define NFTA_CHAIN_MAX (__NFTA_CHAIN_MAX - 1)
enum nft_rule_attributes {
  NFTA_RULE_UNSPEC,
  NFTA_RULE_TABLE,
  NFTA_RULE_CHAIN,
  NFTA_RULE_HANDLE,
  NFTA_RULE_EXPRESSIONS,
  NFTA_RULE_COMPAT,
  NFTA_RULE_POSITION,
  NFTA_RULE_USERDATA,
  NFTA_RULE_PAD,
  NFTA_RULE_ID,
  __NFTA_RULE_MAX
};
#define NFTA_RULE_MAX (__NFTA_RULE_MAX - 1)
enum nft_rule_compat_flags {
  NFT_RULE_COMPAT_F_INV = (1 << 1),
  NFT_RULE_COMPAT_F_MASK = NFT_RULE_COMPAT_F_INV,
};
enum nft_rule_compat_attributes {
  NFTA_RULE_COMPAT_UNSPEC,
  NFTA_RULE_COMPAT_PROTO,
  NFTA_RULE_COMPAT_FLAGS,
  __NFTA_RULE_COMPAT_MAX
};
#define NFTA_RULE_COMPAT_MAX (__NFTA_RULE_COMPAT_MAX - 1)
enum nft_set_flags {
  NFT_SET_ANONYMOUS = 0x1,
  NFT_SET_CONSTANT = 0x2,
  NFT_SET_INTERVAL = 0x4,
  NFT_SET_MAP = 0x8,
  NFT_SET_TIMEOUT = 0x10,
  NFT_SET_EVAL = 0x20,
  NFT_SET_OBJECT = 0x40,
};
enum nft_set_policies {
  NFT_SET_POL_PERFORMANCE,
  NFT_SET_POL_MEMORY,
};
enum nft_set_desc_attributes {
  NFTA_SET_DESC_UNSPEC,
  NFTA_SET_DESC_SIZE,
  __NFTA_SET_DESC_MAX
};
#define NFTA_SET_DESC_MAX (__NFTA_SET_DESC_MAX - 1)
enum nft_set_attributes {
  NFTA_SET_UNSPEC,
  NFTA_SET_TABLE,
  NFTA_SET_NAME,
  NFTA_SET_FLAGS,
  NFTA_SET_KEY_TYPE,
  NFTA_SET_KEY_LEN,
  NFTA_SET_DATA_TYPE,
  NFTA_SET_DATA_LEN,
  NFTA_SET_POLICY,
  NFTA_SET_DESC,
  NFTA_SET_ID,
  NFTA_SET_TIMEOUT,
  NFTA_SET_GC_INTERVAL,
  NFTA_SET_USERDATA,
  NFTA_SET_PAD,
  NFTA_SET_OBJ_TYPE,
  NFTA_SET_HANDLE,
  __NFTA_SET_MAX
};
#define NFTA_SET_MAX (__NFTA_SET_MAX - 1)
enum nft_set_elem_flags {
  NFT_SET_ELEM_INTERVAL_END = 0x1,
};
enum nft_set_elem_attributes {
  NFTA_SET_ELEM_UNSPEC,
  NFTA_SET_ELEM_KEY,
  NFTA_SET_ELEM_DATA,
  NFTA_SET_ELEM_FLAGS,
  NFTA_SET_ELEM_TIMEOUT,
  NFTA_SET_ELEM_EXPIRATION,
  NFTA_SET_ELEM_USERDATA,
  NFTA_SET_ELEM_EXPR,
  NFTA_SET_ELEM_PAD,
  NFTA_SET_ELEM_OBJREF,
  __NFTA_SET_ELEM_MAX
};
#define NFTA_SET_ELEM_MAX (__NFTA_SET_ELEM_MAX - 1)
enum nft_set_elem_list_attributes {
  NFTA_SET_ELEM_LIST_UNSPEC,
  NFTA_SET_ELEM_LIST_TABLE,
  NFTA_SET_ELEM_LIST_SET,
  NFTA_SET_ELEM_LIST_ELEMENTS,
  NFTA_SET_ELEM_LIST_SET_ID,
  __NFTA_SET_ELEM_LIST_MAX
};
#define NFTA_SET_ELEM_LIST_MAX (__NFTA_SET_ELEM_LIST_MAX - 1)
enum nft_data_types {
  NFT_DATA_VALUE,
  NFT_DATA_VERDICT = 0xffffff00U,
};
#define NFT_DATA_RESERVED_MASK 0xffffff00U
enum nft_data_attributes {
  NFTA_DATA_UNSPEC,
  NFTA_DATA_VALUE,
  NFTA_DATA_VERDICT,
  __NFTA_DATA_MAX
};
#define NFTA_DATA_MAX (__NFTA_DATA_MAX - 1)
#define NFT_DATA_VALUE_MAXLEN 64
enum nft_verdict_attributes {
  NFTA_VERDICT_UNSPEC,
  NFTA_VERDICT_CODE,
  NFTA_VERDICT_CHAIN,
  __NFTA_VERDICT_MAX
};
#define NFTA_VERDICT_MAX (__NFTA_VERDICT_MAX - 1)
enum nft_expr_attributes {
  NFTA_EXPR_UNSPEC,
  NFTA_EXPR_NAME,
  NFTA_EXPR_DATA,
  __NFTA_EXPR_MAX
};
#define NFTA_EXPR_MAX (__NFTA_EXPR_MAX - 1)
enum nft_immediate_attributes {
  NFTA_IMMEDIATE_UNSPEC,
  NFTA_IMMEDIATE_DREG,
  NFTA_IMMEDIATE_DATA,
  __NFTA_IMMEDIATE_MAX
};
#define NFTA_IMMEDIATE_MAX (__NFTA_IMMEDIATE_MAX - 1)
enum nft_bitwise_attributes {
  NFTA_BITWISE_UNSPEC,
  NFTA_BITWISE_SREG,
  NFTA_BITWISE_DREG,
  NFTA_BITWISE_LEN,
  NFTA_BITWISE_MASK,
  NFTA_BITWISE_XOR,
  __NFTA_BITWISE_MAX
};
#define NFTA_BITWISE_MAX (__NFTA_BITWISE_MAX - 1)
enum nft_byteorder_ops {
  NFT_BYTEORDER_NTOH,
  NFT_BYTEORDER_HTON,
};
enum nft_byteorder_attributes {
  NFTA_BYTEORDER_UNSPEC,
  NFTA_BYTEORDER_SREG,
  NFTA_BYTEORDER_DREG,
  NFTA_BYTEORDER_OP,
  NFTA_BYTEORDER_LEN,
  NFTA_BYTEORDER_SIZE,
  __NFTA_BYTEORDER_MAX
};
#define NFTA_BYTEORDER_MAX (__NFTA_BYTEORDER_MAX - 1)
enum nft_cmp_ops {
  NFT_CMP_EQ,
  NFT_CMP_NEQ,
  NFT_CMP_LT,
  NFT_CMP_LTE,
  NFT_CMP_GT,
  NFT_CMP_GTE,
};
enum nft_cmp_attributes {
  NFTA_CMP_UNSPEC,
  NFTA_CMP_SREG,
  NFTA_CMP_OP,
  NFTA_CMP_DATA,
  __NFTA_CMP_MAX
};
#define NFTA_CMP_MAX (__NFTA_CMP_MAX - 1)
enum nft_range_ops {
  NFT_RANGE_EQ,
  NFT_RANGE_NEQ,
};
enum nft_range_attributes {
  NFTA_RANGE_UNSPEC,
  NFTA_RANGE_SREG,
  NFTA_RANGE_OP,
  NFTA_RANGE_FROM_DATA,
  NFTA_RANGE_TO_DATA,
  __NFTA_RANGE_MAX
};
#define NFTA_RANGE_MAX (__NFTA_RANGE_MAX - 1)
enum nft_lookup_flags {
  NFT_LOOKUP_F_INV = (1 << 0),
};
enum nft_lookup_attributes {
  NFTA_LOOKUP_UNSPEC,
  NFTA_LOOKUP_SET,
  NFTA_LOOKUP_SREG,
  NFTA_LOOKUP_DREG,
  NFTA_LOOKUP_SET_ID,
  NFTA_LOOKUP_FLAGS,
  __NFTA_LOOKUP_MAX
};
#define NFTA_LOOKUP_MAX (__NFTA_LOOKUP_MAX - 1)
enum nft_dynset_ops {
  NFT_DYNSET_OP_ADD,
  NFT_DYNSET_OP_UPDATE,
};
enum nft_dynset_flags {
  NFT_DYNSET_F_INV = (1 << 0),
};
enum nft_dynset_attributes {
  NFTA_DYNSET_UNSPEC,
  NFTA_DYNSET_SET_NAME,
  NFTA_DYNSET_SET_ID,
  NFTA_DYNSET_OP,
  NFTA_DYNSET_SREG_KEY,
  NFTA_DYNSET_SREG_DATA,
  NFTA_DYNSET_TIMEOUT,
  NFTA_DYNSET_EXPR,
  NFTA_DYNSET_PAD,
  NFTA_DYNSET_FLAGS,
  __NFTA_DYNSET_MAX,
};
#define NFTA_DYNSET_MAX (__NFTA_DYNSET_MAX - 1)
enum nft_payload_bases {
  NFT_PAYLOAD_LL_HEADER,
  NFT_PAYLOAD_NETWORK_HEADER,
  NFT_PAYLOAD_TRANSPORT_HEADER,
};
enum nft_payload_csum_types {
  NFT_PAYLOAD_CSUM_NONE,
  NFT_PAYLOAD_CSUM_INET,
};
enum nft_payload_csum_flags {
  NFT_PAYLOAD_L4CSUM_PSEUDOHDR = (1 << 0),
};
enum nft_payload_attributes {
  NFTA_PAYLOAD_UNSPEC,
  NFTA_PAYLOAD_DREG,
  NFTA_PAYLOAD_BASE,
  NFTA_PAYLOAD_OFFSET,
  NFTA_PAYLOAD_LEN,
  NFTA_PAYLOAD_SREG,
  NFTA_PAYLOAD_CSUM_TYPE,
  NFTA_PAYLOAD_CSUM_OFFSET,
  NFTA_PAYLOAD_CSUM_FLAGS,
  __NFTA_PAYLOAD_MAX
};
#define NFTA_PAYLOAD_MAX (__NFTA_PAYLOAD_MAX - 1)
enum nft_exthdr_flags {
  NFT_EXTHDR_F_PRESENT = (1 << 0),
};
enum nft_exthdr_op {
  NFT_EXTHDR_OP_IPV6,
  NFT_EXTHDR_OP_TCPOPT,
  __NFT_EXTHDR_OP_MAX
};
#define NFT_EXTHDR_OP_MAX (__NFT_EXTHDR_OP_MAX - 1)
enum nft_exthdr_attributes {
  NFTA_EXTHDR_UNSPEC,
  NFTA_EXTHDR_DREG,
  NFTA_EXTHDR_TYPE,
  NFTA_EXTHDR_OFFSET,
  NFTA_EXTHDR_LEN,
  NFTA_EXTHDR_FLAGS,
  NFTA_EXTHDR_OP,
  NFTA_EXTHDR_SREG,
  __NFTA_EXTHDR_MAX
};
#define NFTA_EXTHDR_MAX (__NFTA_EXTHDR_MAX - 1)
enum nft_meta_keys {
  NFT_META_LEN,
  NFT_META_PROTOCOL,
  NFT_META_PRIORITY,
  NFT_META_MARK,
  NFT_META_IIF,
  NFT_META_OIF,
  NFT_META_IIFNAME,
  NFT_META_OIFNAME,
  NFT_META_IIFTYPE,
  NFT_META_OIFTYPE,
  NFT_META_SKUID,
  NFT_META_SKGID,
  NFT_META_NFTRACE,
  NFT_META_RTCLASSID,
  NFT_META_SECMARK,
  NFT_META_NFPROTO,
  NFT_META_L4PROTO,
  NFT_META_BRI_IIFNAME,
  NFT_META_BRI_OIFNAME,
  NFT_META_PKTTYPE,
  NFT_META_CPU,
  NFT_META_IIFGROUP,
  NFT_META_OIFGROUP,
  NFT_META_CGROUP,
  NFT_META_PRANDOM,
  NFT_META_SECPATH,
};
enum nft_rt_keys {
  NFT_RT_CLASSID,
  NFT_RT_NEXTHOP4,
  NFT_RT_NEXTHOP6,
  NFT_RT_TCPMSS,
  NFT_RT_XFRM,
  __NFT_RT_MAX
};
#define NFT_RT_MAX (__NFT_RT_MAX - 1)
enum nft_hash_types {
  NFT_HASH_JENKINS,
  NFT_HASH_SYM,
};
enum nft_hash_attributes {
  NFTA_HASH_UNSPEC,
  NFTA_HASH_SREG,
  NFTA_HASH_DREG,
  NFTA_HASH_LEN,
  NFTA_HASH_MODULUS,
  NFTA_HASH_SEED,
  NFTA_HASH_OFFSET,
  NFTA_HASH_TYPE,
  NFTA_HASH_SET_NAME,
  NFTA_HASH_SET_ID,
  __NFTA_HASH_MAX,
};
#define NFTA_HASH_MAX (__NFTA_HASH_MAX - 1)
enum nft_meta_attributes {
  NFTA_META_UNSPEC,
  NFTA_META_DREG,
  NFTA_META_KEY,
  NFTA_META_SREG,
  __NFTA_META_MAX
};
#define NFTA_META_MAX (__NFTA_META_MAX - 1)
enum nft_rt_attributes {
  NFTA_RT_UNSPEC,
  NFTA_RT_DREG,
  NFTA_RT_KEY,
  __NFTA_RT_MAX
};
#define NFTA_RT_MAX (__NFTA_RT_MAX - 1)
enum nft_socket_attributes {
  NFTA_SOCKET_UNSPEC,
  NFTA_SOCKET_KEY,
  NFTA_SOCKET_DREG,
  __NFTA_SOCKET_MAX
};
#define NFTA_SOCKET_MAX (__NFTA_SOCKET_MAX - 1)
enum nft_socket_keys {
  NFT_SOCKET_TRANSPARENT,
  NFT_SOCKET_MARK,
  __NFT_SOCKET_MAX
};
#define NFT_SOCKET_MAX (__NFT_SOCKET_MAX - 1)
enum nft_ct_keys {
  NFT_CT_STATE,
  NFT_CT_DIRECTION,
  NFT_CT_STATUS,
  NFT_CT_MARK,
  NFT_CT_SECMARK,
  NFT_CT_EXPIRATION,
  NFT_CT_HELPER,
  NFT_CT_L3PROTOCOL,
  NFT_CT_SRC,
  NFT_CT_DST,
  NFT_CT_PROTOCOL,
  NFT_CT_PROTO_SRC,
  NFT_CT_PROTO_DST,
  NFT_CT_LABELS,
  NFT_CT_PKTS,
  NFT_CT_BYTES,
  NFT_CT_AVGPKT,
  NFT_CT_ZONE,
  NFT_CT_EVENTMASK,
  NFT_CT_SRC_IP,
  NFT_CT_DST_IP,
  NFT_CT_SRC_IP6,
  NFT_CT_DST_IP6,
  NFT_CT_TIMEOUT,
  __NFT_CT_MAX
};
#define NFT_CT_MAX (__NFT_CT_MAX - 1)
enum nft_ct_attributes {
  NFTA_CT_UNSPEC,
  NFTA_CT_DREG,
  NFTA_CT_KEY,
  NFTA_CT_DIRECTION,
  NFTA_CT_SREG,
  __NFTA_CT_MAX
};
#define NFTA_CT_MAX (__NFTA_CT_MAX - 1)
enum nft_offload_attributes {
  NFTA_FLOW_UNSPEC,
  NFTA_FLOW_TABLE_NAME,
  __NFTA_FLOW_MAX,
};
#define NFTA_FLOW_MAX (__NFTA_FLOW_MAX - 1)
enum nft_limit_type {
  NFT_LIMIT_PKTS,
  NFT_LIMIT_PKT_BYTES
};
enum nft_limit_flags {
  NFT_LIMIT_F_INV = (1 << 0),
};
enum nft_limit_attributes {
  NFTA_LIMIT_UNSPEC,
  NFTA_LIMIT_RATE,
  NFTA_LIMIT_UNIT,
  NFTA_LIMIT_BURST,
  NFTA_LIMIT_TYPE,
  NFTA_LIMIT_FLAGS,
  NFTA_LIMIT_PAD,
  __NFTA_LIMIT_MAX
};
#define NFTA_LIMIT_MAX (__NFTA_LIMIT_MAX - 1)
enum nft_connlimit_flags {
  NFT_CONNLIMIT_F_INV = (1 << 0),
};
enum nft_connlimit_attributes {
  NFTA_CONNLIMIT_UNSPEC,
  NFTA_CONNLIMIT_COUNT,
  NFTA_CONNLIMIT_FLAGS,
  __NFTA_CONNLIMIT_MAX
};
#define NFTA_CONNLIMIT_MAX (__NFTA_CONNLIMIT_MAX - 1)
enum nft_counter_attributes {
  NFTA_COUNTER_UNSPEC,
  NFTA_COUNTER_BYTES,
  NFTA_COUNTER_PACKETS,
  NFTA_COUNTER_PAD,
  __NFTA_COUNTER_MAX
};
#define NFTA_COUNTER_MAX (__NFTA_COUNTER_MAX - 1)
enum nft_log_attributes {
  NFTA_LOG_UNSPEC,
  NFTA_LOG_GROUP,
  NFTA_LOG_PREFIX,
  NFTA_LOG_SNAPLEN,
  NFTA_LOG_QTHRESHOLD,
  NFTA_LOG_LEVEL,
  NFTA_LOG_FLAGS,
  __NFTA_LOG_MAX
};
#define NFTA_LOG_MAX (__NFTA_LOG_MAX - 1)
enum nft_log_level {
  NFT_LOGLEVEL_EMERG,
  NFT_LOGLEVEL_ALERT,
  NFT_LOGLEVEL_CRIT,
  NFT_LOGLEVEL_ERR,
  NFT_LOGLEVEL_WARNING,
  NFT_LOGLEVEL_NOTICE,
  NFT_LOGLEVEL_INFO,
  NFT_LOGLEVEL_DEBUG,
  NFT_LOGLEVEL_AUDIT,
  __NFT_LOGLEVEL_MAX
};
#define NFT_LOGLEVEL_MAX (__NFT_LOGLEVEL_MAX + 1)
enum nft_queue_attributes {
  NFTA_QUEUE_UNSPEC,
  NFTA_QUEUE_NUM,
  NFTA_QUEUE_TOTAL,
  NFTA_QUEUE_FLAGS,
  NFTA_QUEUE_SREG_QNUM,
  __NFTA_QUEUE_MAX
};
#define NFTA_QUEUE_MAX (__NFTA_QUEUE_MAX - 1)
#define NFT_QUEUE_FLAG_BYPASS 0x01
#define NFT_QUEUE_FLAG_CPU_FANOUT 0x02
#define NFT_QUEUE_FLAG_MASK 0x03
enum nft_quota_flags {
  NFT_QUOTA_F_INV = (1 << 0),
  NFT_QUOTA_F_DEPLETED = (1 << 1),
};
enum nft_quota_attributes {
  NFTA_QUOTA_UNSPEC,
  NFTA_QUOTA_BYTES,
  NFTA_QUOTA_FLAGS,
  NFTA_QUOTA_PAD,
  NFTA_QUOTA_CONSUMED,
  __NFTA_QUOTA_MAX
};
#define NFTA_QUOTA_MAX (__NFTA_QUOTA_MAX - 1)
enum nft_secmark_attributes {
  NFTA_SECMARK_UNSPEC,
  NFTA_SECMARK_CTX,
  __NFTA_SECMARK_MAX,
};
#define NFTA_SECMARK_MAX (__NFTA_SECMARK_MAX - 1)
#define NFT_SECMARK_CTX_MAXLEN 256
enum nft_reject_types {
  NFT_REJECT_ICMP_UNREACH,
  NFT_REJECT_TCP_RST,
  NFT_REJECT_ICMPX_UNREACH,
};
enum nft_reject_inet_code {
  NFT_REJECT_ICMPX_NO_ROUTE = 0,
  NFT_REJECT_ICMPX_PORT_UNREACH,
  NFT_REJECT_ICMPX_HOST_UNREACH,
  NFT_REJECT_ICMPX_ADMIN_PROHIBITED,
  __NFT_REJECT_ICMPX_MAX
};
#define NFT_REJECT_ICMPX_MAX (__NFT_REJECT_ICMPX_MAX - 1)
enum nft_reject_attributes {
  NFTA_REJECT_UNSPEC,
  NFTA_REJECT_TYPE,
  NFTA_REJECT_ICMP_CODE,
  __NFTA_REJECT_MAX
};
#define NFTA_REJECT_MAX (__NFTA_REJECT_MAX - 1)
enum nft_nat_types {
  NFT_NAT_SNAT,
  NFT_NAT_DNAT,
};
enum nft_nat_attributes {
  NFTA_NAT_UNSPEC,
  NFTA_NAT_TYPE,
  NFTA_NAT_FAMILY,
  NFTA_NAT_REG_ADDR_MIN,
  NFTA_NAT_REG_ADDR_MAX,
  NFTA_NAT_REG_PROTO_MIN,
  NFTA_NAT_REG_PROTO_MAX,
  NFTA_NAT_FLAGS,
  __NFTA_NAT_MAX
};
#define NFTA_NAT_MAX (__NFTA_NAT_MAX - 1)
enum nft_tproxy_attributes {
  NFTA_TPROXY_UNSPEC,
  NFTA_TPROXY_FAMILY,
  NFTA_TPROXY_REG_ADDR,
  NFTA_TPROXY_REG_PORT,
  __NFTA_TPROXY_MAX
};
#define NFTA_TPROXY_MAX (__NFTA_TPROXY_MAX - 1)
enum nft_masq_attributes {
  NFTA_MASQ_UNSPEC,
  NFTA_MASQ_FLAGS,
  NFTA_MASQ_REG_PROTO_MIN,
  NFTA_MASQ_REG_PROTO_MAX,
  __NFTA_MASQ_MAX
};
#define NFTA_MASQ_MAX (__NFTA_MASQ_MAX - 1)
enum nft_redir_attributes {
  NFTA_REDIR_UNSPEC,
  NFTA_REDIR_REG_PROTO_MIN,
  NFTA_REDIR_REG_PROTO_MAX,
  NFTA_REDIR_FLAGS,
  __NFTA_REDIR_MAX
};
#define NFTA_REDIR_MAX (__NFTA_REDIR_MAX - 1)
enum nft_dup_attributes {
  NFTA_DUP_UNSPEC,
  NFTA_DUP_SREG_ADDR,
  NFTA_DUP_SREG_DEV,
  __NFTA_DUP_MAX
};
#define NFTA_DUP_MAX (__NFTA_DUP_MAX - 1)
enum nft_fwd_attributes {
  NFTA_FWD_UNSPEC,
  NFTA_FWD_SREG_DEV,
  NFTA_FWD_SREG_ADDR,
  NFTA_FWD_NFPROTO,
  __NFTA_FWD_MAX
};
#define NFTA_FWD_MAX (__NFTA_FWD_MAX - 1)
enum nft_objref_attributes {
  NFTA_OBJREF_UNSPEC,
  NFTA_OBJREF_IMM_TYPE,
  NFTA_OBJREF_IMM_NAME,
  NFTA_OBJREF_SET_SREG,
  NFTA_OBJREF_SET_NAME,
  NFTA_OBJREF_SET_ID,
  __NFTA_OBJREF_MAX
};
#define NFTA_OBJREF_MAX (__NFTA_OBJREF_MAX - 1)
enum nft_gen_attributes {
  NFTA_GEN_UNSPEC,
  NFTA_GEN_ID,
  NFTA_GEN_PROC_PID,
  NFTA_GEN_PROC_NAME,
  __NFTA_GEN_MAX
};
#define NFTA_GEN_MAX (__NFTA_GEN_MAX - 1)
enum nft_fib_attributes {
  NFTA_FIB_UNSPEC,
  NFTA_FIB_DREG,
  NFTA_FIB_RESULT,
  NFTA_FIB_FLAGS,
  __NFTA_FIB_MAX
};
#define NFTA_FIB_MAX (__NFTA_FIB_MAX - 1)
enum nft_fib_result {
  NFT_FIB_RESULT_UNSPEC,
  NFT_FIB_RESULT_OIF,
  NFT_FIB_RESULT_OIFNAME,
  NFT_FIB_RESULT_ADDRTYPE,
  __NFT_FIB_RESULT_MAX
};
#define NFT_FIB_RESULT_MAX (__NFT_FIB_RESULT_MAX - 1)
enum nft_fib_flags {
  NFTA_FIB_F_SADDR = 1 << 0,
  NFTA_FIB_F_DADDR = 1 << 1,
  NFTA_FIB_F_MARK = 1 << 2,
  NFTA_FIB_F_IIF = 1 << 3,
  NFTA_FIB_F_OIF = 1 << 4,
  NFTA_FIB_F_PRESENT = 1 << 5,
};
enum nft_ct_helper_attributes {
  NFTA_CT_HELPER_UNSPEC,
  NFTA_CT_HELPER_NAME,
  NFTA_CT_HELPER_L3PROTO,
  NFTA_CT_HELPER_L4PROTO,
  __NFTA_CT_HELPER_MAX,
};
#define NFTA_CT_HELPER_MAX (__NFTA_CT_HELPER_MAX - 1)
enum nft_ct_timeout_timeout_attributes {
  NFTA_CT_TIMEOUT_UNSPEC,
  NFTA_CT_TIMEOUT_L3PROTO,
  NFTA_CT_TIMEOUT_L4PROTO,
  NFTA_CT_TIMEOUT_DATA,
  __NFTA_CT_TIMEOUT_MAX,
};
#define NFTA_CT_TIMEOUT_MAX (__NFTA_CT_TIMEOUT_MAX - 1)
#define NFT_OBJECT_UNSPEC 0
#define NFT_OBJECT_COUNTER 1
#define NFT_OBJECT_QUOTA 2
#define NFT_OBJECT_CT_HELPER 3
#define NFT_OBJECT_LIMIT 4
#define NFT_OBJECT_CONNLIMIT 5
#define NFT_OBJECT_TUNNEL 6
#define NFT_OBJECT_CT_TIMEOUT 7
#define NFT_OBJECT_SECMARK 8
#define __NFT_OBJECT_MAX 9
#define NFT_OBJECT_MAX (__NFT_OBJECT_MAX - 1)
enum nft_object_attributes {
  NFTA_OBJ_UNSPEC,
  NFTA_OBJ_TABLE,
  NFTA_OBJ_NAME,
  NFTA_OBJ_TYPE,
  NFTA_OBJ_DATA,
  NFTA_OBJ_USE,
  NFTA_OBJ_HANDLE,
  NFTA_OBJ_PAD,
  __NFTA_OBJ_MAX
};
#define NFTA_OBJ_MAX (__NFTA_OBJ_MAX - 1)
enum nft_flowtable_attributes {
  NFTA_FLOWTABLE_UNSPEC,
  NFTA_FLOWTABLE_TABLE,
  NFTA_FLOWTABLE_NAME,
  NFTA_FLOWTABLE_HOOK,
  NFTA_FLOWTABLE_USE,
  NFTA_FLOWTABLE_HANDLE,
  NFTA_FLOWTABLE_PAD,
  __NFTA_FLOWTABLE_MAX
};
#define NFTA_FLOWTABLE_MAX (__NFTA_FLOWTABLE_MAX - 1)
enum nft_flowtable_hook_attributes {
  NFTA_FLOWTABLE_HOOK_UNSPEC,
  NFTA_FLOWTABLE_HOOK_NUM,
  NFTA_FLOWTABLE_HOOK_PRIORITY,
  NFTA_FLOWTABLE_HOOK_DEVS,
  __NFTA_FLOWTABLE_HOOK_MAX
};
#define NFTA_FLOWTABLE_HOOK_MAX (__NFTA_FLOWTABLE_HOOK_MAX - 1)
enum nft_osf_attributes {
  NFTA_OSF_UNSPEC,
  NFTA_OSF_DREG,
  NFTA_OSF_TTL,
  __NFTA_OSF_MAX,
};
#define NFTA_OSF_MAX (__NFTA_OSF_MAX - 1)
enum nft_devices_attributes {
  NFTA_DEVICE_UNSPEC,
  NFTA_DEVICE_NAME,
  __NFTA_DEVICE_MAX
};
#define NFTA_DEVICE_MAX (__NFTA_DEVICE_MAX - 1)
enum nft_xfrm_attributes {
  NFTA_XFRM_UNSPEC,
  NFTA_XFRM_DREG,
  NFTA_XFRM_KEY,
  NFTA_XFRM_DIR,
  NFTA_XFRM_SPNUM,
  __NFTA_XFRM_MAX
};
#define NFTA_XFRM_MAX (__NFTA_XFRM_MAX - 1)
enum nft_xfrm_keys {
  NFT_XFRM_KEY_UNSPEC,
  NFT_XFRM_KEY_DADDR_IP4,
  NFT_XFRM_KEY_DADDR_IP6,
  NFT_XFRM_KEY_SADDR_IP4,
  NFT_XFRM_KEY_SADDR_IP6,
  NFT_XFRM_KEY_REQID,
  NFT_XFRM_KEY_SPI,
  __NFT_XFRM_KEY_MAX,
};
#define NFT_XFRM_KEY_MAX (__NFT_XFRM_KEY_MAX - 1)
enum nft_trace_attributes {
  NFTA_TRACE_UNSPEC,
  NFTA_TRACE_TABLE,
  NFTA_TRACE_CHAIN,
  NFTA_TRACE_RULE_HANDLE,
  NFTA_TRACE_TYPE,
  NFTA_TRACE_VERDICT,
  NFTA_TRACE_ID,
  NFTA_TRACE_LL_HEADER,
  NFTA_TRACE_NETWORK_HEADER,
  NFTA_TRACE_TRANSPORT_HEADER,
  NFTA_TRACE_IIF,
  NFTA_TRACE_IIFTYPE,
  NFTA_TRACE_OIF,
  NFTA_TRACE_OIFTYPE,
  NFTA_TRACE_MARK,
  NFTA_TRACE_NFPROTO,
  NFTA_TRACE_POLICY,
  NFTA_TRACE_PAD,
  __NFTA_TRACE_MAX
};
#define NFTA_TRACE_MAX (__NFTA_TRACE_MAX - 1)
enum nft_trace_types {
  NFT_TRACETYPE_UNSPEC,
  NFT_TRACETYPE_POLICY,
  NFT_TRACETYPE_RETURN,
  NFT_TRACETYPE_RULE,
  __NFT_TRACETYPE_MAX
};
#define NFT_TRACETYPE_MAX (__NFT_TRACETYPE_MAX - 1)
enum nft_ng_attributes {
  NFTA_NG_UNSPEC,
  NFTA_NG_DREG,
  NFTA_NG_MODULUS,
  NFTA_NG_TYPE,
  NFTA_NG_OFFSET,
  NFTA_NG_SET_NAME,
  NFTA_NG_SET_ID,
  __NFTA_NG_MAX
};
#define NFTA_NG_MAX (__NFTA_NG_MAX - 1)
enum nft_ng_types {
  NFT_NG_INCREMENTAL,
  NFT_NG_RANDOM,
  __NFT_NG_MAX
};
#define NFT_NG_MAX (__NFT_NG_MAX - 1)
enum nft_tunnel_key_ip_attributes {
  NFTA_TUNNEL_KEY_IP_UNSPEC,
  NFTA_TUNNEL_KEY_IP_SRC,
  NFTA_TUNNEL_KEY_IP_DST,
  __NFTA_TUNNEL_KEY_IP_MAX
};
#define NFTA_TUNNEL_KEY_IP_MAX (__NFTA_TUNNEL_KEY_IP_MAX - 1)
enum nft_tunnel_ip6_attributes {
  NFTA_TUNNEL_KEY_IP6_UNSPEC,
  NFTA_TUNNEL_KEY_IP6_SRC,
  NFTA_TUNNEL_KEY_IP6_DST,
  NFTA_TUNNEL_KEY_IP6_FLOWLABEL,
  __NFTA_TUNNEL_KEY_IP6_MAX
};
#define NFTA_TUNNEL_KEY_IP6_MAX (__NFTA_TUNNEL_KEY_IP6_MAX - 1)
enum nft_tunnel_opts_attributes {
  NFTA_TUNNEL_KEY_OPTS_UNSPEC,
  NFTA_TUNNEL_KEY_OPTS_VXLAN,
  NFTA_TUNNEL_KEY_OPTS_ERSPAN,
  __NFTA_TUNNEL_KEY_OPTS_MAX
};
#define NFTA_TUNNEL_KEY_OPTS_MAX (__NFTA_TUNNEL_KEY_OPTS_MAX - 1)
enum nft_tunnel_opts_vxlan_attributes {
  NFTA_TUNNEL_KEY_VXLAN_UNSPEC,
  NFTA_TUNNEL_KEY_VXLAN_GBP,
  __NFTA_TUNNEL_KEY_VXLAN_MAX
};
#define NFTA_TUNNEL_KEY_VXLAN_MAX (__NFTA_TUNNEL_KEY_VXLAN_MAX - 1)
enum nft_tunnel_opts_erspan_attributes {
  NFTA_TUNNEL_KEY_ERSPAN_UNSPEC,
  NFTA_TUNNEL_KEY_ERSPAN_VERSION,
  NFTA_TUNNEL_KEY_ERSPAN_V1_INDEX,
  NFTA_TUNNEL_KEY_ERSPAN_V2_HWID,
  NFTA_TUNNEL_KEY_ERSPAN_V2_DIR,
  __NFTA_TUNNEL_KEY_ERSPAN_MAX
};
#define NFTA_TUNNEL_KEY_ERSPAN_MAX (__NFTA_TUNNEL_KEY_ERSPAN_MAX - 1)
enum nft_tunnel_flags {
  NFT_TUNNEL_F_ZERO_CSUM_TX = (1 << 0),
  NFT_TUNNEL_F_DONT_FRAGMENT = (1 << 1),
  NFT_TUNNEL_F_SEQ_NUMBER = (1 << 2),
};
#define NFT_TUNNEL_F_MASK (NFT_TUNNEL_F_ZERO_CSUM_TX | NFT_TUNNEL_F_DONT_FRAGMENT | NFT_TUNNEL_F_SEQ_NUMBER)
enum nft_tunnel_key_attributes {
  NFTA_TUNNEL_KEY_UNSPEC,
  NFTA_TUNNEL_KEY_ID,
  NFTA_TUNNEL_KEY_IP,
  NFTA_TUNNEL_KEY_IP6,
  NFTA_TUNNEL_KEY_FLAGS,
  NFTA_TUNNEL_KEY_TOS,
  NFTA_TUNNEL_KEY_TTL,
  NFTA_TUNNEL_KEY_SPORT,
  NFTA_TUNNEL_KEY_DPORT,
  NFTA_TUNNEL_KEY_OPTS,
  __NFTA_TUNNEL_KEY_MAX
};
#define NFTA_TUNNEL_KEY_MAX (__NFTA_TUNNEL_KEY_MAX - 1)
enum nft_tunnel_keys {
  NFT_TUNNEL_PATH,
  NFT_TUNNEL_ID,
  __NFT_TUNNEL_MAX
};
#define NFT_TUNNEL_MAX (__NFT_TUNNEL_MAX - 1)
enum nft_tunnel_attributes {
  NFTA_TUNNEL_UNSPEC,
  NFTA_TUNNEL_KEY,
  NFTA_TUNNEL_DREG,
  __NFTA_TUNNEL_MAX
};
#define NFTA_TUNNEL_MAX (__NFTA_TUNNEL_MAX - 1)
#endif
