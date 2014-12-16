LIB=	fs++
LIBDIR=	/usr/local/lib
NOPROFILE= true

CPPFLAGS +=	-DENABLE_SRTP

CFLAGS +=	-I/usr/local/include
CFLAGS +=	-I/usr/local/include/apr-1
CFLAGS +=	-I${.CURDIR}/../../include
CFLAGS +=	-Wall

CC=	c++

DEBUG= -g

# For the lua binding...
SRCS+=	switch_cpp.cpp


.include <bsd.lib.mk>
