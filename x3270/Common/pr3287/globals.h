/*
 * Copyright (c) 2000-2009, 2013, 2015 Paul Mattes.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the names of Paul Mattes nor the names of his contributors
 *       may be used to endorse or promote products derived from this software
 *       without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY PAUL MATTES "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 * EVENT SHALL PAUL MATTES BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/* Autoconf settings. */
#include "conf.h"			/* autoconf settings */
#if defined(HAVE_VASPRINTF) && !defined(_GNU_SOURCE) /*[*/
#define _GNU_SOURCE			/* vasprintf isn't POSIX */
#endif /*]*/

#include <stdio.h>			/* Unix standard I/O library */
#include <stdlib.h>			/* Other Unix library functions */
#if !defined(_MSC_VER) /*[*/
# include <unistd.h>			/* Unix system calls */
#endif /*]*/
#include <ctype.h>			/* Character classes */
#include <string.h>			/* String manipulations */
#include <sys/types.h>			/* Basic system data types */
#if !defined(_MSC_VER) /*[*/
# include <sys/time.h>			/* System time-related data types */
#endif /*]*/
#include <time.h>			/* C library time functions */
#include <stdarg.h>			/* Varargs */
#if defined(_WIN32) /*[*/
# include "wincmn.h"			/* Common Windows definitions. */
#endif /*]*/

#include "localdefs.h"

#if defined(__STDC_ISO_10646__) && !defined(USE_ICONV) /*[*/
#define UNICODE_WCHAR   1
#endif /*]*/
#if !defined(_WIN32) && !defined(UNICODE_WCHAR) /*[*/
#undef USE_ICONV
#define USE_ICONV 1
#include <iconv.h>
#endif /*]*/

extern unsigned long cgcsgid;
extern unsigned long cgcsgid_dbcs;
extern int dbcs;

#define Replace(var, value) { Free(var); var = (value); }

typedef unsigned int ucs4_t;
typedef unsigned short ebc_t;

#define CS_MASK		0x03	/* mask for specific character sets */
#define CS_BASE		0x00	/*  base character set (X'00') */
#define CS_APL		0x01	/*  APL character set (X'01' or GE) */
#define CS_LINEDRAW	0x02	/*  DEC line-drawing character set (ANSI) */
#define CS_DBCS		0x03	/*  DBCS character set (X'F8') */
#define CS_GE		0x04	/* cs flag for Graphic Escape */

extern const char *app;
extern const char *build;
extern const char *cyear;

/*
 *  * Compiler-specific #defines.
 *   */

/* '_is_unused' explicitly flags an unused parameter */
#if defined(__GNUC__) /*[*/
# define _is_unused __attribute__((__unused__))
# define printflike(s,f) __attribute__ ((__format__ (__printf__, s, f)))
#else /*][*/
# define _is_unused /* nothing */
# define printflike(s, f) /* nothing */
#endif /*]*/
#if 'A' > 'a' /*[*/
# define EBCDIC_HOST 1
#endif /*]*/

/* Handy stuff. */
#define array_count(a)	sizeof(a)/sizeof(a[0])

/* Doubly-linked lists. */
typedef struct llist {
    struct llist *next;
    struct llist *prev;
} llist_t;

/* Memory allocation. */
void *Malloc(size_t);
void Free(void *);
void *Calloc(size_t, size_t);
void *Realloc(void *, size_t);
char *NewString(const char *);

/* Error exits. */
void Error(const char *);
void Warning(const char *);

/* Typedefs cribbed from X11. */
#if !defined(X3270_DISPLAY) /*[*/
typedef char Boolean;
# define False 0
# define True 1
#endif /*]*/

typedef unsigned long ks_t;
#define KS_NONE 0L

/* Common socket definitions. */
#if !defined(_WIN32) /*[*/
typedef int socket_t;
# define INVALID_SOCKET  (-1)
# define INET_ADDR_T    in_addr_t
# define SOCK_CLOSE(s)  close(s)
# define socket_errno() errno
# define SE_EWOULDBLOCK EWOULDBLOCK
#else /*][*/
typedef SOCKET socket_t;
# define INET_ADDR_T    unsigned long
# define SOCK_CLOSE(s)  closesocket(s)
# define socket_errno() WSAGetLastError()
# define SE_EWOULDBLOCK WSAEWOULDBLOCK
#endif /*]*/
