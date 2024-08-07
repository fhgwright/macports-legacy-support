/*
 * Copyright (c) 2020 Chris Jones <jonesc@macports.org>
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

#ifndef _MACPORTS_STRINGS_H_
#define _MACPORTS_STRINGS_H_

/* MP support header */
#include "MacportsLegacySupport.h"

/* Do our SDK-related setup */
#include <_macports_extras/sdkversion.h>

/* Include the primary system strings.h */
#include_next <strings.h>

/* Darwin extensions */
#if __DARWIN_C_LEVEL >= __DARWIN_C_FULL

/* ffsl */
#if __MPLS_SDK_SUPPORT_FFSL__
__MP__BEGIN_DECLS
extern int ffsl(long int);
__MP__END_DECLS
#endif

/* ffsll */
#if __MPLS_SDK_SUPPORT_FFSLL__
__MP__BEGIN_DECLS
extern int ffsll(long long int);
__MP__END_DECLS
#endif

/* fls */
#if __MPLS_SDK_SUPPORT_FLS__
__MP__BEGIN_DECLS
extern int fls(int);
__MP__END_DECLS
#endif

/* flsl */
#if __MPLS_SDK_SUPPORT_FLSL__
__MP__BEGIN_DECLS
extern int flsl(long int);
__MP__END_DECLS
#endif

/* flsll */
#if __MPLS_SDK_SUPPORT_FLSLL__
__MP__BEGIN_DECLS
extern int flsll(long long int);
__MP__END_DECLS
#endif

#endif /* __DARWIN_C_LEVEL >= __DARWIN_C_FULL */

#endif /* _MACPORTS_STRINGS_H_ */
