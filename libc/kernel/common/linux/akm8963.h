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
#ifndef AKM8963_H
#define AKM8963_H
#include <linux/ioctl.h>
#define AKM8963_I2C_NAME "akm8963"
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define SENSOR_DATA_SIZE 8
#define YPR_DATA_SIZE 12
#define RWBUF_SIZE 16
#define ACC_DATA_FLAG 0
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MAG_DATA_FLAG 1
#define ORI_DATA_FLAG 2
#define AKM_NUM_SENSORS 3
#define ACC_DATA_READY (1<<(ACC_DATA_FLAG))
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MAG_DATA_READY (1<<(MAG_DATA_FLAG))
#define ORI_DATA_READY (1<<(ORI_DATA_FLAG))
#define AK8963_MEASUREMENT_TIME_US 10000
#define AK8963_MODE_SNG_MEASURE 0x01
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define AK8963_MODE_SELF_TEST 0x08
#define AK8963_MODE_FUSE_ACCESS 0x0F
#define AK8963_MODE_POWERDOWN 0x00
#define AK8963_REG_WIA 0x00
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define AK8963_REG_INFO 0x01
#define AK8963_REG_ST1 0x02
#define AK8963_REG_HXL 0x03
#define AK8963_REG_HXH 0x04
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define AK8963_REG_HYL 0x05
#define AK8963_REG_HYH 0x06
#define AK8963_REG_HZL 0x07
#define AK8963_REG_HZH 0x08
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define AK8963_REG_ST2 0x09
#define AK8963_REG_CNTL1 0x0A
#define AK8963_REG_CNTL2 0x0B
#define AK8963_REG_ASTC 0x0C
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define AK8963_REG_TS1 0x0D
#define AK8963_REG_TS2 0x0E
#define AK8963_REG_I2CDIS 0x0F
#define AK8963_FUSE_ASAX 0x10
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define AK8963_FUSE_ASAY 0x11
#define AK8963_FUSE_ASAZ 0x12
#define AKMIO 0xA1
#define ECS_IOCTL_READ _IOWR(AKMIO, 0x01, char*)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define ECS_IOCTL_WRITE _IOW(AKMIO, 0x02, char*)
#define ECS_IOCTL_SET_MODE _IOW(AKMIO, 0x03, short)
#define ECS_IOCTL_GETDATA _IOR(AKMIO, 0x04, char[SENSOR_DATA_SIZE])
#define ECS_IOCTL_SET_YPR _IOW(AKMIO, 0x05, int[YPR_DATA_SIZE])
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define ECS_IOCTL_GET_OPEN_STATUS _IOR(AKMIO, 0x06, int)
#define ECS_IOCTL_GET_CLOSE_STATUS _IOR(AKMIO, 0x07, int)
#define ECS_IOCTL_GET_DELAY _IOR(AKMIO, 0x08, long long int[AKM_NUM_SENSORS])
#define ECS_IOCTL_GET_LAYOUT _IOR(AKMIO, 0x09, char)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define ECS_IOCTL_GET_OUTBIT _IOR(AKMIO, 0x0B, char)
#define ECS_IOCTL_RESET _IO(AKMIO, 0x0C)
#define ECS_IOCTL_GET_ACCEL _IOR(AKMIO, 0x30, short[3])
struct akm8963_platform_data {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 char layout;
 char outbit;
 int gpio_IRQ;
 int gpio_RST;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
#endif

