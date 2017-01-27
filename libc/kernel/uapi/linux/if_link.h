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
#ifndef _UAPI_LINUX_IF_LINK_H
#define _UAPI_LINUX_IF_LINK_H
#include <linux/types.h>
#include <linux/netlink.h>
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct rtnl_link_stats {
  __u32 rx_packets;
  __u32 tx_packets;
  __u32 rx_bytes;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u32 tx_bytes;
  __u32 rx_errors;
  __u32 tx_errors;
  __u32 rx_dropped;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u32 tx_dropped;
  __u32 multicast;
  __u32 collisions;
  __u32 rx_length_errors;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u32 rx_over_errors;
  __u32 rx_crc_errors;
  __u32 rx_frame_errors;
  __u32 rx_fifo_errors;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u32 rx_missed_errors;
  __u32 tx_aborted_errors;
  __u32 tx_carrier_errors;
  __u32 tx_fifo_errors;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u32 tx_heartbeat_errors;
  __u32 tx_window_errors;
  __u32 rx_compressed;
  __u32 tx_compressed;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u32 rx_nohandler;
};
struct rtnl_link_stats64 {
  __u64 rx_packets;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u64 tx_packets;
  __u64 rx_bytes;
  __u64 tx_bytes;
  __u64 rx_errors;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u64 tx_errors;
  __u64 rx_dropped;
  __u64 tx_dropped;
  __u64 multicast;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u64 collisions;
  __u64 rx_length_errors;
  __u64 rx_over_errors;
  __u64 rx_crc_errors;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u64 rx_frame_errors;
  __u64 rx_fifo_errors;
  __u64 rx_missed_errors;
  __u64 tx_aborted_errors;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u64 tx_carrier_errors;
  __u64 tx_fifo_errors;
  __u64 tx_heartbeat_errors;
  __u64 tx_window_errors;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u64 rx_compressed;
  __u64 tx_compressed;
  __u64 rx_nohandler;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct rtnl_link_ifmap {
  __u64 mem_start;
  __u64 mem_end;
  __u64 base_addr;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u16 irq;
  __u8 dma;
  __u8 port;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
enum {
  IFLA_UNSPEC,
  IFLA_ADDRESS,
  IFLA_BROADCAST,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_IFNAME,
  IFLA_MTU,
  IFLA_LINK,
  IFLA_QDISC,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_STATS,
  IFLA_COST,
#define IFLA_COST IFLA_COST
  IFLA_PRIORITY,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define IFLA_PRIORITY IFLA_PRIORITY
  IFLA_MASTER,
#define IFLA_MASTER IFLA_MASTER
  IFLA_WIRELESS,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define IFLA_WIRELESS IFLA_WIRELESS
  IFLA_PROTINFO,
#define IFLA_PROTINFO IFLA_PROTINFO
  IFLA_TXQLEN,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define IFLA_TXQLEN IFLA_TXQLEN
  IFLA_MAP,
#define IFLA_MAP IFLA_MAP
  IFLA_WEIGHT,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define IFLA_WEIGHT IFLA_WEIGHT
  IFLA_OPERSTATE,
  IFLA_LINKMODE,
  IFLA_LINKINFO,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define IFLA_LINKINFO IFLA_LINKINFO
  IFLA_NET_NS_PID,
  IFLA_IFALIAS,
  IFLA_NUM_VF,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_VFINFO_LIST,
  IFLA_STATS64,
  IFLA_VF_PORTS,
  IFLA_PORT_SELF,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_AF_SPEC,
  IFLA_GROUP,
  IFLA_NET_NS_FD,
  IFLA_EXT_MASK,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_PROMISCUITY,
#define IFLA_PROMISCUITY IFLA_PROMISCUITY
  IFLA_NUM_TX_QUEUES,
  IFLA_NUM_RX_QUEUES,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_CARRIER,
  IFLA_PHYS_PORT_ID,
  IFLA_CARRIER_CHANGES,
  IFLA_PHYS_SWITCH_ID,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_LINK_NETNSID,
  IFLA_PHYS_PORT_NAME,
  IFLA_PROTO_DOWN,
  IFLA_GSO_MAX_SEGS,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_GSO_MAX_SIZE,
  IFLA_PAD,
  IFLA_XDP,
  __IFLA_MAX
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
#define IFLA_MAX (__IFLA_MAX - 1)
#define IFLA_RTA(r) ((struct rtattr *) (((char *) (r)) + NLMSG_ALIGN(sizeof(struct ifinfomsg))))
#define IFLA_PAYLOAD(n) NLMSG_PAYLOAD(n, sizeof(struct ifinfomsg))
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
enum {
  IFLA_INET_UNSPEC,
  IFLA_INET_CONF,
  __IFLA_INET_MAX,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
#define IFLA_INET_MAX (__IFLA_INET_MAX - 1)
enum {
  IFLA_INET6_UNSPEC,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_INET6_FLAGS,
  IFLA_INET6_CONF,
  IFLA_INET6_STATS,
  IFLA_INET6_MCAST,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_INET6_CACHEINFO,
  IFLA_INET6_ICMP6STATS,
  IFLA_INET6_TOKEN,
  IFLA_INET6_ADDR_GEN_MODE,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __IFLA_INET6_MAX
};
#define IFLA_INET6_MAX (__IFLA_INET6_MAX - 1)
enum in6_addr_gen_mode {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IN6_ADDR_GEN_MODE_EUI64,
  IN6_ADDR_GEN_MODE_NONE,
  IN6_ADDR_GEN_MODE_STABLE_PRIVACY,
  IN6_ADDR_GEN_MODE_RANDOM,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
enum {
  IFLA_BR_UNSPEC,
  IFLA_BR_FORWARD_DELAY,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_BR_HELLO_TIME,
  IFLA_BR_MAX_AGE,
  IFLA_BR_AGEING_TIME,
  IFLA_BR_STP_STATE,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_BR_PRIORITY,
  IFLA_BR_VLAN_FILTERING,
  IFLA_BR_VLAN_PROTOCOL,
  IFLA_BR_GROUP_FWD_MASK,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_BR_ROOT_ID,
  IFLA_BR_BRIDGE_ID,
  IFLA_BR_ROOT_PORT,
  IFLA_BR_ROOT_PATH_COST,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_BR_TOPOLOGY_CHANGE,
  IFLA_BR_TOPOLOGY_CHANGE_DETECTED,
  IFLA_BR_HELLO_TIMER,
  IFLA_BR_TCN_TIMER,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_BR_TOPOLOGY_CHANGE_TIMER,
  IFLA_BR_GC_TIMER,
  IFLA_BR_GROUP_ADDR,
  IFLA_BR_FDB_FLUSH,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_BR_MCAST_ROUTER,
  IFLA_BR_MCAST_SNOOPING,
  IFLA_BR_MCAST_QUERY_USE_IFADDR,
  IFLA_BR_MCAST_QUERIER,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_BR_MCAST_HASH_ELASTICITY,
  IFLA_BR_MCAST_HASH_MAX,
  IFLA_BR_MCAST_LAST_MEMBER_CNT,
  IFLA_BR_MCAST_STARTUP_QUERY_CNT,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_BR_MCAST_LAST_MEMBER_INTVL,
  IFLA_BR_MCAST_MEMBERSHIP_INTVL,
  IFLA_BR_MCAST_QUERIER_INTVL,
  IFLA_BR_MCAST_QUERY_INTVL,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_BR_MCAST_QUERY_RESPONSE_INTVL,
  IFLA_BR_MCAST_STARTUP_QUERY_INTVL,
  IFLA_BR_NF_CALL_IPTABLES,
  IFLA_BR_NF_CALL_IP6TABLES,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_BR_NF_CALL_ARPTABLES,
  IFLA_BR_VLAN_DEFAULT_PVID,
  IFLA_BR_PAD,
  IFLA_BR_VLAN_STATS_ENABLED,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_BR_MCAST_STATS_ENABLED,
  __IFLA_BR_MAX,
};
#define IFLA_BR_MAX (__IFLA_BR_MAX - 1)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct ifla_bridge_id {
  __u8 prio[2];
  __u8 addr[6];
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
enum {
  BRIDGE_MODE_UNSPEC,
  BRIDGE_MODE_HAIRPIN,
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
enum {
  IFLA_BRPORT_UNSPEC,
  IFLA_BRPORT_STATE,
  IFLA_BRPORT_PRIORITY,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_BRPORT_COST,
  IFLA_BRPORT_MODE,
  IFLA_BRPORT_GUARD,
  IFLA_BRPORT_PROTECT,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_BRPORT_FAST_LEAVE,
  IFLA_BRPORT_LEARNING,
  IFLA_BRPORT_UNICAST_FLOOD,
  IFLA_BRPORT_PROXYARP,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_BRPORT_LEARNING_SYNC,
  IFLA_BRPORT_PROXYARP_WIFI,
  IFLA_BRPORT_ROOT_ID,
  IFLA_BRPORT_BRIDGE_ID,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_BRPORT_DESIGNATED_PORT,
  IFLA_BRPORT_DESIGNATED_COST,
  IFLA_BRPORT_ID,
  IFLA_BRPORT_NO,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_BRPORT_TOPOLOGY_CHANGE_ACK,
  IFLA_BRPORT_CONFIG_PENDING,
  IFLA_BRPORT_MESSAGE_AGE_TIMER,
  IFLA_BRPORT_FORWARD_DELAY_TIMER,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_BRPORT_HOLD_TIMER,
  IFLA_BRPORT_FLUSH,
  IFLA_BRPORT_MULTICAST_ROUTER,
  IFLA_BRPORT_PAD,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_BRPORT_MCAST_FLOOD,
  __IFLA_BRPORT_MAX
};
#define IFLA_BRPORT_MAX (__IFLA_BRPORT_MAX - 1)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct ifla_cacheinfo {
  __u32 max_reasm_len;
  __u32 tstamp;
  __u32 reachable_time;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u32 retrans_time;
};
enum {
  IFLA_INFO_UNSPEC,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_INFO_KIND,
  IFLA_INFO_DATA,
  IFLA_INFO_XSTATS,
  IFLA_INFO_SLAVE_KIND,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_INFO_SLAVE_DATA,
  __IFLA_INFO_MAX,
};
#define IFLA_INFO_MAX (__IFLA_INFO_MAX - 1)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
enum {
  IFLA_VLAN_UNSPEC,
  IFLA_VLAN_ID,
  IFLA_VLAN_FLAGS,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_VLAN_EGRESS_QOS,
  IFLA_VLAN_INGRESS_QOS,
  IFLA_VLAN_PROTOCOL,
  __IFLA_VLAN_MAX,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
#define IFLA_VLAN_MAX (__IFLA_VLAN_MAX - 1)
struct ifla_vlan_flags {
  __u32 flags;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u32 mask;
};
enum {
  IFLA_VLAN_QOS_UNSPEC,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_VLAN_QOS_MAPPING,
  __IFLA_VLAN_QOS_MAX
};
#define IFLA_VLAN_QOS_MAX (__IFLA_VLAN_QOS_MAX - 1)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct ifla_vlan_qos_mapping {
  __u32 from;
  __u32 to;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
enum {
  IFLA_MACVLAN_UNSPEC,
  IFLA_MACVLAN_MODE,
  IFLA_MACVLAN_FLAGS,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_MACVLAN_MACADDR_MODE,
  IFLA_MACVLAN_MACADDR,
  IFLA_MACVLAN_MACADDR_DATA,
  IFLA_MACVLAN_MACADDR_COUNT,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __IFLA_MACVLAN_MAX,
};
#define IFLA_MACVLAN_MAX (__IFLA_MACVLAN_MAX - 1)
enum macvlan_mode {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  MACVLAN_MODE_PRIVATE = 1,
  MACVLAN_MODE_VEPA = 2,
  MACVLAN_MODE_BRIDGE = 4,
  MACVLAN_MODE_PASSTHRU = 8,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  MACVLAN_MODE_SOURCE = 16,
};
enum macvlan_macaddr_mode {
  MACVLAN_MACADDR_ADD,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  MACVLAN_MACADDR_DEL,
  MACVLAN_MACADDR_FLUSH,
  MACVLAN_MACADDR_SET,
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MACVLAN_FLAG_NOPROMISC 1
enum {
  IFLA_VRF_UNSPEC,
  IFLA_VRF_TABLE,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __IFLA_VRF_MAX
};
#define IFLA_VRF_MAX (__IFLA_VRF_MAX - 1)
enum {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_VRF_PORT_UNSPEC,
  IFLA_VRF_PORT_TABLE,
  __IFLA_VRF_PORT_MAX
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define IFLA_VRF_PORT_MAX (__IFLA_VRF_PORT_MAX - 1)
enum {
  IFLA_MACSEC_UNSPEC,
  IFLA_MACSEC_SCI,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_MACSEC_PORT,
  IFLA_MACSEC_ICV_LEN,
  IFLA_MACSEC_CIPHER_SUITE,
  IFLA_MACSEC_WINDOW,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_MACSEC_ENCODING_SA,
  IFLA_MACSEC_ENCRYPT,
  IFLA_MACSEC_PROTECT,
  IFLA_MACSEC_INC_SCI,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_MACSEC_ES,
  IFLA_MACSEC_SCB,
  IFLA_MACSEC_REPLAY_PROTECT,
  IFLA_MACSEC_VALIDATION,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_MACSEC_PAD,
  __IFLA_MACSEC_MAX,
};
#define IFLA_MACSEC_MAX (__IFLA_MACSEC_MAX - 1)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
enum macsec_validation_type {
  MACSEC_VALIDATE_DISABLED = 0,
  MACSEC_VALIDATE_CHECK = 1,
  MACSEC_VALIDATE_STRICT = 2,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __MACSEC_VALIDATE_END,
  MACSEC_VALIDATE_MAX = __MACSEC_VALIDATE_END - 1,
};
enum {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_IPVLAN_UNSPEC,
  IFLA_IPVLAN_MODE,
  __IFLA_IPVLAN_MAX
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define IFLA_IPVLAN_MAX (__IFLA_IPVLAN_MAX - 1)
enum ipvlan_mode {
  IPVLAN_MODE_L2 = 0,
  IPVLAN_MODE_L3,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IPVLAN_MODE_L3S,
  IPVLAN_MODE_MAX
};
enum {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_VXLAN_UNSPEC,
  IFLA_VXLAN_ID,
  IFLA_VXLAN_GROUP,
  IFLA_VXLAN_LINK,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_VXLAN_LOCAL,
  IFLA_VXLAN_TTL,
  IFLA_VXLAN_TOS,
  IFLA_VXLAN_LEARNING,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_VXLAN_AGEING,
  IFLA_VXLAN_LIMIT,
  IFLA_VXLAN_PORT_RANGE,
  IFLA_VXLAN_PROXY,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_VXLAN_RSC,
  IFLA_VXLAN_L2MISS,
  IFLA_VXLAN_L3MISS,
  IFLA_VXLAN_PORT,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_VXLAN_GROUP6,
  IFLA_VXLAN_LOCAL6,
  IFLA_VXLAN_UDP_CSUM,
  IFLA_VXLAN_UDP_ZERO_CSUM6_TX,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_VXLAN_UDP_ZERO_CSUM6_RX,
  IFLA_VXLAN_REMCSUM_TX,
  IFLA_VXLAN_REMCSUM_RX,
  IFLA_VXLAN_GBP,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_VXLAN_REMCSUM_NOPARTIAL,
  IFLA_VXLAN_COLLECT_METADATA,
  IFLA_VXLAN_LABEL,
  IFLA_VXLAN_GPE,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __IFLA_VXLAN_MAX
};
#define IFLA_VXLAN_MAX (__IFLA_VXLAN_MAX - 1)
struct ifla_vxlan_port_range {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __be16 low;
  __be16 high;
};
enum {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_GENEVE_UNSPEC,
  IFLA_GENEVE_ID,
  IFLA_GENEVE_REMOTE,
  IFLA_GENEVE_TTL,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_GENEVE_TOS,
  IFLA_GENEVE_PORT,
  IFLA_GENEVE_COLLECT_METADATA,
  IFLA_GENEVE_REMOTE6,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_GENEVE_UDP_CSUM,
  IFLA_GENEVE_UDP_ZERO_CSUM6_TX,
  IFLA_GENEVE_UDP_ZERO_CSUM6_RX,
  IFLA_GENEVE_LABEL,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __IFLA_GENEVE_MAX
};
#define IFLA_GENEVE_MAX (__IFLA_GENEVE_MAX - 1)
enum {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_PPP_UNSPEC,
  IFLA_PPP_DEV_FD,
  __IFLA_PPP_MAX
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define IFLA_PPP_MAX (__IFLA_PPP_MAX - 1)
enum {
  IFLA_GTP_UNSPEC,
  IFLA_GTP_FD0,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_GTP_FD1,
  IFLA_GTP_PDP_HASHSIZE,
  __IFLA_GTP_MAX,
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define IFLA_GTP_MAX (__IFLA_GTP_MAX - 1)
enum {
  IFLA_BOND_UNSPEC,
  IFLA_BOND_MODE,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_BOND_ACTIVE_SLAVE,
  IFLA_BOND_MIIMON,
  IFLA_BOND_UPDELAY,
  IFLA_BOND_DOWNDELAY,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_BOND_USE_CARRIER,
  IFLA_BOND_ARP_INTERVAL,
  IFLA_BOND_ARP_IP_TARGET,
  IFLA_BOND_ARP_VALIDATE,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_BOND_ARP_ALL_TARGETS,
  IFLA_BOND_PRIMARY,
  IFLA_BOND_PRIMARY_RESELECT,
  IFLA_BOND_FAIL_OVER_MAC,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_BOND_XMIT_HASH_POLICY,
  IFLA_BOND_RESEND_IGMP,
  IFLA_BOND_NUM_PEER_NOTIF,
  IFLA_BOND_ALL_SLAVES_ACTIVE,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_BOND_MIN_LINKS,
  IFLA_BOND_LP_INTERVAL,
  IFLA_BOND_PACKETS_PER_SLAVE,
  IFLA_BOND_AD_LACP_RATE,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_BOND_AD_SELECT,
  IFLA_BOND_AD_INFO,
  IFLA_BOND_AD_ACTOR_SYS_PRIO,
  IFLA_BOND_AD_USER_PORT_KEY,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_BOND_AD_ACTOR_SYSTEM,
  IFLA_BOND_TLB_DYNAMIC_LB,
  __IFLA_BOND_MAX,
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define IFLA_BOND_MAX (__IFLA_BOND_MAX - 1)
enum {
  IFLA_BOND_AD_INFO_UNSPEC,
  IFLA_BOND_AD_INFO_AGGREGATOR,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_BOND_AD_INFO_NUM_PORTS,
  IFLA_BOND_AD_INFO_ACTOR_KEY,
  IFLA_BOND_AD_INFO_PARTNER_KEY,
  IFLA_BOND_AD_INFO_PARTNER_MAC,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __IFLA_BOND_AD_INFO_MAX,
};
#define IFLA_BOND_AD_INFO_MAX (__IFLA_BOND_AD_INFO_MAX - 1)
enum {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_BOND_SLAVE_UNSPEC,
  IFLA_BOND_SLAVE_STATE,
  IFLA_BOND_SLAVE_MII_STATUS,
  IFLA_BOND_SLAVE_LINK_FAILURE_COUNT,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_BOND_SLAVE_PERM_HWADDR,
  IFLA_BOND_SLAVE_QUEUE_ID,
  IFLA_BOND_SLAVE_AD_AGGREGATOR_ID,
  IFLA_BOND_SLAVE_AD_ACTOR_OPER_PORT_STATE,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_BOND_SLAVE_AD_PARTNER_OPER_PORT_STATE,
  __IFLA_BOND_SLAVE_MAX,
};
#define IFLA_BOND_SLAVE_MAX (__IFLA_BOND_SLAVE_MAX - 1)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
enum {
  IFLA_VF_INFO_UNSPEC,
  IFLA_VF_INFO,
  __IFLA_VF_INFO_MAX,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
#define IFLA_VF_INFO_MAX (__IFLA_VF_INFO_MAX - 1)
enum {
  IFLA_VF_UNSPEC,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_VF_MAC,
  IFLA_VF_VLAN,
  IFLA_VF_TX_RATE,
  IFLA_VF_SPOOFCHK,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_VF_LINK_STATE,
  IFLA_VF_RATE,
  IFLA_VF_RSS_QUERY_EN,
  IFLA_VF_STATS,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_VF_TRUST,
  IFLA_VF_IB_NODE_GUID,
  IFLA_VF_IB_PORT_GUID,
  IFLA_VF_VLAN_LIST,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __IFLA_VF_MAX,
};
#define IFLA_VF_MAX (__IFLA_VF_MAX - 1)
struct ifla_vf_mac {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u32 vf;
  __u8 mac[32];
};
struct ifla_vf_vlan {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u32 vf;
  __u32 vlan;
  __u32 qos;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
enum {
  IFLA_VF_VLAN_INFO_UNSPEC,
  IFLA_VF_VLAN_INFO,
  __IFLA_VF_VLAN_INFO_MAX,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
#define IFLA_VF_VLAN_INFO_MAX (__IFLA_VF_VLAN_INFO_MAX - 1)
#define MAX_VLAN_LIST_LEN 1
struct ifla_vf_vlan_info {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u32 vf;
  __u32 vlan;
  __u32 qos;
  __be16 vlan_proto;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct ifla_vf_tx_rate {
  __u32 vf;
  __u32 rate;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct ifla_vf_rate {
  __u32 vf;
  __u32 min_tx_rate;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u32 max_tx_rate;
};
struct ifla_vf_spoofchk {
  __u32 vf;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u32 setting;
};
struct ifla_vf_guid {
  __u32 vf;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u64 guid;
};
enum {
  IFLA_VF_LINK_STATE_AUTO,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_VF_LINK_STATE_ENABLE,
  IFLA_VF_LINK_STATE_DISABLE,
  __IFLA_VF_LINK_STATE_MAX,
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct ifla_vf_link_state {
  __u32 vf;
  __u32 link_state;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct ifla_vf_rss_query_en {
  __u32 vf;
  __u32 setting;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
enum {
  IFLA_VF_STATS_RX_PACKETS,
  IFLA_VF_STATS_TX_PACKETS,
  IFLA_VF_STATS_RX_BYTES,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_VF_STATS_TX_BYTES,
  IFLA_VF_STATS_BROADCAST,
  IFLA_VF_STATS_MULTICAST,
  IFLA_VF_STATS_PAD,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __IFLA_VF_STATS_MAX,
};
#define IFLA_VF_STATS_MAX (__IFLA_VF_STATS_MAX - 1)
struct ifla_vf_trust {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u32 vf;
  __u32 setting;
};
enum {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_VF_PORT_UNSPEC,
  IFLA_VF_PORT,
  __IFLA_VF_PORT_MAX,
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define IFLA_VF_PORT_MAX (__IFLA_VF_PORT_MAX - 1)
enum {
  IFLA_PORT_UNSPEC,
  IFLA_PORT_VF,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_PORT_PROFILE,
  IFLA_PORT_VSI_TYPE,
  IFLA_PORT_INSTANCE_UUID,
  IFLA_PORT_HOST_UUID,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_PORT_REQUEST,
  IFLA_PORT_RESPONSE,
  __IFLA_PORT_MAX,
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define IFLA_PORT_MAX (__IFLA_PORT_MAX - 1)
#define PORT_PROFILE_MAX 40
#define PORT_UUID_MAX 16
#define PORT_SELF_VF - 1
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
enum {
  PORT_REQUEST_PREASSOCIATE = 0,
  PORT_REQUEST_PREASSOCIATE_RR,
  PORT_REQUEST_ASSOCIATE,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  PORT_REQUEST_DISASSOCIATE,
};
enum {
  PORT_VDP_RESPONSE_SUCCESS = 0,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  PORT_VDP_RESPONSE_INVALID_FORMAT,
  PORT_VDP_RESPONSE_INSUFFICIENT_RESOURCES,
  PORT_VDP_RESPONSE_UNUSED_VTID,
  PORT_VDP_RESPONSE_VTID_VIOLATION,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  PORT_VDP_RESPONSE_VTID_VERSION_VIOALTION,
  PORT_VDP_RESPONSE_OUT_OF_SYNC,
  PORT_PROFILE_RESPONSE_SUCCESS = 0x100,
  PORT_PROFILE_RESPONSE_INPROGRESS,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  PORT_PROFILE_RESPONSE_INVALID,
  PORT_PROFILE_RESPONSE_BADSTATE,
  PORT_PROFILE_RESPONSE_INSUFFICIENT_RESOURCES,
  PORT_PROFILE_RESPONSE_ERROR,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct ifla_port_vsi {
  __u8 vsi_mgr_id;
  __u8 vsi_type_id[3];
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u8 vsi_type_version;
  __u8 pad[3];
};
enum {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_IPOIB_UNSPEC,
  IFLA_IPOIB_PKEY,
  IFLA_IPOIB_MODE,
  IFLA_IPOIB_UMCAST,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __IFLA_IPOIB_MAX
};
enum {
  IPOIB_MODE_DATAGRAM = 0,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IPOIB_MODE_CONNECTED = 1,
};
#define IFLA_IPOIB_MAX (__IFLA_IPOIB_MAX - 1)
enum {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_HSR_UNSPEC,
  IFLA_HSR_SLAVE1,
  IFLA_HSR_SLAVE2,
  IFLA_HSR_MULTICAST_SPEC,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_HSR_SUPERVISION_ADDR,
  IFLA_HSR_SEQ_NR,
  IFLA_HSR_VERSION,
  __IFLA_HSR_MAX,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
#define IFLA_HSR_MAX (__IFLA_HSR_MAX - 1)
struct if_stats_msg {
  __u8 family;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u8 pad1;
  __u16 pad2;
  __u32 ifindex;
  __u32 filter_mask;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
enum {
  IFLA_STATS_UNSPEC,
  IFLA_STATS_LINK_64,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_STATS_LINK_XSTATS,
  IFLA_STATS_LINK_XSTATS_SLAVE,
  IFLA_STATS_LINK_OFFLOAD_XSTATS,
  __IFLA_STATS_MAX,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
#define IFLA_STATS_MAX (__IFLA_STATS_MAX - 1)
#define IFLA_STATS_FILTER_BIT(ATTR) (1 << (ATTR - 1))
enum {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  LINK_XSTATS_TYPE_UNSPEC,
  LINK_XSTATS_TYPE_BRIDGE,
  __LINK_XSTATS_TYPE_MAX
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define LINK_XSTATS_TYPE_MAX (__LINK_XSTATS_TYPE_MAX - 1)
enum {
  IFLA_OFFLOAD_XSTATS_UNSPEC,
  IFLA_OFFLOAD_XSTATS_CPU_HIT,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __IFLA_OFFLOAD_XSTATS_MAX
};
#define IFLA_OFFLOAD_XSTATS_MAX (__IFLA_OFFLOAD_XSTATS_MAX - 1)
enum {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  IFLA_XDP_UNSPEC,
  IFLA_XDP_FD,
  IFLA_XDP_ATTACHED,
  __IFLA_XDP_MAX,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
#define IFLA_XDP_MAX (__IFLA_XDP_MAX - 1)
#endif
