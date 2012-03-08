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
#ifndef _LINUX_PLIST_H_
#define _LINUX_PLIST_H_
#include <linux/kernel.h>
#include <linux/list.h>
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#include <linux/spinlock_types.h>
struct plist_head {
 struct list_head prio_list;
 struct list_head node_list;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct plist_node {
 int prio;
 struct plist_head plist;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
#define PLIST_HEAD_LOCK_INIT(_lock)
#define PLIST_HEAD_INIT(head, _lock)  {   .prio_list = LIST_HEAD_INIT((head).prio_list),   .node_list = LIST_HEAD_INIT((head).node_list),   PLIST_HEAD_LOCK_INIT(&(_lock))  }
#define PLIST_NODE_INIT(node, __prio)  {   .prio = (__prio),   .plist = PLIST_HEAD_INIT((node).plist, NULL),  }
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define plist_for_each(pos, head)   list_for_each_entry(pos, &(head)->node_list, plist.node_list)
#define plist_for_each_safe(pos, n, head)   list_for_each_entry_safe(pos, n, &(head)->node_list, plist.node_list)
#define plist_for_each_entry(pos, head, mem)   list_for_each_entry(pos, &(head)->node_list, mem.plist.node_list)
#define plist_for_each_entry_safe(pos, n, head, m)   list_for_each_entry_safe(pos, n, &(head)->node_list, m.plist.node_list)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define plist_first_entry(head, type, member)   container_of(plist_first(head), type, member)
#endif
