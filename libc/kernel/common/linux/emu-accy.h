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
#ifndef __EMU_ACCY_H__
#define __EMU_ACCY_H__

#include <linux/ioctl.h>

enum emu_accy {
 EMU_ACCY_USB,
 EMU_ACCY_FACTORY,
 EMU_ACCY_CHARGER,
 EMU_ACCY_USB_DEVICE,
 EMU_ACCY_WHISPER_PPD,
 EMU_ACCY_WHISPER_SPD,
 EMU_ACCY_WHISPER_SMART_DOCK,
 EMU_ACCY_NONE,

 EMU_ACCY_UNKNOWN,
};

struct emu_accy_platform_data {
 enum emu_accy accy;
};

#undef CPCAP_DEV_NAME
#define CPCAP_DEV_NAME "emu_det"

#define CPCAP_WHISPER_MODE_PU 0x00000001
#define CPCAP_WHISPER_ENABLE_UART 0x00000002
#define CPCAP_WHISPER_ACCY_MASK 0xF8000000
#define CPCAP_WHISPER_ACCY_SHFT 27
#define CPCAP_WHISPER_ID_SIZE 16
#define CPCAP_WHISPER_PROP_SIZE 7

struct cpcap_whisper_request {
 unsigned int cmd;
 char dock_id[CPCAP_WHISPER_ID_SIZE];
 char dock_prop[CPCAP_WHISPER_PROP_SIZE];
};

#define CPCAP_IOCTL_NUM_ACCY_WHISPER 23

#define CPCAP_IOCTL_ACCY_WHISPER   _IOW(0, CPCAP_IOCTL_NUM_ACCY_WHISPER, struct cpcap_whisper_request*)

#endif

