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
#ifndef _UAPI_LINUX_NFS_H
#define _UAPI_LINUX_NFS_H
#define NFS_PROGRAM 100003
#define NFS_PORT 2049
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define NFS_MAXDATA 8192
#define NFS_MAXPATHLEN 1024
#define NFS_MAXNAMLEN 255
#define NFS_MAXGROUPS 16
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define NFS_FHSIZE 32
#define NFS_COOKIESIZE 4
#define NFS_FIFO_DEV (- 1)
#define NFSMODE_FMT 0170000
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define NFSMODE_DIR 0040000
#define NFSMODE_CHR 0020000
#define NFSMODE_BLK 0060000
#define NFSMODE_REG 0100000
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define NFSMODE_LNK 0120000
#define NFSMODE_SOCK 0140000
#define NFSMODE_FIFO 0010000
#define NFS_MNT_PROGRAM 100005
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define NFS_MNT_VERSION 1
#define NFS_MNT3_VERSION 3
#define NFS_PIPE_DIRNAME "nfs"
enum nfs_stat {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFS_OK = 0,
  NFSERR_PERM = 1,
  NFSERR_NOENT = 2,
  NFSERR_IO = 5,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFSERR_NXIO = 6,
  NFSERR_EAGAIN = 11,
  NFSERR_ACCES = 13,
  NFSERR_EXIST = 17,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFSERR_XDEV = 18,
  NFSERR_NODEV = 19,
  NFSERR_NOTDIR = 20,
  NFSERR_ISDIR = 21,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFSERR_INVAL = 22,
  NFSERR_FBIG = 27,
  NFSERR_NOSPC = 28,
  NFSERR_ROFS = 30,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFSERR_MLINK = 31,
  NFSERR_OPNOTSUPP = 45,
  NFSERR_NAMETOOLONG = 63,
  NFSERR_NOTEMPTY = 66,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFSERR_DQUOT = 69,
  NFSERR_STALE = 70,
  NFSERR_REMOTE = 71,
  NFSERR_WFLUSH = 99,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFSERR_BADHANDLE = 10001,
  NFSERR_NOT_SYNC = 10002,
  NFSERR_BAD_COOKIE = 10003,
  NFSERR_NOTSUPP = 10004,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFSERR_TOOSMALL = 10005,
  NFSERR_SERVERFAULT = 10006,
  NFSERR_BADTYPE = 10007,
  NFSERR_JUKEBOX = 10008,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFSERR_SAME = 10009,
  NFSERR_DENIED = 10010,
  NFSERR_EXPIRED = 10011,
  NFSERR_LOCKED = 10012,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFSERR_GRACE = 10013,
  NFSERR_FHEXPIRED = 10014,
  NFSERR_SHARE_DENIED = 10015,
  NFSERR_WRONGSEC = 10016,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFSERR_CLID_INUSE = 10017,
  NFSERR_RESOURCE = 10018,
  NFSERR_MOVED = 10019,
  NFSERR_NOFILEHANDLE = 10020,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFSERR_MINOR_VERS_MISMATCH = 10021,
  NFSERR_STALE_CLIENTID = 10022,
  NFSERR_STALE_STATEID = 10023,
  NFSERR_OLD_STATEID = 10024,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFSERR_BAD_STATEID = 10025,
  NFSERR_BAD_SEQID = 10026,
  NFSERR_NOT_SAME = 10027,
  NFSERR_LOCK_RANGE = 10028,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFSERR_SYMLINK = 10029,
  NFSERR_RESTOREFH = 10030,
  NFSERR_LEASE_MOVED = 10031,
  NFSERR_ATTRNOTSUPP = 10032,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFSERR_NO_GRACE = 10033,
  NFSERR_RECLAIM_BAD = 10034,
  NFSERR_RECLAIM_CONFLICT = 10035,
  NFSERR_BAD_XDR = 10036,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFSERR_LOCKS_HELD = 10037,
  NFSERR_OPENMODE = 10038,
  NFSERR_BADOWNER = 10039,
  NFSERR_BADCHAR = 10040,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFSERR_BADNAME = 10041,
  NFSERR_BAD_RANGE = 10042,
  NFSERR_LOCK_NOTSUPP = 10043,
  NFSERR_OP_ILLEGAL = 10044,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFSERR_DEADLOCK = 10045,
  NFSERR_FILE_OPEN = 10046,
  NFSERR_ADMIN_REVOKED = 10047,
  NFSERR_CB_PATH_DOWN = 10048,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
enum nfs_ftype {
  NFNON = 0,
  NFREG = 1,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFDIR = 2,
  NFBLK = 3,
  NFCHR = 4,
  NFLNK = 5,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  NFSOCK = 6,
  NFBAD = 7,
  NFFIFO = 8
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#endif
