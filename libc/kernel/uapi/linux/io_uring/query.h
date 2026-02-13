/*
 * This file is auto-generated. Modifications will be lost.
 *
 * See https://android.googlesource.com/platform/bionic/+/master/libc/kernel/
 * for more information.
 */
#ifndef LINUX_IO_URING_QUERY_H
#define LINUX_IO_URING_QUERY_H
#include <linux/types.h>
struct io_uring_query_hdr {
  __u64 next_entry;
  __u64 query_data;
  __u32 query_op;
  __u32 size;
  __s32 result;
  __u32 __resv[3];
};
enum {
  IO_URING_QUERY_OPCODES = 0,
  IO_URING_QUERY_ZCRX = 1,
  IO_URING_QUERY_SCQ = 2,
  __IO_URING_QUERY_MAX,
};
struct io_uring_query_opcode {
  __u32 nr_request_opcodes;
  __u32 nr_register_opcodes;
  __u64 feature_flags;
  __u64 ring_setup_flags;
  __u64 enter_flags;
  __u64 sqe_flags;
  __u32 nr_query_opcodes;
  __u32 __pad;
};
struct io_uring_query_zcrx {
  __u64 register_flags;
  __u64 area_flags;
  __u32 nr_ctrl_opcodes;
  __u32 __resv1;
  __u32 rq_hdr_size;
  __u32 rq_hdr_alignment;
  __u64 __resv2;
};
struct io_uring_query_scq {
  __u64 hdr_size;
  __u64 hdr_alignment;
};
#endif
