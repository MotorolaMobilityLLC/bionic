# auto-generated by gensyscalls.py, do not touch
syscall_src := 
syscall_src += arch-sh/syscalls/_exit.S
syscall_src += arch-sh/syscalls/_exit_thread.S
syscall_src += arch-sh/syscalls/__fork.S
syscall_src += arch-sh/syscalls/_waitpid.S
syscall_src += arch-sh/syscalls/__waitid.S
syscall_src += arch-sh/syscalls/__sys_clone.S
syscall_src += arch-sh/syscalls/execve.S
syscall_src += arch-sh/syscalls/__setuid.S
syscall_src += arch-sh/syscalls/getuid.S
syscall_src += arch-sh/syscalls/getgid.S
syscall_src += arch-sh/syscalls/geteuid.S
syscall_src += arch-sh/syscalls/getegid.S
syscall_src += arch-sh/syscalls/getresuid.S
syscall_src += arch-sh/syscalls/getresgid.S
syscall_src += arch-sh/syscalls/gettid.S
syscall_src += arch-sh/syscalls/getgroups.S
syscall_src += arch-sh/syscalls/getpgid.S
syscall_src += arch-sh/syscalls/getppid.S
syscall_src += arch-sh/syscalls/setsid.S
syscall_src += arch-sh/syscalls/setgid.S
syscall_src += arch-sh/syscalls/__setreuid.S
syscall_src += arch-sh/syscalls/__setresuid.S
syscall_src += arch-sh/syscalls/setresgid.S
syscall_src += arch-sh/syscalls/__brk.S
syscall_src += arch-sh/syscalls/kill.S
syscall_src += arch-sh/syscalls/tkill.S
syscall_src += arch-sh/syscalls/__ptrace.S
syscall_src += arch-sh/syscalls/__set_thread_area.S
syscall_src += arch-sh/syscalls/__getpriority.S
syscall_src += arch-sh/syscalls/setpriority.S
syscall_src += arch-sh/syscalls/setrlimit.S
syscall_src += arch-sh/syscalls/getrlimit.S
syscall_src += arch-sh/syscalls/getrusage.S
syscall_src += arch-sh/syscalls/setgroups.S
syscall_src += arch-sh/syscalls/setpgid.S
syscall_src += arch-sh/syscalls/vfork.S
syscall_src += arch-sh/syscalls/setregid.S
syscall_src += arch-sh/syscalls/chroot.S
syscall_src += arch-sh/syscalls/prctl.S
syscall_src += arch-sh/syscalls/capget.S
syscall_src += arch-sh/syscalls/capset.S
syscall_src += arch-sh/syscalls/sigaltstack.S
syscall_src += arch-sh/syscalls/acct.S
syscall_src += arch-sh/syscalls/read.S
syscall_src += arch-sh/syscalls/write.S
syscall_src += arch-sh/syscalls/__pread64.S
syscall_src += arch-sh/syscalls/__pwrite64.S
syscall_src += arch-sh/syscalls/__open.S
syscall_src += arch-sh/syscalls/__openat.S
syscall_src += arch-sh/syscalls/close.S
syscall_src += arch-sh/syscalls/lseek.S
syscall_src += arch-sh/syscalls/__llseek.S
syscall_src += arch-sh/syscalls/getpid.S
syscall_src += arch-sh/syscalls/__mmap2.S
syscall_src += arch-sh/syscalls/munmap.S
syscall_src += arch-sh/syscalls/mremap.S
syscall_src += arch-sh/syscalls/msync.S
syscall_src += arch-sh/syscalls/mprotect.S
syscall_src += arch-sh/syscalls/madvise.S
syscall_src += arch-sh/syscalls/mlock.S
syscall_src += arch-sh/syscalls/munlock.S
syscall_src += arch-sh/syscalls/mincore.S
syscall_src += arch-sh/syscalls/__ioctl.S
syscall_src += arch-sh/syscalls/readv.S
syscall_src += arch-sh/syscalls/writev.S
syscall_src += arch-sh/syscalls/__fcntl.S
syscall_src += arch-sh/syscalls/flock.S
syscall_src += arch-sh/syscalls/fchmod.S
syscall_src += arch-sh/syscalls/dup.S
syscall_src += arch-sh/syscalls/pipe2.S
syscall_src += arch-sh/syscalls/dup2.S
syscall_src += arch-sh/syscalls/select.S
syscall_src += arch-sh/syscalls/ftruncate.S
syscall_src += arch-sh/syscalls/getdents.S
syscall_src += arch-sh/syscalls/fsync.S
syscall_src += arch-sh/syscalls/fdatasync.S
syscall_src += arch-sh/syscalls/fchown.S
syscall_src += arch-sh/syscalls/sync.S
syscall_src += arch-sh/syscalls/__fcntl64.S
syscall_src += arch-sh/syscalls/__fstatfs64.S
syscall_src += arch-sh/syscalls/sendfile.S
syscall_src += arch-sh/syscalls/fstatat.S
syscall_src += arch-sh/syscalls/mkdirat.S
syscall_src += arch-sh/syscalls/fchownat.S
syscall_src += arch-sh/syscalls/fchmodat.S
syscall_src += arch-sh/syscalls/renameat.S
syscall_src += arch-sh/syscalls/link.S
syscall_src += arch-sh/syscalls/unlink.S
syscall_src += arch-sh/syscalls/unlinkat.S
syscall_src += arch-sh/syscalls/chdir.S
syscall_src += arch-sh/syscalls/mknod.S
syscall_src += arch-sh/syscalls/chmod.S
syscall_src += arch-sh/syscalls/chown.S
syscall_src += arch-sh/syscalls/lchown.S
syscall_src += arch-sh/syscalls/mount.S
syscall_src += arch-sh/syscalls/umount2.S
syscall_src += arch-sh/syscalls/fstat.S
syscall_src += arch-sh/syscalls/stat.S
syscall_src += arch-sh/syscalls/lstat.S
syscall_src += arch-sh/syscalls/mkdir.S
syscall_src += arch-sh/syscalls/readlink.S
syscall_src += arch-sh/syscalls/rmdir.S
syscall_src += arch-sh/syscalls/rename.S
syscall_src += arch-sh/syscalls/__getcwd.S
syscall_src += arch-sh/syscalls/access.S
syscall_src += arch-sh/syscalls/symlink.S
syscall_src += arch-sh/syscalls/fchdir.S
syscall_src += arch-sh/syscalls/truncate.S
syscall_src += arch-sh/syscalls/__statfs64.S
syscall_src += arch-sh/syscalls/pause.S
syscall_src += arch-sh/syscalls/gettimeofday.S
syscall_src += arch-sh/syscalls/settimeofday.S
syscall_src += arch-sh/syscalls/times.S
syscall_src += arch-sh/syscalls/nanosleep.S
syscall_src += arch-sh/syscalls/clock_gettime.S
syscall_src += arch-sh/syscalls/clock_settime.S
syscall_src += arch-sh/syscalls/clock_getres.S
syscall_src += arch-sh/syscalls/clock_nanosleep.S
syscall_src += arch-sh/syscalls/getitimer.S
syscall_src += arch-sh/syscalls/setitimer.S
syscall_src += arch-sh/syscalls/__timer_create.S
syscall_src += arch-sh/syscalls/__timer_settime.S
syscall_src += arch-sh/syscalls/__timer_gettime.S
syscall_src += arch-sh/syscalls/__timer_getoverrun.S
syscall_src += arch-sh/syscalls/__timer_delete.S
syscall_src += arch-sh/syscalls/utimes.S
syscall_src += arch-sh/syscalls/sigaction.S
syscall_src += arch-sh/syscalls/sigprocmask.S
syscall_src += arch-sh/syscalls/__sigsuspend.S
syscall_src += arch-sh/syscalls/__rt_sigaction.S
syscall_src += arch-sh/syscalls/__rt_sigprocmask.S
syscall_src += arch-sh/syscalls/__rt_sigtimedwait.S
syscall_src += arch-sh/syscalls/sigpending.S
syscall_src += arch-sh/syscalls/__socketcall.S
syscall_src += arch-sh/syscalls/sched_setscheduler.S
syscall_src += arch-sh/syscalls/sched_getscheduler.S
syscall_src += arch-sh/syscalls/sched_yield.S
syscall_src += arch-sh/syscalls/sched_setparam.S
syscall_src += arch-sh/syscalls/sched_getparam.S
syscall_src += arch-sh/syscalls/sched_get_priority_max.S
syscall_src += arch-sh/syscalls/sched_get_priority_min.S
syscall_src += arch-sh/syscalls/sched_rr_get_interval.S
syscall_src += arch-sh/syscalls/ioprio_set.S
syscall_src += arch-sh/syscalls/ioprio_get.S
syscall_src += arch-sh/syscalls/uname.S
syscall_src += arch-sh/syscalls/__wait4.S
syscall_src += arch-sh/syscalls/umask.S
syscall_src += arch-sh/syscalls/__reboot.S
syscall_src += arch-sh/syscalls/__syslog.S
syscall_src += arch-sh/syscalls/init_module.S
syscall_src += arch-sh/syscalls/delete_module.S
syscall_src += arch-sh/syscalls/klogctl.S
syscall_src += arch-sh/syscalls/sysinfo.S
syscall_src += arch-sh/syscalls/futex.S
syscall_src += arch-sh/syscalls/epoll_create.S
syscall_src += arch-sh/syscalls/epoll_ctl.S
syscall_src += arch-sh/syscalls/epoll_wait.S
syscall_src += arch-sh/syscalls/inotify_init.S
syscall_src += arch-sh/syscalls/inotify_add_watch.S
syscall_src += arch-sh/syscalls/inotify_rm_watch.S
syscall_src += arch-sh/syscalls/poll.S
