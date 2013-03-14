/*
 * Copyright (c) 2013 Ted Bullock <tbullock@northernartifex.com>
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

#ifndef SWITCH_AM_CONFIG_H
#define SWITCH_AM_CONFIG_H

/*
 * Please note this is handwritten
 * stdint.h is a c99 file, so I suppose its not available
 * everywhere (at the time of writing its 2013... wtf)
 */
#include <stdint.h>
#include <sys/types.h>

#define SWITCH_INT_16  int16_t
#define SWITCH_INT_32  int32_t
#define SWITCH_INT_64  int64_t
#define SWITCH_SIZE_T  size_t
#define SWITCH_SSIZE_T ssize_t

#define SWITCH_SIZEOF_VOIDP sizeof(void*)
/*
 * Ok, a note on implementation (should probably go elsewhere)
 * Upstream freeswitch handles the problem of cross platform porting
 * by creating distribution bundles of 'known good' library versions.
 *
 * This is fine from a stability point of view (dependencies don't 
 * change underneath them), but causes major problems for distributors
 * which have taken a substantial amount of time to make the various
 * library dependencies actually work properly on their platforms
 * (http://marc.info/?l=openbsd-ports&m=132247710226325&w=2)
 *
 * Upstream Freeswitch in its current form, although stable is not
 * packagable.
 *
 * Point here is that the following line will probably be changed
 */
#define SWITCH_PREFIX_DIR "/usr/local"

/*
 * From> man 3 printf on OpenBSD
 * Note: the t modifier, when applied to an o, u, x, or X conversion,
 * indicates that the argument is of an unsigned type equivalent in size
 * to a ptrdiff_t.  The z modifier, when applied to a d or i conversion,
 * indicates that the argument is of a signed type equivalent in size to
 * a size_t.  Similarly, when applied to an n conversion, it indicates
 * that the argument is a pointer to a signed type equivalent in size to
 * a size_t.
 */
#define SWITCH_SSIZE_T_FMT "zd"
#define SWITCH_SIZE_T_FMT "tu"
#define SWITCH_INT64_T_FMT "lld"
#define SWITCH_UINT64_T_FMT "llu"

#endif
