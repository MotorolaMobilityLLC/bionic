/*	$NetBSD: icmp6.h,v 1.47 2013/07/01 12:43:15 christos Exp $	*/
/*	$KAME: icmp6.h,v 1.84 2003/04/23 10:26:51 itojun Exp $	*/


/*
 * Copyright (C) 1995, 1996, 1997, and 1998 WIDE Project.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the project nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

/*
 * Copyright (c) 1982, 1986, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *	@(#)ip_icmp.h	8.1 (Berkeley) 6/10/93
 */

#ifndef _NETINET_ICMP6_H_
#define _NETINET_ICMP6_H_

#include <netinet/in.h> /* android-added: glibc source compatibility. */
#include <sys/cdefs.h>

#define ICMPV6_PLD_MAXLEN	1232	/* IPV6_MMTU - sizeof(struct ip6_hdr)
					   - sizeof(struct icmp6_hdr) */

struct icmp6_hdr {
	u_int8_t	icmp6_type;	/* type field */
	u_int8_t	icmp6_code;	/* code field */
	u_int16_t	icmp6_cksum;	/* checksum field */
	union {
		u_int32_t	icmp6_un_data32[1]; /* type-specific field */
		u_int16_t	icmp6_un_data16[2]; /* type-specific field */
		u_int8_t	icmp6_un_data8[4];  /* type-specific field */
	} icmp6_dataun;
} __packed;

#define icmp6_data32	icmp6_dataun.icmp6_un_data32
#define icmp6_data16	icmp6_dataun.icmp6_un_data16
#define icmp6_data8	icmp6_dataun.icmp6_un_data8
#define icmp6_pptr	icmp6_data32[0]		/* parameter prob */
#define icmp6_mtu	icmp6_data32[0]		/* packet too big */
#define icmp6_id	icmp6_data16[0]		/* echo request/reply */
#define icmp6_seq	icmp6_data16[1]		/* echo request/reply */
#define icmp6_maxdelay	icmp6_data16[0]		/* mcast group membership */

#define ICMP6_DST_UNREACH		1	/* dest unreachable, codes: */
#define ICMP6_PACKET_TOO_BIG		2	/* packet too big */
#define ICMP6_TIME_EXCEEDED		3	/* time exceeded, code: */
#define ICMP6_PARAM_PROB		4	/* ip6 header bad */

#define ICMP6_ECHO_REQUEST		128	/* echo service */
#define ICMP6_ECHO_REPLY		129	/* echo reply */
#define MLD_LISTENER_QUERY		130 	/* multicast listener query */
#define MLD_LISTENER_REPORT		131	/* multicast listener report */
#define MLD_LISTENER_DONE		132	/* multicast listener done */
#define MLD_LISTENER_REDUCTION MLD_LISTENER_DONE /* RFC3542 definition */

/* RFC2292 decls */
#define ICMP6_MEMBERSHIP_QUERY		130	/* group membership query */
#define ICMP6_MEMBERSHIP_REPORT		131	/* group membership report */
#define ICMP6_MEMBERSHIP_REDUCTION	132	/* group membership termination */

#define ND_ROUTER_SOLICIT		133	/* router solicitation */
#define ND_ROUTER_ADVERT		134	/* router advertisement */
#define ND_NEIGHBOR_SOLICIT		135	/* neighbor solicitation */
#define ND_NEIGHBOR_ADVERT		136	/* neighbor advertisement */
#define ND_REDIRECT			137	/* redirect */

#define ICMP6_ROUTER_RENUMBERING	138	/* router renumbering */

#define ICMP6_WRUREQUEST		139	/* who are you request */
#define ICMP6_WRUREPLY			140	/* who are you reply */
#define ICMP6_FQDN_QUERY		139	/* FQDN query */
#define ICMP6_FQDN_REPLY		140	/* FQDN reply */
#define ICMP6_NI_QUERY			139	/* node information request */
#define ICMP6_NI_REPLY			140	/* node information reply */
#define MLDV2_LISTENER_REPORT		143	/* RFC3810 listener report */

/* The definitions below are experimental. TBA */
#define MLD_MTRACE_RESP			200	/* mtrace response(to sender) */
#define MLD_MTRACE			201	/* mtrace messages */

#define ICMP6_MAXTYPE			201

