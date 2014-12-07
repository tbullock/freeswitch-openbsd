LIB=	mod_spandsp
LIBDIR=	/usr/local/lib/fs_mod

CFLAGS += -I../../../include
CFLAGS += -I/usr/local/include

LDADD+=	-L/usr/local/lib -lspandsp -ltiff

SRCS=	mod_spandsp.c mod_spandsp_codecs.c mod_spandsp_dsp.c \
	mod_spandsp_fax.c mod_spandsp_modem.c udptl.c

.include "${.CURDIR}/../../fs.mod.mk"
