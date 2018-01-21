// Autogenerated file - edit at your peril!!

#include <linux/filter.h>
#include <errno.h>

#include "seccomp_bpfs.h"
const sock_filter mips_global_filter[] = {
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4001, 0, 110),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4131, 55, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4063, 27, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4036, 13, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4023, 7, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4010, 3, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4008, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4007, 103, 102), //exit|fork|read|write|open|close
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4009, 102, 101), //creat
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4019, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4013, 100, 99), //unlink|execve|chdir
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4022, 99, 98), //lseek|getpid|mount
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4033, 3, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4026, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4025, 96, 95), //setuid|getuid
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4027, 95, 94), //ptrace
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4034, 94, 93), //access
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4054, 7, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4045, 3, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4041, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4040, 90, 89), //sync|kill|rename|mkdir
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4044, 89, 88), //dup|pipe|times
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4049, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4048, 87, 86), //brk|setgid|getgid
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4053, 86, 85), //geteuid|getegid|acct|umount2
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4060, 3, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4057, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4056, 83, 82), //ioctl|fcntl
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4058, 82, 81), //setpgid
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4062, 81, 80), //umask|chroot
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4094, 13, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4085, 7, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4070, 3, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4066, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4065, 76, 75), //dup2|getppid
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4068, 75, 74), //setsid|sigaction
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4074, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4072, 73, 72), //setreuid|setregid
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4082, 72, 71), //sethostname|setrlimit|getrlimit|getrusage|gettimeofday|settimeofday|getgroups|setgroups
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4090, 3, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4087, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4086, 69, 68), //readlink
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4089, 68, 67), //swapon|reboot
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4093, 67, 66), //mmap|munmap|truncate
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4118, 7, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4114, 3, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4103, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4098, 63, 62), //fchmod|fchown|getpriority|setpriority
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4106, 62, 61), //syslog|setitimer|getitimer
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4116, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4115, 60, 59), //wait4
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4117, 59, 58), //sysinfo
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4128, 3, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4124, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4123, 56, 55), //fsync|sigreturn|clone|setdomainname|uname
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4126, 55, 54), //adjtimex|mprotect
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4130, 54, 53), //init_module|delete_module
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4248, 27, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4179, 13, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4154, 7, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4138, 3, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4136, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4134, 48, 47), //quotactl|getpgid|fchdir
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4137, 47, 46), //personality
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4151, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4148, 45, 44), //setfsuid|setfsgid|_llseek|getdents|_newselect|flock|msync|readv|writev|cacheflush
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4153, 44, 43), //getsid|fdatasync
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4176, 3, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4169, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4168, 41, 40), //mlock|munlock|mlockall|munlockall|sched_setparam|sched_getparam|sched_setscheduler|sched_getscheduler|sched_yield|sched_get_priority_max|sched_get_priority_min|sched_rr_get_interval|nanosleep|mremap
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4175, 40, 39), //bind|connect|getpeername|getsockname|getsockopt|listen
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4178, 39, 38), //recvfrom|recvmsg
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4210, 7, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4190, 3, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4188, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4187, 35, 34), //sendmsg|sendto|setsockopt|shutdown|socket|socketpair|setresuid|getresuid
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4189, 34, 33), //poll
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4203, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4202, 32, 31), //setresgid|getresgid|prctl|rt_sigreturn|rt_sigaction|rt_sigprocmask|rt_sigpending|rt_sigtimedwait|rt_sigqueueinfo|rt_sigsuspend|pread64|pwrite64
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4208, 31, 30), //getcwd|capget|capset|sigaltstack|sendfile
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4222, 3, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4217, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4216, 28, 27), //mmap2|truncate64|ftruncate64|stat64|lstat64|fstat64
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4221, 27, 26), //mincore|madvise|getdents64|fcntl64
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4247, 26, 25), //gettid|readahead|setxattr|lsetxattr|fsetxattr|getxattr|lgetxattr|fgetxattr|listxattr|llistxattr|flistxattr|removexattr|lremovexattr|fremovexattr|tkill|sendfile64|futex|sched_setaffinity|sched_getaffinity|io_setup|io_destroy|io_getevents|io_submit|io_cancel|exit_group
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4316, 13, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4288, 7, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4280, 3, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4278, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4267, 21, 20), //epoll_create|epoll_ctl|epoll_wait|remap_file_pages|set_tid_address|restart_syscall|fadvise64|statfs64|fstatfs64|timer_create|timer_settime|timer_gettime|timer_getoverrun|timer_delete|clock_settime|clock_gettime|clock_getres|clock_nanosleep|tgkill
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4279, 20, 19), //waitid
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4282, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4281, 18, 17), //add_key
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4287, 17, 16), //keyctl|set_thread_area|inotify_init|inotify_add_watch|inotify_rm_watch
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4312, 3, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4293, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4292, 14, 13), //openat|mkdirat|mknodat|fchownat
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4308, 13, 12), //fstatat64|unlinkat|renameat|linkat|symlinkat|readlinkat|fchmodat|faccessat|pselect6|ppoll|unshare|splice|sync_file_range|tee|vmsplice
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4314, 12, 11), //getcpu|epoll_pwait
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4341, 5, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4338, 3, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4319, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4317, 8, 7), //utimensat
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4336, 7, 6), //eventfd|fallocate|timerfd_create|timerfd_gettime|timerfd_settime|signalfd4|eventfd2|epoll_create1|dup3|pipe2|inotify_init1|preadv|pwritev|rt_tgsigqueueinfo|perf_event_open|accept4|recvmmsg
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4339, 6, 5), //prlimit64
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4359, 3, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4348, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4347, 3, 2), //clock_adjtime|syncfs|sendmmsg|setns|process_vm_readv|process_vm_writev
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4357, 2, 1), //finit_module|sched_setattr|sched_getattr|renameat2|seccomp|getrandom|memfd_create|bpf|execveat
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4363, 1, 0), //mlock2|copy_file_range|preadv2|pwritev2
BPF_STMT(BPF_RET|BPF_K, SECCOMP_RET_ALLOW),
};

const size_t mips_global_filter_size = sizeof(mips_global_filter) / sizeof(struct sock_filter);
