/*
 * This file is auto-generated. Modifications will be lost.
 *
 * See https://android.googlesource.com/platform/bionic/+/master/libc/kernel/
 * for more information.
 */
#ifndef _GPIB_H
#define _GPIB_H
#define GPIB_MAX_NUM_BOARDS 16
#define GPIB_MAX_NUM_DESCRIPTORS 0x1000
enum ibsta_bit_numbers {
  DCAS_NUM = 0,
  DTAS_NUM = 1,
  LACS_NUM = 2,
  TACS_NUM = 3,
  ATN_NUM = 4,
  CIC_NUM = 5,
  REM_NUM = 6,
  LOK_NUM = 7,
  CMPL_NUM = 8,
  EVENT_NUM = 9,
  SPOLL_NUM = 10,
  RQS_NUM = 11,
  SRQI_NUM = 12,
  END_NUM = 13,
  TIMO_NUM = 14,
  ERR_NUM = 15
};
enum ibsta_bits {
  DCAS = (1 << DCAS_NUM),
  DTAS = (1 << DTAS_NUM),
  LACS = (1 << LACS_NUM),
  TACS = (1 << TACS_NUM),
  ATN = (1 << ATN_NUM),
  CIC = (1 << CIC_NUM),
  REM = (1 << REM_NUM),
  LOK = (1 << LOK_NUM),
  CMPL = (1 << CMPL_NUM),
  EVENT = (1 << EVENT_NUM),
  SPOLL = (1 << SPOLL_NUM),
  RQS = (1 << RQS_NUM),
  SRQI = (1 << SRQI_NUM),
  END = (1 << END_NUM),
  TIMO = (1 << TIMO_NUM),
  ERR = (1 << ERR_NUM),
  device_status_mask = ERR | TIMO | END | CMPL | RQS,
  board_status_mask = ERR | TIMO | END | CMPL | SPOLL | EVENT | LOK | REM | CIC | ATN | TACS | LACS | DTAS | DCAS | SRQI,
};
enum eos_flags {
  EOS_MASK = 0x1c00,
  REOS = 0x0400,
  XEOS = 0x800,
  BIN = 0x1000
};
enum bus_control_line {
  VALID_DAV = 0x01,
  VALID_NDAC = 0x02,
  VALID_NRFD = 0x04,
  VALID_IFC = 0x08,
  VALID_REN = 0x10,
  VALID_SRQ = 0x20,
  VALID_ATN = 0x40,
  VALID_EOI = 0x80,
  VALID_ALL = 0xff,
  BUS_DAV = 0x0100,
  BUS_NDAC = 0x0200,
  BUS_NRFD = 0x0400,
  BUS_IFC = 0x0800,
  BUS_REN = 0x1000,
  BUS_SRQ = 0x2000,
  BUS_ATN = 0x4000,
  BUS_EOI = 0x8000
};
enum ppe_bits {
  PPC_DISABLE = 0x10,
  PPC_SENSE = 0x8,
  PPC_DIO_MASK = 0x7
};
enum {
  request_service_bit = 0x40,
};
enum gpib_events {
  EVENT_NONE = 0,
  EVENT_DEV_TRG = 1,
  EVENT_DEV_CLR = 2,
  EVENT_IFC = 3
};
#endif
