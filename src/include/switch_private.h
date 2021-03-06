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


#ifndef SWITCH_PRIVATE_H
#define SWITCH_PRIVATE_H

/* Please note this is a handwritten configuration file for OpenBSD
 * 
 * If you take a look at the autogenerated version, there are a million
 * settings in it, but when I search through the source files for the
 * pre-processor symbols, very few are actually used.
 *
 * The symbols below are actually being referenced somewhere in the FS 
 * source tree.
 */

/* Used in switch_time.c */
#define HAVE_CLOCK_GETRES
#define HAVE_CLOCK_GETTIME
#define SWITCH_USE_CLOCK_FUNCS

/* Used in switch_core.c */
#define HAVE_GETDTABLESIZE

/* Used in switch_util.c */
#define HAVE_GETIFADDRS

/* Used in switch_core.c */
#define HAVE_INITGROUPS

/* Used in switch_core_pvt.h */
#define HAVE_MLOCKALL

/* Used in switch_core_pvt.h */
#define HAVE_NETDB_H

/* Used in some modules */
#define HAVE_OPENPTY

/* Used in switch_ssl.h */
#define HAVE_OPENSSL

/* OpenBSD introduced this in 5.3, undefine for now */
#undef HAVE_POSIX_OPENPT

/*
 * Ok OpenBSD does not yet implement some sched.h functionality.
 * The implications of this are: TODO
 */
 
 /* This is probably useless */
#define HAVE_SCHED_FIFO
#define HAVE_SCHED_RR

/* Unused get rid of this I think */
#undef HAVE_SCHED_GETAFFINITY
#undef HAVE_SCHED_SETAFFINITY

/* Yes we have sched.h but FS doesn't check this */
#define HAVE_SCHED_H

/* Listed as TODO in sched.h, so lets undefine for now */
#undef HAVE_SCHED_SETSCHEDULER
#undef USE_SCHED_SETSCHEDULER

/* Used in switch_core.c */
#define HAVE_SETGROUPS

/* Used in switch_core.c */
#define HAVE_SETPRIORITY

/* Used in switch_core.c - Disabling for now...*/
#undef HAVE_SETRLIMIT

/* Used in switch_utils.c */
#define HAVE_STRERROR_R

/* OpenBSD strerror_r returns int (see man 3 strerror_r)  */
#undef STRERROR_R_CHAR_P

/* Used in switch_time.c */
#define HAVE_STRUCT_TM_TM_GMTOFF
#undef HAVE_STRUCT_TM_TM_ZONE

/* Used in switch_core.c */
#define HAVE_SYS_IOCTL_H

/* Used in switch_core_pvt.h */
#define HAVE_SYS_RESOURCE_H

/* Used in inet_pton.c <-- TODO Confirm if we need this  */
#define HAVE_SYS_TYPES_H

/* OpenBSD does not have the `timerfd_create' function */
#undef HAVE_TIMERFD_CREATE

/* Used in various places */
#define HAVE_VASPRINTF

/*
 * PostgeSQL
 * TODO
 */
//#define SWITCH_HAVE_PGSQL
//#define POSTGRESQL_MAJOR_VERSION ??
//#define POSTGRESQL_MINOR_VERSION ??
//#define POSTGRESQL_PATCH_VERSION ??
//#define POSTGRESQL_VERSION ??

/* Little Endian */
/* Endianness */
#include <sys/endian.h>
#define SWITCH_BYTE_ORDER _BYTE_ORDER

/* Put data and config in good places */
#define SWITCH_CONF_DIR "/etc/freeswitch"
#define SWITCH_DB_DIR "/var/freeswitch/db"
#define SWITCH_GRAMMAR_DIR "/usr/local/share/freeswitch/grammar"
#define SWITCH_HTDOCS_DIR "/var/freeswitch/htdocs"
#define SWITCH_LIB_DIR "/var/freeswitch/lib"
#define SWITCH_LOG_DIR "/var/freeswitch/log"
#define SWITCH_MOD_DIR "/usr/local/lib/fs_mod"
#define SWITCH_PREFIX_DIR "/var/freeswitch"
#define SWITCH_RECORDINGS_DIR "/var/freeswitch/recordings"
#define SWITCH_RUN_DIR "/var/freeswitch/run"
#define SWITCH_SCRIPT_DIR "/usr/local/share/freeswitch/scripts"
#define SWITCH_SOUNDS_DIR "/usr/local/share/freeswitch/sounds"
#define SWITCH_STORAGE_DIR "/var/freeswitch/storage"
#define SWITCH_TEMP_DIR "/tmp"


#endif
