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
#define NFT_CHAIN_MAXNAMELEN 32
#define NFT_USERDATA_MAXLEN 256
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
enum nft_registers {
  NFT_REG_VERDICT,
  NFT_REG_1,
  NFT_REG_2,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFT_REG_3,
  NFT_REG_4,
  __NFT_REG_MAX
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define NFT_REG_MAX (__NFT_REG_MAX - 1)
enum nft_verdicts {
  NFT_CONTINUE = - 1,
  NFT_BREAK = - 2,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFT_JUMP = - 3,
  NFT_GOTO = - 4,
  NFT_RETURN = - 5,
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
enum nf_tables_msg_types {
  NFT_MSG_NEWTABLE,
  NFT_MSG_GETTABLE,
  NFT_MSG_DELTABLE,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFT_MSG_NEWCHAIN,
  NFT_MSG_GETCHAIN,
  NFT_MSG_DELCHAIN,
  NFT_MSG_NEWRULE,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFT_MSG_GETRULE,
  NFT_MSG_DELRULE,
  NFT_MSG_NEWSET,
  NFT_MSG_GETSET,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFT_MSG_DELSET,
  NFT_MSG_NEWSETELEM,
  NFT_MSG_GETSETELEM,
  NFT_MSG_DELSETELEM,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFT_MSG_NEWGEN,
  NFT_MSG_GETGEN,
  NFT_MSG_MAX,
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
enum nft_list_attributes {
  NFTA_LIST_UNPEC,
  NFTA_LIST_ELEM,
  __NFTA_LIST_MAX
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
#define NFTA_LIST_MAX (__NFTA_LIST_MAX - 1)
enum nft_hook_attributes {
  NFTA_HOOK_UNSPEC,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFTA_HOOK_HOOKNUM,
  NFTA_HOOK_PRIORITY,
  __NFTA_HOOK_MAX
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define NFTA_HOOK_MAX (__NFTA_HOOK_MAX - 1)
enum nft_table_flags {
  NFT_TABLE_F_DORMANT = 0x1,
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
enum nft_table_attributes {
  NFTA_TABLE_UNSPEC,
  NFTA_TABLE_NAME,
  NFTA_TABLE_FLAGS,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFTA_TABLE_USE,
  __NFTA_TABLE_MAX
};
#define NFTA_TABLE_MAX (__NFTA_TABLE_MAX - 1)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
enum nft_chain_attributes {
  NFTA_CHAIN_UNSPEC,
  NFTA_CHAIN_TABLE,
  NFTA_CHAIN_HANDLE,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFTA_CHAIN_NAME,
  NFTA_CHAIN_HOOK,
  NFTA_CHAIN_POLICY,
  NFTA_CHAIN_USE,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFTA_CHAIN_TYPE,
  NFTA_CHAIN_COUNTERS,
  __NFTA_CHAIN_MAX
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define NFTA_CHAIN_MAX (__NFTA_CHAIN_MAX - 1)
enum nft_rule_attributes {
  NFTA_RULE_UNSPEC,
  NFTA_RULE_TABLE,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFTA_RULE_CHAIN,
  NFTA_RULE_HANDLE,
  NFTA_RULE_EXPRESSIONS,
  NFTA_RULE_COMPAT,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFTA_RULE_POSITION,
  NFTA_RULE_USERDATA,
  __NFTA_RULE_MAX
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define NFTA_RULE_MAX (__NFTA_RULE_MAX - 1)
enum nft_rule_compat_flags {
  NFT_RULE_COMPAT_F_INV = (1 << 1),
  NFT_RULE_COMPAT_F_MASK = NFT_RULE_COMPAT_F_INV,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
enum nft_rule_compat_attributes {
  NFTA_RULE_COMPAT_UNSPEC,
  NFTA_RULE_COMPAT_PROTO,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFTA_RULE_COMPAT_FLAGS,
  __NFTA_RULE_COMPAT_MAX
};
#define NFTA_RULE_COMPAT_MAX (__NFTA_RULE_COMPAT_MAX - 1)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
enum nft_set_flags {
  NFT_SET_ANONYMOUS = 0x1,
  NFT_SET_CONSTANT = 0x2,
  NFT_SET_INTERVAL = 0x4,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFT_SET_MAP = 0x8,
};
enum nft_set_policies {
  NFT_SET_POL_PERFORMANCE,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFT_SET_POL_MEMORY,
};
enum nft_set_desc_attributes {
  NFTA_SET_DESC_UNSPEC,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFTA_SET_DESC_SIZE,
  __NFTA_SET_DESC_MAX
};
#define NFTA_SET_DESC_MAX (__NFTA_SET_DESC_MAX - 1)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
enum nft_set_attributes {
  NFTA_SET_UNSPEC,
  NFTA_SET_TABLE,
  NFTA_SET_NAME,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFTA_SET_FLAGS,
  NFTA_SET_KEY_TYPE,
  NFTA_SET_KEY_LEN,
  NFTA_SET_DATA_TYPE,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFTA_SET_DATA_LEN,
  NFTA_SET_POLICY,
  NFTA_SET_DESC,
  NFTA_SET_ID,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __NFTA_SET_MAX
};
#define NFTA_SET_MAX (__NFTA_SET_MAX - 1)
enum nft_set_elem_flags {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFT_SET_ELEM_INTERVAL_END = 0x1,
};
enum nft_set_elem_attributes {
  NFTA_SET_ELEM_UNSPEC,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFTA_SET_ELEM_KEY,
  NFTA_SET_ELEM_DATA,
  NFTA_SET_ELEM_FLAGS,
  __NFTA_SET_ELEM_MAX
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
#define NFTA_SET_ELEM_MAX (__NFTA_SET_ELEM_MAX - 1)
enum nft_set_elem_list_attributes {
  NFTA_SET_ELEM_LIST_UNSPEC,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFTA_SET_ELEM_LIST_TABLE,
  NFTA_SET_ELEM_LIST_SET,
  NFTA_SET_ELEM_LIST_ELEMENTS,
  NFTA_SET_ELEM_LIST_SET_ID,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __NFTA_SET_ELEM_LIST_MAX
};
#define NFTA_SET_ELEM_LIST_MAX (__NFTA_SET_ELEM_LIST_MAX - 1)
enum nft_data_types {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFT_DATA_VALUE,
  NFT_DATA_VERDICT = 0xffffff00U,
};
#define NFT_DATA_RESERVED_MASK 0xffffff00U
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
enum nft_data_attributes {
  NFTA_DATA_UNSPEC,
  NFTA_DATA_VALUE,
  NFTA_DATA_VERDICT,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __NFTA_DATA_MAX
};
#define NFTA_DATA_MAX (__NFTA_DATA_MAX - 1)
enum nft_verdict_attributes {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFTA_VERDICT_UNSPEC,
  NFTA_VERDICT_CODE,
  NFTA_VERDICT_CHAIN,
  __NFTA_VERDICT_MAX
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
#define NFTA_VERDICT_MAX (__NFTA_VERDICT_MAX - 1)
enum nft_expr_attributes {
  NFTA_EXPR_UNSPEC,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFTA_EXPR_NAME,
  NFTA_EXPR_DATA,
  __NFTA_EXPR_MAX
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define NFTA_EXPR_MAX (__NFTA_EXPR_MAX - 1)
enum nft_immediate_attributes {
  NFTA_IMMEDIATE_UNSPEC,
  NFTA_IMMEDIATE_DREG,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFTA_IMMEDIATE_DATA,
  __NFTA_IMMEDIATE_MAX
};
#define NFTA_IMMEDIATE_MAX (__NFTA_IMMEDIATE_MAX - 1)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
enum nft_bitwise_attributes {
  NFTA_BITWISE_UNSPEC,
  NFTA_BITWISE_SREG,
  NFTA_BITWISE_DREG,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFTA_BITWISE_LEN,
  NFTA_BITWISE_MASK,
  NFTA_BITWISE_XOR,
  __NFTA_BITWISE_MAX
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
#define NFTA_BITWISE_MAX (__NFTA_BITWISE_MAX - 1)
enum nft_byteorder_ops {
  NFT_BYTEORDER_NTOH,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFT_BYTEORDER_HTON,
};
enum nft_byteorder_attributes {
  NFTA_BYTEORDER_UNSPEC,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFTA_BYTEORDER_SREG,
  NFTA_BYTEORDER_DREG,
  NFTA_BYTEORDER_OP,
  NFTA_BYTEORDER_LEN,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFTA_BYTEORDER_SIZE,
  __NFTA_BYTEORDER_MAX
};
#define NFTA_BYTEORDER_MAX (__NFTA_BYTEORDER_MAX - 1)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
enum nft_cmp_ops {
  NFT_CMP_EQ,
  NFT_CMP_NEQ,
  NFT_CMP_LT,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFT_CMP_LTE,
  NFT_CMP_GT,
  NFT_CMP_GTE,
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
enum nft_cmp_attributes {
  NFTA_CMP_UNSPEC,
  NFTA_CMP_SREG,
  NFTA_CMP_OP,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFTA_CMP_DATA,
  __NFTA_CMP_MAX
};
#define NFTA_CMP_MAX (__NFTA_CMP_MAX - 1)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
enum nft_lookup_attributes {
  NFTA_LOOKUP_UNSPEC,
  NFTA_LOOKUP_SET,
  NFTA_LOOKUP_SREG,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFTA_LOOKUP_DREG,
  NFTA_LOOKUP_SET_ID,
  __NFTA_LOOKUP_MAX
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define NFTA_LOOKUP_MAX (__NFTA_LOOKUP_MAX - 1)
enum nft_payload_bases {
  NFT_PAYLOAD_LL_HEADER,
  NFT_PAYLOAD_NETWORK_HEADER,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFT_PAYLOAD_TRANSPORT_HEADER,
};
enum nft_payload_attributes {
  NFTA_PAYLOAD_UNSPEC,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFTA_PAYLOAD_DREG,
  NFTA_PAYLOAD_BASE,
  NFTA_PAYLOAD_OFFSET,
  NFTA_PAYLOAD_LEN,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __NFTA_PAYLOAD_MAX
};
#define NFTA_PAYLOAD_MAX (__NFTA_PAYLOAD_MAX - 1)
enum nft_exthdr_attributes {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFTA_EXTHDR_UNSPEC,
  NFTA_EXTHDR_DREG,
  NFTA_EXTHDR_TYPE,
  NFTA_EXTHDR_OFFSET,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFTA_EXTHDR_LEN,
  __NFTA_EXTHDR_MAX
};
#define NFTA_EXTHDR_MAX (__NFTA_EXTHDR_MAX - 1)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
enum nft_meta_keys {
  NFT_META_LEN,
  NFT_META_PROTOCOL,
  NFT_META_PRIORITY,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFT_META_MARK,
  NFT_META_IIF,
  NFT_META_OIF,
  NFT_META_IIFNAME,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFT_META_OIFNAME,
  NFT_META_IIFTYPE,
  NFT_META_OIFTYPE,
  NFT_META_SKUID,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFT_META_SKGID,
  NFT_META_NFTRACE,
  NFT_META_RTCLASSID,
  NFT_META_SECMARK,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFT_META_NFPROTO,
  NFT_META_L4PROTO,
  NFT_META_BRI_IIFNAME,
  NFT_META_BRI_OIFNAME,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFT_META_PKTTYPE,
  NFT_META_CPU,
  NFT_META_IIFGROUP,
  NFT_META_OIFGROUP,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
enum nft_meta_attributes {
  NFTA_META_UNSPEC,
  NFTA_META_DREG,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFTA_META_KEY,
  NFTA_META_SREG,
  __NFTA_META_MAX
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define NFTA_META_MAX (__NFTA_META_MAX - 1)
enum nft_ct_keys {
  NFT_CT_STATE,
  NFT_CT_DIRECTION,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFT_CT_STATUS,
  NFT_CT_MARK,
  NFT_CT_SECMARK,
  NFT_CT_EXPIRATION,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFT_CT_HELPER,
  NFT_CT_L3PROTOCOL,
  NFT_CT_SRC,
  NFT_CT_DST,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFT_CT_PROTOCOL,
  NFT_CT_PROTO_SRC,
  NFT_CT_PROTO_DST,
  NFT_CT_LABELS,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
enum nft_ct_attributes {
  NFTA_CT_UNSPEC,
  NFTA_CT_DREG,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFTA_CT_KEY,
  NFTA_CT_DIRECTION,
  NFTA_CT_SREG,
  __NFTA_CT_MAX
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
#define NFTA_CT_MAX (__NFTA_CT_MAX - 1)
enum nft_limit_attributes {
  NFTA_LIMIT_UNSPEC,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFTA_LIMIT_RATE,
  NFTA_LIMIT_UNIT,
  __NFTA_LIMIT_MAX
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define NFTA_LIMIT_MAX (__NFTA_LIMIT_MAX - 1)
enum nft_counter_attributes {
  NFTA_COUNTER_UNSPEC,
  NFTA_COUNTER_BYTES,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFTA_COUNTER_PACKETS,
  __NFTA_COUNTER_MAX
};
#define NFTA_COUNTER_MAX (__NFTA_COUNTER_MAX - 1)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
enum nft_log_attributes {
  NFTA_LOG_UNSPEC,
  NFTA_LOG_GROUP,
  NFTA_LOG_PREFIX,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFTA_LOG_SNAPLEN,
  NFTA_LOG_QTHRESHOLD,
  NFTA_LOG_LEVEL,
  NFTA_LOG_FLAGS,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __NFTA_LOG_MAX
};
#define NFTA_LOG_MAX (__NFTA_LOG_MAX - 1)
enum nft_queue_attributes {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFTA_QUEUE_UNSPEC,
  NFTA_QUEUE_NUM,
  NFTA_QUEUE_TOTAL,
  NFTA_QUEUE_FLAGS,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __NFTA_QUEUE_MAX
};
#define NFTA_QUEUE_MAX (__NFTA_QUEUE_MAX - 1)
#define NFT_QUEUE_FLAG_BYPASS 0x01
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define NFT_QUEUE_FLAG_CPU_FANOUT 0x02
#define NFT_QUEUE_FLAG_MASK 0x03
enum nft_reject_types {
  NFT_REJECT_ICMP_UNREACH,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFT_REJECT_TCP_RST,
  NFT_REJECT_ICMPX_UNREACH,
};
enum nft_reject_inet_code {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFT_REJECT_ICMPX_NO_ROUTE = 0,
  NFT_REJECT_ICMPX_PORT_UNREACH,
  NFT_REJECT_ICMPX_HOST_UNREACH,
  NFT_REJECT_ICMPX_ADMIN_PROHIBITED,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __NFT_REJECT_ICMPX_MAX
};
#define NFT_REJECT_ICMPX_MAX (__NFT_REJECT_ICMPX_MAX - 1)
enum nft_reject_attributes {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFTA_REJECT_UNSPEC,
  NFTA_REJECT_TYPE,
  NFTA_REJECT_ICMP_CODE,
  __NFTA_REJECT_MAX
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
#define NFTA_REJECT_MAX (__NFTA_REJECT_MAX - 1)
enum nft_nat_types {
  NFT_NAT_SNAT,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFT_NAT_DNAT,
};
enum nft_nat_attributes {
  NFTA_NAT_UNSPEC,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFTA_NAT_TYPE,
  NFTA_NAT_FAMILY,
  NFTA_NAT_REG_ADDR_MIN,
  NFTA_NAT_REG_ADDR_MAX,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFTA_NAT_REG_PROTO_MIN,
  NFTA_NAT_REG_PROTO_MAX,
  NFTA_NAT_FLAGS,
  __NFTA_NAT_MAX
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
#define NFTA_NAT_MAX (__NFTA_NAT_MAX - 1)
enum nft_masq_attributes {
  NFTA_MASQ_UNSPEC,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFTA_MASQ_FLAGS,
  __NFTA_MASQ_MAX
};
#define NFTA_MASQ_MAX (__NFTA_MASQ_MAX - 1)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
enum nft_gen_attributes {
  NFTA_GEN_UNSPEC,
  NFTA_GEN_ID,
  __NFTA_GEN_MAX
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
#define NFTA_GEN_MAX (__NFTA_GEN_MAX - 1)
#endif
