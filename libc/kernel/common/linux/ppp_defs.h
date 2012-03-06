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
#ifndef _PPP_DEFS_H_
#define _PPP_DEFS_H_
#define PPP_HDRLEN 4  
#define PPP_FCSLEN 2  
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define PPP_MRU 1500  
#define PPP_ADDRESS(p) (((__u8 *)(p))[0])
#define PPP_CONTROL(p) (((__u8 *)(p))[1])
#define PPP_PROTOCOL(p) ((((__u8 *)(p))[2] << 8) + ((__u8 *)(p))[3])
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define PPP_ALLSTATIONS 0xff  
#define PPP_UI 0x03  
#define PPP_FLAG 0x7e  
#define PPP_ESCAPE 0x7d  
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define PPP_TRANS 0x20  
#define PPP_IP 0x21  
#define PPP_AT 0x29  
#define PPP_IPX 0x2b  
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define PPP_VJC_COMP 0x2d  
#define PPP_VJC_UNCOMP 0x2f  
#define PPP_MP 0x3d  
#define PPP_IPV6 0x57  
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define PPP_COMPFRAG 0xfb  
#define PPP_COMP 0xfd  
#define PPP_MPLS_UC 0x0281  
#define PPP_MPLS_MC 0x0283  
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define PPP_IPCP 0x8021  
#define PPP_ATCP 0x8029  
#define PPP_IPXCP 0x802b  
#define PPP_IPV6CP 0x8057  
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define PPP_CCPFRAG 0x80fb  
#define PPP_CCP 0x80fd  
#define PPP_MPLSCP 0x80fd  
#define PPP_LCP 0xc021  
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define PPP_PAP 0xc023  
#define PPP_LQR 0xc025  
#define PPP_CHAP 0xc223  
#define PPP_CBCP 0xc029  
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define PPP_INITFCS 0xffff  
#define PPP_GOODFCS 0xf0b8  
typedef __u32 ext_accm[8];
enum NPmode {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 NPMODE_PASS,
 NPMODE_DROP,
 NPMODE_ERROR,
 NPMODE_QUEUE
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct pppstat {
 __u32 ppp_discards;
 __u32 ppp_ibytes;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 ppp_ioctects;
 __u32 ppp_ipackets;
 __u32 ppp_ierrors;
 __u32 ppp_ilqrs;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 ppp_obytes;
 __u32 ppp_ooctects;
 __u32 ppp_opackets;
 __u32 ppp_oerrors;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 ppp_olqrs;
};
struct vjstat {
 __u32 vjs_packets;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 vjs_compressed;
 __u32 vjs_searches;
 __u32 vjs_misses;
 __u32 vjs_uncompressedin;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 vjs_compressedin;
 __u32 vjs_errorin;
 __u32 vjs_tossed;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct compstat {
 __u32 unc_bytes;
 __u32 unc_packets;
 __u32 comp_bytes;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 comp_packets;
 __u32 inc_bytes;
 __u32 inc_packets;
 __u32 in_count;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 bytes_out;
 double ratio;
};
struct ppp_stats {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 struct pppstat p;
 struct vjstat vj;
};
struct ppp_comp_stats {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 struct compstat c;
 struct compstat d;
};
struct ppp_idle {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 time_t xmit_idle;
 time_t recv_idle;
};
#endif
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
