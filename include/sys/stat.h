/*
 * Copyright (c) 2018 Chris Jones <jonesc@macports.org>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef _MACPORTS_SYS_STAT_H_
#define _MACPORTS_SYS_STAT_H_

/* MP support header */
#include "MacportsLegacySupport.h"

/* Do our SDK-related setup */
#include <_macports_extras/sdkversion.h>

/* Include the primary system sys/stat.h */
#include_next <sys/stat.h>

#if __DARWIN_C_LEVEL >= 200809L

#if __MPLS_SDK_SUPPORT_UTIMENSAT__

#define UTIME_NOW -1
#define UTIME_OMIT -2

__MP__BEGIN_DECLS

extern int futimens(int fd, const struct timespec _times_in[2]);
extern int utimensat(int fd, const char *path,
                     const struct timespec _times_in[2], int flags);

__MP__END_DECLS

#endif /* __MPLS_SDK_SUPPORT_UTIMENSAT__ */

#if __MPLS_SDK_SUPPORT_ATCALLS__

__MP__BEGIN_DECLS

extern int fchmodat(int dirfd, const char *pathname, mode_t mode, int flags);
extern int fstatat(int dirfd, const char *pathname,
                   struct stat *buf, int flags);

/*
 * 64bit inode types appeared only on 10.5, and currently can't be replaced
 * on Tiger due to lack of kernel support for the underlying syscalls
 */
#if !__DARWIN_ONLY_64_BIT_INO_T && __MPLS_TARGET_OSVER >= 1050
struct stat64;
extern int fstatat64(int dirfd, const char *pathname,
                     struct stat64 *buf, int flags);
#endif

extern int mkdirat(int dirfd, const char *pathname, mode_t mode);

__MP__END_DECLS

#endif /* __MPLS_SDK_SUPPORT_ATCALLS__ */

#endif /* __DARWIN_C_LEVEL >= 200809L */

#if !defined(_POSIX_C_SOURCE) || defined(_DARWIN_C_SOURCE)

#if __MPLS_SDK_SUPPORT_LCHMOD__

__MP__BEGIN_DECLS

extern int lchmod(const char *, mode_t);

__MP__END_DECLS

#endif /* __MPLS_SDK_SUPPORT_LCHMOD__ */

#endif /* (!_POSIX_C_SOURCE || _DARWIN_C_SOURCE) */

#endif /* _MACPORTS_SYS_STAT_H_ */
