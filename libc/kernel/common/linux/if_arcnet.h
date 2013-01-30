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
#ifndef _LINUX_IF_ARCNET_H
#define _LINUX_IF_ARCNET_H
#include <linux/if_ether.h>
#define ARC_P_IP 212
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define ARC_P_IPV6 196
#define ARC_P_ARP 213
#define ARC_P_RARP 214
#define ARC_P_IPX 250
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define ARC_P_NOVELL_EC 236
#define ARC_P_IP_RFC1051 240
#define ARC_P_ARP_RFC1051 241
#define ARC_P_ETHER 232
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define ARC_P_DATAPOINT_BOOT 0
#define ARC_P_DATAPOINT_MOUNT 1
#define ARC_P_POWERLAN_BEACON 8
#define ARC_P_POWERLAN_BEACON2 243
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define ARC_P_LANSOFT 251
#define ARC_P_ATALK 0xDD
#define ARCNET_ALEN 1
struct arc_rfc1201
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
{
 uint8_t proto;
 uint8_t split_flag;
 uint16_t sequence;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 uint8_t payload[0];
};
#define RFC1201_HDR_SIZE 4
struct arc_rfc1051
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
{
 uint8_t proto;
 uint8_t payload[0];
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define RFC1051_HDR_SIZE 1
struct arc_eth_encap
{
 uint8_t proto;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 struct ethhdr eth;
 uint8_t payload[0];
};
#define ETH_ENCAP_HDR_SIZE 14
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct arc_cap
{
 uint8_t proto;
 uint8_t cookie[sizeof(int)];
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 union {
 uint8_t ack;
 uint8_t raw[0];
 } mes;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct arc_hardware
{
 uint8_t source,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 dest,
 offset[2];
};
#define ARC_HDR_SIZE 4
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct archdr
{
 struct arc_hardware hard;
 union {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 struct arc_rfc1201 rfc1201;
 struct arc_rfc1051 rfc1051;
 struct arc_eth_encap eth_encap;
 struct arc_cap cap;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 uint8_t raw[0];
 } soft;
};
#endif
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
