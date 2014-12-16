LIB=	esl
LIBDIR=	/usr/local/lib
NOPROFILE= true

CFLAGS+=	-Iinclude

SRCS=	esl.c esl_buffer.c esl_config.c esl_event.c esl_json.c \
	esl_threadmutex.c

# No C++ swig bindings (for now)
#SRCS+=	esl_oop.cpp

.include <bsd.lib.mk>
