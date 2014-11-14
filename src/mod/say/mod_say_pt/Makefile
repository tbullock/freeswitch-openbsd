LIB=	mod_say_pt
LIBDIR=	/usr/local/lib/fs_mod
NOPROFILE= true

CFLAGS += -I../../../include

LINKS= ${LIBDIR}/lib${LIB}.so.${SHLIB_MAJOR}.${SHLIB_MINOR} ${LIBDIR}/${LIB}.so

SRCS=	mod_say_pt.c

.include <bsd.lib.mk>
