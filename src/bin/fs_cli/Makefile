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

PROG=	fs_cli
BINDIR=	/usr/local/bin
MANDIR=	/usr/local/man/man

NOMAN=	noman

CFLAGS +=	-I../../lib/libesl/include
CFLAGS +=	-DHAVE_EDITLINE

SRCS=	fs_cli.c

DEBUG= -g

LDADD +=	-ledit -lpthread -lncurses -lm -lesl
DPADD +=	${LIBEDIT} ${LIBPTHREAD} ${LIBNCURSES} ${LIBM}

LDFLAGS += 	-L../../lib/libesl




.include <bsd.prog.mk>
