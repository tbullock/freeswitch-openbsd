LIB=	mod_xml_curl
LIBDIR=	/usr/local/lib/fs_mod
NOPROFILE= true

CFLAGS += -I../../../include
CFLAGS += -I/usr/local/include
LDADD += -L/usr/local/lib/ -lcurl

LINKS= ${LIBDIR}/lib${LIB}.so.${SHLIB_MAJOR}.${SHLIB_MINOR} ${LIBDIR}/${LIB}.so

SRCS=	mod_xml_curl.c

.include <bsd.lib.mk>