#define ICMP6_DST_UNREACH_NOROUTE	0	/* no route to destination */
#define ICMP6_DST_UNREACH_ADMIN	 	1	/* administratively prohibited */
#define ICMP6_DST_UNREACH_NOTNEIGHBOR	2	/* not a neighbor(obsolete) */
#define ICMP6_DST_UNREACH_BEYONDSCOPE	2	/* beyond scope of source address */
#define ICMP6_DST_UNREACH_ADDR		3	/* address unreachable */
#define ICMP6_DST_UNREACH_NOPORT	4	/* port unreachable */
#define ICMP6_DST_UNREACH_POLICY	5	/* source address failed ingress/egress policy */
#define ICMP6_DST_UNREACH_REJROUTE	6	/* reject route to destination */
#define ICMP6_DST_UNREACH_SOURCERT	7	/* error in source routing header */

#define ICMP6_TIME_EXCEED_TRANSIT 	0	/* ttl==0 in transit */
#define ICMP6_TIME_EXCEED_REASSEMBLY	1	/* ttl==0 in reass */

#define ICMP6_PARAMPROB_HEADER 	 	0	/* erroneous header field */
#define ICMP6_PARAMPROB_NEXTHEADER	1	/* unrecognized next header */
#define ICMP6_PARAMPROB_OPTION		2	/* unrecognized option */

#define ICMP6_INFOMSG_MASK		0x80	/* all informational messages */

#define ICMP6_NI_SUBJ_IPV6	0	/* Query Subject is an IPv6 address */
#define ICMP6_NI_SUBJ_FQDN	1	/* Query Subject is a Domain name */
#define ICMP6_NI_SUBJ_IPV4	2	/* Query Subject is an IPv4 address */

#define ICMP6_NI_SUCCESS	0	/* node information successful reply */
#define ICMP6_NI_REFUSED	1	/* node information request is refused */
#define ICMP6_NI_UNKNOWN	2	/* unknown Qtype */

#define ICMP6_ROUTER_RENUMBERING_COMMAND  0	/* rr command */
#define ICMP6_ROUTER_RENUMBERING_RESULT   1	/* rr result */
#define ICMP6_ROUTER_RENUMBERING_SEQNUM_RESET   255	/* rr seq num reset */

/* Used in kernel only */
#define ND_REDIRECT_ONLINK	0	/* redirect to an on-link node */
#define ND_REDIRECT_ROUTER	1	/* redirect to a better router */

/*
 * Multicast Listener Discovery
 */
struct mld_hdr {
	struct icmp6_hdr	mld_icmp6_hdr;
	struct in6_addr		mld_addr; /* multicast address */
} __packed;

/* shortcut macro definitions */
#define mld_type	mld_icmp6_hdr.icmp6_type
#define mld_code	mld_icmp6_hdr.icmp6_code
#define mld_cksum	mld_icmp6_hdr.icmp6_cksum
#define mld_maxdelay	mld_icmp6_hdr.icmp6_data16[0]
#define mld_reserved	mld_icmp6_hdr.icmp6_data16[1]

#define MLD_MINLEN			24

/*
 * Neighbor Discovery
 */

struct nd_router_solicit {	/* router solicitation */
	struct icmp6_hdr 	nd_rs_hdr;
	/* could be followed by options */
} __packed;

#define nd_rs_type	nd_rs_hdr.icmp6_type
#define nd_rs_code	nd_rs_hdr.icmp6_code
#define nd_rs_cksum	nd_rs_hdr.icmp6_cksum
#define nd_rs_reserved	nd_rs_hdr.icmp6_data32[0]

struct nd_router_advert {	/* router advertisement */
	struct icmp6_hdr	nd_ra_hdr;
	u_int32_t		nd_ra_reachable;	/* reachable time */
	u_int32_t		nd_ra_retransmit;	/* retransmit timer */
	/* could be followed by options */
} __packed;

#define nd_ra_type		nd_ra_hdr.icmp6_type
#define nd_ra_code		nd_ra_hdr.icmp6_code
#define nd_ra_cksum		nd_ra_hdr.icmp6_cksum
#define nd_ra_curhoplimit	nd_ra_hdr.icmp6_data8[0]
#define nd_ra_flags_reserved	nd_ra_hdr.icmp6_data8[1]
#define ND_RA_FLAG_MANAGED	0x80
#define ND_RA_FLAG_OTHER	0x40
#define ND_RA_FLAG_HOME_AGENT	0x20

/*
 * Router preference values based on RFC4191.
 */
