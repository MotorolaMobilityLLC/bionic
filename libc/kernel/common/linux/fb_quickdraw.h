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
#ifndef _FB_QUICKDRAW_H_
#define _FB_QUICKDRAW_H_
#define FB_QUICKDRAW_IOCTL_MAGIC 'q'
#define FB_QUICKDRAW_INIT _IO(FB_QUICKDRAW_IOCTL_MAGIC, 1)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define FB_QUICKDRAW_ADD_BUFFER _IOW(FB_QUICKDRAW_IOCTL_MAGIC, 2,   struct fb_quickdraw_buffer_data)
#define FB_QUICKDRAW_REMOVE_BUFFER _IOW(FB_QUICKDRAW_IOCTL_MAGIC, 3, int)
#define FB_QUICKDRAW_LOCK_BUFFER _IOW(FB_QUICKDRAW_IOCTL_MAGIC, 4, int)
#define FB_QUICKDRAW_UNLOCK_BUFFER _IOW(FB_QUICKDRAW_IOCTL_MAGIC, 5, int)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct fb_quickdraw_buffer_data {
 int buffer_id;
 int user_fd;
 int format;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 int x;
 int y;
 int w;
 int h;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
#endif
