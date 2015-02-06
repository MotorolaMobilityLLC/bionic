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
#ifndef __SAVAGE_DRM_H__
#define __SAVAGE_DRM_H__
#ifndef __SAVAGE_SAREA_DEFINES__
#define __SAVAGE_SAREA_DEFINES__
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SAVAGE_CARD_HEAP 0
#define SAVAGE_AGP_HEAP 1
#define SAVAGE_NR_TEX_HEAPS 2
#define SAVAGE_NR_TEX_REGIONS 16
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SAVAGE_LOG_MIN_TEX_REGION_SIZE 16
#endif
typedef struct _drm_savage_sarea {
  struct drm_tex_region texList[SAVAGE_NR_TEX_HEAPS][SAVAGE_NR_TEX_REGIONS + 1];
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  unsigned int texAge[SAVAGE_NR_TEX_HEAPS];
  int ctxOwner;
} drm_savage_sarea_t, * drm_savage_sarea_ptr;
#define DRM_SAVAGE_BCI_INIT 0x00
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define DRM_SAVAGE_BCI_CMDBUF 0x01
#define DRM_SAVAGE_BCI_EVENT_EMIT 0x02
#define DRM_SAVAGE_BCI_EVENT_WAIT 0x03
#define DRM_IOCTL_SAVAGE_BCI_INIT DRM_IOW(DRM_COMMAND_BASE + DRM_SAVAGE_BCI_INIT, drm_savage_init_t)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define DRM_IOCTL_SAVAGE_BCI_CMDBUF DRM_IOW(DRM_COMMAND_BASE + DRM_SAVAGE_BCI_CMDBUF, drm_savage_cmdbuf_t)
#define DRM_IOCTL_SAVAGE_BCI_EVENT_EMIT DRM_IOWR(DRM_COMMAND_BASE + DRM_SAVAGE_BCI_EVENT_EMIT, drm_savage_event_emit_t)
#define DRM_IOCTL_SAVAGE_BCI_EVENT_WAIT DRM_IOW(DRM_COMMAND_BASE + DRM_SAVAGE_BCI_EVENT_WAIT, drm_savage_event_wait_t)
#define SAVAGE_DMA_PCI 1
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SAVAGE_DMA_AGP 3
typedef struct drm_savage_init {
  enum {
    SAVAGE_INIT_BCI = 1,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
    SAVAGE_CLEANUP_BCI = 2
  } func;
  unsigned int sarea_priv_offset;
  unsigned int cob_size;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  unsigned int bci_threshold_lo, bci_threshold_hi;
  unsigned int dma_type;
  unsigned int fb_bpp;
  unsigned int front_offset, front_pitch;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  unsigned int back_offset, back_pitch;
  unsigned int depth_bpp;
  unsigned int depth_offset, depth_pitch;
  unsigned int texture_offset;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  unsigned int texture_size;
  unsigned long status_offset;
  unsigned long buffers_offset;
  unsigned long agp_textures_offset;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  unsigned long cmd_dma_offset;
} drm_savage_init_t;
typedef union drm_savage_cmd_header drm_savage_cmd_header_t;
typedef struct drm_savage_cmdbuf {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  drm_savage_cmd_header_t __user * cmd_addr;
  unsigned int size;
  unsigned int dma_idx;
  int discard;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  unsigned int __user * vb_addr;
  unsigned int vb_size;
  unsigned int vb_stride;
  struct drm_clip_rect __user * box_addr;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  unsigned int nbox;
} drm_savage_cmdbuf_t;
#define SAVAGE_WAIT_2D 0x1
#define SAVAGE_WAIT_3D 0x2
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SAVAGE_WAIT_IRQ 0x4
typedef struct drm_savage_event {
  unsigned int count;
  unsigned int flags;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
} drm_savage_event_emit_t, drm_savage_event_wait_t;
#define SAVAGE_CMD_STATE 0
#define SAVAGE_CMD_DMA_PRIM 1
#define SAVAGE_CMD_VB_PRIM 2
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SAVAGE_CMD_DMA_IDX 3
#define SAVAGE_CMD_VB_IDX 4
#define SAVAGE_CMD_CLEAR 5
#define SAVAGE_CMD_SWAP 6
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SAVAGE_PRIM_TRILIST 0
#define SAVAGE_PRIM_TRISTRIP 1
#define SAVAGE_PRIM_TRIFAN 2
#define SAVAGE_PRIM_TRILIST_201 3
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SAVAGE_SKIP_Z 0x01
#define SAVAGE_SKIP_W 0x02
#define SAVAGE_SKIP_C0 0x04
#define SAVAGE_SKIP_C1 0x08
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SAVAGE_SKIP_S0 0x10
#define SAVAGE_SKIP_T0 0x20
#define SAVAGE_SKIP_ST0 0x30
#define SAVAGE_SKIP_S1 0x40
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SAVAGE_SKIP_T1 0x80
#define SAVAGE_SKIP_ST1 0xc0
#define SAVAGE_SKIP_ALL_S3D 0x3f
#define SAVAGE_SKIP_ALL_S4 0xff
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SAVAGE_FRONT 0x1
#define SAVAGE_BACK 0x2
#define SAVAGE_DEPTH 0x4
union drm_savage_cmd_header {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  struct {
    unsigned char cmd;
    unsigned char pad0;
    unsigned short pad1;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
    unsigned short pad2;
    unsigned short pad3;
  } cmd;
  struct {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
    unsigned char cmd;
    unsigned char global;
    unsigned short count;
    unsigned short start;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
    unsigned short pad3;
  } state;
  struct {
    unsigned char cmd;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
    unsigned char prim;
    unsigned short skip;
    unsigned short count;
    unsigned short start;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  } prim;
  struct {
    unsigned char cmd;
    unsigned char prim;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
    unsigned short skip;
    unsigned short count;
    unsigned short pad3;
  } idx;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  struct {
    unsigned char cmd;
    unsigned char pad0;
    unsigned short pad1;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
    unsigned int flags;
  } clear0;
  struct {
    unsigned int mask;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
    unsigned int value;
  } clear1;
};
#endif
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
