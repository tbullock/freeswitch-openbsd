LIB=	mod_sndfile
LIBDIR=	/usr/local/lib/fs_mod

CFLAGS += -I/usr/local/include
CFLAGS += -I../../../include

LDADD += -L/usr/local/lib -lsndfile

SRCS=	mod_sndfile.c

.include "${.CURDIR}/../../fs.mod.mk"
