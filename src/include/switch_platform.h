/*
 * Copyright (c) 2014 Ted Bullock <tbullock@northernaritfex.com>
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

/* Hand written switch_platform.h specifically for OpenBSD */

#ifndef SWITCH_PLATFORM_H
#define SWITCH_PLATFORM_H

#include <arpa/inet.h> /* for inet_ntoa, since.... reasons */

#ifdef __cplusplus
extern "C"
{
#endif

#define SWITCH_VA_NONE "%s",""

/* XXX: change this in the tree to __func__ */
#define __SWITCH_FUNC__ __func__

/* XXX: probably work to delete all of these */
#define SWITCH_DECLARE(x) x
#define SWITCH_DECLARE_NONSTD(x) x
#define SWITCH_DECLARE_DATA
#define SWITCH_DECLARE_CLASS
#define SWITCH_DECLARE_CONSTRUCTOR
#define SWITCH_MOD_DECLARE(x) x
#define SWITCH_MOD_DECLARE_NONSTD(x) x
#define SWITCH_MOD_DECLARE_DATA

/* XXX: delete this after nuking all the stubs from switch_apr.* */
#define SWITCH_THREAD_FUNC

/* time_t is 64bit on all OpenBSD platforms */
#define TIME_T_FMT "%lld"
#define SWITCH_TIME_T_FMT "lld" /* so stupid */

/* definitely nuke all this stuff after moving to intrinsic types */
typedef size_t switch_size_t;
typedef ssize_t switch_ssize_t;
typedef int32_t switch_int32_t;

/* XXX: excise this */
#define O_BINARY 0

/* this a gcc extension, I don't really like extensions */
#define PRINTF_FUNCTION(fmtstr,vars) __attribute__((format(printf,fmtstr,vars)))

/* XXX: these are hold overs from windows compat stuff, nukem */
#define _In_
#define _In_z_
#define _In_opt_z_
#define _In_opt_
#define _Printf_format_string_
#define _Ret_opt_z_
#define _Ret_z_
#define _Out_opt_
#define _Out_
#define _Check_return_
#define _Inout_
#define _Inout_opt_
#define _In_bytecount_(x)
#define _Out_opt_bytecapcount_(x)
#define _Out_bytecapcount_(x)
#define _Ret_
#define _Post_z_
#define _Out_cap_(x)
#define _Out_z_cap_(x)
#define _Out_ptrdiff_cap_(x)
#define _Out_opt_ptrdiff_cap_(x)
#define _Post_count_(x)

/* XXX: change all instances of switch_assert to -> assert ... duh */
#define switch_assert(expr) assert(expr)

#ifdef __cplusplus
}
#endif

#endif
