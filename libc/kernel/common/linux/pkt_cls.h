/****************************************************************************
 ****************************************************************************
 ***
 ***   This header was automatically generated from a Linux kernel header
 ***   of the same name, to make information necessary for userspace to
 ***   call into the kernel available to libc.  It contains only constants,
 ***   structures, and macros generated from the original header, and thus,
 ***   contains no copyrightable information.
 ***
 ****************************************************************************
 ****************************************************************************/
#ifndef __LINUX_PKT_CLS_H
#define __LINUX_PKT_CLS_H

#include <linux/pkt_sched.h>

#define _TC_MAKE32(x) ((x))

#define _TC_MAKEMASK1(n) (_TC_MAKE32(1) << _TC_MAKE32(n))
#define _TC_MAKEMASK(v,n) (_TC_MAKE32((_TC_MAKE32(1)<<(v))-1) << _TC_MAKE32(n))
#define _TC_MAKEVALUE(v,n) (_TC_MAKE32(v) << _TC_MAKE32(n))
#define _TC_GETVALUE(v,n,m) ((_TC_MAKE32(v) & _TC_MAKE32(m)) >> _TC_MAKE32(n))

#define TC_MUNGED _TC_MAKEMASK1(0)
#define SET_TC_MUNGED(v) ( TC_MUNGED | (v & ~TC_MUNGED))
#define CLR_TC_MUNGED(v) ( v & ~TC_MUNGED)

#define TC_OK2MUNGE _TC_MAKEMASK1(1)
#define SET_TC_OK2MUNGE(v) ( TC_OK2MUNGE | (v & ~TC_OK2MUNGE))
#define CLR_TC_OK2MUNGE(v) ( v & ~TC_OK2MUNGE)

#define S_TC_VERD _TC_MAKE32(2)
#define M_TC_VERD _TC_MAKEMASK(4,S_TC_VERD)
#define G_TC_VERD(x) _TC_GETVALUE(x,S_TC_VERD,M_TC_VERD)
#define V_TC_VERD(x) _TC_MAKEVALUE(x,S_TC_VERD)
#define SET_TC_VERD(v,n) ((V_TC_VERD(n)) | (v & ~M_TC_VERD))

#define S_TC_FROM _TC_MAKE32(6)
#define M_TC_FROM _TC_MAKEMASK(2,S_TC_FROM)
#define G_TC_FROM(x) _TC_GETVALUE(x,S_TC_FROM,M_TC_FROM)
#define V_TC_FROM(x) _TC_MAKEVALUE(x,S_TC_FROM)
#define SET_TC_FROM(v,n) ((V_TC_FROM(n)) | (v & ~M_TC_FROM))
#define AT_STACK 0x0
#define AT_INGRESS 0x1
#define AT_EGRESS 0x2

#define TC_NCLS _TC_MAKEMASK1(8)
#define SET_TC_NCLS(v) ( TC_NCLS | (v & ~TC_NCLS))
#define CLR_TC_NCLS(v) ( v & ~TC_NCLS)

#define S_TC_RTTL _TC_MAKE32(9)
#define M_TC_RTTL _TC_MAKEMASK(3,S_TC_RTTL)
#define G_TC_RTTL(x) _TC_GETVALUE(x,S_TC_RTTL,M_TC_RTTL)
#define V_TC_RTTL(x) _TC_MAKEVALUE(x,S_TC_RTTL)
#define SET_TC_RTTL(v,n) ((V_TC_RTTL(n)) | (v & ~M_TC_RTTL))

#define S_TC_AT _TC_MAKE32(12)
#define M_TC_AT _TC_MAKEMASK(2,S_TC_AT)
#define G_TC_AT(x) _TC_GETVALUE(x,S_TC_AT,M_TC_AT)
#define V_TC_AT(x) _TC_MAKEVALUE(x,S_TC_AT)
#define SET_TC_AT(v,n) ((V_TC_AT(n)) | (v & ~M_TC_AT))

enum
{
 TCA_ACT_UNSPEC,
 TCA_ACT_KIND,
 TCA_ACT_OPTIONS,
 TCA_ACT_INDEX,
 TCA_ACT_STATS,
 __TCA_ACT_MAX
};

