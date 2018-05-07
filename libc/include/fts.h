/*	$OpenBSD: fts.h,v 1.12 2009/08/27 16:19:27 millert Exp $	*/
/*	$NetBSD: fts.h,v 1.5 1994/12/28 01:41:50 mycroft Exp $	*/

/*
 * Copyright (c) 1989, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *	@(#)fts.h	8.3 (Berkeley) 8/14/94
 */

#ifndef	_FTS_H_
#define	_FTS_H_

#include <sys/cdefs.h>
#include <sys/types.h>

typedef struct {
	struct _ftsent *fts_cur;	/* current node */
	struct _ftsent *fts_child;	/* linked list of children */
	struct _ftsent **fts_array;	/* sort array */
	dev_t fts_dev;			/* starting device # */
	char *fts_path;			/* path for this descent */
	int fts_rfd;			/* fd for root */
	size_t fts_pathlen;		/* sizeof(path) */
	int fts_nitems;			/* elements in the sort array */
	int (*fts_compar)();		/* compare function */

#define	FTS_COMFOLLOW	0x0001		/* follow command line symlinks */
#define	FTS_LOGICAL	0x0002		/* logical walk */
#define	FTS_NOCHDIR	0x0004		/* don't change directories */
#define	FTS_NOSTAT	0x0008		/* don't get stat info */
#define	FTS_PHYSICAL	0x0010		/* physical walk */
#define	FTS_SEEDOT	0x0020		/* return dot and dot-dot */
#define	FTS_XDEV	0x0040		/* don't cross devices */
#define	FTS_OPTIONMASK	0x00ff		/* valid user option mask */

#define FTS_NAMEONLY 0x1000  /* (private) child names only */
#define FTS_STOP 0x2000      /* (private) unrecoverable error */
#define FTS_FOR_FTW 0x4000   /* (private) fts is being called by ftw/nftw */
	int fts_options;		/* fts_open options, global flags */
} FTS;

typedef struct _ftsent {
	struct _ftsent *fts_cycle;	/* cycle node */
	struct _ftsent *fts_parent;	/* parent directory */
	struct _ftsent *fts_link;	/* next file in directory */
	long fts_number;	        /* local numeric value */
	void *fts_pointer;	        /* local address value */
	char *fts_accpath;		/* access path */
	char *fts_path;			/* root path */
	int fts_errno;			/* errno for this node */
	int fts_symfd;			/* fd for symlink */
	size_t fts_pathlen;		/* strlen(fts_path) */
	size_t fts_namelen;		/* strlen(fts_name) */

	ino_t fts_ino;			/* inode */
	dev_t fts_dev;			/* device */
	nlink_t fts_nlink;		/* link count */

#define	FTS_ROOTPARENTLEVEL	-1
#define	FTS_ROOTLEVEL		 0
#define	FTS_MAXLEVEL		 0x7fff
	short fts_level;		/* depth (-1 to N) */

#define	FTS_D		 1		/* preorder directory */
#define	FTS_DC		 2		/* directory that causes cycles */
#define	FTS_DEFAULT	 3		/* none of the above */
#define	FTS_DNR		 4		/* unreadable directory */
#define	FTS_DOT		 5		/* dot or dot-dot */
#define	FTS_DP		 6		/* postorder directory */
#define	FTS_ERR		 7		/* error; errno is set */
#define	FTS_F		 8		/* regular file */
#define	FTS_INIT	 9		/* initialized only */
#define	FTS_NS		10		/* stat(2) failed */
#define	FTS_NSOK	11		/* no stat(2) requested */
#define	FTS_SL		12		/* symbolic link */
#define	FTS_SLNONE	13		/* symbolic link without target */
	unsigned short fts_info;	/* user flags for FTSENT structure */

#define	FTS_DONTCHDIR	 0x01		/* don't chdir .. to the parent */
#define	FTS_SYMFOLLOW	 0x02		/* followed a symlink to get here */
	unsigned short fts_flags;	/* private flags for FTSENT structure */

#define	FTS_AGAIN	 1		/* read node again */
#define	FTS_FOLLOW	 2		/* follow symbolic link */
#define	FTS_NOINSTR	 3		/* no instructions */
#define	FTS_SKIP	 4		/* discard node */
	unsigned short fts_instr;	/* fts_set() instructions */

	struct stat *fts_statp;		/* stat(2) information */
	char fts_name[1];		/* file name */
} FTSENT;

__BEGIN_DECLS

/*
 * Strictly these functions were available before Lollipop/21, but there was an accidental ABI
 * breakage in 21 that means you can't write code that runs on current devices and pre-21 devices,
 * so we break the tie in favor of current and future devices.
 */
FTSENT* fts_children(FTS* __fts, int __options) __INTRODUCED_IN(21);
int fts_close(FTS* __fts) __INTRODUCED_IN(21);
FTS* fts_open(char* const* __path, int __options, int (*__comparator)(const FTSENT** __lhs, const FTSENT** __rhs)) __INTRODUCED_IN(21);
FTSENT* fts_read(FTS* __fts) __INTRODUCED_IN(21);
int fts_set(FTS* __fts, FTSENT* __entry, int __options) __INTRODUCED_IN(21);

__END_DECLS

#endif /* !_FTS_H_ */
