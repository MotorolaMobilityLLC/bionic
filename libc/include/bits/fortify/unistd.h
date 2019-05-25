/*
 * Copyright (C) 2017 The Android Open Source Project
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */
#ifndef _UNISTD_H_
#error "Never include this file directly; instead, include <unistd.h>"
#endif

char* __getcwd_chk(char*, size_t, size_t) __INTRODUCED_IN(24);

ssize_t __pread_chk(int, void*, size_t, off_t, size_t) __INTRODUCED_IN(23);
ssize_t __pread_real(int, void*, size_t, off_t) __RENAME(pread);

ssize_t __pread64_chk(int, void*, size_t, off64_t, size_t) __INTRODUCED_IN(23);
ssize_t __pread64_real(int, void*, size_t, off64_t) __RENAME(pread64) __INTRODUCED_IN(12);

ssize_t __pwrite_chk(int, const void*, size_t, off_t, size_t) __INTRODUCED_IN(24);
ssize_t __pwrite_real(int, const void*, size_t, off_t) __RENAME(pwrite);

ssize_t __pwrite64_chk(int, const void*, size_t, off64_t, size_t) __INTRODUCED_IN(24);
ssize_t __pwrite64_real(int, const void*, size_t, off64_t) __RENAME(pwrite64)
  __INTRODUCED_IN(12);

ssize_t __read_chk(int, void*, size_t, size_t) __INTRODUCED_IN(21);
ssize_t __write_chk(int, const void*, size_t, size_t) __INTRODUCED_IN(24);
ssize_t __readlink_chk(const char*, char*, size_t, size_t) __INTRODUCED_IN(23);
ssize_t __readlinkat_chk(int dirfd, const char*, char*, size_t, size_t) __INTRODUCED_IN(23);

#if defined(__BIONIC_FORTIFY)

#if defined(__USE_FILE_OFFSET64)
#define __PREAD_PREFIX(x) __pread64_ ## x
#define __PWRITE_PREFIX(x) __pwrite64_ ## x
#else
#define __PREAD_PREFIX(x) __pread_ ## x
#define __PWRITE_PREFIX(x) __pwrite_ ## x
#endif

