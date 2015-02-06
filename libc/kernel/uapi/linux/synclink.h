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
#ifndef _UAPI_SYNCLINK_H_
#define _UAPI_SYNCLINK_H_
#define SYNCLINK_H_VERSION 3.6
#include <linux/types.h>
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define BIT0 0x0001
#define BIT1 0x0002
#define BIT2 0x0004
#define BIT3 0x0008
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define BIT4 0x0010
#define BIT5 0x0020
#define BIT6 0x0040
#define BIT7 0x0080
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define BIT8 0x0100
#define BIT9 0x0200
#define BIT10 0x0400
#define BIT11 0x0800
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define BIT12 0x1000
#define BIT13 0x2000
#define BIT14 0x4000
#define BIT15 0x8000
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define BIT16 0x00010000
#define BIT17 0x00020000
#define BIT18 0x00040000
#define BIT19 0x00080000
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define BIT20 0x00100000
#define BIT21 0x00200000
#define BIT22 0x00400000
#define BIT23 0x00800000
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define BIT24 0x01000000
#define BIT25 0x02000000
#define BIT26 0x04000000
#define BIT27 0x08000000
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define BIT28 0x10000000
#define BIT29 0x20000000
#define BIT30 0x40000000
#define BIT31 0x80000000
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define HDLC_MAX_FRAME_SIZE 65535
#define MAX_ASYNC_TRANSMIT 4096
#define MAX_ASYNC_BUFFER_SIZE 4096
#define ASYNC_PARITY_NONE 0
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define ASYNC_PARITY_EVEN 1
#define ASYNC_PARITY_ODD 2
#define ASYNC_PARITY_SPACE 3
#define HDLC_FLAG_UNDERRUN_ABORT7 0x0000
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define HDLC_FLAG_UNDERRUN_ABORT15 0x0001
#define HDLC_FLAG_UNDERRUN_FLAG 0x0002
#define HDLC_FLAG_UNDERRUN_CRC 0x0004
#define HDLC_FLAG_SHARE_ZERO 0x0010
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define HDLC_FLAG_AUTO_CTS 0x0020
#define HDLC_FLAG_AUTO_DCD 0x0040
#define HDLC_FLAG_AUTO_RTS 0x0080
#define HDLC_FLAG_RXC_DPLL 0x0100
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define HDLC_FLAG_RXC_BRG 0x0200
#define HDLC_FLAG_RXC_TXCPIN 0x8000
#define HDLC_FLAG_RXC_RXCPIN 0x0000
#define HDLC_FLAG_TXC_DPLL 0x0400
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define HDLC_FLAG_TXC_BRG 0x0800
#define HDLC_FLAG_TXC_TXCPIN 0x0000
#define HDLC_FLAG_TXC_RXCPIN 0x0008
#define HDLC_FLAG_DPLL_DIV8 0x1000
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define HDLC_FLAG_DPLL_DIV16 0x2000
#define HDLC_FLAG_DPLL_DIV32 0x0000
#define HDLC_FLAG_HDLC_LOOPMODE 0x4000
#define HDLC_CRC_NONE 0
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define HDLC_CRC_16_CCITT 1
#define HDLC_CRC_32_CCITT 2
#define HDLC_CRC_MASK 0x00ff
#define HDLC_CRC_RETURN_EX 0x8000
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define RX_OK 0
#define RX_CRC_ERROR 1
#define HDLC_TXIDLE_FLAGS 0
#define HDLC_TXIDLE_ALT_ZEROS_ONES 1
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define HDLC_TXIDLE_ZEROS 2
#define HDLC_TXIDLE_ONES 3
#define HDLC_TXIDLE_ALT_MARK_SPACE 4
#define HDLC_TXIDLE_SPACE 5
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define HDLC_TXIDLE_MARK 6
#define HDLC_TXIDLE_CUSTOM_8 0x10000000
#define HDLC_TXIDLE_CUSTOM_16 0x20000000
#define HDLC_ENCODING_NRZ 0
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define HDLC_ENCODING_NRZB 1
#define HDLC_ENCODING_NRZI_MARK 2
#define HDLC_ENCODING_NRZI_SPACE 3
#define HDLC_ENCODING_NRZI HDLC_ENCODING_NRZI_SPACE
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define HDLC_ENCODING_BIPHASE_MARK 4
#define HDLC_ENCODING_BIPHASE_SPACE 5
#define HDLC_ENCODING_BIPHASE_LEVEL 6
#define HDLC_ENCODING_DIFF_BIPHASE_LEVEL 7
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define HDLC_PREAMBLE_LENGTH_8BITS 0
#define HDLC_PREAMBLE_LENGTH_16BITS 1
#define HDLC_PREAMBLE_LENGTH_32BITS 2
#define HDLC_PREAMBLE_LENGTH_64BITS 3
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define HDLC_PREAMBLE_PATTERN_NONE 0
#define HDLC_PREAMBLE_PATTERN_ZEROS 1
#define HDLC_PREAMBLE_PATTERN_FLAGS 2
#define HDLC_PREAMBLE_PATTERN_10 3
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define HDLC_PREAMBLE_PATTERN_01 4
#define HDLC_PREAMBLE_PATTERN_ONES 5
#define MGSL_MODE_ASYNC 1
#define MGSL_MODE_HDLC 2
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MGSL_MODE_MONOSYNC 3
#define MGSL_MODE_BISYNC 4
#define MGSL_MODE_RAW 6
#define MGSL_MODE_BASE_CLOCK 7
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MGSL_MODE_XSYNC 8
#define MGSL_BUS_TYPE_ISA 1
#define MGSL_BUS_TYPE_EISA 2
#define MGSL_BUS_TYPE_PCI 5
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MGSL_INTERFACE_MASK 0xf
#define MGSL_INTERFACE_DISABLE 0
#define MGSL_INTERFACE_RS232 1
#define MGSL_INTERFACE_V35 2
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MGSL_INTERFACE_RS422 3
#define MGSL_INTERFACE_RTS_EN 0x10
#define MGSL_INTERFACE_LL 0x20
#define MGSL_INTERFACE_RL 0x40
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MGSL_INTERFACE_MSB_FIRST 0x80
typedef struct _MGSL_PARAMS {
  unsigned long mode;
  unsigned char loopback;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  unsigned short flags;
  unsigned char encoding;
  unsigned long clock_speed;
  unsigned char addr_filter;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  unsigned short crc_type;
  unsigned char preamble_length;
  unsigned char preamble;
  unsigned long data_rate;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  unsigned char data_bits;
  unsigned char stop_bits;
  unsigned char parity;
} MGSL_PARAMS, * PMGSL_PARAMS;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MICROGATE_VENDOR_ID 0x13c0
#define SYNCLINK_DEVICE_ID 0x0010
#define MGSCC_DEVICE_ID 0x0020
#define SYNCLINK_SCA_DEVICE_ID 0x0030
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SYNCLINK_GT_DEVICE_ID 0x0070
#define SYNCLINK_GT4_DEVICE_ID 0x0080
#define SYNCLINK_AC_DEVICE_ID 0x0090
#define SYNCLINK_GT2_DEVICE_ID 0x00A0
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MGSL_MAX_SERIAL_NUMBER 30
#define DiagStatus_OK 0
#define DiagStatus_AddressFailure 1
#define DiagStatus_AddressConflict 2
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define DiagStatus_IrqFailure 3
#define DiagStatus_IrqConflict 4
#define DiagStatus_DmaFailure 5
#define DiagStatus_DmaConflict 6
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define DiagStatus_PciAdapterNotFound 7
#define DiagStatus_CantAssignPciResources 8
#define DiagStatus_CantAssignPciMemAddr 9
#define DiagStatus_CantAssignPciIoAddr 10
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define DiagStatus_CantAssignPciIrq 11
#define DiagStatus_MemoryError 12
#define SerialSignal_DCD 0x01
#define SerialSignal_TXD 0x02
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SerialSignal_RI 0x04
#define SerialSignal_RXD 0x08
#define SerialSignal_CTS 0x10
#define SerialSignal_RTS 0x20
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SerialSignal_DSR 0x40
#define SerialSignal_DTR 0x80
struct mgsl_icount {
  __u32 cts, dsr, rng, dcd, tx, rx;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u32 frame, parity, overrun, brk;
  __u32 buf_overrun;
  __u32 txok;
  __u32 txunder;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u32 txabort;
  __u32 txtimeout;
  __u32 rxshort;
  __u32 rxlong;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u32 rxabort;
  __u32 rxover;
  __u32 rxcrc;
  __u32 rxok;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u32 exithunt;
  __u32 rxidle;
};
struct gpio_desc {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  __u32 state;
  __u32 smask;
  __u32 dir;
  __u32 dmask;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
#define DEBUG_LEVEL_DATA 1
#define DEBUG_LEVEL_ERROR 2
#define DEBUG_LEVEL_INFO 3
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define DEBUG_LEVEL_BH 4
#define DEBUG_LEVEL_ISR 5
#define MgslEvent_DsrActive 0x0001
#define MgslEvent_DsrInactive 0x0002
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MgslEvent_Dsr 0x0003
#define MgslEvent_CtsActive 0x0004
#define MgslEvent_CtsInactive 0x0008
#define MgslEvent_Cts 0x000c
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MgslEvent_DcdActive 0x0010
#define MgslEvent_DcdInactive 0x0020
#define MgslEvent_Dcd 0x0030
#define MgslEvent_RiActive 0x0040
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MgslEvent_RiInactive 0x0080
#define MgslEvent_Ri 0x00c0
#define MgslEvent_ExitHuntMode 0x0100
#define MgslEvent_IdleReceived 0x0200
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MGSL_MAGIC_IOC 'm'
#define MGSL_IOCSPARAMS _IOW(MGSL_MAGIC_IOC, 0, struct _MGSL_PARAMS)
#define MGSL_IOCGPARAMS _IOR(MGSL_MAGIC_IOC, 1, struct _MGSL_PARAMS)
#define MGSL_IOCSTXIDLE _IO(MGSL_MAGIC_IOC, 2)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MGSL_IOCGTXIDLE _IO(MGSL_MAGIC_IOC, 3)
#define MGSL_IOCTXENABLE _IO(MGSL_MAGIC_IOC, 4)
#define MGSL_IOCRXENABLE _IO(MGSL_MAGIC_IOC, 5)
#define MGSL_IOCTXABORT _IO(MGSL_MAGIC_IOC, 6)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MGSL_IOCGSTATS _IO(MGSL_MAGIC_IOC, 7)
#define MGSL_IOCWAITEVENT _IOWR(MGSL_MAGIC_IOC, 8, int)
#define MGSL_IOCCLRMODCOUNT _IO(MGSL_MAGIC_IOC, 15)
#define MGSL_IOCLOOPTXDONE _IO(MGSL_MAGIC_IOC, 9)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MGSL_IOCSIF _IO(MGSL_MAGIC_IOC, 10)
#define MGSL_IOCGIF _IO(MGSL_MAGIC_IOC, 11)
#define MGSL_IOCSGPIO _IOW(MGSL_MAGIC_IOC, 16, struct gpio_desc)
#define MGSL_IOCGGPIO _IOR(MGSL_MAGIC_IOC, 17, struct gpio_desc)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MGSL_IOCWAITGPIO _IOWR(MGSL_MAGIC_IOC, 18, struct gpio_desc)
#define MGSL_IOCSXSYNC _IO(MGSL_MAGIC_IOC, 19)
#define MGSL_IOCGXSYNC _IO(MGSL_MAGIC_IOC, 20)
#define MGSL_IOCSXCTRL _IO(MGSL_MAGIC_IOC, 21)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MGSL_IOCGXCTRL _IO(MGSL_MAGIC_IOC, 22)
#endif
