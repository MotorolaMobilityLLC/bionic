# Auto-generated by gensyscalls.py. Do not edit.
syscall_src :=
syscall_src += arch-x86_64/syscalls/_exit.S
syscall_src += arch-x86_64/syscalls/_exit_thread.S
syscall_src += arch-x86_64/syscalls/__fork.S
syscall_src += arch-x86_64/syscalls/__waitid.S
syscall_src += arch-x86_64/syscalls/wait4.S
syscall_src += arch-x86_64/syscalls/__sys_clone.S
syscall_src += arch-x86_64/syscalls/execve.S
syscall_src += arch-x86_64/syscalls/getuid.S
syscall_src += arch-x86_64/syscalls/getgid.S
syscall_src += arch-x86_64/syscalls/geteuid.S
syscall_src += arch-x86_64/syscalls/getegid.S
syscall_src += arch-x86_64/syscalls/getresuid.S
syscall_src += arch-x86_64/syscalls/getresgid.S
syscall_src += arch-x86_64/syscalls/gettid.S
syscall_src += arch-x86_64/syscalls/readahead.S
syscall_src += arch-x86_64/syscalls/getgroups.S
syscall_src += arch-x86_64/syscalls/getpgid.S
syscall_src += arch-x86_64/syscalls/getppid.S
syscall_src += arch-x86_64/syscalls/getsid.S
syscall_src += arch-x86_64/syscalls/setsid.S
syscall_src += arch-x86_64/syscalls/setgid.S
syscall_src += arch-x86_64/syscalls/setuid.S
syscall_src += arch-x86_64/syscalls/setreuid.S
syscall_src += arch-x86_64/syscalls/setresuid.S
syscall_src += arch-x86_64/syscalls/setresgid.S
syscall_src += arch-x86_64/syscalls/__brk.S
syscall_src += arch-x86_64/syscalls/kill.S
syscall_src += arch-x86_64/syscalls/tkill.S
syscall_src += arch-x86_64/syscalls/tgkill.S
syscall_src += arch-x86_64/syscalls/__ptrace.S
syscall_src += arch-x86_64/syscalls/__getpriority.S
syscall_src += arch-x86_64/syscalls/setpriority.S
syscall_src += arch-x86_64/syscalls/setrlimit.S
syscall_src += arch-x86_64/syscalls/getrlimit.S
syscall_src += arch-x86_64/syscalls/getrusage.S
syscall_src += arch-x86_64/syscalls/setgroups.S
syscall_src += arch-x86_64/syscalls/setpgid.S
syscall_src += arch-x86_64/syscalls/vfork.S
syscall_src += arch-x86_64/syscalls/setregid.S
syscall_src += arch-x86_64/syscalls/chroot.S
syscall_src += arch-x86_64/syscalls/prctl.S
syscall_src += arch-x86_64/syscalls/__arch_prctl.S
syscall_src += arch-x86_64/syscalls/capget.S
syscall_src += arch-x86_64/syscalls/capset.S
syscall_src += arch-x86_64/syscalls/sigaltstack.S
syscall_src += arch-x86_64/syscalls/acct.S
syscall_src += arch-x86_64/syscalls/read.S
syscall_src += arch-x86_64/syscalls/write.S
syscall_src += arch-x86_64/syscalls/pread64.S
syscall_src += arch-x86_64/syscalls/pwrite64.S
syscall_src += arch-x86_64/syscalls/__open.S
syscall_src += arch-x86_64/syscalls/__openat.S
syscall_src += arch-x86_64/syscalls/close.S
syscall_src += arch-x86_64/syscalls/lseek.S
syscall_src += arch-x86_64/syscalls/getpid.S
syscall_src += arch-x86_64/syscalls/mmap.S
syscall_src += arch-x86_64/syscalls/munmap.S
syscall_src += arch-x86_64/syscalls/mremap.S
syscall_src += arch-x86_64/syscalls/msync.S
syscall_src += arch-x86_64/syscalls/mprotect.S
syscall_src += arch-x86_64/syscalls/madvise.S
syscall_src += arch-x86_64/syscalls/mlock.S
syscall_src += arch-x86_64/syscalls/munlock.S
syscall_src += arch-x86_64/syscalls/mlockall.S
syscall_src += arch-x86_64/syscalls/munlockall.S
syscall_src += arch-x86_64/syscalls/mincore.S
syscall_src += arch-x86_64/syscalls/__ioctl.S
syscall_src += arch-x86_64/syscalls/readv.S
syscall_src += arch-x86_64/syscalls/writev.S
syscall_src += arch-x86_64/syscalls/fcntl.S
syscall_src += arch-x86_64/syscalls/flock.S
syscall_src += arch-x86_64/syscalls/fchmod.S
syscall_src += arch-x86_64/syscalls/dup.S
syscall_src += arch-x86_64/syscalls/pipe.S
syscall_src += arch-x86_64/syscalls/pipe2.S
syscall_src += arch-x86_64/syscalls/dup2.S
syscall_src += arch-x86_64/syscalls/select.S
syscall_src += arch-x86_64/syscalls/ftruncate.S
syscall_src += arch-x86_64/syscalls/getdents.S
syscall_src += arch-x86_64/syscalls/fsync.S
syscall_src += arch-x86_64/syscalls/fdatasync.S
syscall_src += arch-x86_64/syscalls/fchown.S
syscall_src += arch-x86_64/syscalls/sync.S
syscall_src += arch-x86_64/syscalls/fstatfs.S
syscall_src += arch-x86_64/syscalls/sendfile.S
syscall_src += arch-x86_64/syscalls/mkdirat.S
syscall_src += arch-x86_64/syscalls/fchownat.S
syscall_src += arch-x86_64/syscalls/fchmodat.S
syscall_src += arch-x86_64/syscalls/renameat.S
syscall_src += arch-x86_64/syscalls/fsetxattr.S
syscall_src += arch-x86_64/syscalls/fgetxattr.S
syscall_src += arch-x86_64/syscalls/flistxattr.S
syscall_src += arch-x86_64/syscalls/fremovexattr.S
syscall_src += arch-x86_64/syscalls/link.S
syscall_src += arch-x86_64/syscalls/unlink.S
syscall_src += arch-x86_64/syscalls/unlinkat.S
syscall_src += arch-x86_64/syscalls/chdir.S
syscall_src += arch-x86_64/syscalls/mknod.S
syscall_src += arch-x86_64/syscalls/chmod.S
syscall_src += arch-x86_64/syscalls/chown.S
syscall_src += arch-x86_64/syscalls/lchown.S
syscall_src += arch-x86_64/syscalls/mount.S
syscall_src += arch-x86_64/syscalls/umount2.S
syscall_src += arch-x86_64/syscalls/fstat.S
syscall_src += arch-x86_64/syscalls/stat.S
syscall_src += arch-x86_64/syscalls/lstat.S
syscall_src += arch-x86_64/syscalls/mkdir.S
syscall_src += arch-x86_64/syscalls/readlink.S
syscall_src += arch-x86_64/syscalls/rmdir.S
syscall_src += arch-x86_64/syscalls/rename.S
syscall_src += arch-x86_64/syscalls/__getcwd.S
syscall_src += arch-x86_64/syscalls/access.S
syscall_src += arch-x86_64/syscalls/faccessat.S
syscall_src += arch-x86_64/syscalls/symlink.S
syscall_src += arch-x86_64/syscalls/fchdir.S
syscall_src += arch-x86_64/syscalls/truncate.S
syscall_src += arch-x86_64/syscalls/setxattr.S
syscall_src += arch-x86_64/syscalls/lsetxattr.S
syscall_src += arch-x86_64/syscalls/getxattr.S
syscall_src += arch-x86_64/syscalls/lgetxattr.S
syscall_src += arch-x86_64/syscalls/listxattr.S
syscall_src += arch-x86_64/syscalls/llistxattr.S
syscall_src += arch-x86_64/syscalls/removexattr.S
syscall_src += arch-x86_64/syscalls/lremovexattr.S
syscall_src += arch-x86_64/syscalls/statfs.S
syscall_src += arch-x86_64/syscalls/unshare.S
syscall_src += arch-x86_64/syscalls/swapon.S
syscall_src += arch-x86_64/syscalls/swapoff.S
syscall_src += arch-x86_64/syscalls/pause.S
syscall_src += arch-x86_64/syscalls/gettimeofday.S
syscall_src += arch-x86_64/syscalls/settimeofday.S
syscall_src += arch-x86_64/syscalls/times.S
syscall_src += arch-x86_64/syscalls/nanosleep.S
syscall_src += arch-x86_64/syscalls/clock_gettime.S
syscall_src += arch-x86_64/syscalls/clock_settime.S
syscall_src += arch-x86_64/syscalls/clock_getres.S
syscall_src += arch-x86_64/syscalls/clock_nanosleep.S
syscall_src += arch-x86_64/syscalls/getitimer.S
syscall_src += arch-x86_64/syscalls/setitimer.S
syscall_src += arch-x86_64/syscalls/__timer_create.S
syscall_src += arch-x86_64/syscalls/__timer_settime.S
syscall_src += arch-x86_64/syscalls/__timer_gettime.S
syscall_src += arch-x86_64/syscalls/__timer_getoverrun.S
syscall_src += arch-x86_64/syscalls/__timer_delete.S
syscall_src += arch-x86_64/syscalls/utimes.S
syscall_src += arch-x86_64/syscalls/utimensat.S
syscall_src += arch-x86_64/syscalls/timerfd_create.S
syscall_src += arch-x86_64/syscalls/timerfd_settime.S
syscall_src += arch-x86_64/syscalls/timerfd_gettime.S
syscall_src += arch-x86_64/syscalls/__rt_sigaction.S
syscall_src += arch-x86_64/syscalls/__rt_sigprocmask.S
syscall_src += arch-x86_64/syscalls/__rt_sigsuspend.S
syscall_src += arch-x86_64/syscalls/__rt_sigtimedwait.S
syscall_src += arch-x86_64/syscalls/signalfd4.S
syscall_src += arch-x86_64/syscalls/socket.S
syscall_src += arch-x86_64/syscalls/socketpair.S
syscall_src += arch-x86_64/syscalls/bind.S
syscall_src += arch-x86_64/syscalls/connect.S
syscall_src += arch-x86_64/syscalls/listen.S
syscall_src += arch-x86_64/syscalls/accept.S
syscall_src += arch-x86_64/syscalls/getsockname.S
syscall_src += arch-x86_64/syscalls/getpeername.S
syscall_src += arch-x86_64/syscalls/sendto.S
syscall_src += arch-x86_64/syscalls/recvfrom.S
syscall_src += arch-x86_64/syscalls/shutdown.S
syscall_src += arch-x86_64/syscalls/setsockopt.S
syscall_src += arch-x86_64/syscalls/getsockopt.S
syscall_src += arch-x86_64/syscalls/sendmsg.S
syscall_src += arch-x86_64/syscalls/recvmsg.S
syscall_src += arch-x86_64/syscalls/sched_setscheduler.S
syscall_src += arch-x86_64/syscalls/sched_getscheduler.S
syscall_src += arch-x86_64/syscalls/sched_yield.S
syscall_src += arch-x86_64/syscalls/sched_setparam.S
syscall_src += arch-x86_64/syscalls/sched_getparam.S
syscall_src += arch-x86_64/syscalls/sched_get_priority_max.S
syscall_src += arch-x86_64/syscalls/sched_get_priority_min.S
syscall_src += arch-x86_64/syscalls/sched_rr_get_interval.S
syscall_src += arch-x86_64/syscalls/sched_setaffinity.S
syscall_src += arch-x86_64/syscalls/__sched_getaffinity.S
syscall_src += arch-x86_64/syscalls/__getcpu.S
syscall_src += arch-x86_64/syscalls/ioprio_set.S
syscall_src += arch-x86_64/syscalls/ioprio_get.S
syscall_src += arch-x86_64/syscalls/uname.S
syscall_src += arch-x86_64/syscalls/umask.S
syscall_src += arch-x86_64/syscalls/__reboot.S
syscall_src += arch-x86_64/syscalls/__syslog.S
syscall_src += arch-x86_64/syscalls/init_module.S
syscall_src += arch-x86_64/syscalls/delete_module.S
syscall_src += arch-x86_64/syscalls/klogctl.S
syscall_src += arch-x86_64/syscalls/sysinfo.S
syscall_src += arch-x86_64/syscalls/personality.S
syscall_src += arch-x86_64/syscalls/perf_event_open.S
syscall_src += arch-x86_64/syscalls/futex.S
syscall_src += arch-x86_64/syscalls/epoll_create.S
syscall_src += arch-x86_64/syscalls/epoll_ctl.S
syscall_src += arch-x86_64/syscalls/epoll_wait.S
syscall_src += arch-x86_64/syscalls/inotify_init.S
syscall_src += arch-x86_64/syscalls/inotify_add_watch.S
syscall_src += arch-x86_64/syscalls/inotify_rm_watch.S
syscall_src += arch-x86_64/syscalls/poll.S
syscall_src += arch-x86_64/syscalls/eventfd.S