#define TCA_ACT_MAX __TCA_ACT_MAX
#define TCA_OLD_COMPAT (TCA_ACT_MAX+1)
#define TCA_ACT_MAX_PRIO 32
#define TCA_ACT_BIND 1
#define TCA_ACT_NOBIND 0
#define TCA_ACT_UNBIND 1
#define TCA_ACT_NOUNBIND 0
#define TCA_ACT_REPLACE 1
#define TCA_ACT_NOREPLACE 0
#define MAX_REC_LOOP 4
#define MAX_RED_LOOP 4

#define TC_ACT_UNSPEC (-1)
#define TC_ACT_OK 0
#define TC_ACT_RECLASSIFY 1
#define TC_ACT_SHOT 2
#define TC_ACT_PIPE 3
#define TC_ACT_STOLEN 4
#define TC_ACT_QUEUED 5
#define TC_ACT_REPEAT 6
#define TC_ACT_JUMP 0x10000000

enum
{
 TCA_ID_UNSPEC=0,
 TCA_ID_POLICE=1,

 __TCA_ID_MAX=255
};

#define TCA_ID_MAX __TCA_ID_MAX

struct tc_police
{
 __u32 index;
 int action;
#define TC_POLICE_UNSPEC TC_ACT_UNSPEC
#define TC_POLICE_OK TC_ACT_OK
#define TC_POLICE_RECLASSIFY TC_ACT_RECLASSIFY
#define TC_POLICE_SHOT TC_ACT_SHOT
#define TC_POLICE_PIPE TC_ACT_PIPE

 __u32 limit;
 __u32 burst;
 __u32 mtu;
 struct tc_ratespec rate;
 struct tc_ratespec peakrate;
 int refcnt;
 int bindcnt;
 __u32 capab;
};

struct tcf_t
{
 __u64 install;
 __u64 lastuse;
 __u64 expires;
};

struct tc_cnt
{
 int refcnt;
 int bindcnt;
};

#define tc_gen   __u32 index;   __u32 capab;   int action;   int refcnt;   int bindcnt

enum
{
 TCA_POLICE_UNSPEC,
 TCA_POLICE_TBF,
 TCA_POLICE_RATE,
 TCA_POLICE_PEAKRATE,
 TCA_POLICE_AVRATE,
 TCA_POLICE_RESULT,
 __TCA_POLICE_MAX
#define TCA_POLICE_RESULT TCA_POLICE_RESULT
};

#define TCA_POLICE_MAX (__TCA_POLICE_MAX - 1)

#define TC_U32_HTID(h) ((h)&0xFFF00000)
#define TC_U32_USERHTID(h) (TC_U32_HTID(h)>>20)
#define TC_U32_HASH(h) (((h)>>12)&0xFF)
#define TC_U32_NODE(h) ((h)&0xFFF)
#define TC_U32_KEY(h) ((h)&0xFFFFF)
#define TC_U32_UNSPEC 0
#define TC_U32_ROOT (0xFFF00000)

enum
{
 TCA_U32_UNSPEC,
 TCA_U32_CLASSID,
 TCA_U32_HASH,
 TCA_U32_LINK,
 TCA_U32_DIVISOR,
 TCA_U32_SEL,
 TCA_U32_POLICE,
 TCA_U32_ACT,
 TCA_U32_INDEV,
 TCA_U32_PCNT,
 TCA_U32_MARK,
 __TCA_U32_MAX
};

#define TCA_U32_MAX (__TCA_U32_MAX - 1)

struct tc_u32_key
{
 __u32 mask;
 __u32 val;
 int off;
 int offmask;
};

struct tc_u32_sel
{
 unsigned char flags;
 unsigned char offshift;
 unsigned char nkeys;

 __u16 offmask;
 __u16 off;
 short offoff;

 short hoff;
 __u32 hmask;
 struct tc_u32_key keys[0];
};

struct tc_u32_mark
{
 __u32 val;
 __u32 mask;
 __u32 success;
};

struct tc_u32_pcnt
{
 __u64 rcnt;
 __u64 rhit;
 __u64 kcnts[0];
};

#define TC_U32_TERMINAL 1
#define TC_U32_OFFSET 2
#define TC_U32_VAROFFSET 4
#define TC_U32_EAT 8

