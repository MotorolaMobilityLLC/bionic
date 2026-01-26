libc/kernel/android/uapi/linux/ contains header files that the kernel uapi
headers depend upon but do not provide.

libc/kernel/android/scsi/ contains frozen copies of kernel scsi headers.
Linux's scsi headers are a mix of userspace-facing and kernel-facing
declarations that can't be directly used by userspace. The glibc
maintainers manually copy-and-pasted these definitions into their own
scsi headers and haven't substantially updated them in 15 years. The
musl libc project has a similar set of definitions in its scsi headers.
Our versions of these files are actually maintained in
`external/kernel-headers/modified/scsi/`.
