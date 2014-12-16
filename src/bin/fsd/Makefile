PROG=	fsd
BINDIR=	/usr/local/sbin
MANDIR=	/usr/local/man/man

MAN=	fsd.1

CFLAGS +=	-I/usr/local/include
CFLAGS +=	-I/usr/local/include/apr-1
CFLAGS +=	-I/usr/local/include/srtp
CFLAGS +=	-I${.CURDIR}/../../include

SRCS=	switch.c

DEBUG= -g

LDFLAGS +=	-L/usr/local/lib
LDADD +=	-lutil -lssl -lcrypto -lm -lz -lsqlite3 -lpthread
DPADD +=	${LIBUTIL} ${LIBSSL} ${LIBCRYPTO} ${LIBM} ${LIBZ} \
		${LIBSQLITE3} ${LIBPTHREAD}

LDFLAGS += 	-L../../lib/libfreeswitch -L../../lib/libapr-shim \
		-L../../lib/libfreeswitch++
LDADD +=	-lfs
LDADD +=	-lfs++
LDADD +=	-lfs_apr-shim

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
