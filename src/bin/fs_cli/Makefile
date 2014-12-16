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
