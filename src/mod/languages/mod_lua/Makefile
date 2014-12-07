LIB=	mod_lua
LIBDIR=	/usr/local/lib/fs_mod

CFLAGS += -I../../../include
CFLAGS += -I/usr/local/include/lua-5.1

LDADD+=	-L/usr/local/lib -llua5.1

SRCS=	mod_lua.cpp freeswitch_lua.cpp mod_lua_wrap.cpp 

.include "${.CURDIR}/../../fs.mod.mk"
