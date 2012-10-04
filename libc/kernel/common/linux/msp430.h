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
#ifndef __MSP430_H__
#define __MSP430_H__
#define MSP430_IOCTL_BASE 77
#define MSP430_IOCTL_BOOTLOADERMODE   _IOW(MSP430_IOCTL_BASE, 0, unsigned char)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSP430_IOCTL_NORMALMODE   _IOW(MSP430_IOCTL_BASE, 1, unsigned char)
#define MSP430_IOCTL_MASSERASE   _IOW(MSP430_IOCTL_BASE, 2, unsigned char)
#define MSP430_IOCTL_SETSTARTADDR   _IOW(MSP430_IOCTL_BASE, 3, unsigned int)
#define MSP430_IOCTL_TEST_READ   _IOR(MSP430_IOCTL_BASE, 4, unsigned char)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSP430_IOCTL_TEST_WRITE   _IOW(MSP430_IOCTL_BASE, 5, unsigned char)
#define MSP430_IOCTL_TEST_WRITE_READ   _IOWR(MSP430_IOCTL_BASE, 6, unsigned short)
#define MSP430_IOCTL_SET_MAG_DELAY   _IOW(MSP430_IOCTL_BASE, 7, unsigned char)
#define MSP430_IOCTL_TEST_BOOTMODE   _IOW(MSP430_IOCTL_BASE, 8, unsigned char)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSP430_IOCTL_SET_ACC_DELAY   _IOW(MSP430_IOCTL_BASE, 9, unsigned char)
#define MSP430_IOCTL_SET_MOTION_DELAY   _IOW(MSP430_IOCTL_BASE, 10, unsigned char)
#define MSP430_IOCTL_SET_ENV_DELAY   _IOW(MSP430_IOCTL_BASE, 11, unsigned char)
#define MSP430_IOCTL_SET_DEBUG   _IOW(MSP430_IOCTL_BASE, 12, unsigned char)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSP430_IOCTL_SET_USER_PROFILE   _IOW(MSP430_IOCTL_BASE, 13, int)
#define MSP430_IOCTL_SET_GPS_DATA   _IOW(MSP430_IOCTL_BASE, 14, int)
#define MSP430_IOCTL_SET_SEA_LEVEL_PRESSURE   _IOW(MSP430_IOCTL_BASE, 15, int)
#define MSP430_IOCTL_SET_REF_ALTITUDE   _IOW(MSP430_IOCTL_BASE, 16, int)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSP430_IOCTL_SET_ACTIVE_MODE   _IOW(MSP430_IOCTL_BASE, 17, unsigned char)
#define MSP430_IOCTL_SET_PASSIVE_MODE   _IOW(MSP430_IOCTL_BASE, 18, unsigned char)
#define MSP430_IOCTL_SET_FACTORY_MODE   _IOW(MSP430_IOCTL_BASE, 19, unsigned char)
#define MSP430_IOCTL_GET_SENSORS   _IOR(MSP430_IOCTL_BASE, 20, unsigned char)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSP430_IOCTL_SET_SENSORS   _IOW(MSP430_IOCTL_BASE, 21, unsigned char)
#define MSP430_IOCTL_GET_VERSION   _IOR(MSP430_IOCTL_BASE, 22, unsigned char)
#define MSP430_IOCTL_SET_MONITOR_DELAY   _IOW(MSP430_IOCTL_BASE, 23, unsigned char)
#define MSP430_IOCTL_SET_DOCK_STATUS   _IOW(MSP430_IOCTL_BASE, 24, unsigned char)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSP430_IOCTL_SET_ORIENTATION_DELAY   _IOW(MSP430_IOCTL_BASE, 25, unsigned char)
#define MSP430_IOCTL_SET_EQUIPMENT_TYPE   _IOW(MSP430_IOCTL_BASE, 26, unsigned char)
#define MSP430_IOCTL_SET_POWER_MODE   _IOW(MSP430_IOCTL_BASE, 27, unsigned char)
#define MSP430_IOCTL_GET_ALGOS   _IOR(MSP430_IOCTL_BASE, 28, unsigned char)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSP430_IOCTL_SET_ALGOS   _IOW(MSP430_IOCTL_BASE, 29, unsigned char)
#define MSP430_IOCTL_SET_RADIAL_THR   _IOW(MSP430_IOCTL_BASE, 30, unsigned int)
#define MSP430_IOCTL_SET_RADIAL_DUR   _IOW(MSP430_IOCTL_BASE, 31, unsigned int)
#define MSP430_IOCTL_SET_MOTION_THR   _IOW(MSP430_IOCTL_BASE, 32, unsigned int)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSP430_IOCTL_SET_MOTION_DUR   _IOW(MSP430_IOCTL_BASE, 33, unsigned int)
#define MSP430_IOCTL_SET_ZRMOTION_THR   _IOW(MSP430_IOCTL_BASE, 34, unsigned int)
#define MSP430_IOCTL_SET_ZRMOTION_DUR   _IOW(MSP430_IOCTL_BASE, 35, unsigned int)
#define MSP430_MAX_PACKET_LENGTH 10
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define M_ACCEL 0x01
#define M_GYRO 0x02
#define M_PRESSURE 0x04
#define M_ECOMPASS 0x08
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define M_TEMPERATURE 0x10
#define M_ALS 0x20
#define M_PROXIMITY 0x40
#define M_ACTIVITY_CHANGE 0x80
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define M_MMOVEME 0x01
#define M_NOMMOVE 0x02
#define M_RADIAL 0x04
#endif
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
