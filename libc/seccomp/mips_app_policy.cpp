// Autogenerated file - edit at your peril!!

#include <linux/filter.h>
#include <errno.h>

#include "seccomp_bpfs.h"
const sock_filter mips_app_filter[] = {
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4001, 0, 114),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4131, 57, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4063, 29, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4041, 15, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4024, 7, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4010, 3, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4008, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4007, 107, 106), //exit|fork|read|write|open|close
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4009, 106, 105), //creat
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4019, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4013, 104, 103), //unlink|execve|chdir
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4021, 103, 102), //lseek|getpid
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4033, 3, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4026, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4025, 100, 99), //getuid
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4027, 99, 98), //ptrace
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4036, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4034, 97, 96), //access
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4040, 96, 95), //sync|kill|rename|mkdir
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4054, 7, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4047, 3, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4045, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4044, 92, 91), //dup|pipe|times
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4046, 91, 90), //brk
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4049, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4048, 89, 88), //getgid
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4051, 88, 87), //geteuid|getegid
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4060, 3, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4057, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4056, 85, 84), //ioctl|fcntl
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4058, 84, 83), //setpgid
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4061, 83, 82), //umask
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4094, 13, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4080, 7, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4071, 3, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4066, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4065, 78, 77), //dup2|getppid
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4068, 77, 76), //setsid|sigaction
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4075, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4072, 75, 74), //setregid
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4079, 74, 73), //setrlimit|getrlimit|getrusage|gettimeofday
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4090, 3, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4085, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4081, 71, 70), //getgroups
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4086, 70, 69), //readlink
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4093, 69, 68), //mmap|munmap|truncate
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4118, 7, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4114, 3, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4104, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4098, 65, 64), //fchmod|fchown|getpriority|setpriority
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4106, 64, 63), //setitimer|getitimer
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4116, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4115, 62, 61), //wait4
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4117, 61, 60), //sysinfo
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4125, 3, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4122, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4121, 58, 57), //fsync|sigreturn|clone
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4123, 57, 56), //uname
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4126, 56, 55), //mprotect
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4248, 27, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4179, 13, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4154, 7, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4140, 3, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4136, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4134, 50, 49), //quotactl|getpgid|fchdir
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4137, 49, 48), //personality
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4151, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4148, 47, 46), //_llseek|getdents|_newselect|flock|msync|readv|writev|cacheflush
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4153, 46, 45), //getsid|fdatasync
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4176, 3, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4169, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4168, 43, 42), //mlock|munlock|mlockall|munlockall|sched_setparam|sched_getparam|sched_setscheduler|sched_getscheduler|sched_yield|sched_get_priority_max|sched_get_priority_min|sched_rr_get_interval|nanosleep|mremap
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4175, 42, 41), //bind|connect|getpeername|getsockname|getsockopt|listen
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4178, 41, 40), //recvfrom|recvmsg
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4210, 7, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4191, 3, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4188, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4187, 37, 36), //sendmsg|sendto|setsockopt|shutdown|socket|socketpair|setresuid|getresuid
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4189, 36, 35), //poll
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4203, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4202, 34, 33), //getresgid|prctl|rt_sigreturn|rt_sigaction|rt_sigprocmask|rt_sigpending|rt_sigtimedwait|rt_sigqueueinfo|rt_sigsuspend|pread64|pwrite64
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4208, 33, 32), //getcwd|capget|capset|sigaltstack|sendfile
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4222, 3, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4217, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4216, 30, 29), //mmap2|truncate64|ftruncate64|stat64|lstat64|fstat64
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4221, 29, 28), //mincore|madvise|getdents64|fcntl64
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4247, 28, 27), //gettid|readahead|setxattr|lsetxattr|fsetxattr|getxattr|lgetxattr|fgetxattr|listxattr|llistxattr|flistxattr|removexattr|lremovexattr|fremovexattr|tkill|sendfile64|futex|sched_setaffinity|sched_getaffinity|io_setup|io_destroy|io_getevents|io_submit|io_cancel|exit_group
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4316, 13, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4288, 7, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4278, 3, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4263, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4262, 23, 22), //epoll_create|epoll_ctl|epoll_wait|remap_file_pages|set_tid_address|restart_syscall|fadvise64|statfs64|fstatfs64|timer_create|timer_settime|timer_gettime|timer_getoverrun|timer_delete
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4267, 22, 21), //clock_gettime|clock_getres|clock_nanosleep|tgkill
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4283, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4279, 20, 19), //waitid
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4287, 19, 18), //set_thread_area|inotify_init|inotify_add_watch|inotify_rm_watch
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4312, 3, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4293, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4292, 16, 15), //openat|mkdirat|mknodat|fchownat
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4308, 15, 14), //fstatat64|unlinkat|renameat|linkat|symlinkat|readlinkat|fchmodat|faccessat|pselect6|ppoll|unshare|splice|sync_file_range|tee|vmsplice
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4314, 14, 13), //getcpu|epoll_pwait
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4349, 7, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4338, 3, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4319, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4317, 10, 9), //utimensat
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4336, 9, 8), //eventfd|fallocate|timerfd_create|timerfd_gettime|timerfd_settime|signalfd4|eventfd2|epoll_create1|dup3|pipe2|inotify_init1|preadv|pwritev|rt_tgsigqueueinfo|perf_event_open|accept4|recvmmsg
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4342, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4339, 7, 6), //prlimit64
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4347, 6, 5), //syncfs|sendmmsg|setns|process_vm_readv|process_vm_writev
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4359, 3, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4356, 1, 0),
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4355, 3, 2), //sched_setattr|sched_getattr|renameat2|seccomp|getrandom|memfd_create
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4357, 2, 1), //execveat
BPF_JUMP(BPF_JMP|BPF_JGE|BPF_K, 4363, 1, 0), //mlock2|copy_file_range|preadv2|pwritev2
BPF_STMT(BPF_RET|BPF_K, SECCOMP_RET_ALLOW),
};

const size_t mips_app_filter_size = sizeof(mips_app_filter) / sizeof(struct sock_filter);
