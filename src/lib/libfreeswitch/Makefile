# Copyright (c) 2013 Ted Bullock <tbullock@northernartifex.com>
#
# Permission to use, copy, modify, and distribute this software for any
# purpose with or without fee is hereby granted, provided that the above
# copyright notice and this permission notice appear in all copies.
#
# THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
# WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
# MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
# ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
# WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
# ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
# OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.


LIB=	fs
LIBDIR=	/usr/local/lib
NOPROFILE= true

CPPFLAGS +=	-DENABLE_SRTP

CFLAGS +=	-I/usr/local/include
CFLAGS +=	-I/usr/local/include/apr-1
CFLAGS +=	-I/usr/local/include/srtp
CFLAGS +=	-I${.CURDIR}/../../include
CFLAGS +=	-Wall

DEBUG= -g

HDRS=	libteletone.h libteletone_detect.h libteletone_generate.h \
		stfu.h switch.h switch_am_config.h switch_apr.h \
		switch_buffer.h switch_caller.h switch_channel.h \
		switch_config.h switch_console.h switch_core.h \
		switch_core_db.h switch_core_event_hook.h switch_cpp.h \
		switch_dso.h switch_event.h switch_frame.h \
		switch_ivr.h switch_json.h switch_limit.h \
		switch_loadable_module.h switch_log.h \
		switch_module_interfaces.h switch_mprintf.h \
		switch_nat.h switch_odbc.h switch_pgsql.h \
		switch_platform.h switch_regex.h switch_resample.h \
		switch_rtcp_frame.h switch_rtp.h switch_scheduler.h \
		switch_stun.h switch_types.h switch_utils.h \
		switch_xml.h switch_xml_config.h tpl.h

SRCS=	g711.c switch_apr.c switch_buffer.c switch_caller.c \
		switch_channel.c switch_config.c switch_console.c \
		switch_core.c switch_core_asr.c switch_core_codec.c \
		switch_core_db.c switch_core_directory.c \
		switch_core_event_hook.c switch_core_file.c \
		switch_core_hash.c switch_core_io.c \
		switch_core_media_bug.c switch_core_memory.c \
		switch_core_port_allocator.c switch_core_rwlock.c \
		switch_core_session.c switch_core_speech.c \
		switch_core_sqldb.c switch_core_state_machine.c \
		switch_core_timer.c switch_curl.c switch_dso.c \
		switch_event.c switch_ivr.c switch_ivr_async.c \
		switch_ivr_bridge.c switch_ivr_menu.c \
		switch_ivr_originate.c switch_ivr_play_say.c \
		switch_ivr_say.c switch_json.c \
		switch_limit.c switch_loadable_module.c \
		switch_log.c switch_mprintf.c switch_nat.c \
		switch_odbc.c switch_pcm.c switch_pgsql.c \
		switch_profile.c switch_regex.c switch_resample.c \
		switch_rtp.c switch_scheduler.c switch_stun.c \
		switch_time.c switch_utils.c switch_xml.c \
		switch_xml_config.c

# Specialty libraries
SRCS+=	stfu.c
SRCS+=	libteletone_detect.c libteletone_generate.c
SRCS+=	tpl.c

.include <bsd.lib.mk>
