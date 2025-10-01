/*
 * This file is auto-generated. Modifications will be lost.
 *
 * See https://android.googlesource.com/platform/bionic/+/master/libc/kernel/
 * for more information.
 */
#ifndef _UAPI_LINUX_VT_H
#define _UAPI_LINUX_VT_H
#include <linux/ioctl.h>
#include <linux/types.h>
#define MIN_NR_CONSOLES 1
#define MAX_NR_CONSOLES 63
#define VT_OPENQRY 0x5600
struct vt_mode {
  __u8 mode;
  __u8 waitv;
  __s16 relsig;
  __s16 acqsig;
  __s16 frsig;
};
#define VT_GETMODE 0x5601
#define VT_SETMODE 0x5602
#define VT_AUTO 0x00
#define VT_PROCESS 0x01
#define VT_ACKACQ 0x02
struct vt_stat {
  __u16 v_active;
  __u16 v_signal;
  __u16 v_state;
};
#define VT_GETSTATE 0x5603
#define VT_SENDSIG 0x5604
#define VT_RELDISP 0x5605
#define VT_ACTIVATE 0x5606
#define VT_WAITACTIVE 0x5607
#define VT_DISALLOCATE 0x5608
struct vt_sizes {
  __u16 v_rows;
  __u16 v_cols;
  __u16 v_scrollsize;
};
#define VT_RESIZE 0x5609
struct vt_consize {
  __u16 v_rows;
  __u16 v_cols;
  __u16 v_vlin;
  __u16 v_clin;
  __u16 v_vcol;
  __u16 v_ccol;
};
#define VT_RESIZEX 0x560A
#define VT_LOCKSWITCH 0x560B
#define VT_UNLOCKSWITCH 0x560C
#define VT_GETHIFONTMASK 0x560D
struct vt_event {
  __u32 event;
#define VT_EVENT_SWITCH 0x0001
#define VT_EVENT_BLANK 0x0002
#define VT_EVENT_UNBLANK 0x0004
#define VT_EVENT_RESIZE 0x0008
#define VT_MAX_EVENT 0x000F
  __u32 oldev;
  __u32 newev;
  __u32 pad[4];
};
#define VT_WAITEVENT 0x560E
struct vt_setactivate {
  __u32 console;
  struct vt_mode mode;
};
#define VT_SETACTIVATE 0x560F
struct vt_consizecsrpos {
  __u16 con_rows;
  __u16 con_cols;
  __u16 csr_row;
  __u16 csr_col;
};
#define VT_GETCONSIZECSRPOS _IOR('V', 0x10, struct vt_consizecsrpos)
#endif
