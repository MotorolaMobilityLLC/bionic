/*	$NetBSD: elf_machdep.h,v 1.12 2016/02/02 20:16:59 christos Exp $	*/

#ifndef _X86_ELF_MACHDEP_H_
#define _X86_ELF_MACHDEP_H_

/* i386 relocations */
#define	R_386_NONE	0
#define	R_386_32	1
#define	R_386_PC32	2
#define	R_386_GOT32	3
#define	R_386_PLT32	4
#define	R_386_COPY	5
#define	R_386_GLOB_DAT	6
#define	R_386_JMP_SLOT	7
#define	R_386_RELATIVE	8
#define	R_386_GOTOFF	9
#define	R_386_GOTPC	10
#define	R_386_32PLT	11

/* TLS relocations */
#define	R_386_TLS_TPOFF	14
#define	R_386_TLS_IE	15
#define	R_386_TLS_GOTIE	16
#define	R_386_TLS_LE	17
#define	R_386_TLS_GD	18
#define	R_386_TLS_LDM	19

/* The following relocations are GNU extensions. */
#define	R_386_16	20
#define	R_386_PC16	21
#define	R_386_8		22
#define	R_386_PC8	23

/* More TLS relocations */
#define	R_386_TLS_GD_32		24
#define	R_386_TLS_GD_PUSH	25
#define	R_386_TLS_GD_CALL	26
#define	R_386_TLS_GD_POP	27
#define	R_386_TLS_LDM_32	28
#define	R_386_TLS_LDM_PUSH	29
#define	R_386_TLS_LDM_CALL	30
#define	R_386_TLS_LDM_POP	31
#define	R_386_TLS_LDO_32	32
#define	R_386_TLS_IE_32		33
#define	R_386_TLS_LE_32		34
#define	R_386_TLS_DTPMOD32	35
#define	R_386_TLS_DTPOFF32	36
#define	R_386_TLS_TPOFF32	37

#define R_386_SIZE32		38

/* More TLS relocations */
#define	R_386_TLS_GOTDESC	39
#define	R_386_TLS_DESC_CALL	40
#define	R_386_TLS_DESC		41

#define R_386_IRELATIVE		42
#define R_386_GOT32X		43

#endif