#define ND_RA_FLAG_RTPREF_MASK	0x18 /* 00011000 */

#define ND_RA_FLAG_RTPREF_HIGH	0x08 /* 00001000 */
#define ND_RA_FLAG_RTPREF_MEDIUM	0x00 /* 00000000 */
#define ND_RA_FLAG_RTPREF_LOW	0x18 /* 00011000 */
#define ND_RA_FLAG_RTPREF_RSV	0x10 /* 00010000 */

#define nd_ra_router_lifetime	nd_ra_hdr.icmp6_data16[1]

struct nd_neighbor_solicit {	/* neighbor solicitation */
	struct icmp6_hdr	nd_ns_hdr;
	struct in6_addr		nd_ns_target;	/*target address */
	/* could be followed by options */
} __packed;

#define nd_ns_type		nd_ns_hdr.icmp6_type
#define nd_ns_code		nd_ns_hdr.icmp6_code
#define nd_ns_cksum		nd_ns_hdr.icmp6_cksum
#define nd_ns_reserved		nd_ns_hdr.icmp6_data32[0]

struct nd_neighbor_advert {	/* neighbor advertisement */
	struct icmp6_hdr	nd_na_hdr;
	struct in6_addr		nd_na_target;	/* target address */
	/* could be followed by options */
} __packed;

#define nd_na_type		nd_na_hdr.icmp6_type
#define nd_na_code		nd_na_hdr.icmp6_code
#define nd_na_cksum		nd_na_hdr.icmp6_cksum
#define nd_na_flags_reserved	nd_na_hdr.icmp6_data32[0]
#define ND_NA_FLAG_ROUTER		0x80
#define ND_NA_FLAG_SOLICITED		0x40
#define ND_NA_FLAG_OVERRIDE		0x20

struct nd_redirect {		/* redirect */
	struct icmp6_hdr	nd_rd_hdr;
	struct in6_addr		nd_rd_target;	/* target address */
	struct in6_addr		nd_rd_dst;	/* destination address */
	/* could be followed by options */
} __packed;

#define nd_rd_type		nd_rd_hdr.icmp6_type
#define nd_rd_code		nd_rd_hdr.icmp6_code
#define nd_rd_cksum		nd_rd_hdr.icmp6_cksum
#define nd_rd_reserved		nd_rd_hdr.icmp6_data32[0]

struct nd_opt_hdr {		/* Neighbor discovery option header */
	u_int8_t	nd_opt_type;
	u_int8_t	nd_opt_len;
	/* followed by option specific data*/
} __packed;

#define ND_OPT_SOURCE_LINKADDR		1
#define ND_OPT_TARGET_LINKADDR		2
#define ND_OPT_PREFIX_INFORMATION	3
#define ND_OPT_REDIRECTED_HEADER	4
#define ND_OPT_MTU			5
#define ND_OPT_ADVINTERVAL		7
#define ND_OPT_HOMEAGENT_INFO		8
#define ND_OPT_SOURCE_ADDRLIST		9
#define ND_OPT_TARGET_ADDRLIST		10
#define ND_OPT_MAP			23	/* RFC 5380 */
#define ND_OPT_ROUTE_INFO		24	/* RFC 4191 */
#define ND_OPT_RDNSS			25	/* RFC 6016 */
#define ND_OPT_DNSSL			31	/* RFC 6016 */

struct nd_opt_route_info {	/* route info */
	u_int8_t	nd_opt_rti_type;
	u_int8_t	nd_opt_rti_len;
	u_int8_t	nd_opt_rti_prefixlen;
	u_int8_t	nd_opt_rti_flags;
	u_int32_t	nd_opt_rti_lifetime;
	/* prefix follows */
};

struct nd_opt_prefix_info {	/* prefix information */
	u_int8_t	nd_opt_pi_type;
	u_int8_t	nd_opt_pi_len;
	u_int8_t	nd_opt_pi_prefix_len;
	u_int8_t	nd_opt_pi_flags_reserved;
	u_int32_t	nd_opt_pi_valid_time;
	u_int32_t	nd_opt_pi_preferred_time;
	u_int32_t	nd_opt_pi_reserved2;
	struct in6_addr	nd_opt_pi_prefix;
} __packed;

#define ND_OPT_PI_FLAG_ONLINK		0x80
#define ND_OPT_PI_FLAG_AUTO		0x40

