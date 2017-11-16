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
#ifndef _UAPI_LINUX_DEVLINK_H_
#define _UAPI_LINUX_DEVLINK_H_
#define DEVLINK_GENL_NAME "devlink"
#define DEVLINK_GENL_VERSION 0x1
#define DEVLINK_GENL_MCGRP_CONFIG_NAME "config"
enum devlink_command {
  DEVLINK_CMD_UNSPEC,
  DEVLINK_CMD_GET,
  DEVLINK_CMD_SET,
  DEVLINK_CMD_NEW,
  DEVLINK_CMD_DEL,
  DEVLINK_CMD_PORT_GET,
  DEVLINK_CMD_PORT_SET,
  DEVLINK_CMD_PORT_NEW,
  DEVLINK_CMD_PORT_DEL,
  DEVLINK_CMD_PORT_SPLIT,
  DEVLINK_CMD_PORT_UNSPLIT,
  DEVLINK_CMD_SB_GET,
  DEVLINK_CMD_SB_SET,
  DEVLINK_CMD_SB_NEW,
  DEVLINK_CMD_SB_DEL,
  DEVLINK_CMD_SB_POOL_GET,
  DEVLINK_CMD_SB_POOL_SET,
  DEVLINK_CMD_SB_POOL_NEW,
  DEVLINK_CMD_SB_POOL_DEL,
  DEVLINK_CMD_SB_PORT_POOL_GET,
  DEVLINK_CMD_SB_PORT_POOL_SET,
  DEVLINK_CMD_SB_PORT_POOL_NEW,
  DEVLINK_CMD_SB_PORT_POOL_DEL,
  DEVLINK_CMD_SB_TC_POOL_BIND_GET,
  DEVLINK_CMD_SB_TC_POOL_BIND_SET,
  DEVLINK_CMD_SB_TC_POOL_BIND_NEW,
  DEVLINK_CMD_SB_TC_POOL_BIND_DEL,
  DEVLINK_CMD_SB_OCC_SNAPSHOT,
  DEVLINK_CMD_SB_OCC_MAX_CLEAR,
  DEVLINK_CMD_ESWITCH_GET,
#define DEVLINK_CMD_ESWITCH_MODE_GET DEVLINK_CMD_ESWITCH_GET
  DEVLINK_CMD_ESWITCH_SET,
#define DEVLINK_CMD_ESWITCH_MODE_SET DEVLINK_CMD_ESWITCH_SET
  DEVLINK_CMD_DPIPE_TABLE_GET,
  DEVLINK_CMD_DPIPE_ENTRIES_GET,
  DEVLINK_CMD_DPIPE_HEADERS_GET,
  DEVLINK_CMD_DPIPE_TABLE_COUNTERS_SET,
  __DEVLINK_CMD_MAX,
  DEVLINK_CMD_MAX = __DEVLINK_CMD_MAX - 1
};
enum devlink_port_type {
  DEVLINK_PORT_TYPE_NOTSET,
  DEVLINK_PORT_TYPE_AUTO,
  DEVLINK_PORT_TYPE_ETH,
  DEVLINK_PORT_TYPE_IB,
};
enum devlink_sb_pool_type {
  DEVLINK_SB_POOL_TYPE_INGRESS,
  DEVLINK_SB_POOL_TYPE_EGRESS,
};
enum devlink_sb_threshold_type {
  DEVLINK_SB_THRESHOLD_TYPE_STATIC,
  DEVLINK_SB_THRESHOLD_TYPE_DYNAMIC,
};
#define DEVLINK_SB_THRESHOLD_TO_ALPHA_MAX 20
enum devlink_eswitch_mode {
  DEVLINK_ESWITCH_MODE_LEGACY,
  DEVLINK_ESWITCH_MODE_SWITCHDEV,
};
enum devlink_eswitch_inline_mode {
  DEVLINK_ESWITCH_INLINE_MODE_NONE,
  DEVLINK_ESWITCH_INLINE_MODE_LINK,
  DEVLINK_ESWITCH_INLINE_MODE_NETWORK,
  DEVLINK_ESWITCH_INLINE_MODE_TRANSPORT,
};
enum devlink_eswitch_encap_mode {
  DEVLINK_ESWITCH_ENCAP_MODE_NONE,
  DEVLINK_ESWITCH_ENCAP_MODE_BASIC,
};
enum devlink_attr {
  DEVLINK_ATTR_UNSPEC,
  DEVLINK_ATTR_BUS_NAME,
  DEVLINK_ATTR_DEV_NAME,
  DEVLINK_ATTR_PORT_INDEX,
  DEVLINK_ATTR_PORT_TYPE,
  DEVLINK_ATTR_PORT_DESIRED_TYPE,
  DEVLINK_ATTR_PORT_NETDEV_IFINDEX,
  DEVLINK_ATTR_PORT_NETDEV_NAME,
  DEVLINK_ATTR_PORT_IBDEV_NAME,
  DEVLINK_ATTR_PORT_SPLIT_COUNT,
  DEVLINK_ATTR_PORT_SPLIT_GROUP,
  DEVLINK_ATTR_SB_INDEX,
  DEVLINK_ATTR_SB_SIZE,
  DEVLINK_ATTR_SB_INGRESS_POOL_COUNT,
  DEVLINK_ATTR_SB_EGRESS_POOL_COUNT,
  DEVLINK_ATTR_SB_INGRESS_TC_COUNT,
  DEVLINK_ATTR_SB_EGRESS_TC_COUNT,
  DEVLINK_ATTR_SB_POOL_INDEX,
  DEVLINK_ATTR_SB_POOL_TYPE,
  DEVLINK_ATTR_SB_POOL_SIZE,
  DEVLINK_ATTR_SB_POOL_THRESHOLD_TYPE,
  DEVLINK_ATTR_SB_THRESHOLD,
  DEVLINK_ATTR_SB_TC_INDEX,
  DEVLINK_ATTR_SB_OCC_CUR,
  DEVLINK_ATTR_SB_OCC_MAX,
  DEVLINK_ATTR_ESWITCH_MODE,
  DEVLINK_ATTR_ESWITCH_INLINE_MODE,
  DEVLINK_ATTR_DPIPE_TABLES,
  DEVLINK_ATTR_DPIPE_TABLE,
  DEVLINK_ATTR_DPIPE_TABLE_NAME,
  DEVLINK_ATTR_DPIPE_TABLE_SIZE,
  DEVLINK_ATTR_DPIPE_TABLE_MATCHES,
  DEVLINK_ATTR_DPIPE_TABLE_ACTIONS,
  DEVLINK_ATTR_DPIPE_TABLE_COUNTERS_ENABLED,
  DEVLINK_ATTR_DPIPE_ENTRIES,
  DEVLINK_ATTR_DPIPE_ENTRY,
  DEVLINK_ATTR_DPIPE_ENTRY_INDEX,
  DEVLINK_ATTR_DPIPE_ENTRY_MATCH_VALUES,
  DEVLINK_ATTR_DPIPE_ENTRY_ACTION_VALUES,
  DEVLINK_ATTR_DPIPE_ENTRY_COUNTER,
  DEVLINK_ATTR_DPIPE_MATCH,
  DEVLINK_ATTR_DPIPE_MATCH_VALUE,
  DEVLINK_ATTR_DPIPE_MATCH_TYPE,
  DEVLINK_ATTR_DPIPE_ACTION,
  DEVLINK_ATTR_DPIPE_ACTION_VALUE,
  DEVLINK_ATTR_DPIPE_ACTION_TYPE,
  DEVLINK_ATTR_DPIPE_VALUE,
  DEVLINK_ATTR_DPIPE_VALUE_MASK,
  DEVLINK_ATTR_DPIPE_VALUE_MAPPING,
  DEVLINK_ATTR_DPIPE_HEADERS,
  DEVLINK_ATTR_DPIPE_HEADER,
  DEVLINK_ATTR_DPIPE_HEADER_NAME,
  DEVLINK_ATTR_DPIPE_HEADER_ID,
  DEVLINK_ATTR_DPIPE_HEADER_FIELDS,
  DEVLINK_ATTR_DPIPE_HEADER_GLOBAL,
  DEVLINK_ATTR_DPIPE_HEADER_INDEX,
  DEVLINK_ATTR_DPIPE_FIELD,
  DEVLINK_ATTR_DPIPE_FIELD_NAME,
  DEVLINK_ATTR_DPIPE_FIELD_ID,
  DEVLINK_ATTR_DPIPE_FIELD_BITWIDTH,
  DEVLINK_ATTR_DPIPE_FIELD_MAPPING_TYPE,
  DEVLINK_ATTR_PAD,
  DEVLINK_ATTR_ESWITCH_ENCAP_MODE,
  __DEVLINK_ATTR_MAX,
  DEVLINK_ATTR_MAX = __DEVLINK_ATTR_MAX - 1
};
enum devlink_dpipe_field_mapping_type {
  DEVLINK_DPIPE_FIELD_MAPPING_TYPE_NONE,
  DEVLINK_DPIPE_FIELD_MAPPING_TYPE_IFINDEX,
};
enum devlink_dpipe_match_type {
  DEVLINK_DPIPE_MATCH_TYPE_FIELD_EXACT,
};
enum devlink_dpipe_action_type {
  DEVLINK_DPIPE_ACTION_TYPE_FIELD_MODIFY,
};
enum devlink_dpipe_field_ethernet_id {
  DEVLINK_DPIPE_FIELD_ETHERNET_DST_MAC,
};
enum devlink_dpipe_field_ipv4_id {
  DEVLINK_DPIPE_FIELD_IPV4_DST_IP,
};
enum devlink_dpipe_field_ipv6_id {
  DEVLINK_DPIPE_FIELD_IPV6_DST_IP,
};
enum devlink_dpipe_header_id {
  DEVLINK_DPIPE_HEADER_ETHERNET,
  DEVLINK_DPIPE_HEADER_IPV4,
  DEVLINK_DPIPE_HEADER_IPV6,
};
#endif
