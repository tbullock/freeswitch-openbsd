LIB=	mod_hash
LIBDIR=	/usr/local/lib/fs_mod

CFLAGS += -I../../../include
CFLAGS += -I../mod_esl
CFLAGS += -I../../../lib/libesl/include

LDADD+=		-L../../../lib/libesl -lesl

SRCS=	mod_hash.c 

.include "${.CURDIR}/../../fs.mod.mk"
