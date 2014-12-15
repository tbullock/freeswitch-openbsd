# Originally from Openbsd <bsd.lib.mk> and stripped to work for fs modules

.include <bsd.own.mk>				# for 'NOPIC' definition

.MAIN: all

CFLAGS += -I/usr/local/include/apr-1
# prefer .S to a .c, add .po, remove stuff not used in the BSD libraries.
# .so used for PIC object files.
# .do used for distrib "crunchgen" object files
# .m for objective c files.
.SUFFIXES:
.SUFFIXES: .out .o .go .po .so .do .S .s .c .cc .cpp .C .cxx .f .y .l .m4 .m

.if defined(NOPIE)
CFLAGS+=        ${NOPIE_FLAGS}
AFLAGS+=        ${NOPIE_FLAGS}
.endif

.c.o:
	@echo "${COMPILE.c} ${PICFLAG} -DPIC ${.IMPSRC} -o ${.TARGET}"
	@${COMPILE.c} ${PICFLAG} -DPIC ${.IMPSRC} -o ${.TARGET}.o
	@${LD} -X -r ${.TARGET}.o -o ${.TARGET}
	@rm -f ${.TARGET}.o

.cc.o .cpp.o .C.o .cxx.o:
	@echo "${COMPILE.cc} ${PICFLAG} -DPIC ${.IMPSRC} -o ${.TARGET}"
	@${COMPILE.cc} ${PICFLAG} -DPIC ${.IMPSRC} -o ${.TARGET}.o
	@${LD} -X -r ${.TARGET}.o -o ${.TARGET}
	@rm -f ${.TARGET}.o

.if ${WARNINGS:L} == "yes"
CFLAGS+=	${CDIAGFLAGS}
CXXFLAGS+=	${CXXDIAGFLAGS}
.endif
CFLAGS+=	${COPTS}
CXXFLAGS+=	${CXXOPTS}

DEBUG?=	-g

_LIBS=${LIB}.so

all: ${_LIBS}  _SUBDIRUSE

SOBJS+=	${SRCS:N*.h:R:S/$/.o/}
${LIB}.so: ${SOBJS} ${DPADD}
	@echo building module ${LIB}
	@rm -f ${LIB}.so
	${CC} -shared ${PICFLAG} \
	    -o ${LIB}.so \
	    `${LORDER} ${SOBJS}|tsort -q` ${LDADD}


.if !target(clean)
clean: _SUBDIRUSE
	rm -f a.out [Ee]rrs mklog *.core ${CLEANFILES}
	rm -f ${LIB}.so ${SOBJS}
.endif

cleandir: _SUBDIRUSE clean

.if defined(SRCS)
afterdepend: .depend
	@(TMP=`mktemp -q /tmp/_dependXXXXXXXXXX`; \
	if [ $$? -ne 0 ]; then \
		echo "$$0: cannot create temp file, exiting..."; \
		exit 1; \
	fi; \
	sed -e 's/^\([^\.]*\).o[ ]*:/\1.o \1.go \1.po \1.so \1.do:/' \
	      < .depend > $$TMP; \
	mv $$TMP .depend)
.endif

.if !target(install)
.if !target(beforeinstall)
beforeinstall:
.endif

realinstall:
	${INSTALL} ${INSTALL_COPY} -S -o ${LIBOWN} -g ${LIBGRP} -m ${LIBMODE} \
	    ${LIB}.so ${DESTDIR}${LIBDIR}

install: maninstall _SUBDIRUSE
maninstall: afterinstall
afterinstall: realinstall
realinstall: beforeinstall
.endif

.if !defined(NOMAN)
.include <bsd.man.mk>
.endif

.if !defined(NONLS)
.include <bsd.nls.mk>
.endif

.include <bsd.obj.mk>
.include <bsd.dep.mk>
.include <bsd.subdir.mk>
.include <bsd.sys.mk>
