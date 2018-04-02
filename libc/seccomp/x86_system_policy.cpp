// Autogenerated file - edit at your peril!!

#include <linux/filter.h>
#include <errno.h>

#include "seccomp_bpfs.h"
const sock_filter x86_system_filter[] = {
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 0, 0, 120),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 136, 59, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 66, 29, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 43, 15, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 19, 7, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 6, 3, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 3, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 2, 113, 112), //restart_syscall|exit
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 5, 112, 111), //read|write
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 11, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 7, 110, 109), //close
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 13, 109, 108), //execve|chdir
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 36, 3, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 26, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 22, 106, 105), //lseek|getpid|mount
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 27, 105, 104), //ptrace
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 41, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 38, 103, 102), //sync|kill
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 42, 102, 101), //dup
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 57, 7, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 51, 3, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 45, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 44, 98, 97), //times
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 46, 97, 96), //brk
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 54, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 53, 95, 94), //acct|umount2
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 55, 94, 93), //ioctl
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 64, 3, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 60, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 58, 91, 90), //setpgid
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 62, 90, 89), //umask|chroot
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 65, 89, 88), //getppid
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 102, 15, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 88, 7, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 77, 3, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 74, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 68, 84, 83), //setsid|sigaction
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 76, 83, 82), //sethostname|setrlimit
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 85, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 80, 81, 80), //getrusage|gettimeofday|settimeofday
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 86, 80, 79), //readlink
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 94, 3, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 91, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 89, 77, 76), //reboot
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 93, 76, 75), //munmap|truncate
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 96, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 95, 74, 73), //fchmod
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 98, 73, 72), //getpriority|setpriority
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 124, 7, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 116, 3, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 114, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 106, 69, 68), //socketcall|syslog|setitimer|getitimer
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 115, 68, 67), //wait4
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 118, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 117, 66, 65), //sysinfo
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 123, 65, 64), //fsync|sigreturn|clone|setdomainname|uname
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 131, 3, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 128, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 126, 62, 61), //adjtimex|mprotect
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 130, 61, 60), //init_module|delete_module
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 134, 60, 59), //quotactl|getpgid|fchdir
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 258, 29, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 199, 15, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 172, 7, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 143, 3, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 138, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 137, 54, 53), //personality
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 141, 53, 52), //setfsuid|setfsgid|_llseek
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 150, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 149, 51, 50), //flock|msync|readv|writev|getsid|fdatasync
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 164, 50, 49), //mlock|munlock|mlockall|munlockall|sched_setparam|sched_getparam|sched_setscheduler|sched_getscheduler|sched_yield|sched_get_priority_max|sched_get_priority_min|sched_rr_get_interval|nanosleep|mremap
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 190, 3, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 183, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 182, 47, 46), //prctl|rt_sigreturn|rt_sigaction|rt_sigprocmask|rt_sigpending|rt_sigtimedwait|rt_sigqueueinfo|rt_sigsuspend|pread64|pwrite64
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 188, 46, 45), //getcwd|capget|capset|sigaltstack|sendfile
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 197, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 195, 44, 43), //vfork|ugetrlimit|mmap2|truncate64|ftruncate64
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 198, 43, 42), //fstat64
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 245, 7, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 218, 3, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 213, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 212, 39, 38), //getuid32|getgid32|geteuid32|getegid32|setreuid32|setregid32|getgroups32|setgroups32|fchown32|setresuid32|getresuid32|setresgid32|getresgid32
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 215, 38, 37), //setuid32|setgid32
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 224, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 222, 36, 35), //mincore|madvise|getdents64|fcntl64
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 244, 35, 34), //gettid|readahead|setxattr|lsetxattr|fsetxattr|getxattr|lgetxattr|fgetxattr|listxattr|llistxattr|flistxattr|removexattr|lremovexattr|fremovexattr|tkill|sendfile64|futex|sched_setaffinity|sched_getaffinity|set_thread_area
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 255, 3, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 252, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 250, 32, 31), //io_setup|io_destroy|io_getevents|io_submit|io_cancel
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 253, 31, 30), //exit_group
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 256, 30, 29), //epoll_ctl
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 322, 15, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 295, 7, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 284, 3, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 272, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 271, 25, 24), //set_tid_address|timer_create|timer_settime|timer_gettime|timer_getoverrun|timer_delete|clock_settime|clock_gettime|clock_getres|clock_nanosleep|statfs64|fstatfs64|tgkill
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 273, 24, 23), //fadvise64_64
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 292, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 285, 22, 21), //waitid
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 294, 21, 20), //inotify_add_watch|inotify_rm_watch
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 313, 3, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 300, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 299, 18, 17), //openat|mkdirat|mknodat|fchownat
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 311, 17, 16), //fstatat64|unlinkat|renameat|linkat|symlinkat|readlinkat|fchmodat|faccessat|pselect6|ppoll|unshare
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 318, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 317, 15, 14), //splice|sync_file_range|tee|vmsplice
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 321, 14, 13), //getcpu|epoll_pwait|utimensat
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 346, 7, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 340, 3, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 324, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 323, 10, 9), //timerfd_create
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 337, 9, 8), //fallocate|timerfd_settime|timerfd_gettime|signalfd4|eventfd2|epoll_create1|dup3|pipe2|inotify_init1|preadv|pwritev|rt_tgsigqueueinfo|perf_event_open
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 343, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 341, 7, 6), //prlimit64
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 345, 6, 5), //clock_adjtime|syncfs
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 376, 3, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 351, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 349, 3, 2), //setns|process_vm_readv|process_vm_writev
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 359, 2, 1), //sched_setattr|sched_getattr|renameat2|seccomp|getrandom|memfd_create|bpf|execveat
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 380, 1, 0), //mlock2|copy_file_range|preadv2|pwritev2
BPF_STMT(BPF_RET|BPF_K, SECCOMP_RET_ALLOW),
};

const size_t x86_system_filter_size = sizeof(x86_system_filter) / sizeof(struct sock_filter);
