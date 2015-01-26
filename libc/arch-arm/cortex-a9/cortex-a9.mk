libc_bionic_src_files_arm += \
    arch-arm/generic/bionic/memcmp.S \
    arch-arm/cortex-a9/bionic/memcpy.S \
    arch-arm/cortex-a9/bionic/memset.S \
    arch-arm/cortex-a9/bionic/stpcpy.S \
    arch-arm/cortex-a9/bionic/strcat.S \
    arch-arm/cortex-a9/bionic/__strcat_chk.S \
    arch-arm/cortex-a9/bionic/strcmp.S \
    arch-arm/cortex-a9/bionic/strcpy.S \
    arch-arm/cortex-a9/bionic/__strcpy_chk.S \
    arch-arm/cortex-a9/bionic/strlen.S \

libc_openbsd_src_files_arm += \
    upstream-openbsd/lib/libc/string/memmove.c \