#define __error_if_overflows_ssizet(what, fn) \
    __clang_error_if((what) > SSIZE_MAX, "in call to '" #fn "', '" #what "' must be <= SSIZE_MAX")

#define __error_if_overflows_objectsize(what, objsize, fn) \
    __clang_error_if(__bos_unevaluated_lt((objsize), (what)), \
                     "in call to '" #fn "', '" #what "' bytes overflows the given object")

#if __ANDROID_API__ >= __ANDROID_API_N__
__BIONIC_FORTIFY_INLINE
char* getcwd(char* const __pass_object_size buf, size_t size)
        __overloadable
        __error_if_overflows_objectsize(size, __bos(buf), getcwd) {
    size_t bos = __bos(buf);

    if (bos == __BIONIC_FORTIFY_UNKNOWN_SIZE) {
        return __call_bypassing_fortify(getcwd)(buf, size);
    }

    return __getcwd_chk(buf, size, bos);
}
#endif /* __ANDROID_API__ >= __ANDROID_API_N__ */

#if __ANDROID_API__ >= __ANDROID_API_M__
__BIONIC_FORTIFY_INLINE
ssize_t pread(int fd, void* const __pass_object_size0 buf, size_t count, off_t offset)
        __overloadable
        __error_if_overflows_ssizet(count, pread)
        __error_if_overflows_objectsize(count, __bos0(buf), pread) {
    size_t bos = __bos0(buf);

    if (count == __BIONIC_FORTIFY_UNKNOWN_SIZE) {
        return __PREAD_PREFIX(real)(fd, buf, count, offset);
    }

    return __PREAD_PREFIX(chk)(fd, buf, count, offset, bos);
}

__BIONIC_FORTIFY_INLINE
ssize_t pread64(int fd, void* const __pass_object_size0 buf, size_t count, off64_t offset)
        __overloadable
        __error_if_overflows_ssizet(count, pread64)
        __error_if_overflows_objectsize(count, __bos0(buf), pread64) {
    size_t bos = __bos0(buf);

    if (bos == __BIONIC_FORTIFY_UNKNOWN_SIZE) {
        return __pread64_real(fd, buf, count, offset);
    }

    return __pread64_chk(fd, buf, count, offset, bos);
}
#endif /* __ANDROID_API__ >= __ANDROID_API_M__ */

#if __ANDROID_API__ >= __ANDROID_API_N__
__BIONIC_FORTIFY_INLINE
ssize_t pwrite(int fd, const void* const __pass_object_size0 buf, size_t count, off_t offset)
        __overloadable
        __error_if_overflows_ssizet(count, pwrite)
        __error_if_overflows_objectsize(count, __bos0(buf), pwrite) {
    size_t bos = __bos0(buf);

    if (bos == __BIONIC_FORTIFY_UNKNOWN_SIZE) {
        return __PWRITE_PREFIX(real)(fd, buf, count, offset);
    }

    return __PWRITE_PREFIX(chk)(fd, buf, count, offset, bos);
}

__BIONIC_FORTIFY_INLINE
ssize_t pwrite64(int fd, const void* const __pass_object_size0 buf, size_t count, off64_t offset)
        __overloadable
        __error_if_overflows_ssizet(count, pwrite64)
        __error_if_overflows_objectsize(count, __bos0(buf), pwrite64) {
    size_t bos = __bos0(buf);

    if (bos == __BIONIC_FORTIFY_UNKNOWN_SIZE) {
        return __pwrite64_real(fd, buf, count, offset);
    }

    return __pwrite64_chk(fd, buf, count, offset, bos);
}
#endif /* __ANDROID_API__ >= __ANDROID_API_N__ */

#if __ANDROID_API__ >= __ANDROID_API_L__
__BIONIC_FORTIFY_INLINE
ssize_t read(int fd, void* const __pass_object_size0 buf, size_t count)
        __overloadable
        __error_if_overflows_ssizet(count, read)
        __error_if_overflows_objectsize(count, __bos0(buf), read) {
    size_t bos = __bos0(buf);

    if (bos == __BIONIC_FORTIFY_UNKNOWN_SIZE) {
        return __call_bypassing_fortify(read)(fd, buf, count);
    }

    return __read_chk(fd, buf, count, bos);
}
#endif /* __ANDROID_API__ >= __ANDROID_API_L__ */

#if __ANDROID_API__ >= __ANDROID_API_N__
__BIONIC_FORTIFY_INLINE
ssize_t write(int fd, const void* const __pass_object_size0 buf, size_t count)
        __overloadable
        __error_if_overflows_ssizet(count, write)
        __error_if_overflows_objectsize(count, __bos0(buf), write) {
    size_t bos = __bos0(buf);

    if (bos == __BIONIC_FORTIFY_UNKNOWN_SIZE) {
        return __call_bypassing_fortify(write)(fd, buf, count);
    }

    return __write_chk(fd, buf, count, bos);
}
#endif /* __ANDROID_API__ >= __ANDROID_API_N__ */

#if __ANDROID_API__ >= __ANDROID_API_M__
__BIONIC_FORTIFY_INLINE
ssize_t readlink(const char* path, char* const __pass_object_size buf, size_t size)
        __overloadable
        __error_if_overflows_ssizet(size, readlink)
        __error_if_overflows_objectsize(size, __bos(buf), readlink) {
    size_t bos = __bos(buf);

    if (bos == __BIONIC_FORTIFY_UNKNOWN_SIZE) {
        return __call_bypassing_fortify(readlink)(path, buf, size);
    }

    return __readlink_chk(path, buf, size, bos);
}

__BIONIC_FORTIFY_INLINE
ssize_t readlinkat(int dirfd, const char* path, char* const __pass_object_size buf, size_t size)
        __overloadable
        __error_if_overflows_ssizet(size, readlinkat)
        __error_if_overflows_objectsize(size, __bos(buf), readlinkat) {
    size_t bos = __bos(buf);

    if (bos == __BIONIC_FORTIFY_UNKNOWN_SIZE) {
        return __call_bypassing_fortify(readlinkat)(dirfd, path, buf, size);
    }

    return __readlinkat_chk(dirfd, path, buf, size, bos);
}
#endif /* __ANDROID_API__ >= __ANDROID_API_M__ */

#undef __enable_if_no_overflow_ssizet
#undef __error_if_overflows_objectsize
#undef __error_if_overflows_ssizet
#undef __PREAD_PREFIX
#undef __PWRITE_PREFIX
#endif /* defined(__BIONIC_FORTIFY) */