struct nd_opt_rd_hdr {		/* redirected header */
	u_int8_t	nd_opt_rh_type;
	u_int8_t	nd_opt_rh_len;
	u_int16_t	nd_opt_rh_reserved1;
	u_int32_t	nd_opt_rh_reserved2;
	/* followed by IP header and data */
} __packed;

struct nd_opt_mtu {		/* MTU option */
	u_int8_t	nd_opt_mtu_type;
	u_int8_t	nd_opt_mtu_len;
	u_int16_t	nd_opt_mtu_reserved;
	u_int32_t	nd_opt_mtu_mtu;
} __packed;

struct nd_opt_rdnss {		/* RDNSS option RFC 6106 */
	u_int8_t	nd_opt_rdnss_type;
	u_int8_t	nd_opt_rdnss_len;
	u_int16_t	nd_opt_rdnss_reserved;
	u_int32_t	nd_opt_rdnss_lifetime;
	/* followed by list of IP prefixes */
} __packed;

struct nd_opt_dnssl {		/* DNSSL option RFC 6106 */
	u_int8_t	nd_opt_dnssl_type;
	u_int8_t	nd_opt_dnssl_len;
	u_int16_t	nd_opt_dnssl_reserved;
	u_int32_t	nd_opt_dnssl_lifetime;
	/* followed by list of IP prefixes */
} __packed;

/*
 * icmp6 namelookup
 */

struct icmp6_namelookup {
	struct icmp6_hdr 	icmp6_nl_hdr;
	u_int8_t	icmp6_nl_nonce[8];
	int32_t		icmp6_nl_ttl;
#if 0
	u_int8_t	icmp6_nl_len;
	u_int8_t	icmp6_nl_name[3];
#endif
	/* could be followed by options */
} __packed;

/*
 * icmp6 node information
 */
struct icmp6_nodeinfo {
	struct icmp6_hdr icmp6_ni_hdr;
	u_int8_t icmp6_ni_nonce[8];
	/* could be followed by reply data */
} __packed;

/*
 * BEGIN android-removed: glibc doesn't have these, and external/ping declares them itself.
#define ni_type		icmp6_ni_hdr.icmp6_type
#define ni_code		icmp6_ni_hdr.icmp6_code
#define ni_cksum	icmp6_ni_hdr.icmp6_cksum
#define ni_qtype	icmp6_ni_hdr.icmp6_data16[0]
#define ni_flags	icmp6_ni_hdr.icmp6_data16[1]
 * END android-removed
 */

#define NI_QTYPE_NOOP		0 /* NOOP  */
#define NI_QTYPE_SUPTYPES	1 /* Supported Qtypes */
#define NI_QTYPE_FQDN		2 /* FQDN (draft 04) */
#define NI_QTYPE_DNSNAME	2 /* DNS Name */
#define NI_QTYPE_NODEADDR	3 /* Node Addresses */
#define NI_QTYPE_IPV4ADDR	4 /* IPv4 Addresses */

#define NI_SUPTYPE_FLAG_COMPRESS	0x0100
#define NI_FQDN_FLAG_VALIDTTL		0x0100

#ifdef NAME_LOOKUPS_04
#define NI_NODEADDR_FLAG_LINKLOCAL	0x0100
#define NI_NODEADDR_FLAG_SITELOCAL	0x0200
#define NI_NODEADDR_FLAG_GLOBAL		0x0400
#define NI_NODEADDR_FLAG_ALL		0x0800
#define NI_NODEADDR_FLAG_TRUNCATE	0x1000
#define NI_NODEADDR_FLAG_ANYCAST	0x2000 /* just experimental. not in spec */
#else  /* draft-ietf-ipngwg-icmp-name-lookups-05 (and later?) */
#define NI_NODEADDR_FLAG_TRUNCATE	0x0100
#define NI_NODEADDR_FLAG_ALL		0x0200
#define NI_NODEADDR_FLAG_COMPAT		0x0400
#define NI_NODEADDR_FLAG_LINKLOCAL	0x0800
#define NI_NODEADDR_FLAG_SITELOCAL	0x1000
#define NI_NODEADDR_FLAG_GLOBAL		0x2000
#define NI_NODEADDR_FLAG_ANYCAST	0x4000 /* just experimental. not in spec */
#endif

struct ni_reply_fqdn {
	u_int32_t ni_fqdn_ttl;	/* TTL */
	u_int8_t ni_fqdn_namelen; /* length in octets of the FQDN */
	u_int8_t ni_fqdn_name[3]; /* XXX: alignment */
} __packed;

