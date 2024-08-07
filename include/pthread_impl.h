/*
 * Copyright (c) 2018
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

#ifndef _MACPORTS_PTHREAD_IMPL_H_
#define _MACPORTS_PTHREAD_IMPL_H_

/* Include the primary system pthread_impl.h */
#include_next <pthread_impl.h>

/* _PTHREAD_RWLOCK_SIG_init is not defined on Tiger */
#ifndef _PTHREAD_RWLOCK_SIG_init
#define _PTHREAD_RWLOCK_SIG_init    0x2DA8B3B4
#endif

#endif /* _MACPORTS_PTHREAD_IMPL_H_ */
