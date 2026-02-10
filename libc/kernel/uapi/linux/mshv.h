/*
 * This file is auto-generated. Modifications will be lost.
 *
 * See https://android.googlesource.com/platform/bionic/+/master/libc/kernel/
 * for more information.
 */
#ifndef _UAPI_LINUX_MSHV_H
#define _UAPI_LINUX_MSHV_H
#include <linux/types.h>
#define MSHV_IOCTL 0xB8
enum {
  MSHV_PT_BIT_LAPIC,
  MSHV_PT_BIT_X2APIC,
  MSHV_PT_BIT_GPA_SUPER_PAGES,
  MSHV_PT_BIT_CPU_AND_XSAVE_FEATURES,
  MSHV_PT_BIT_COUNT,
};
#define MSHV_PT_FLAGS_MASK ((1 << MSHV_PT_BIT_COUNT) - 1)
enum {
  MSHV_PT_ISOLATION_NONE,
  MSHV_PT_ISOLATION_COUNT,
};
struct mshv_create_partition {
  __u64 pt_flags;
  __u64 pt_isolation;
};
#define MSHV_NUM_CPU_FEATURES_BANKS 2
struct mshv_create_partition_v2 {
  __u64 pt_flags;
  __u64 pt_isolation;
  __u16 pt_num_cpu_fbanks;
  __u8 pt_rsvd[6];
  __u64 pt_cpu_fbanks[MSHV_NUM_CPU_FEATURES_BANKS];
  __u64 pt_rsvd1[2];
#ifdef __x86_64__
  __u64 pt_disabled_xsave;
#else
  __u64 pt_rsvd2;
#endif
} __attribute__((__packed__));
#define MSHV_CREATE_PARTITION _IOW(MSHV_IOCTL, 0x00, struct mshv_create_partition)
struct mshv_create_vp {
  __u32 vp_index;
};
enum {
  MSHV_SET_MEM_BIT_WRITABLE,
  MSHV_SET_MEM_BIT_EXECUTABLE,
  MSHV_SET_MEM_BIT_UNMAP,
  MSHV_SET_MEM_BIT_COUNT
};
#define MSHV_SET_MEM_FLAGS_MASK ((1 << MSHV_SET_MEM_BIT_COUNT) - 1)
#define MSHV_HV_PAGE_SIZE 0x1000
struct mshv_user_mem_region {
  __u64 size;
  __u64 guest_pfn;
  __u64 userspace_addr;
  __u8 flags;
  __u8 rsvd[7];
};
enum {
  MSHV_IRQFD_BIT_DEASSIGN,
  MSHV_IRQFD_BIT_RESAMPLE,
  MSHV_IRQFD_BIT_COUNT,
};
#define MSHV_IRQFD_FLAGS_MASK ((1 << MSHV_IRQFD_BIT_COUNT) - 1)
struct mshv_user_irqfd {
  __s32 fd;
  __s32 resamplefd;
  __u32 gsi;
  __u32 flags;
};
enum {
  MSHV_IOEVENTFD_BIT_DATAMATCH,
  MSHV_IOEVENTFD_BIT_PIO,
  MSHV_IOEVENTFD_BIT_DEASSIGN,
  MSHV_IOEVENTFD_BIT_COUNT,
};
#define MSHV_IOEVENTFD_FLAGS_MASK ((1 << MSHV_IOEVENTFD_BIT_COUNT) - 1)
struct mshv_user_ioeventfd {
  __u64 datamatch;
  __u64 addr;
  __u32 len;
  __s32 fd;
  __u32 flags;
  __u8 rsvd[4];
};
struct mshv_user_irq_entry {
  __u32 gsi;
  __u32 address_lo;
  __u32 address_hi;
  __u32 data;
};
struct mshv_user_irq_table {
  __u32 nr;
  __u32 rsvd;
  struct mshv_user_irq_entry entries[];
};
enum {
  MSHV_GPAP_ACCESS_TYPE_ACCESSED,
  MSHV_GPAP_ACCESS_TYPE_DIRTY,
  MSHV_GPAP_ACCESS_TYPE_COUNT
};
enum {
  MSHV_GPAP_ACCESS_OP_NOOP,
  MSHV_GPAP_ACCESS_OP_CLEAR,
  MSHV_GPAP_ACCESS_OP_SET,
  MSHV_GPAP_ACCESS_OP_COUNT
};
struct mshv_gpap_access_bitmap {
  __u8 access_type;
  __u8 access_op;
  __u8 rsvd[6];
  __u64 page_count;
  __u64 gpap_base;
  __u64 bitmap_ptr;
};
struct mshv_root_hvcall {
  __u16 code;
  __u16 reps;
  __u16 in_sz;
  __u16 out_sz;
  __u16 status;
  __u8 rsvd[6];
  __u64 in_ptr;
  __u64 out_ptr;
};
#define MSHV_INITIALIZE_PARTITION _IO(MSHV_IOCTL, 0x00)
#define MSHV_CREATE_VP _IOW(MSHV_IOCTL, 0x01, struct mshv_create_vp)
#define MSHV_SET_GUEST_MEMORY _IOW(MSHV_IOCTL, 0x02, struct mshv_user_mem_region)
#define MSHV_IRQFD _IOW(MSHV_IOCTL, 0x03, struct mshv_user_irqfd)
#define MSHV_IOEVENTFD _IOW(MSHV_IOCTL, 0x04, struct mshv_user_ioeventfd)
#define MSHV_SET_MSI_ROUTING _IOW(MSHV_IOCTL, 0x05, struct mshv_user_irq_table)
#define MSHV_GET_GPAP_ACCESS_BITMAP _IOWR(MSHV_IOCTL, 0x06, struct mshv_gpap_access_bitmap)
#define MSHV_ROOT_HVCALL _IOWR(MSHV_IOCTL, 0x07, struct mshv_root_hvcall)
#define MSHV_RUN_VP_BUF_SZ 256
enum {
  MSHV_VP_MMAP_OFFSET_REGISTERS,
  MSHV_VP_MMAP_OFFSET_INTERCEPT_MESSAGE,
  MSHV_VP_MMAP_OFFSET_GHCB,
  MSHV_VP_MMAP_OFFSET_COUNT
};
struct mshv_run_vp {
  __u8 msg_buf[MSHV_RUN_VP_BUF_SZ];
};
enum {
  MSHV_VP_STATE_LAPIC,
  MSHV_VP_STATE_XSAVE,
  MSHV_VP_STATE_SIMP,
  MSHV_VP_STATE_SIEFP,
  MSHV_VP_STATE_SYNTHETIC_TIMERS,
  MSHV_VP_STATE_COUNT,
};
struct mshv_get_set_vp_state {
  __u8 type;
  __u8 rsvd[3];
  __u32 buf_sz;
  __u64 buf_ptr;
};
#define MSHV_RUN_VP _IOR(MSHV_IOCTL, 0x00, struct mshv_run_vp)
#define MSHV_GET_VP_STATE _IOWR(MSHV_IOCTL, 0x01, struct mshv_get_set_vp_state)
#define MSHV_SET_VP_STATE _IOWR(MSHV_IOCTL, 0x02, struct mshv_get_set_vp_state)
#define MSHV_CAP_CORE_API_STABLE 0x0
#define MSHV_CAP_REGISTER_PAGE 0x1
#define MSHV_CAP_VTL_RETURN_ACTION 0x2
#define MSHV_CAP_DR6_SHARED 0x3
#define MSHV_MAX_RUN_MSG_SIZE 256
struct mshv_vp_registers {
  __u32 count;
  __u32 reserved;
  __u64 regs_ptr;
};
struct mshv_vtl_set_eventfd {
  __s32 fd;
  __u32 flag;
};
struct mshv_vtl_signal_event {
  __u32 connection_id;
  __u32 flag;
};
struct mshv_vtl_sint_post_msg {
  __u64 message_type;
  __u32 connection_id;
  __u32 payload_size;
  __u64 payload_ptr;
};
struct mshv_vtl_ram_disposition {
  __u64 start_pfn;
  __u64 last_pfn;
};
struct mshv_vtl_set_poll_file {
  __u32 cpu;
  __u32 fd;
};
struct mshv_vtl_hvcall_setup {
  __u64 bitmap_array_size;
  __u64 allow_bitmap_ptr;
};
struct mshv_vtl_hvcall {
  __u64 control;
  __u64 input_size;
  __u64 input_ptr;
  __u64 status;
  __u64 output_size;
  __u64 output_ptr;
};
struct mshv_sint_mask {
  __u8 mask;
  __u8 reserved[7];
};
#define MSHV_CHECK_EXTENSION _IOW(MSHV_IOCTL, 0x00, __u32)
#define MSHV_CREATE_VTL _IOR(MSHV_IOCTL, 0x1D, char)
#define MSHV_ADD_VTL0_MEMORY _IOW(MSHV_IOCTL, 0x21, struct mshv_vtl_ram_disposition)
#define MSHV_SET_POLL_FILE _IOW(MSHV_IOCTL, 0x25, struct mshv_vtl_set_poll_file)
#define MSHV_RETURN_TO_LOWER_VTL _IO(MSHV_IOCTL, 0x27)
#define MSHV_GET_VP_REGISTERS _IOWR(MSHV_IOCTL, 0x05, struct mshv_vp_registers)
#define MSHV_SET_VP_REGISTERS _IOW(MSHV_IOCTL, 0x06, struct mshv_vp_registers)
#define MSHV_SINT_SIGNAL_EVENT _IOW(MSHV_IOCTL, 0x22, struct mshv_vtl_signal_event)
#define MSHV_SINT_POST_MESSAGE _IOW(MSHV_IOCTL, 0x23, struct mshv_vtl_sint_post_msg)
#define MSHV_SINT_SET_EVENTFD _IOW(MSHV_IOCTL, 0x24, struct mshv_vtl_set_eventfd)
#define MSHV_SINT_PAUSE_MESSAGE_STREAM _IOW(MSHV_IOCTL, 0x25, struct mshv_sint_mask)
#define MSHV_HVCALL_SETUP _IOW(MSHV_IOCTL, 0x1E, struct mshv_vtl_hvcall_setup)
#define MSHV_HVCALL _IOWR(MSHV_IOCTL, 0x1F, struct mshv_vtl_hvcall)
#endif
