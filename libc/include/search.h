/*-
 * Written by J.T. Conklin <jtc@netbsd.org>
 * Public domain.
 *
 *	$NetBSD: search.h,v 1.12 1999/02/22 10:34:28 christos Exp $
 * $FreeBSD: release/9.0.0/include/search.h 105250 2002-10-16 14:29:23Z robert $
 */

#ifndef _SEARCH_H_
#define _SEARCH_H_

#include <sys/cdefs.h>
#include <sys/types.h>

typedef enum {
  preorder,
  postorder,
  endorder,
  leaf
} VISIT;

#ifdef _SEARCH_PRIVATE
typedef struct node {
  char* key;
  struct node* llink;
  struct node* rlink;
} node_t;
#endif

__BEGIN_DECLS

void insque(void* __element, void* __previous) __INTRODUCED_IN(21);
void remque(void* __element) __INTRODUCED_IN(21);

void* lfind(const void* __key, const void* __base, size_t* __count, size_t __size, int (*__comparator)(const void*, const void*))
  __INTRODUCED_IN(21);
void* lsearch(const void* __key, void* __base, size_t* __count, size_t __size, int (*__comparator)(const void*, const void*))
  __INTRODUCED_IN(21);

void* tdelete(const void* __key, void** __root_ptr, int (*__comparator)(const void*, const void*)) __INTRODUCED_IN(16);
void tdestroy(void* __root, void (*__free_fn)(void*)) __INTRODUCED_IN(16);
void* tfind(const void* __key, void* const* __root_ptr, int (*__comparator)(const void*, const void*)) __INTRODUCED_IN(16);
void* tsearch(const void* __key, void** __root_ptr, int (*__comparator)(const void*, const void*)) __INTRODUCED_IN(16);
void twalk(const void* __root, void (*__visitor)(const void*, VISIT, int)) __INTRODUCED_IN(21);

__END_DECLS

#endif
