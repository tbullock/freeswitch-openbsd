# Copyright (c) 2013 Ted Bullock <tbullock@northernartifex.com>
#
# Permission to use, copy, modify, and distribute this software for any
# purpose with or without fee is hereby granted, provided that the above
# copyright notice and this permission notice appear in all copies.
#
# THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
# WITH REGARD TO THIS SOFTWARE INCLUDING ALL LIBEVENTIMPLIED WARRANTIES OF
# MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
# ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
# WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
# ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
# OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.

PROG=	fsd
BINDIR=	/usr/local/bin
MANDIR=	/usr/local/man/man

MAN=	fsd.1

CFLAGS +=	-I/usr/local/include
CFLAGS +=	-I/usr/local/include/apr-1
CFLAGS +=	-I/usr/local/include/srtp
CFLAGS +=	-I${.CURDIR}/../../include

SRCS=	switch.c

LDFLAGS +=	-L/usr/local/lib
LDADD +=	-lutil -lssl -lcrypto -lm -lz -lsqlite3 -lpthread
DPADD +=	${LIBUTIL} ${LIBSSL} ${LIBCRYPTO} ${LIBM} ${LIBZ} \
		${LIBSQLITE3} ${LIBPTHREAD}

LDADD +=	../../lib/libfreeswitch/libfreeswitch.a
LDADD +=	../../lib/libapr-shim/libapr-shim.a

# Rest are from ports
LDADD +=	-laprutil-1
LDADD +=	-lapr-1
LDADD +=	-lcurl
LDADD +=	-lidn
LDADD +=	-lpcre
LDADD +=	-lsrtp	
LDADD +=	-lspeex
LDADD +=	-lspeexdsp
LDADD +=	-liconv
LDADD +=	-lintl
LDADD +=	-lnatpmp
LDADD +=	-lminiupnpc
LDADD +=	-lspandsp



.include <bsd.prog.mk>