/*
 * Router Renumbering. as router-renum-08.txt
 */
struct icmp6_router_renum {	/* router renumbering header */
	struct icmp6_hdr	rr_hdr;
	u_int8_t	rr_segnum;
	u_int8_t	rr_flags;
	u_int16_t	rr_maxdelay;
	u_int32_t	rr_reserved;
} __packed;

#define ICMP6_RR_FLAGS_TEST		0x80
#define ICMP6_RR_FLAGS_REQRESULT	0x40
#define ICMP6_RR_FLAGS_FORCEAPPLY	0x20
#define ICMP6_RR_FLAGS_SPECSITE		0x10
#define ICMP6_RR_FLAGS_PREVDONE		0x08

#define rr_type		rr_hdr.icmp6_type
#define rr_code		rr_hdr.icmp6_code
#define rr_cksum	rr_hdr.icmp6_cksum
#define rr_seqnum 	rr_hdr.icmp6_data32[0]

struct rr_pco_match {		/* match prefix part */
	u_int8_t	rpm_code;
	u_int8_t	rpm_len;
	u_int8_t	rpm_ordinal;
	u_int8_t	rpm_matchlen;
	u_int8_t	rpm_minlen;
	u_int8_t	rpm_maxlen;
	u_int16_t	rpm_reserved;
	struct	in6_addr	rpm_prefix;
} __packed;

#define RPM_PCO_ADD		1
#define RPM_PCO_CHANGE		2
#define RPM_PCO_SETGLOBAL	3
#define RPM_PCO_MAX		4

struct rr_pco_use {		/* use prefix part */
	u_int8_t	rpu_uselen;
	u_int8_t	rpu_keeplen;
	u_int8_t	rpu_ramask;
	u_int8_t	rpu_raflags;
	u_int32_t	rpu_vltime;
	u_int32_t	rpu_pltime;
	u_int32_t	rpu_flags;
	struct	in6_addr rpu_prefix;
} __packed;
#define ICMP6_RR_PCOUSE_RAFLAGS_ONLINK	0x80
#define ICMP6_RR_PCOUSE_RAFLAGS_AUTO	0x40

#define ICMP6_RR_PCOUSE_FLAGS_DECRVLTIME     0x80
#define ICMP6_RR_PCOUSE_FLAGS_DECRPLTIME     0x40

struct rr_result {		/* router renumbering result message */
	u_int16_t	rrr_flags;
	u_int8_t	rrr_ordinal;
	u_int8_t	rrr_matchedlen;
	u_int32_t	rrr_ifid;
	struct	in6_addr rrr_prefix;
} __packed;
#define ICMP6_RR_RESULT_FLAGS_OOB		0x0200
#define ICMP6_RR_RESULT_FLAGS_FORBIDDEN		0x0100

/*
 * icmp6 filter structures.
 */

struct icmp6_filter {
	u_int32_t icmp6_filt[8];
};

/*
 * BEGIN android-changed
 * Linux and *BSD kernels use opposite values to indicate pass/block in ICMPv6
 * filters, and assign a different value to the ICMP6_FILTER sockopt.
 */
#define ICMP6_FILTER 1

#define	ICMP6_FILTER_SETPASSALL(filterp) \
	(void)memset(filterp, 0x00, sizeof(struct icmp6_filter))
#define	ICMP6_FILTER_SETBLOCKALL(filterp) \
	(void)memset(filterp, 0xff, sizeof(struct icmp6_filter))
#define	ICMP6_FILTER_SETPASS(type, filterp) \
	(((filterp)->icmp6_filt[(type) >> 5]) &= ~(1 << ((type) & 31)))
#define	ICMP6_FILTER_SETBLOCK(type, filterp) \
	(((filterp)->icmp6_filt[(type) >> 5]) |= (1 << ((type) & 31)))
#define	ICMP6_FILTER_WILLPASS(type, filterp) \
	((((filterp)->icmp6_filt[(type) >> 5]) & (1 << ((type) & 31))) == 0)
#define	ICMP6_FILTER_WILLBLOCK(type, filterp) \
	((((filterp)->icmp6_filt[(type) >> 5]) & (1 << ((type) & 31))) != 0)
/*
 * END android-changed
 */

#endif /* !_NETINET_ICMP6_H_ */
