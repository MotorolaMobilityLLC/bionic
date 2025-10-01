/*
 * This file is auto-generated. Modifications will be lost.
 *
 * See https://android.googlesource.com/platform/bionic/+/master/libc/kernel/
 * for more information.
 */
#ifndef _UAPI_PWM_H_
#define _UAPI_PWM_H_
#include <linux/ioctl.h>
#include <linux/types.h>
struct pwmchip_waveform {
  __u32 hwpwm;
  __u32 __pad;
  __u64 period_length_ns;
  __u64 duty_length_ns;
  __u64 duty_offset_ns;
};
#define PWM_IOCTL_REQUEST _IO(0x75, 1)
#define PWM_IOCTL_FREE _IO(0x75, 2)
#define PWM_IOCTL_ROUNDWF _IOWR(0x75, 3, struct pwmchip_waveform)
#define PWM_IOCTL_GETWF _IOWR(0x75, 4, struct pwmchip_waveform)
#define PWM_IOCTL_SETROUNDEDWF _IOW(0x75, 5, struct pwmchip_waveform)
#define PWM_IOCTL_SETEXACTWF _IOW(0x75, 6, struct pwmchip_waveform)
#endif
