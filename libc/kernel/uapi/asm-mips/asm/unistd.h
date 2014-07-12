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
#ifndef _UAPI_ASM_UNISTD_H
#define _UAPI_ASM_UNISTD_H
#include <asm/sgidefs.h>
#if _MIPS_SIM == _MIPS_SIM_ABI32
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_Linux 4000
#define __NR_syscall (__NR_Linux + 0)
#define __NR_exit (__NR_Linux + 1)
#define __NR_fork (__NR_Linux + 2)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_read (__NR_Linux + 3)
#define __NR_write (__NR_Linux + 4)
#define __NR_open (__NR_Linux + 5)
#define __NR_close (__NR_Linux + 6)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_waitpid (__NR_Linux + 7)
#define __NR_creat (__NR_Linux + 8)
#define __NR_link (__NR_Linux + 9)
#define __NR_unlink (__NR_Linux + 10)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_execve (__NR_Linux + 11)
#define __NR_chdir (__NR_Linux + 12)
#define __NR_time (__NR_Linux + 13)
#define __NR_mknod (__NR_Linux + 14)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_chmod (__NR_Linux + 15)
#define __NR_lchown (__NR_Linux + 16)
#define __NR_break (__NR_Linux + 17)
#define __NR_unused18 (__NR_Linux + 18)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_lseek (__NR_Linux + 19)
#define __NR_getpid (__NR_Linux + 20)
#define __NR_mount (__NR_Linux + 21)
#define __NR_umount (__NR_Linux + 22)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_setuid (__NR_Linux + 23)
#define __NR_getuid (__NR_Linux + 24)
#define __NR_stime (__NR_Linux + 25)
#define __NR_ptrace (__NR_Linux + 26)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_alarm (__NR_Linux + 27)
#define __NR_unused28 (__NR_Linux + 28)
#define __NR_pause (__NR_Linux + 29)
#define __NR_utime (__NR_Linux + 30)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_stty (__NR_Linux + 31)
#define __NR_gtty (__NR_Linux + 32)
#define __NR_access (__NR_Linux + 33)
#define __NR_nice (__NR_Linux + 34)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_ftime (__NR_Linux + 35)
#define __NR_sync (__NR_Linux + 36)
#define __NR_kill (__NR_Linux + 37)
#define __NR_rename (__NR_Linux + 38)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_mkdir (__NR_Linux + 39)
#define __NR_rmdir (__NR_Linux + 40)
#define __NR_dup (__NR_Linux + 41)
#define __NR_pipe (__NR_Linux + 42)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_times (__NR_Linux + 43)
#define __NR_prof (__NR_Linux + 44)
#define __NR_brk (__NR_Linux + 45)
#define __NR_setgid (__NR_Linux + 46)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_getgid (__NR_Linux + 47)
#define __NR_signal (__NR_Linux + 48)
#define __NR_geteuid (__NR_Linux + 49)
#define __NR_getegid (__NR_Linux + 50)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_acct (__NR_Linux + 51)
#define __NR_umount2 (__NR_Linux + 52)
#define __NR_lock (__NR_Linux + 53)
#define __NR_ioctl (__NR_Linux + 54)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_fcntl (__NR_Linux + 55)
#define __NR_mpx (__NR_Linux + 56)
#define __NR_setpgid (__NR_Linux + 57)
#define __NR_ulimit (__NR_Linux + 58)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_unused59 (__NR_Linux + 59)
#define __NR_umask (__NR_Linux + 60)
#define __NR_chroot (__NR_Linux + 61)
#define __NR_ustat (__NR_Linux + 62)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_dup2 (__NR_Linux + 63)
#define __NR_getppid (__NR_Linux + 64)
#define __NR_getpgrp (__NR_Linux + 65)
#define __NR_setsid (__NR_Linux + 66)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_sigaction (__NR_Linux + 67)
#define __NR_sgetmask (__NR_Linux + 68)
#define __NR_ssetmask (__NR_Linux + 69)
#define __NR_setreuid (__NR_Linux + 70)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_setregid (__NR_Linux + 71)
#define __NR_sigsuspend (__NR_Linux + 72)
#define __NR_sigpending (__NR_Linux + 73)
#define __NR_sethostname (__NR_Linux + 74)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_setrlimit (__NR_Linux + 75)
#define __NR_getrlimit (__NR_Linux + 76)
#define __NR_getrusage (__NR_Linux + 77)
#define __NR_gettimeofday (__NR_Linux + 78)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_settimeofday (__NR_Linux + 79)
#define __NR_getgroups (__NR_Linux + 80)
#define __NR_setgroups (__NR_Linux + 81)
#define __NR_reserved82 (__NR_Linux + 82)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_symlink (__NR_Linux + 83)
#define __NR_unused84 (__NR_Linux + 84)
#define __NR_readlink (__NR_Linux + 85)
#define __NR_uselib (__NR_Linux + 86)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_swapon (__NR_Linux + 87)
#define __NR_reboot (__NR_Linux + 88)
#define __NR_readdir (__NR_Linux + 89)
#define __NR_mmap (__NR_Linux + 90)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_munmap (__NR_Linux + 91)
#define __NR_truncate (__NR_Linux + 92)
#define __NR_ftruncate (__NR_Linux + 93)
#define __NR_fchmod (__NR_Linux + 94)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_fchown (__NR_Linux + 95)
#define __NR_getpriority (__NR_Linux + 96)
#define __NR_setpriority (__NR_Linux + 97)
#define __NR_profil (__NR_Linux + 98)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_statfs (__NR_Linux + 99)
#define __NR_fstatfs (__NR_Linux + 100)
#define __NR_ioperm (__NR_Linux + 101)
#define __NR_socketcall (__NR_Linux + 102)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_syslog (__NR_Linux + 103)
#define __NR_setitimer (__NR_Linux + 104)
#define __NR_getitimer (__NR_Linux + 105)
#define __NR_stat (__NR_Linux + 106)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_lstat (__NR_Linux + 107)
#define __NR_fstat (__NR_Linux + 108)
#define __NR_unused109 (__NR_Linux + 109)
#define __NR_iopl (__NR_Linux + 110)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_vhangup (__NR_Linux + 111)
#define __NR_idle (__NR_Linux + 112)
#define __NR_vm86 (__NR_Linux + 113)
#define __NR_wait4 (__NR_Linux + 114)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_swapoff (__NR_Linux + 115)
#define __NR_sysinfo (__NR_Linux + 116)
#define __NR_ipc (__NR_Linux + 117)
#define __NR_fsync (__NR_Linux + 118)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_sigreturn (__NR_Linux + 119)
#define __NR_clone (__NR_Linux + 120)
#define __NR_setdomainname (__NR_Linux + 121)
#define __NR_uname (__NR_Linux + 122)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_modify_ldt (__NR_Linux + 123)
#define __NR_adjtimex (__NR_Linux + 124)
#define __NR_mprotect (__NR_Linux + 125)
#define __NR_sigprocmask (__NR_Linux + 126)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_create_module (__NR_Linux + 127)
#define __NR_init_module (__NR_Linux + 128)
#define __NR_delete_module (__NR_Linux + 129)
#define __NR_get_kernel_syms (__NR_Linux + 130)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_quotactl (__NR_Linux + 131)
#define __NR_getpgid (__NR_Linux + 132)
#define __NR_fchdir (__NR_Linux + 133)
#define __NR_bdflush (__NR_Linux + 134)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_sysfs (__NR_Linux + 135)
#define __NR_personality (__NR_Linux + 136)
#define __NR_afs_syscall (__NR_Linux + 137)
#define __NR_setfsuid (__NR_Linux + 138)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_setfsgid (__NR_Linux + 139)
#define __NR__llseek (__NR_Linux + 140)
#define __NR_getdents (__NR_Linux + 141)
#define __NR__newselect (__NR_Linux + 142)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_flock (__NR_Linux + 143)
#define __NR_msync (__NR_Linux + 144)
#define __NR_readv (__NR_Linux + 145)
#define __NR_writev (__NR_Linux + 146)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_cacheflush (__NR_Linux + 147)
#define __NR_cachectl (__NR_Linux + 148)
#define __NR_sysmips (__NR_Linux + 149)
#define __NR_unused150 (__NR_Linux + 150)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_getsid (__NR_Linux + 151)
#define __NR_fdatasync (__NR_Linux + 152)
#define __NR__sysctl (__NR_Linux + 153)
#define __NR_mlock (__NR_Linux + 154)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_munlock (__NR_Linux + 155)
#define __NR_mlockall (__NR_Linux + 156)
#define __NR_munlockall (__NR_Linux + 157)
#define __NR_sched_setparam (__NR_Linux + 158)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_sched_getparam (__NR_Linux + 159)
#define __NR_sched_setscheduler (__NR_Linux + 160)
#define __NR_sched_getscheduler (__NR_Linux + 161)
#define __NR_sched_yield (__NR_Linux + 162)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_sched_get_priority_max (__NR_Linux + 163)
#define __NR_sched_get_priority_min (__NR_Linux + 164)
#define __NR_sched_rr_get_interval (__NR_Linux + 165)
#define __NR_nanosleep (__NR_Linux + 166)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_mremap (__NR_Linux + 167)
#define __NR_accept (__NR_Linux + 168)
#define __NR_bind (__NR_Linux + 169)
#define __NR_connect (__NR_Linux + 170)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_getpeername (__NR_Linux + 171)
#define __NR_getsockname (__NR_Linux + 172)
#define __NR_getsockopt (__NR_Linux + 173)
#define __NR_listen (__NR_Linux + 174)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_recv (__NR_Linux + 175)
#define __NR_recvfrom (__NR_Linux + 176)
#define __NR_recvmsg (__NR_Linux + 177)
#define __NR_send (__NR_Linux + 178)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_sendmsg (__NR_Linux + 179)
#define __NR_sendto (__NR_Linux + 180)
#define __NR_setsockopt (__NR_Linux + 181)
#define __NR_shutdown (__NR_Linux + 182)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_socket (__NR_Linux + 183)
#define __NR_socketpair (__NR_Linux + 184)
#define __NR_setresuid (__NR_Linux + 185)
#define __NR_getresuid (__NR_Linux + 186)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_query_module (__NR_Linux + 187)
#define __NR_poll (__NR_Linux + 188)
#define __NR_nfsservctl (__NR_Linux + 189)
#define __NR_setresgid (__NR_Linux + 190)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_getresgid (__NR_Linux + 191)
#define __NR_prctl (__NR_Linux + 192)
#define __NR_rt_sigreturn (__NR_Linux + 193)
#define __NR_rt_sigaction (__NR_Linux + 194)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_rt_sigprocmask (__NR_Linux + 195)
#define __NR_rt_sigpending (__NR_Linux + 196)
#define __NR_rt_sigtimedwait (__NR_Linux + 197)
#define __NR_rt_sigqueueinfo (__NR_Linux + 198)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_rt_sigsuspend (__NR_Linux + 199)
#define __NR_pread64 (__NR_Linux + 200)
#define __NR_pwrite64 (__NR_Linux + 201)
#define __NR_chown (__NR_Linux + 202)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_getcwd (__NR_Linux + 203)
#define __NR_capget (__NR_Linux + 204)
#define __NR_capset (__NR_Linux + 205)
#define __NR_sigaltstack (__NR_Linux + 206)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_sendfile (__NR_Linux + 207)
#define __NR_getpmsg (__NR_Linux + 208)
#define __NR_putpmsg (__NR_Linux + 209)
#define __NR_mmap2 (__NR_Linux + 210)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_truncate64 (__NR_Linux + 211)
#define __NR_ftruncate64 (__NR_Linux + 212)
#define __NR_stat64 (__NR_Linux + 213)
#define __NR_lstat64 (__NR_Linux + 214)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_fstat64 (__NR_Linux + 215)
#define __NR_pivot_root (__NR_Linux + 216)
#define __NR_mincore (__NR_Linux + 217)
#define __NR_madvise (__NR_Linux + 218)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_getdents64 (__NR_Linux + 219)
#define __NR_fcntl64 (__NR_Linux + 220)
#define __NR_reserved221 (__NR_Linux + 221)
#define __NR_gettid (__NR_Linux + 222)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_readahead (__NR_Linux + 223)
#define __NR_setxattr (__NR_Linux + 224)
#define __NR_lsetxattr (__NR_Linux + 225)
#define __NR_fsetxattr (__NR_Linux + 226)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_getxattr (__NR_Linux + 227)
#define __NR_lgetxattr (__NR_Linux + 228)
#define __NR_fgetxattr (__NR_Linux + 229)
#define __NR_listxattr (__NR_Linux + 230)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_llistxattr (__NR_Linux + 231)
#define __NR_flistxattr (__NR_Linux + 232)
#define __NR_removexattr (__NR_Linux + 233)
#define __NR_lremovexattr (__NR_Linux + 234)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_fremovexattr (__NR_Linux + 235)
#define __NR_tkill (__NR_Linux + 236)
#define __NR_sendfile64 (__NR_Linux + 237)
#define __NR_futex (__NR_Linux + 238)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_sched_setaffinity (__NR_Linux + 239)
#define __NR_sched_getaffinity (__NR_Linux + 240)
#define __NR_io_setup (__NR_Linux + 241)
#define __NR_io_destroy (__NR_Linux + 242)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_io_getevents (__NR_Linux + 243)
#define __NR_io_submit (__NR_Linux + 244)
#define __NR_io_cancel (__NR_Linux + 245)
#define __NR_exit_group (__NR_Linux + 246)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_lookup_dcookie (__NR_Linux + 247)
#define __NR_epoll_create (__NR_Linux + 248)
#define __NR_epoll_ctl (__NR_Linux + 249)
#define __NR_epoll_wait (__NR_Linux + 250)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_remap_file_pages (__NR_Linux + 251)
#define __NR_set_tid_address (__NR_Linux + 252)
#define __NR_restart_syscall (__NR_Linux + 253)
#define __NR_fadvise64 (__NR_Linux + 254)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_statfs64 (__NR_Linux + 255)
#define __NR_fstatfs64 (__NR_Linux + 256)
#define __NR_timer_create (__NR_Linux + 257)
#define __NR_timer_settime (__NR_Linux + 258)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_timer_gettime (__NR_Linux + 259)
#define __NR_timer_getoverrun (__NR_Linux + 260)
#define __NR_timer_delete (__NR_Linux + 261)
#define __NR_clock_settime (__NR_Linux + 262)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_clock_gettime (__NR_Linux + 263)
#define __NR_clock_getres (__NR_Linux + 264)
#define __NR_clock_nanosleep (__NR_Linux + 265)
#define __NR_tgkill (__NR_Linux + 266)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_utimes (__NR_Linux + 267)
#define __NR_mbind (__NR_Linux + 268)
#define __NR_get_mempolicy (__NR_Linux + 269)
#define __NR_set_mempolicy (__NR_Linux + 270)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_mq_open (__NR_Linux + 271)
#define __NR_mq_unlink (__NR_Linux + 272)
#define __NR_mq_timedsend (__NR_Linux + 273)
#define __NR_mq_timedreceive (__NR_Linux + 274)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_mq_notify (__NR_Linux + 275)
#define __NR_mq_getsetattr (__NR_Linux + 276)
#define __NR_vserver (__NR_Linux + 277)
#define __NR_waitid (__NR_Linux + 278)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_add_key (__NR_Linux + 280)
#define __NR_request_key (__NR_Linux + 281)
#define __NR_keyctl (__NR_Linux + 282)
#define __NR_set_thread_area (__NR_Linux + 283)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_inotify_init (__NR_Linux + 284)
#define __NR_inotify_add_watch (__NR_Linux + 285)
#define __NR_inotify_rm_watch (__NR_Linux + 286)
#define __NR_migrate_pages (__NR_Linux + 287)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_openat (__NR_Linux + 288)
#define __NR_mkdirat (__NR_Linux + 289)
#define __NR_mknodat (__NR_Linux + 290)
#define __NR_fchownat (__NR_Linux + 291)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_futimesat (__NR_Linux + 292)
#define __NR_fstatat64 (__NR_Linux + 293)
#define __NR_unlinkat (__NR_Linux + 294)
#define __NR_renameat (__NR_Linux + 295)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_linkat (__NR_Linux + 296)
#define __NR_symlinkat (__NR_Linux + 297)
#define __NR_readlinkat (__NR_Linux + 298)
#define __NR_fchmodat (__NR_Linux + 299)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_faccessat (__NR_Linux + 300)
#define __NR_pselect6 (__NR_Linux + 301)
#define __NR_ppoll (__NR_Linux + 302)
#define __NR_unshare (__NR_Linux + 303)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_splice (__NR_Linux + 304)
#define __NR_sync_file_range (__NR_Linux + 305)
#define __NR_tee (__NR_Linux + 306)
#define __NR_vmsplice (__NR_Linux + 307)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_move_pages (__NR_Linux + 308)
#define __NR_set_robust_list (__NR_Linux + 309)
#define __NR_get_robust_list (__NR_Linux + 310)
#define __NR_kexec_load (__NR_Linux + 311)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_getcpu (__NR_Linux + 312)
#define __NR_epoll_pwait (__NR_Linux + 313)
#define __NR_ioprio_set (__NR_Linux + 314)
#define __NR_ioprio_get (__NR_Linux + 315)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_utimensat (__NR_Linux + 316)
#define __NR_signalfd (__NR_Linux + 317)
#define __NR_timerfd (__NR_Linux + 318)
#define __NR_eventfd (__NR_Linux + 319)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_fallocate (__NR_Linux + 320)
#define __NR_timerfd_create (__NR_Linux + 321)
#define __NR_timerfd_gettime (__NR_Linux + 322)
#define __NR_timerfd_settime (__NR_Linux + 323)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_signalfd4 (__NR_Linux + 324)
#define __NR_eventfd2 (__NR_Linux + 325)
#define __NR_epoll_create1 (__NR_Linux + 326)
#define __NR_dup3 (__NR_Linux + 327)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_pipe2 (__NR_Linux + 328)
#define __NR_inotify_init1 (__NR_Linux + 329)
#define __NR_preadv (__NR_Linux + 330)
#define __NR_pwritev (__NR_Linux + 331)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_rt_tgsigqueueinfo (__NR_Linux + 332)
#define __NR_perf_event_open (__NR_Linux + 333)
#define __NR_accept4 (__NR_Linux + 334)
#define __NR_recvmmsg (__NR_Linux + 335)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_fanotify_init (__NR_Linux + 336)
#define __NR_fanotify_mark (__NR_Linux + 337)
#define __NR_prlimit64 (__NR_Linux + 338)
#define __NR_name_to_handle_at (__NR_Linux + 339)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_open_by_handle_at (__NR_Linux + 340)
#define __NR_clock_adjtime (__NR_Linux + 341)
#define __NR_syncfs (__NR_Linux + 342)
#define __NR_sendmmsg (__NR_Linux + 343)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_setns (__NR_Linux + 344)
#define __NR_process_vm_readv (__NR_Linux + 345)
#define __NR_process_vm_writev (__NR_Linux + 346)
#define __NR_kcmp (__NR_Linux + 347)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_finit_module (__NR_Linux + 348)
#define __NR_sched_setattr (__NR_Linux + 349)
#define __NR_sched_getattr (__NR_Linux + 350)
#define __NR_Linux_syscalls 350
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#endif
#define __NR_O32_Linux 4000
#define __NR_O32_Linux_syscalls 350
#if _MIPS_SIM == _MIPS_SIM_ABI64
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_Linux 5000
#define __NR_read (__NR_Linux + 0)
#define __NR_write (__NR_Linux + 1)
#define __NR_open (__NR_Linux + 2)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_close (__NR_Linux + 3)
#define __NR_stat (__NR_Linux + 4)
#define __NR_fstat (__NR_Linux + 5)
#define __NR_lstat (__NR_Linux + 6)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_poll (__NR_Linux + 7)
#define __NR_lseek (__NR_Linux + 8)
#define __NR_mmap (__NR_Linux + 9)
#define __NR_mprotect (__NR_Linux + 10)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_munmap (__NR_Linux + 11)
#define __NR_brk (__NR_Linux + 12)
#define __NR_rt_sigaction (__NR_Linux + 13)
#define __NR_rt_sigprocmask (__NR_Linux + 14)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_ioctl (__NR_Linux + 15)
#define __NR_pread64 (__NR_Linux + 16)
#define __NR_pwrite64 (__NR_Linux + 17)
#define __NR_readv (__NR_Linux + 18)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_writev (__NR_Linux + 19)
#define __NR_access (__NR_Linux + 20)
#define __NR_pipe (__NR_Linux + 21)
#define __NR__newselect (__NR_Linux + 22)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_sched_yield (__NR_Linux + 23)
#define __NR_mremap (__NR_Linux + 24)
#define __NR_msync (__NR_Linux + 25)
#define __NR_mincore (__NR_Linux + 26)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_madvise (__NR_Linux + 27)
#define __NR_shmget (__NR_Linux + 28)
#define __NR_shmat (__NR_Linux + 29)
#define __NR_shmctl (__NR_Linux + 30)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_dup (__NR_Linux + 31)
#define __NR_dup2 (__NR_Linux + 32)
#define __NR_pause (__NR_Linux + 33)
#define __NR_nanosleep (__NR_Linux + 34)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_getitimer (__NR_Linux + 35)
#define __NR_setitimer (__NR_Linux + 36)
#define __NR_alarm (__NR_Linux + 37)
#define __NR_getpid (__NR_Linux + 38)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_sendfile (__NR_Linux + 39)
#define __NR_socket (__NR_Linux + 40)
#define __NR_connect (__NR_Linux + 41)
#define __NR_accept (__NR_Linux + 42)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_sendto (__NR_Linux + 43)
#define __NR_recvfrom (__NR_Linux + 44)
#define __NR_sendmsg (__NR_Linux + 45)
#define __NR_recvmsg (__NR_Linux + 46)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_shutdown (__NR_Linux + 47)
#define __NR_bind (__NR_Linux + 48)
#define __NR_listen (__NR_Linux + 49)
#define __NR_getsockname (__NR_Linux + 50)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_getpeername (__NR_Linux + 51)
#define __NR_socketpair (__NR_Linux + 52)
#define __NR_setsockopt (__NR_Linux + 53)
#define __NR_getsockopt (__NR_Linux + 54)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_clone (__NR_Linux + 55)
#define __NR_fork (__NR_Linux + 56)
#define __NR_execve (__NR_Linux + 57)
#define __NR_exit (__NR_Linux + 58)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_wait4 (__NR_Linux + 59)
#define __NR_kill (__NR_Linux + 60)
#define __NR_uname (__NR_Linux + 61)
#define __NR_semget (__NR_Linux + 62)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_semop (__NR_Linux + 63)
#define __NR_semctl (__NR_Linux + 64)
#define __NR_shmdt (__NR_Linux + 65)
#define __NR_msgget (__NR_Linux + 66)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_msgsnd (__NR_Linux + 67)
#define __NR_msgrcv (__NR_Linux + 68)
#define __NR_msgctl (__NR_Linux + 69)
#define __NR_fcntl (__NR_Linux + 70)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_flock (__NR_Linux + 71)
#define __NR_fsync (__NR_Linux + 72)
#define __NR_fdatasync (__NR_Linux + 73)
#define __NR_truncate (__NR_Linux + 74)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_ftruncate (__NR_Linux + 75)
#define __NR_getdents (__NR_Linux + 76)
#define __NR_getcwd (__NR_Linux + 77)
#define __NR_chdir (__NR_Linux + 78)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_fchdir (__NR_Linux + 79)
#define __NR_rename (__NR_Linux + 80)
#define __NR_mkdir (__NR_Linux + 81)
#define __NR_rmdir (__NR_Linux + 82)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_creat (__NR_Linux + 83)
#define __NR_link (__NR_Linux + 84)
#define __NR_unlink (__NR_Linux + 85)
#define __NR_symlink (__NR_Linux + 86)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_readlink (__NR_Linux + 87)
#define __NR_chmod (__NR_Linux + 88)
#define __NR_fchmod (__NR_Linux + 89)
#define __NR_chown (__NR_Linux + 90)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_fchown (__NR_Linux + 91)
#define __NR_lchown (__NR_Linux + 92)
#define __NR_umask (__NR_Linux + 93)
#define __NR_gettimeofday (__NR_Linux + 94)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_getrlimit (__NR_Linux + 95)
#define __NR_getrusage (__NR_Linux + 96)
#define __NR_sysinfo (__NR_Linux + 97)
#define __NR_times (__NR_Linux + 98)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_ptrace (__NR_Linux + 99)
#define __NR_getuid (__NR_Linux + 100)
#define __NR_syslog (__NR_Linux + 101)
#define __NR_getgid (__NR_Linux + 102)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_setuid (__NR_Linux + 103)
#define __NR_setgid (__NR_Linux + 104)
#define __NR_geteuid (__NR_Linux + 105)
#define __NR_getegid (__NR_Linux + 106)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_setpgid (__NR_Linux + 107)
#define __NR_getppid (__NR_Linux + 108)
#define __NR_getpgrp (__NR_Linux + 109)
#define __NR_setsid (__NR_Linux + 110)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_setreuid (__NR_Linux + 111)
#define __NR_setregid (__NR_Linux + 112)
#define __NR_getgroups (__NR_Linux + 113)
#define __NR_setgroups (__NR_Linux + 114)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_setresuid (__NR_Linux + 115)
#define __NR_getresuid (__NR_Linux + 116)
#define __NR_setresgid (__NR_Linux + 117)
#define __NR_getresgid (__NR_Linux + 118)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_getpgid (__NR_Linux + 119)
#define __NR_setfsuid (__NR_Linux + 120)
#define __NR_setfsgid (__NR_Linux + 121)
#define __NR_getsid (__NR_Linux + 122)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_capget (__NR_Linux + 123)
#define __NR_capset (__NR_Linux + 124)
#define __NR_rt_sigpending (__NR_Linux + 125)
#define __NR_rt_sigtimedwait (__NR_Linux + 126)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_rt_sigqueueinfo (__NR_Linux + 127)
#define __NR_rt_sigsuspend (__NR_Linux + 128)
#define __NR_sigaltstack (__NR_Linux + 129)
#define __NR_utime (__NR_Linux + 130)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_mknod (__NR_Linux + 131)
#define __NR_personality (__NR_Linux + 132)
#define __NR_ustat (__NR_Linux + 133)
#define __NR_statfs (__NR_Linux + 134)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_fstatfs (__NR_Linux + 135)
#define __NR_sysfs (__NR_Linux + 136)
#define __NR_getpriority (__NR_Linux + 137)
#define __NR_setpriority (__NR_Linux + 138)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_sched_setparam (__NR_Linux + 139)
#define __NR_sched_getparam (__NR_Linux + 140)
#define __NR_sched_setscheduler (__NR_Linux + 141)
#define __NR_sched_getscheduler (__NR_Linux + 142)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_sched_get_priority_max (__NR_Linux + 143)
#define __NR_sched_get_priority_min (__NR_Linux + 144)
#define __NR_sched_rr_get_interval (__NR_Linux + 145)
#define __NR_mlock (__NR_Linux + 146)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_munlock (__NR_Linux + 147)
#define __NR_mlockall (__NR_Linux + 148)
#define __NR_munlockall (__NR_Linux + 149)
#define __NR_vhangup (__NR_Linux + 150)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_pivot_root (__NR_Linux + 151)
#define __NR__sysctl (__NR_Linux + 152)
#define __NR_prctl (__NR_Linux + 153)
#define __NR_adjtimex (__NR_Linux + 154)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_setrlimit (__NR_Linux + 155)
#define __NR_chroot (__NR_Linux + 156)
#define __NR_sync (__NR_Linux + 157)
#define __NR_acct (__NR_Linux + 158)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_settimeofday (__NR_Linux + 159)
#define __NR_mount (__NR_Linux + 160)
#define __NR_umount2 (__NR_Linux + 161)
#define __NR_swapon (__NR_Linux + 162)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_swapoff (__NR_Linux + 163)
#define __NR_reboot (__NR_Linux + 164)
#define __NR_sethostname (__NR_Linux + 165)
#define __NR_setdomainname (__NR_Linux + 166)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_create_module (__NR_Linux + 167)
#define __NR_init_module (__NR_Linux + 168)
#define __NR_delete_module (__NR_Linux + 169)
#define __NR_get_kernel_syms (__NR_Linux + 170)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_query_module (__NR_Linux + 171)
#define __NR_quotactl (__NR_Linux + 172)
#define __NR_nfsservctl (__NR_Linux + 173)
#define __NR_getpmsg (__NR_Linux + 174)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_putpmsg (__NR_Linux + 175)
#define __NR_afs_syscall (__NR_Linux + 176)
#define __NR_reserved177 (__NR_Linux + 177)
#define __NR_gettid (__NR_Linux + 178)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_readahead (__NR_Linux + 179)
#define __NR_setxattr (__NR_Linux + 180)
#define __NR_lsetxattr (__NR_Linux + 181)
#define __NR_fsetxattr (__NR_Linux + 182)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_getxattr (__NR_Linux + 183)
#define __NR_lgetxattr (__NR_Linux + 184)
#define __NR_fgetxattr (__NR_Linux + 185)
#define __NR_listxattr (__NR_Linux + 186)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_llistxattr (__NR_Linux + 187)
#define __NR_flistxattr (__NR_Linux + 188)
#define __NR_removexattr (__NR_Linux + 189)
#define __NR_lremovexattr (__NR_Linux + 190)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_fremovexattr (__NR_Linux + 191)
#define __NR_tkill (__NR_Linux + 192)
#define __NR_reserved193 (__NR_Linux + 193)
#define __NR_futex (__NR_Linux + 194)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_sched_setaffinity (__NR_Linux + 195)
#define __NR_sched_getaffinity (__NR_Linux + 196)
#define __NR_cacheflush (__NR_Linux + 197)
#define __NR_cachectl (__NR_Linux + 198)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_sysmips (__NR_Linux + 199)
#define __NR_io_setup (__NR_Linux + 200)
#define __NR_io_destroy (__NR_Linux + 201)
#define __NR_io_getevents (__NR_Linux + 202)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_io_submit (__NR_Linux + 203)
#define __NR_io_cancel (__NR_Linux + 204)
#define __NR_exit_group (__NR_Linux + 205)
#define __NR_lookup_dcookie (__NR_Linux + 206)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_epoll_create (__NR_Linux + 207)
#define __NR_epoll_ctl (__NR_Linux + 208)
#define __NR_epoll_wait (__NR_Linux + 209)
#define __NR_remap_file_pages (__NR_Linux + 210)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_rt_sigreturn (__NR_Linux + 211)
#define __NR_set_tid_address (__NR_Linux + 212)
#define __NR_restart_syscall (__NR_Linux + 213)
#define __NR_semtimedop (__NR_Linux + 214)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_fadvise64 (__NR_Linux + 215)
#define __NR_timer_create (__NR_Linux + 216)
#define __NR_timer_settime (__NR_Linux + 217)
#define __NR_timer_gettime (__NR_Linux + 218)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_timer_getoverrun (__NR_Linux + 219)
#define __NR_timer_delete (__NR_Linux + 220)
#define __NR_clock_settime (__NR_Linux + 221)
#define __NR_clock_gettime (__NR_Linux + 222)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_clock_getres (__NR_Linux + 223)
#define __NR_clock_nanosleep (__NR_Linux + 224)
#define __NR_tgkill (__NR_Linux + 225)
#define __NR_utimes (__NR_Linux + 226)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_mbind (__NR_Linux + 227)
#define __NR_get_mempolicy (__NR_Linux + 228)
#define __NR_set_mempolicy (__NR_Linux + 229)
#define __NR_mq_open (__NR_Linux + 230)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_mq_unlink (__NR_Linux + 231)
#define __NR_mq_timedsend (__NR_Linux + 232)
#define __NR_mq_timedreceive (__NR_Linux + 233)
#define __NR_mq_notify (__NR_Linux + 234)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_mq_getsetattr (__NR_Linux + 235)
#define __NR_vserver (__NR_Linux + 236)
#define __NR_waitid (__NR_Linux + 237)
#define __NR_add_key (__NR_Linux + 239)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_request_key (__NR_Linux + 240)
#define __NR_keyctl (__NR_Linux + 241)
#define __NR_set_thread_area (__NR_Linux + 242)
#define __NR_inotify_init (__NR_Linux + 243)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_inotify_add_watch (__NR_Linux + 244)
#define __NR_inotify_rm_watch (__NR_Linux + 245)
#define __NR_migrate_pages (__NR_Linux + 246)
#define __NR_openat (__NR_Linux + 247)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_mkdirat (__NR_Linux + 248)
#define __NR_mknodat (__NR_Linux + 249)
#define __NR_fchownat (__NR_Linux + 250)
#define __NR_futimesat (__NR_Linux + 251)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_newfstatat (__NR_Linux + 252)
#define __NR_unlinkat (__NR_Linux + 253)
#define __NR_renameat (__NR_Linux + 254)
#define __NR_linkat (__NR_Linux + 255)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_symlinkat (__NR_Linux + 256)
#define __NR_readlinkat (__NR_Linux + 257)
#define __NR_fchmodat (__NR_Linux + 258)
#define __NR_faccessat (__NR_Linux + 259)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_pselect6 (__NR_Linux + 260)
#define __NR_ppoll (__NR_Linux + 261)
#define __NR_unshare (__NR_Linux + 262)
#define __NR_splice (__NR_Linux + 263)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_sync_file_range (__NR_Linux + 264)
#define __NR_tee (__NR_Linux + 265)
#define __NR_vmsplice (__NR_Linux + 266)
#define __NR_move_pages (__NR_Linux + 267)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_set_robust_list (__NR_Linux + 268)
#define __NR_get_robust_list (__NR_Linux + 269)
#define __NR_kexec_load (__NR_Linux + 270)
#define __NR_getcpu (__NR_Linux + 271)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_epoll_pwait (__NR_Linux + 272)
#define __NR_ioprio_set (__NR_Linux + 273)
#define __NR_ioprio_get (__NR_Linux + 274)
#define __NR_utimensat (__NR_Linux + 275)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_signalfd (__NR_Linux + 276)
#define __NR_timerfd (__NR_Linux + 277)
#define __NR_eventfd (__NR_Linux + 278)
#define __NR_fallocate (__NR_Linux + 279)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_timerfd_create (__NR_Linux + 280)
#define __NR_timerfd_gettime (__NR_Linux + 281)
#define __NR_timerfd_settime (__NR_Linux + 282)
#define __NR_signalfd4 (__NR_Linux + 283)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_eventfd2 (__NR_Linux + 284)
#define __NR_epoll_create1 (__NR_Linux + 285)
#define __NR_dup3 (__NR_Linux + 286)
#define __NR_pipe2 (__NR_Linux + 287)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_inotify_init1 (__NR_Linux + 288)
#define __NR_preadv (__NR_Linux + 289)
#define __NR_pwritev (__NR_Linux + 290)
#define __NR_rt_tgsigqueueinfo (__NR_Linux + 291)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_perf_event_open (__NR_Linux + 292)
#define __NR_accept4 (__NR_Linux + 293)
#define __NR_recvmmsg (__NR_Linux + 294)
#define __NR_fanotify_init (__NR_Linux + 295)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_fanotify_mark (__NR_Linux + 296)
#define __NR_prlimit64 (__NR_Linux + 297)
#define __NR_name_to_handle_at (__NR_Linux + 298)
#define __NR_open_by_handle_at (__NR_Linux + 299)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_clock_adjtime (__NR_Linux + 300)
#define __NR_syncfs (__NR_Linux + 301)
#define __NR_sendmmsg (__NR_Linux + 302)
#define __NR_setns (__NR_Linux + 303)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_process_vm_readv (__NR_Linux + 304)
#define __NR_process_vm_writev (__NR_Linux + 305)
#define __NR_kcmp (__NR_Linux + 306)
#define __NR_finit_module (__NR_Linux + 307)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_getdents64 (__NR_Linux + 308)
#define __NR_sched_setattr (__NR_Linux + 309)
#define __NR_sched_getattr (__NR_Linux + 310)
#define __NR_Linux_syscalls 310
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#endif
#define __NR_64_Linux 5000
#define __NR_64_Linux_syscalls 310
#if _MIPS_SIM == _MIPS_SIM_NABI32
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_Linux 6000
#define __NR_read (__NR_Linux + 0)
#define __NR_write (__NR_Linux + 1)
#define __NR_open (__NR_Linux + 2)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_close (__NR_Linux + 3)
#define __NR_stat (__NR_Linux + 4)
#define __NR_fstat (__NR_Linux + 5)
#define __NR_lstat (__NR_Linux + 6)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_poll (__NR_Linux + 7)
#define __NR_lseek (__NR_Linux + 8)
#define __NR_mmap (__NR_Linux + 9)
#define __NR_mprotect (__NR_Linux + 10)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_munmap (__NR_Linux + 11)
#define __NR_brk (__NR_Linux + 12)
#define __NR_rt_sigaction (__NR_Linux + 13)
#define __NR_rt_sigprocmask (__NR_Linux + 14)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_ioctl (__NR_Linux + 15)
#define __NR_pread64 (__NR_Linux + 16)
#define __NR_pwrite64 (__NR_Linux + 17)
#define __NR_readv (__NR_Linux + 18)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_writev (__NR_Linux + 19)
#define __NR_access (__NR_Linux + 20)
#define __NR_pipe (__NR_Linux + 21)
#define __NR__newselect (__NR_Linux + 22)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_sched_yield (__NR_Linux + 23)
#define __NR_mremap (__NR_Linux + 24)
#define __NR_msync (__NR_Linux + 25)
#define __NR_mincore (__NR_Linux + 26)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_madvise (__NR_Linux + 27)
#define __NR_shmget (__NR_Linux + 28)
#define __NR_shmat (__NR_Linux + 29)
#define __NR_shmctl (__NR_Linux + 30)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_dup (__NR_Linux + 31)
#define __NR_dup2 (__NR_Linux + 32)
#define __NR_pause (__NR_Linux + 33)
#define __NR_nanosleep (__NR_Linux + 34)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_getitimer (__NR_Linux + 35)
#define __NR_setitimer (__NR_Linux + 36)
#define __NR_alarm (__NR_Linux + 37)
#define __NR_getpid (__NR_Linux + 38)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_sendfile (__NR_Linux + 39)
#define __NR_socket (__NR_Linux + 40)
#define __NR_connect (__NR_Linux + 41)
#define __NR_accept (__NR_Linux + 42)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_sendto (__NR_Linux + 43)
#define __NR_recvfrom (__NR_Linux + 44)
#define __NR_sendmsg (__NR_Linux + 45)
#define __NR_recvmsg (__NR_Linux + 46)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_shutdown (__NR_Linux + 47)
#define __NR_bind (__NR_Linux + 48)
#define __NR_listen (__NR_Linux + 49)
#define __NR_getsockname (__NR_Linux + 50)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_getpeername (__NR_Linux + 51)
#define __NR_socketpair (__NR_Linux + 52)
#define __NR_setsockopt (__NR_Linux + 53)
#define __NR_getsockopt (__NR_Linux + 54)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_clone (__NR_Linux + 55)
#define __NR_fork (__NR_Linux + 56)
#define __NR_execve (__NR_Linux + 57)
#define __NR_exit (__NR_Linux + 58)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_wait4 (__NR_Linux + 59)
#define __NR_kill (__NR_Linux + 60)
#define __NR_uname (__NR_Linux + 61)
#define __NR_semget (__NR_Linux + 62)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_semop (__NR_Linux + 63)
#define __NR_semctl (__NR_Linux + 64)
#define __NR_shmdt (__NR_Linux + 65)
#define __NR_msgget (__NR_Linux + 66)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_msgsnd (__NR_Linux + 67)
#define __NR_msgrcv (__NR_Linux + 68)
#define __NR_msgctl (__NR_Linux + 69)
#define __NR_fcntl (__NR_Linux + 70)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_flock (__NR_Linux + 71)
#define __NR_fsync (__NR_Linux + 72)
#define __NR_fdatasync (__NR_Linux + 73)
#define __NR_truncate (__NR_Linux + 74)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_ftruncate (__NR_Linux + 75)
#define __NR_getdents (__NR_Linux + 76)
#define __NR_getcwd (__NR_Linux + 77)
#define __NR_chdir (__NR_Linux + 78)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_fchdir (__NR_Linux + 79)
#define __NR_rename (__NR_Linux + 80)
#define __NR_mkdir (__NR_Linux + 81)
#define __NR_rmdir (__NR_Linux + 82)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_creat (__NR_Linux + 83)
#define __NR_link (__NR_Linux + 84)
#define __NR_unlink (__NR_Linux + 85)
#define __NR_symlink (__NR_Linux + 86)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_readlink (__NR_Linux + 87)
#define __NR_chmod (__NR_Linux + 88)
#define __NR_fchmod (__NR_Linux + 89)
#define __NR_chown (__NR_Linux + 90)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_fchown (__NR_Linux + 91)
#define __NR_lchown (__NR_Linux + 92)
#define __NR_umask (__NR_Linux + 93)
#define __NR_gettimeofday (__NR_Linux + 94)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_getrlimit (__NR_Linux + 95)
#define __NR_getrusage (__NR_Linux + 96)
#define __NR_sysinfo (__NR_Linux + 97)
#define __NR_times (__NR_Linux + 98)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_ptrace (__NR_Linux + 99)
#define __NR_getuid (__NR_Linux + 100)
#define __NR_syslog (__NR_Linux + 101)
#define __NR_getgid (__NR_Linux + 102)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_setuid (__NR_Linux + 103)
#define __NR_setgid (__NR_Linux + 104)
#define __NR_geteuid (__NR_Linux + 105)
#define __NR_getegid (__NR_Linux + 106)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_setpgid (__NR_Linux + 107)
#define __NR_getppid (__NR_Linux + 108)
#define __NR_getpgrp (__NR_Linux + 109)
#define __NR_setsid (__NR_Linux + 110)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_setreuid (__NR_Linux + 111)
#define __NR_setregid (__NR_Linux + 112)
#define __NR_getgroups (__NR_Linux + 113)
#define __NR_setgroups (__NR_Linux + 114)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_setresuid (__NR_Linux + 115)
#define __NR_getresuid (__NR_Linux + 116)
#define __NR_setresgid (__NR_Linux + 117)
#define __NR_getresgid (__NR_Linux + 118)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_getpgid (__NR_Linux + 119)
#define __NR_setfsuid (__NR_Linux + 120)
#define __NR_setfsgid (__NR_Linux + 121)
#define __NR_getsid (__NR_Linux + 122)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_capget (__NR_Linux + 123)
#define __NR_capset (__NR_Linux + 124)
#define __NR_rt_sigpending (__NR_Linux + 125)
#define __NR_rt_sigtimedwait (__NR_Linux + 126)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_rt_sigqueueinfo (__NR_Linux + 127)
#define __NR_rt_sigsuspend (__NR_Linux + 128)
#define __NR_sigaltstack (__NR_Linux + 129)
#define __NR_utime (__NR_Linux + 130)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_mknod (__NR_Linux + 131)
#define __NR_personality (__NR_Linux + 132)
#define __NR_ustat (__NR_Linux + 133)
#define __NR_statfs (__NR_Linux + 134)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_fstatfs (__NR_Linux + 135)
#define __NR_sysfs (__NR_Linux + 136)
#define __NR_getpriority (__NR_Linux + 137)
#define __NR_setpriority (__NR_Linux + 138)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_sched_setparam (__NR_Linux + 139)
#define __NR_sched_getparam (__NR_Linux + 140)
#define __NR_sched_setscheduler (__NR_Linux + 141)
#define __NR_sched_getscheduler (__NR_Linux + 142)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_sched_get_priority_max (__NR_Linux + 143)
#define __NR_sched_get_priority_min (__NR_Linux + 144)
#define __NR_sched_rr_get_interval (__NR_Linux + 145)
#define __NR_mlock (__NR_Linux + 146)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_munlock (__NR_Linux + 147)
#define __NR_mlockall (__NR_Linux + 148)
#define __NR_munlockall (__NR_Linux + 149)
#define __NR_vhangup (__NR_Linux + 150)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_pivot_root (__NR_Linux + 151)
#define __NR__sysctl (__NR_Linux + 152)
#define __NR_prctl (__NR_Linux + 153)
#define __NR_adjtimex (__NR_Linux + 154)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_setrlimit (__NR_Linux + 155)
#define __NR_chroot (__NR_Linux + 156)
#define __NR_sync (__NR_Linux + 157)
#define __NR_acct (__NR_Linux + 158)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_settimeofday (__NR_Linux + 159)
#define __NR_mount (__NR_Linux + 160)
#define __NR_umount2 (__NR_Linux + 161)
#define __NR_swapon (__NR_Linux + 162)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_swapoff (__NR_Linux + 163)
#define __NR_reboot (__NR_Linux + 164)
#define __NR_sethostname (__NR_Linux + 165)
#define __NR_setdomainname (__NR_Linux + 166)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_create_module (__NR_Linux + 167)
#define __NR_init_module (__NR_Linux + 168)
#define __NR_delete_module (__NR_Linux + 169)
#define __NR_get_kernel_syms (__NR_Linux + 170)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_query_module (__NR_Linux + 171)
#define __NR_quotactl (__NR_Linux + 172)
#define __NR_nfsservctl (__NR_Linux + 173)
#define __NR_getpmsg (__NR_Linux + 174)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_putpmsg (__NR_Linux + 175)
#define __NR_afs_syscall (__NR_Linux + 176)
#define __NR_reserved177 (__NR_Linux + 177)
#define __NR_gettid (__NR_Linux + 178)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_readahead (__NR_Linux + 179)
#define __NR_setxattr (__NR_Linux + 180)
#define __NR_lsetxattr (__NR_Linux + 181)
#define __NR_fsetxattr (__NR_Linux + 182)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_getxattr (__NR_Linux + 183)
#define __NR_lgetxattr (__NR_Linux + 184)
#define __NR_fgetxattr (__NR_Linux + 185)
#define __NR_listxattr (__NR_Linux + 186)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_llistxattr (__NR_Linux + 187)
#define __NR_flistxattr (__NR_Linux + 188)
#define __NR_removexattr (__NR_Linux + 189)
#define __NR_lremovexattr (__NR_Linux + 190)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_fremovexattr (__NR_Linux + 191)
#define __NR_tkill (__NR_Linux + 192)
#define __NR_reserved193 (__NR_Linux + 193)
#define __NR_futex (__NR_Linux + 194)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_sched_setaffinity (__NR_Linux + 195)
#define __NR_sched_getaffinity (__NR_Linux + 196)
#define __NR_cacheflush (__NR_Linux + 197)
#define __NR_cachectl (__NR_Linux + 198)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_sysmips (__NR_Linux + 199)
#define __NR_io_setup (__NR_Linux + 200)
#define __NR_io_destroy (__NR_Linux + 201)
#define __NR_io_getevents (__NR_Linux + 202)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_io_submit (__NR_Linux + 203)
#define __NR_io_cancel (__NR_Linux + 204)
#define __NR_exit_group (__NR_Linux + 205)
#define __NR_lookup_dcookie (__NR_Linux + 206)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_epoll_create (__NR_Linux + 207)
#define __NR_epoll_ctl (__NR_Linux + 208)
#define __NR_epoll_wait (__NR_Linux + 209)
#define __NR_remap_file_pages (__NR_Linux + 210)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_rt_sigreturn (__NR_Linux + 211)
#define __NR_fcntl64 (__NR_Linux + 212)
#define __NR_set_tid_address (__NR_Linux + 213)
#define __NR_restart_syscall (__NR_Linux + 214)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_semtimedop (__NR_Linux + 215)
#define __NR_fadvise64 (__NR_Linux + 216)
#define __NR_statfs64 (__NR_Linux + 217)
#define __NR_fstatfs64 (__NR_Linux + 218)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_sendfile64 (__NR_Linux + 219)
#define __NR_timer_create (__NR_Linux + 220)
#define __NR_timer_settime (__NR_Linux + 221)
#define __NR_timer_gettime (__NR_Linux + 222)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_timer_getoverrun (__NR_Linux + 223)
#define __NR_timer_delete (__NR_Linux + 224)
#define __NR_clock_settime (__NR_Linux + 225)
#define __NR_clock_gettime (__NR_Linux + 226)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_clock_getres (__NR_Linux + 227)
#define __NR_clock_nanosleep (__NR_Linux + 228)
#define __NR_tgkill (__NR_Linux + 229)
#define __NR_utimes (__NR_Linux + 230)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_mbind (__NR_Linux + 231)
#define __NR_get_mempolicy (__NR_Linux + 232)
#define __NR_set_mempolicy (__NR_Linux + 233)
#define __NR_mq_open (__NR_Linux + 234)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_mq_unlink (__NR_Linux + 235)
#define __NR_mq_timedsend (__NR_Linux + 236)
#define __NR_mq_timedreceive (__NR_Linux + 237)
#define __NR_mq_notify (__NR_Linux + 238)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_mq_getsetattr (__NR_Linux + 239)
#define __NR_vserver (__NR_Linux + 240)
#define __NR_waitid (__NR_Linux + 241)
#define __NR_add_key (__NR_Linux + 243)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_request_key (__NR_Linux + 244)
#define __NR_keyctl (__NR_Linux + 245)
#define __NR_set_thread_area (__NR_Linux + 246)
#define __NR_inotify_init (__NR_Linux + 247)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_inotify_add_watch (__NR_Linux + 248)
#define __NR_inotify_rm_watch (__NR_Linux + 249)
#define __NR_migrate_pages (__NR_Linux + 250)
#define __NR_openat (__NR_Linux + 251)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_mkdirat (__NR_Linux + 252)
#define __NR_mknodat (__NR_Linux + 253)
#define __NR_fchownat (__NR_Linux + 254)
#define __NR_futimesat (__NR_Linux + 255)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_newfstatat (__NR_Linux + 256)
#define __NR_unlinkat (__NR_Linux + 257)
#define __NR_renameat (__NR_Linux + 258)
#define __NR_linkat (__NR_Linux + 259)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_symlinkat (__NR_Linux + 260)
#define __NR_readlinkat (__NR_Linux + 261)
#define __NR_fchmodat (__NR_Linux + 262)
#define __NR_faccessat (__NR_Linux + 263)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_pselect6 (__NR_Linux + 264)
#define __NR_ppoll (__NR_Linux + 265)
#define __NR_unshare (__NR_Linux + 266)
#define __NR_splice (__NR_Linux + 267)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_sync_file_range (__NR_Linux + 268)
#define __NR_tee (__NR_Linux + 269)
#define __NR_vmsplice (__NR_Linux + 270)
#define __NR_move_pages (__NR_Linux + 271)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_set_robust_list (__NR_Linux + 272)
#define __NR_get_robust_list (__NR_Linux + 273)
#define __NR_kexec_load (__NR_Linux + 274)
#define __NR_getcpu (__NR_Linux + 275)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_epoll_pwait (__NR_Linux + 276)
#define __NR_ioprio_set (__NR_Linux + 277)
#define __NR_ioprio_get (__NR_Linux + 278)
#define __NR_utimensat (__NR_Linux + 279)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_signalfd (__NR_Linux + 280)
#define __NR_timerfd (__NR_Linux + 281)
#define __NR_eventfd (__NR_Linux + 282)
#define __NR_fallocate (__NR_Linux + 283)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_timerfd_create (__NR_Linux + 284)
#define __NR_timerfd_gettime (__NR_Linux + 285)
#define __NR_timerfd_settime (__NR_Linux + 286)
#define __NR_signalfd4 (__NR_Linux + 287)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_eventfd2 (__NR_Linux + 288)
#define __NR_epoll_create1 (__NR_Linux + 289)
#define __NR_dup3 (__NR_Linux + 290)
#define __NR_pipe2 (__NR_Linux + 291)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_inotify_init1 (__NR_Linux + 292)
#define __NR_preadv (__NR_Linux + 293)
#define __NR_pwritev (__NR_Linux + 294)
#define __NR_rt_tgsigqueueinfo (__NR_Linux + 295)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_perf_event_open (__NR_Linux + 296)
#define __NR_accept4 (__NR_Linux + 297)
#define __NR_recvmmsg (__NR_Linux + 298)
#define __NR_getdents64 (__NR_Linux + 299)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_fanotify_init (__NR_Linux + 300)
#define __NR_fanotify_mark (__NR_Linux + 301)
#define __NR_prlimit64 (__NR_Linux + 302)
#define __NR_name_to_handle_at (__NR_Linux + 303)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_open_by_handle_at (__NR_Linux + 304)
#define __NR_clock_adjtime (__NR_Linux + 305)
#define __NR_syncfs (__NR_Linux + 306)
#define __NR_sendmmsg (__NR_Linux + 307)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_setns (__NR_Linux + 308)
#define __NR_process_vm_readv (__NR_Linux + 309)
#define __NR_process_vm_writev (__NR_Linux + 310)
#define __NR_kcmp (__NR_Linux + 311)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __NR_finit_module (__NR_Linux + 312)
#define __NR_sched_setattr (__NR_Linux + 313)
#define __NR_sched_getattr (__NR_Linux + 314)
#define __NR_Linux_syscalls 314
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#endif
#define __NR_N32_Linux 6000
#define __NR_N32_Linux_syscalls 314
#endif
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
