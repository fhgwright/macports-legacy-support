/*
 * Version of test_darwin_c with __DARWIN_C_LEVEL set to 199309L-1.
 */

/* Set __DARWIN_C_LEVEL indirectly (can't be set directly) */
#define _POSIX_C_SOURCE (199309L-1)

#include "test_darwin_c.c"
