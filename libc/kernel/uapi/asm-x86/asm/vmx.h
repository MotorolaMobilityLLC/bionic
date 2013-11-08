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
#ifndef _UAPIVMX_H
#define _UAPIVMX_H
#define VMX_EXIT_REASONS_FAILED_VMENTRY 0x80000000
#define EXIT_REASON_EXCEPTION_NMI 0
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define EXIT_REASON_EXTERNAL_INTERRUPT 1
#define EXIT_REASON_TRIPLE_FAULT 2
#define EXIT_REASON_PENDING_INTERRUPT 7
#define EXIT_REASON_NMI_WINDOW 8
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define EXIT_REASON_TASK_SWITCH 9
#define EXIT_REASON_CPUID 10
#define EXIT_REASON_HLT 12
#define EXIT_REASON_INVD 13
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define EXIT_REASON_INVLPG 14
#define EXIT_REASON_RDPMC 15
#define EXIT_REASON_RDTSC 16
#define EXIT_REASON_VMCALL 18
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define EXIT_REASON_VMCLEAR 19
#define EXIT_REASON_VMLAUNCH 20
#define EXIT_REASON_VMPTRLD 21
#define EXIT_REASON_VMPTRST 22
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define EXIT_REASON_VMREAD 23
#define EXIT_REASON_VMRESUME 24
#define EXIT_REASON_VMWRITE 25
#define EXIT_REASON_VMOFF 26
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define EXIT_REASON_VMON 27
#define EXIT_REASON_CR_ACCESS 28
#define EXIT_REASON_DR_ACCESS 29
#define EXIT_REASON_IO_INSTRUCTION 30
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define EXIT_REASON_MSR_READ 31
#define EXIT_REASON_MSR_WRITE 32
#define EXIT_REASON_INVALID_STATE 33
#define EXIT_REASON_MWAIT_INSTRUCTION 36
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define EXIT_REASON_MONITOR_INSTRUCTION 39
#define EXIT_REASON_PAUSE_INSTRUCTION 40
#define EXIT_REASON_MCE_DURING_VMENTRY 41
#define EXIT_REASON_TPR_BELOW_THRESHOLD 43
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define EXIT_REASON_APIC_ACCESS 44
#define EXIT_REASON_EOI_INDUCED 45
#define EXIT_REASON_EPT_VIOLATION 48
#define EXIT_REASON_EPT_MISCONFIG 49
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define EXIT_REASON_PREEMPTION_TIMER 52
#define EXIT_REASON_WBINVD 54
#define EXIT_REASON_XSETBV 55
#define EXIT_REASON_APIC_WRITE 56
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define EXIT_REASON_INVPCID 58
#define VMX_EXIT_REASONS   { EXIT_REASON_EXCEPTION_NMI, "EXCEPTION_NMI" },   { EXIT_REASON_EXTERNAL_INTERRUPT, "EXTERNAL_INTERRUPT" },   { EXIT_REASON_TRIPLE_FAULT, "TRIPLE_FAULT" },   { EXIT_REASON_PENDING_INTERRUPT, "PENDING_INTERRUPT" },   { EXIT_REASON_NMI_WINDOW, "NMI_WINDOW" },   { EXIT_REASON_TASK_SWITCH, "TASK_SWITCH" },   { EXIT_REASON_CPUID, "CPUID" },   { EXIT_REASON_HLT, "HLT" },   { EXIT_REASON_INVLPG, "INVLPG" },   { EXIT_REASON_RDPMC, "RDPMC" },   { EXIT_REASON_RDTSC, "RDTSC" },   { EXIT_REASON_VMCALL, "VMCALL" },   { EXIT_REASON_VMCLEAR, "VMCLEAR" },   { EXIT_REASON_VMLAUNCH, "VMLAUNCH" },   { EXIT_REASON_VMPTRLD, "VMPTRLD" },   { EXIT_REASON_VMPTRST, "VMPTRST" },   { EXIT_REASON_VMREAD, "VMREAD" },   { EXIT_REASON_VMRESUME, "VMRESUME" },   { EXIT_REASON_VMWRITE, "VMWRITE" },   { EXIT_REASON_VMOFF, "VMOFF" },   { EXIT_REASON_VMON, "VMON" },   { EXIT_REASON_CR_ACCESS, "CR_ACCESS" },   { EXIT_REASON_DR_ACCESS, "DR_ACCESS" },   { EXIT_REASON_IO_INSTRUCTION, "IO_INSTRUCTION" },   { EXIT_REASON_MSR_READ, "MSR_READ" },   { EXIT_REASON_MSR_WRITE, "MSR_WRITE" },   { EXIT_REASON_MWAIT_INSTRUCTION, "MWAIT_INSTRUCTION" },   { EXIT_REASON_MONITOR_INSTRUCTION, "MONITOR_INSTRUCTION" },   { EXIT_REASON_PAUSE_INSTRUCTION, "PAUSE_INSTRUCTION" },   { EXIT_REASON_MCE_DURING_VMENTRY, "MCE_DURING_VMENTRY" },   { EXIT_REASON_TPR_BELOW_THRESHOLD, "TPR_BELOW_THRESHOLD" },   { EXIT_REASON_APIC_ACCESS, "APIC_ACCESS" },   { EXIT_REASON_EPT_VIOLATION, "EPT_VIOLATION" },   { EXIT_REASON_EPT_MISCONFIG, "EPT_MISCONFIG" },   { EXIT_REASON_WBINVD, "WBINVD" },   { EXIT_REASON_APIC_WRITE, "APIC_WRITE" },   { EXIT_REASON_EOI_INDUCED, "EOI_INDUCED" },   { EXIT_REASON_INVALID_STATE, "INVALID_STATE" },   { EXIT_REASON_INVD, "INVD" },   { EXIT_REASON_INVPCID, "INVPCID" },   { EXIT_REASON_PREEMPTION_TIMER, "PREEMPTION_TIMER" }
#endif
