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
#ifndef _I386_PGALLOC_H
#define _I386_PGALLOC_H
#include <linux/threads.h>
#include <linux/mm.h>  
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define paravirt_alloc_pt(mm, pfn) do { } while (0)
#define paravirt_alloc_pd(pfn) do { } while (0)
#define paravirt_alloc_pd(pfn) do { } while (0)
#define paravirt_alloc_pd_clone(pfn, clonepfn, start, count) do { } while (0)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define paravirt_release_pt(pfn) do { } while (0)
#define paravirt_release_pd(pfn) do { } while (0)
#define pmd_populate_kernel(mm, pmd, pte)  do {   paravirt_alloc_pt(mm, __pa(pte) >> PAGE_SHIFT);   set_pmd(pmd, __pmd(_PAGE_TABLE + __pa(pte)));  } while (0)
#define pmd_populate(mm, pmd, pte)  do {   paravirt_alloc_pt(mm, page_to_pfn(pte));   set_pmd(pmd, __pmd(_PAGE_TABLE +   ((unsigned long long)page_to_pfn(pte) <<   (unsigned long long) PAGE_SHIFT)));  } while (0)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define __pte_free_tlb(tlb,pte)  do {   paravirt_release_pt(page_to_pfn(pte));   tlb_remove_page((tlb),(pte));  } while (0)
#endif