#define TC_U32_MAXDEPTH 8

enum
{
 TCA_RSVP_UNSPEC,
 TCA_RSVP_CLASSID,
 TCA_RSVP_DST,
 TCA_RSVP_SRC,
 TCA_RSVP_PINFO,
 TCA_RSVP_POLICE,
 TCA_RSVP_ACT,
 __TCA_RSVP_MAX
};

#define TCA_RSVP_MAX (__TCA_RSVP_MAX - 1 )

struct tc_rsvp_gpi
{
 __u32 key;
 __u32 mask;
 int offset;
};

struct tc_rsvp_pinfo
{
 struct tc_rsvp_gpi dpi;
 struct tc_rsvp_gpi spi;
 __u8 protocol;
 __u8 tunnelid;
 __u8 tunnelhdr;
 __u8 pad;
};

enum
{
 TCA_ROUTE4_UNSPEC,
 TCA_ROUTE4_CLASSID,
 TCA_ROUTE4_TO,
 TCA_ROUTE4_FROM,
 TCA_ROUTE4_IIF,
 TCA_ROUTE4_POLICE,
 TCA_ROUTE4_ACT,
 __TCA_ROUTE4_MAX
};

#define TCA_ROUTE4_MAX (__TCA_ROUTE4_MAX - 1)

enum
{
 TCA_FW_UNSPEC,
 TCA_FW_CLASSID,
 TCA_FW_POLICE,
 TCA_FW_INDEV,
 TCA_FW_ACT,
 __TCA_FW_MAX
};

#define TCA_FW_MAX (__TCA_FW_MAX - 1)

enum
{
 TCA_TCINDEX_UNSPEC,
 TCA_TCINDEX_HASH,
 TCA_TCINDEX_MASK,
 TCA_TCINDEX_SHIFT,
 TCA_TCINDEX_FALL_THROUGH,
 TCA_TCINDEX_CLASSID,
 TCA_TCINDEX_POLICE,
 TCA_TCINDEX_ACT,
 __TCA_TCINDEX_MAX
};

#define TCA_TCINDEX_MAX (__TCA_TCINDEX_MAX - 1)

enum
{
 TCA_BASIC_UNSPEC,
 TCA_BASIC_CLASSID,
 TCA_BASIC_EMATCHES,
 TCA_BASIC_ACT,
 TCA_BASIC_POLICE,
 __TCA_BASIC_MAX
};

#define TCA_BASIC_MAX (__TCA_BASIC_MAX - 1)

struct tcf_ematch_tree_hdr
{
 __u16 nmatches;
 __u16 progid;
};

enum
{
 TCA_EMATCH_TREE_UNSPEC,
 TCA_EMATCH_TREE_HDR,
 TCA_EMATCH_TREE_LIST,
 __TCA_EMATCH_TREE_MAX
};
#define TCA_EMATCH_TREE_MAX (__TCA_EMATCH_TREE_MAX - 1)

struct tcf_ematch_hdr
{
 __u16 matchid;
 __u16 kind;
 __u16 flags;
 __u16 pad;
};

#define TCF_EM_REL_END 0
#define TCF_EM_REL_AND (1<<0)
#define TCF_EM_REL_OR (1<<1)
#define TCF_EM_INVERT (1<<2)
#define TCF_EM_SIMPLE (1<<3)

#define TCF_EM_REL_MASK 3
#define TCF_EM_REL_VALID(v) (((v) & TCF_EM_REL_MASK) != TCF_EM_REL_MASK)

enum
{
 TCF_LAYER_LINK,
 TCF_LAYER_NETWORK,
 TCF_LAYER_TRANSPORT,
 __TCF_LAYER_MAX
};
#define TCF_LAYER_MAX (__TCF_LAYER_MAX - 1)

enum
{
 TCF_EM_CONTAINER,
 TCF_EM_CMP,
 TCF_EM_NBYTE,
 TCF_EM_U32,
 TCF_EM_META,
 TCF_EM_TEXT,
 __TCF_EM_MAX
};

enum
{
 TCF_EM_PROG_TC
};

enum
{
 TCF_EM_OPND_EQ,
 TCF_EM_OPND_GT,
 TCF_EM_OPND_LT
};

#endif
