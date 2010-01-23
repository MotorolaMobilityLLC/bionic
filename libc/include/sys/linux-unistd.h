/* auto-generated by gensyscalls.py, do not touch */
#ifndef _BIONIC_LINUX_UNISTD_H_

#ifdef __cplusplus
extern "C" {
#endif

void             _exit (int);
void             _exit_thread (int);
pid_t            __fork (void);
pid_t            _waitpid (pid_t, int*, int, struct rusage*);
int              waitid (int, pid_t, struct siginfo_t*, int,void*);
pid_t            __sys_clone (int, void*, int*, void*, int*);
int              execve (const char*, char* const*, char* const*);
int              setuid (uid_t);
uid_t            getuid (void);
gid_t            getgid (void);
uid_t            geteuid (void);
gid_t            getegid (void);
uid_t            getresuid (void);
gid_t            getresgid (void);
pid_t            gettid (void);
int              getgroups (int, gid_t *);
pid_t            getpgid (pid_t);
pid_t            getppid (void);
pid_t            setsid (void);
int              setgid (gid_t);
int              seteuid (uid_t);
int              setreuid (uid_t, uid_t);
int              setresuid (uid_t, uid_t, uid_t);
int              setresgid (gid_t, gid_t, gid_t);
void*            __brk (void*);
int              kill (pid_t, int);
int              tkill (pid_t tid, int sig);
int              __ptrace (int request, int pid, void* addr, void* data);
int              __set_thread_area (void*  user_desc);
int              __getpriority (int, int);
int              setpriority (int, int, int);
int              setrlimit (int resource, const struct rlimit *rlp);
int              getrlimit (int resource, struct rlimit *rlp);
int              getrusage (int who, struct rusage*  r_usage);
int              setgroups (int, const gid_t *);
pid_t            getpgrp (void);
int              setpgid (pid_t, pid_t);
pid_t            vfork (void);
int              setregid (gid_t, gid_t);
int              chroot (const char *);
int              prctl (int option, unsigned int arg2, unsigned int arg3, unsigned int arg4, unsigned int arg5);
int              capget (cap_user_header_t header, cap_user_data_t data);
int              capset (cap_user_header_t header, const cap_user_data_t data);
int              acct (const char*  filepath);
ssize_t          read (int, void*, size_t);
ssize_t          write (int, const void*, size_t);
ssize_t          __pread64 (int, void *, size_t, off_t, off_t);
ssize_t          __pwrite64 (int, void *, size_t, off_t, off_t);
int              __open (const char*, int, mode_t);
int              __openat (int, const char*, int, mode_t);
int              close (int);
int              creat (const char*, mode_t);
off_t            lseek (int, off_t, int);
int              __llseek (int, unsigned long, unsigned long, loff_t*, int);
pid_t            getpid (void);
void *           mmap (void *, size_t, int, int, int, long);
void *           __mmap2 (void*, size_t, int, int, int, long);
int              munmap (void *, size_t);
void *           mremap (void *, size_t, size_t, unsigned long);
int              msync (const void *, size_t, int);
int              mprotect (const void *, size_t, int);
int              madvise (const void *, size_t, int);
int              mlock (const void *addr, size_t len);
int              munlock (const void *addr, size_t len);
int              mincore (void*  start, size_t  length, unsigned char*  vec);
int              __ioctl (int, int, void *);
int              readv (int, const struct iovec *, int);
int              writev (int, const struct iovec *, int);
int              __fcntl (int, int, void*);
int              flock (int, int);
int              fchmod (int, mode_t);
int              dup (int);
int              pipe (int *);
int              dup2 (int, int);
int              select (int, struct fd_set *, struct fd_set *, struct fd_set *, struct timeval *);
int              ftruncate (int, off_t);
int              getdents (unsigned int, struct dirent *, unsigned int);
int              fsync (int);
int              fchown (int, uid_t, gid_t);
void             sync (void);
int              __fcntl64 (int, int, void *);
int              fstatfs (int, size_t, struct statfs *);
ssize_t          sendfile (int out_fd, int in_fd, off_t *offset, size_t count);
int              fstatat (int dirfd, const char *path, struct stat *buf, int flags);
int              mkdirat (int dirfd, const char *pathname, mode_t mode);
int              fchownat (int dirfd, const char *path, uid_t owner, gid_t group, int flags);
int              fchmodat (int dirfd, const char *path, mode_t mode, int flags);
int              renameat (int olddirfd, const char *oldpath, int newdirfd, const char *newpath);
int              link (const char*, const char*);
int              unlink (const char*);
int              unlinkat (int, const char *, int);
int              chdir (const char*);
int              mknod (const char*, mode_t, dev_t);
int              chmod (const char*,mode_t);
int              chown (const char *, uid_t, gid_t);
int              lchown (const char*, uid_t, gid_t);
int              mount (const char*, const char*, const char*, unsigned long, const void*);
int              umount (const char*);
int              umount2 (const char*, int);
int              fstat (int, struct stat*);
int              stat (const char *, struct stat *);
int              lstat (const char *, struct stat *);
int              mkdir (const char *, mode_t);
int              readlink (const char *, char *, size_t);
int              rmdir (const char *);
int              rename (const char *, const char *);
int              __getcwd (char * buf, size_t size);
int              access (const char *, int);
int              symlink (const char *, const char *);
int              fchdir (int);
int              truncate (const char*, off_t);
int              __statfs64 (const char *, size_t, struct statfs *);
int              pause (void);
int              gettimeofday (struct timeval*, struct timezone*);
int              settimeofday (const struct timeval*, const struct timezone*);
clock_t          times (struct tms *);
int              nanosleep (const struct timespec *, struct timespec *);
int              clock_gettime (clockid_t clk_id, struct timespec *tp);
int              clock_settime (clockid_t clk_id, const struct timespec *tp);
int              clock_getres (clockid_t clk_id, struct timespec *res);
int              clock_nanosleep (const struct timespec *req, struct timespec *rem);
int              getitimer (int, const struct itimerval *);
int              setitimer (int, const struct itimerval *, struct itimerval *);
int              __timer_create (clockid_t clockid, struct sigevent *evp, timer_t *timerid);
int              __timer_settime (timer_t, int, const struct itimerspec*, struct itimerspec*);
int              __timer_gettime (timer_t, struct itimerspec*);
int              __timer_getoverrun (timer_t);
int              __timer_delete (timer_t);
int              utimes (const char*, const struct timeval tvp[2]);
int              sigaction (int, const struct sigaction *, struct sigaction *);
int              sigprocmask (int, const sigset_t *, sigset_t *);
int              __sigsuspend (int unused1, int unused2, unsigned mask);
int              __rt_sigaction (int sig, const struct sigaction *act, struct sigaction *oact, size_t sigsetsize);
int              __rt_sigprocmask (int  how, const sigset_t *set, sigset_t *oset, size_t sigsetsize);
int              __rt_sigtimedwait (const sigset_t *set, struct siginfo_t  *info, struct timespec_t  *timeout, size_t  sigset_size);
int              sigpending (sigset_t *);
int              socket (int, int, int);
int              socketpair (int, int, int, int*);
int              bind (int, struct sockaddr *, int);
int              connect (int, struct sockaddr *, socklen_t);
int              listen (int, int);
int              accept (int, struct sockaddr *, socklen_t *);
int              getsockname (int, struct sockaddr *, socklen_t *);
int              getpeername (int, struct sockaddr *, socklen_t *);
int              sendto (int, const void *, size_t, int, const struct sockaddr *, socklen_t);
int              recvfrom (int, void *, size_t, unsigned int, struct sockaddr *, socklen_t *);
int              shutdown (int, int);
int              setsockopt (int, int, int, const void *, socklen_t);
int              getsockopt (int, int, int, void *, socklen_t *);
int              sendmsg (int, const struct msghdr *, unsigned int);
int              recvmsg (int, struct msghdr *, unsigned int);
int              socket (int, int, int);
int              bind (int, struct sockaddr *, int);
int              connect (int, struct sockaddr *, socklen_t);
int              listen (int, int);
int              accept (int, struct sockaddr *, socklen_t *);
int              getsockname (int, struct sockaddr *, socklen_t *);
int              getpeername (int, struct sockaddr *, socklen_t *);
int              socketpair (int, int, int, int*);
int              sendto (int, const void *, size_t, int, const struct sockaddr *, socklen_t);
int              recvfrom (int, void *, size_t, unsigned int, struct sockaddr *, socklen_t *);
int              shutdown (int, int);
int              setsockopt (int, int, int, const void *, socklen_t);
int              getsockopt (int, int, int, void *, socklen_t *);
int              sendmsg (int, const struct msghdr *, unsigned int);
int              recvmsg (int, struct msghdr *, unsigned int);
int              __socketcall (int, unsigned long*);
int              sched_setscheduler (pid_t pid, int policy, const struct sched_param *param);
int              sched_getscheduler (pid_t pid);
int              sched_yield (void);
int              sched_setparam (pid_t pid, const struct sched_param *param);
int              sched_getparam (pid_t pid, struct sched_param *param);
int              sched_get_priority_max (int policy);
int              sched_get_priority_min (int policy);
int              sched_rr_get_interval (pid_t pid, struct timespec *interval);
int              uname (struct utsname *);
pid_t            __wait4 (pid_t pid, int *status, int options, struct rusage *rusage);
mode_t           umask (mode_t);
int              __reboot (int, int, int, void *);
int              __syslog (int, char *, int);
int              init_module (void *, unsigned long, const char *);
int              delete_module (const char*, unsigned int);
int              klogctl (int, char *, int);
int              futex (void *, int, int, void *, void *, int);
int              epoll_create (int size);
int              epoll_ctl (int epfd, int op, int fd, struct epoll_event *event);
int              epoll_wait (int epfd, struct epoll_event *events, int max, int timeout);
int              inotify_init (void);
int              inotify_add_watch (int, const char *, unsigned int);
int              inotify_rm_watch (int, unsigned int);
int              poll (struct pollfd *, unsigned int, long);
int              __set_tls (void*);
int              cacheflush (long start, long end, long flags);
#ifdef __cplusplus
}
#endif

#endif /* _BIONIC_LINUX_UNISTD_H_ */
