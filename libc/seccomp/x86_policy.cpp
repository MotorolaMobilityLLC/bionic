// Autogenerated file - edit at your peril!!

#include <linux/filter.h>
#include <errno.h>

#include "seccomp_bpfs.h"
const sock_filter x86_filter[] = {
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 0, 0, 110),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 131, 55, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 64, 27, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 36, 13, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 24, 7, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 10, 3, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 8, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 7, 103, 102), //restart_syscall|exit|fork|read|write|open|close
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 9, 102, 101), //creat
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 19, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 13, 100, 99), //unlink|execve|chdir
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 22, 99, 98), //lseek|getpid|mount
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 33, 3, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 26, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 25, 96, 95), //getuid
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 27, 95, 94), //ptrace
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 34, 94, 93), //access
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 54, 7, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 45, 3, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 41, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 38, 90, 89), //sync|kill
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 44, 89, 88), //dup|pipe|times
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 51, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 46, 87, 86), //brk
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 53, 86, 85), //acct|umount2
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 60, 3, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 57, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 56, 83, 82), //ioctl|fcntl
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 58, 82, 81), //setpgid
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 62, 81, 80), //umask|chroot
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 94, 13, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 85, 7, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 74, 3, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 66, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 65, 76, 75), //getppid
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 68, 75, 74), //setsid|sigaction
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 77, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 76, 73, 72), //sethostname|setrlimit
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 80, 72, 71), //getrusage|gettimeofday|settimeofday
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 91, 3, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 87, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 86, 69, 68), //readlink
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 89, 68, 67), //swapon|reboot
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 93, 67, 66), //munmap|truncate
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 118, 7, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 102, 3, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 96, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 95, 63, 62), //fchmod
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 98, 62, 61), //getpriority|setpriority
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 114, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 106, 60, 59), //socketcall|syslog|setitimer|getitimer
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 117, 59, 58), //wait4|swapoff|sysinfo
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 128, 3, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 124, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 123, 56, 55), //fsync|sigreturn|clone|setdomainname|uname
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 126, 55, 54), //adjtimex|mprotect
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 130, 54, 53), //init_module|delete_module
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 254, 27, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 183, 13, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 150, 7, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 138, 3, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 136, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 134, 48, 47), //quotactl|getpgid|fchdir
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 137, 47, 46), //personality
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 143, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 142, 45, 44), //setfsuid|setfsgid|_llseek|getdents
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 149, 44, 43), //flock|msync|readv|writev|getsid|fdatasync
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 172, 3, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 168, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 164, 41, 40), //mlock|munlock|mlockall|munlockall|sched_setparam|sched_getparam|sched_setscheduler|sched_getscheduler|sched_yield|sched_get_priority_max|sched_get_priority_min|sched_rr_get_interval|nanosleep|mremap
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 169, 40, 39), //poll
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 182, 39, 38), //prctl|rt_sigreturn|rt_sigaction|rt_sigprocmask|rt_sigpending|rt_sigtimedwait|rt_sigqueueinfo|rt_sigsuspend|pread64|pwrite64
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 218, 7, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 199, 3, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 190, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 188, 35, 34), //getcwd|capget|capset|sigaltstack|sendfile
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 198, 34, 33), //vfork|ugetrlimit|mmap2|truncate64|ftruncate64|stat64|lstat64|fstat64
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 213, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 212, 32, 31), //getuid32|getgid32|geteuid32|getegid32|setreuid32|setregid32|getgroups32|setgroups32|fchown32|setresuid32|getresuid32|setresgid32|getresgid32
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 215, 31, 30), //setuid32|setgid32
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 252, 3, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 224, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 222, 28, 27), //mincore|madvise|getdents64|fcntl64
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 244, 27, 26), //gettid|readahead|setxattr|lsetxattr|fsetxattr|getxattr|lgetxattr|fgetxattr|listxattr|llistxattr|flistxattr|removexattr|lremovexattr|fremovexattr|tkill|sendfile64|futex|sched_setaffinity|sched_getaffinity|set_thread_area
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 253, 26, 25), //exit_group
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 318, 13, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 295, 7, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 284, 3, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 272, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 271, 21, 20), //epoll_create|epoll_ctl|epoll_wait|remap_file_pages|set_tid_address|timer_create|timer_settime|timer_gettime|timer_getoverrun|timer_delete|clock_settime|clock_gettime|clock_getres|clock_nanosleep|statfs64|fstatfs64|tgkill
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 273, 20, 19), //fadvise64_64
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 291, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 285, 18, 17), //waitid
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 294, 17, 16), //inotify_init|inotify_add_watch|inotify_rm_watch
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 313, 3, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 300, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 299, 14, 13), //openat|mkdirat|mknodat|fchownat
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 311, 13, 12), //fstatat64|unlinkat|renameat|linkat|symlinkat|readlinkat|fchmodat|faccessat|pselect6|ppoll|unshare
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 317, 12, 11), //splice|sync_file_range|tee|vmsplice
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 343, 5, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 340, 3, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 322, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 321, 8, 7), //getcpu|epoll_pwait|utimensat
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 337, 7, 6), //timerfd_create|eventfd|fallocate|timerfd_settime|timerfd_gettime|signalfd4|eventfd2|epoll_create1|dup3|pipe2|inotify_init1|preadv|pwritev|rt_tgsigqueueinfo|perf_event_open
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 341, 6, 5), //prlimit64
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 354, 3, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 346, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 345, 3, 2), //clock_adjtime|syncfs
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 349, 2, 1), //setns|process_vm_readv|process_vm_writev
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 356, 1, 0), //seccomp|getrandom
BPF_STMT(BPF_RET|BPF_K, SECCOMP_RET_ALLOW),
};

const size_t x86_filter_size = sizeof(x86_filter) / sizeof(struct sock_filter);
