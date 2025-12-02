#include <private/bionic_asm.h>

// pid_t __bionic_clone(int flags, void* child_stack, pid_t* parent_tid, void* tls, pid_t* child_tid, int (*fn)(void*), void* arg);
ENTRY_PRIVATE(__bionic_clone)
        pushl   %ebx
        .cfi_adjust_cfa_offset 4
        .cfi_rel_offset ebx, 0
        pushl   %esi
        .cfi_adjust_cfa_offset 4
        .cfi_rel_offset esi, 0
        pushl   %edi
        .cfi_adjust_cfa_offset 4
        .cfi_rel_offset edi, 0

        # Load system call arguments into registers.
        movl    16(%esp), %ebx   # flags
        movl    20(%esp), %ecx   # child_stack
        movl    24(%esp), %edx   # parent_tid
        movl    28(%esp), %esi   # tls
        movl    32(%esp), %edi   # child_tid

        # Copy 'fn' and 'arg' onto the child stack
        movl    36(%esp), %eax   # Read 'fn'.
        movl    %eax, -16(%ecx)  # Write 'fn'.
        movl    40(%esp), %eax   # Read 'arg'.
        movl    %eax, -12(%ecx)  # Write 'arg'.
        subl    $16, %ecx

        # Make the system call.
        movl    $__NR_clone, %eax
        int     $0x80

        # Check result.
        testl    %eax, %eax
        jz      L(child)
        jg      L(parent)

        # An error occurred, so set errno and return -1.
        pushl   %eax
        call    __set_errno_internal
        addl    $4, %esp
        jmp     L(return)

L(child):
        # We don't want anyone to unwind past this point.
        .cfi_undefined %eip
        .cfi_undefined %ebp
        xorl    %ebp, %ebp
        call    __start_thread
        hlt

L(parent):
        # We're the parent; nothing to do.
L(return):
        popl    %edi
        .cfi_adjust_cfa_offset -4
        .cfi_restore edi
        popl    %esi
        .cfi_adjust_cfa_offset -4
        .cfi_restore esi
        popl    %ebx
        .cfi_adjust_cfa_offset -4
        .cfi_restore ebx
        ret
END(__bionic_clone)
