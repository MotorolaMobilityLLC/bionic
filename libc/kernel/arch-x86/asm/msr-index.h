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
#ifndef __ASM_MSR_INDEX_H
#define __ASM_MSR_INDEX_H
#define MSR_EFER 0xc0000080
#define MSR_STAR 0xc0000081
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSR_LSTAR 0xc0000082
#define MSR_CSTAR 0xc0000083
#define MSR_SYSCALL_MASK 0xc0000084
#define MSR_FS_BASE 0xc0000100
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSR_GS_BASE 0xc0000101
#define MSR_KERNEL_GS_BASE 0xc0000102
#define _EFER_SCE 0
#define _EFER_LME 8
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define _EFER_LMA 10
#define _EFER_NX 11
#define EFER_SCE (1<<_EFER_SCE)
#define EFER_LME (1<<_EFER_LME)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define EFER_LMA (1<<_EFER_LMA)
#define EFER_NX (1<<_EFER_NX)
#define MSR_IA32_PERFCTR0 0x000000c1
#define MSR_IA32_PERFCTR1 0x000000c2
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSR_FSB_FREQ 0x000000cd
#define MSR_MTRRcap 0x000000fe
#define MSR_IA32_BBL_CR_CTL 0x00000119
#define MSR_IA32_SYSENTER_CS 0x00000174
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSR_IA32_SYSENTER_ESP 0x00000175
#define MSR_IA32_SYSENTER_EIP 0x00000176
#define MSR_IA32_MCG_CAP 0x00000179
#define MSR_IA32_MCG_STATUS 0x0000017a
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSR_IA32_MCG_CTL 0x0000017b
#define MSR_IA32_PEBS_ENABLE 0x000003f1
#define MSR_IA32_DS_AREA 0x00000600
#define MSR_IA32_PERF_CAPABILITIES 0x00000345
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSR_MTRRfix64K_00000 0x00000250
#define MSR_MTRRfix16K_80000 0x00000258
#define MSR_MTRRfix16K_A0000 0x00000259
#define MSR_MTRRfix4K_C0000 0x00000268
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSR_MTRRfix4K_C8000 0x00000269
#define MSR_MTRRfix4K_D0000 0x0000026a
#define MSR_MTRRfix4K_D8000 0x0000026b
#define MSR_MTRRfix4K_E0000 0x0000026c
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSR_MTRRfix4K_E8000 0x0000026d
#define MSR_MTRRfix4K_F0000 0x0000026e
#define MSR_MTRRfix4K_F8000 0x0000026f
#define MSR_MTRRdefType 0x000002ff
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSR_IA32_DEBUGCTLMSR 0x000001d9
#define MSR_IA32_LASTBRANCHFROMIP 0x000001db
#define MSR_IA32_LASTBRANCHTOIP 0x000001dc
#define MSR_IA32_LASTINTFROMIP 0x000001dd
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSR_IA32_LASTINTTOIP 0x000001de
#define MSR_IA32_MC0_CTL 0x00000400
#define MSR_IA32_MC0_STATUS 0x00000401
#define MSR_IA32_MC0_ADDR 0x00000402
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSR_IA32_MC0_MISC 0x00000403
#define MSR_P6_PERFCTR0 0x000000c1
#define MSR_P6_PERFCTR1 0x000000c2
#define MSR_P6_EVNTSEL0 0x00000186
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSR_P6_EVNTSEL1 0x00000187
#define MSR_AMD64_IBSFETCHCTL 0xc0011030
#define MSR_AMD64_IBSFETCHLINAD 0xc0011031
#define MSR_AMD64_IBSFETCHPHYSAD 0xc0011032
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSR_AMD64_IBSOPCTL 0xc0011033
#define MSR_AMD64_IBSOPRIP 0xc0011034
#define MSR_AMD64_IBSOPDATA 0xc0011035
#define MSR_AMD64_IBSOPDATA2 0xc0011036
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSR_AMD64_IBSOPDATA3 0xc0011037
#define MSR_AMD64_IBSDCLINAD 0xc0011038
#define MSR_AMD64_IBSDCPHYSAD 0xc0011039
#define MSR_AMD64_IBSCTL 0xc001103a
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSR_K8_TOP_MEM1 0xc001001a
#define MSR_K8_TOP_MEM2 0xc001001d
#define MSR_K8_SYSCFG 0xc0010010
#define MSR_K8_HWCR 0xc0010015
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSR_K8_ENABLE_C1E 0xc0010055
#define K8_MTRRFIXRANGE_DRAM_ENABLE 0x00040000
#define K8_MTRRFIXRANGE_DRAM_MODIFY 0x00080000
#define K8_MTRR_RDMEM_WRMEM_MASK 0x18181818
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSR_K7_EVNTSEL0 0xc0010000
#define MSR_K7_PERFCTR0 0xc0010004
#define MSR_K7_EVNTSEL1 0xc0010001
#define MSR_K7_PERFCTR1 0xc0010005
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSR_K7_EVNTSEL2 0xc0010002
#define MSR_K7_PERFCTR2 0xc0010006
#define MSR_K7_EVNTSEL3 0xc0010003
#define MSR_K7_PERFCTR3 0xc0010007
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSR_K7_CLK_CTL 0xc001001b
#define MSR_K7_HWCR 0xc0010015
#define MSR_K7_FID_VID_CTL 0xc0010041
#define MSR_K7_FID_VID_STATUS 0xc0010042
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSR_K6_EFER 0xc0000080
#define MSR_K6_STAR 0xc0000081
#define MSR_K6_WHCR 0xc0000082
#define MSR_K6_UWCCR 0xc0000085
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSR_K6_EPMR 0xc0000086
#define MSR_K6_PSOR 0xc0000087
#define MSR_K6_PFIR 0xc0000088
#define MSR_IDT_FCR1 0x00000107
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSR_IDT_FCR2 0x00000108
#define MSR_IDT_FCR3 0x00000109
#define MSR_IDT_FCR4 0x0000010a
#define MSR_IDT_MCR0 0x00000110
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSR_IDT_MCR1 0x00000111
#define MSR_IDT_MCR2 0x00000112
#define MSR_IDT_MCR3 0x00000113
#define MSR_IDT_MCR4 0x00000114
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSR_IDT_MCR5 0x00000115
#define MSR_IDT_MCR6 0x00000116
#define MSR_IDT_MCR7 0x00000117
#define MSR_IDT_MCR_CTRL 0x00000120
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSR_VIA_FCR 0x00001107
#define MSR_VIA_LONGHAUL 0x0000110a
#define MSR_VIA_RNG 0x0000110b
#define MSR_VIA_BCR2 0x00001147
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSR_TMTA_LONGRUN_CTRL 0x80868010
#define MSR_TMTA_LONGRUN_FLAGS 0x80868011
#define MSR_TMTA_LRTI_READOUT 0x80868018
#define MSR_TMTA_LRTI_VOLT_MHZ 0x8086801a
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSR_IA32_P5_MC_ADDR 0x00000000
#define MSR_IA32_P5_MC_TYPE 0x00000001
#define MSR_IA32_TSC 0x00000010
#define MSR_IA32_PLATFORM_ID 0x00000017
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSR_IA32_EBL_CR_POWERON 0x0000002a
#define MSR_IA32_APICBASE 0x0000001b
#define MSR_IA32_APICBASE_BSP (1<<8)
#define MSR_IA32_APICBASE_ENABLE (1<<11)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSR_IA32_APICBASE_BASE (0xfffff<<12)
#define MSR_IA32_UCODE_WRITE 0x00000079
#define MSR_IA32_UCODE_REV 0x0000008b
#define MSR_IA32_PERF_STATUS 0x00000198
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSR_IA32_PERF_CTL 0x00000199
#define MSR_IA32_MPERF 0x000000e7
#define MSR_IA32_APERF 0x000000e8
#define MSR_IA32_THERM_CONTROL 0x0000019a
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSR_IA32_THERM_INTERRUPT 0x0000019b
#define MSR_IA32_THERM_STATUS 0x0000019c
#define MSR_IA32_MISC_ENABLE 0x000001a0
#define MSR_P6_EVNTSEL0 0x00000186
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSR_P6_EVNTSEL1 0x00000187
#define MSR_IA32_MCG_EAX 0x00000180
#define MSR_IA32_MCG_EBX 0x00000181
#define MSR_IA32_MCG_ECX 0x00000182
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSR_IA32_MCG_EDX 0x00000183
#define MSR_IA32_MCG_ESI 0x00000184
#define MSR_IA32_MCG_EDI 0x00000185
#define MSR_IA32_MCG_EBP 0x00000186
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSR_IA32_MCG_ESP 0x00000187
#define MSR_IA32_MCG_EFLAGS 0x00000188
#define MSR_IA32_MCG_EIP 0x00000189
#define MSR_IA32_MCG_RESERVED 0x0000018a
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSR_P4_BPU_PERFCTR0 0x00000300
#define MSR_P4_BPU_PERFCTR1 0x00000301
#define MSR_P4_BPU_PERFCTR2 0x00000302
#define MSR_P4_BPU_PERFCTR3 0x00000303
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSR_P4_MS_PERFCTR0 0x00000304
#define MSR_P4_MS_PERFCTR1 0x00000305
#define MSR_P4_MS_PERFCTR2 0x00000306
#define MSR_P4_MS_PERFCTR3 0x00000307
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSR_P4_FLAME_PERFCTR0 0x00000308
#define MSR_P4_FLAME_PERFCTR1 0x00000309
#define MSR_P4_FLAME_PERFCTR2 0x0000030a
#define MSR_P4_FLAME_PERFCTR3 0x0000030b
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSR_P4_IQ_PERFCTR0 0x0000030c
#define MSR_P4_IQ_PERFCTR1 0x0000030d
#define MSR_P4_IQ_PERFCTR2 0x0000030e
#define MSR_P4_IQ_PERFCTR3 0x0000030f
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSR_P4_IQ_PERFCTR4 0x00000310
#define MSR_P4_IQ_PERFCTR5 0x00000311
#define MSR_P4_BPU_CCCR0 0x00000360
#define MSR_P4_BPU_CCCR1 0x00000361
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSR_P4_BPU_CCCR2 0x00000362
#define MSR_P4_BPU_CCCR3 0x00000363
#define MSR_P4_MS_CCCR0 0x00000364
#define MSR_P4_MS_CCCR1 0x00000365
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSR_P4_MS_CCCR2 0x00000366
#define MSR_P4_MS_CCCR3 0x00000367
#define MSR_P4_FLAME_CCCR0 0x00000368
#define MSR_P4_FLAME_CCCR1 0x00000369
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSR_P4_FLAME_CCCR2 0x0000036a
#define MSR_P4_FLAME_CCCR3 0x0000036b
#define MSR_P4_IQ_CCCR0 0x0000036c
#define MSR_P4_IQ_CCCR1 0x0000036d
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSR_P4_IQ_CCCR2 0x0000036e
#define MSR_P4_IQ_CCCR3 0x0000036f
#define MSR_P4_IQ_CCCR4 0x00000370
#define MSR_P4_IQ_CCCR5 0x00000371
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSR_P4_ALF_ESCR0 0x000003ca
#define MSR_P4_ALF_ESCR1 0x000003cb
#define MSR_P4_BPU_ESCR0 0x000003b2
#define MSR_P4_BPU_ESCR1 0x000003b3
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSR_P4_BSU_ESCR0 0x000003a0
#define MSR_P4_BSU_ESCR1 0x000003a1
#define MSR_P4_CRU_ESCR0 0x000003b8
#define MSR_P4_CRU_ESCR1 0x000003b9
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSR_P4_CRU_ESCR2 0x000003cc
#define MSR_P4_CRU_ESCR3 0x000003cd
#define MSR_P4_CRU_ESCR4 0x000003e0
#define MSR_P4_CRU_ESCR5 0x000003e1
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSR_P4_DAC_ESCR0 0x000003a8
#define MSR_P4_DAC_ESCR1 0x000003a9
#define MSR_P4_FIRM_ESCR0 0x000003a4
#define MSR_P4_FIRM_ESCR1 0x000003a5
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSR_P4_FLAME_ESCR0 0x000003a6
#define MSR_P4_FLAME_ESCR1 0x000003a7
#define MSR_P4_FSB_ESCR0 0x000003a2
#define MSR_P4_FSB_ESCR1 0x000003a3
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSR_P4_IQ_ESCR0 0x000003ba
#define MSR_P4_IQ_ESCR1 0x000003bb
#define MSR_P4_IS_ESCR0 0x000003b4
#define MSR_P4_IS_ESCR1 0x000003b5
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSR_P4_ITLB_ESCR0 0x000003b6
#define MSR_P4_ITLB_ESCR1 0x000003b7
#define MSR_P4_IX_ESCR0 0x000003c8
#define MSR_P4_IX_ESCR1 0x000003c9
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSR_P4_MOB_ESCR0 0x000003aa
#define MSR_P4_MOB_ESCR1 0x000003ab
#define MSR_P4_MS_ESCR0 0x000003c0
#define MSR_P4_MS_ESCR1 0x000003c1
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSR_P4_PMH_ESCR0 0x000003ac
#define MSR_P4_PMH_ESCR1 0x000003ad
#define MSR_P4_RAT_ESCR0 0x000003bc
#define MSR_P4_RAT_ESCR1 0x000003bd
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSR_P4_SAAT_ESCR0 0x000003ae
#define MSR_P4_SAAT_ESCR1 0x000003af
#define MSR_P4_SSU_ESCR0 0x000003be
#define MSR_P4_SSU_ESCR1 0x000003bf
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSR_P4_TBPU_ESCR0 0x000003c2
#define MSR_P4_TBPU_ESCR1 0x000003c3
#define MSR_P4_TC_ESCR0 0x000003c4
#define MSR_P4_TC_ESCR1 0x000003c5
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSR_P4_U2L_ESCR0 0x000003b0
#define MSR_P4_U2L_ESCR1 0x000003b1
#define MSR_CORE_PERF_FIXED_CTR0 0x00000309
#define MSR_CORE_PERF_FIXED_CTR1 0x0000030a
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSR_CORE_PERF_FIXED_CTR2 0x0000030b
#define MSR_CORE_PERF_FIXED_CTR_CTRL 0x0000038d
#define MSR_CORE_PERF_GLOBAL_STATUS 0x0000038e
#define MSR_CORE_PERF_GLOBAL_CTRL 0x0000038f
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MSR_CORE_PERF_GLOBAL_OVF_CTRL 0x00000390
#define MSR_GEODE_BUSCONT_CONF0 0x00001900
#endif
