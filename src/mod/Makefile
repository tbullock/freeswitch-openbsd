SUBDIR = endpoints loggers applications event_handlers dialplans formats \
	languages xml_int say

beforeinstall:
	${INSTALL} -d -m 755 -o $(BINOWN) -g $(LOCALEGRP) \
	  ${DESTDIR}/usr/local/lib/fs_mod

.include <bsd.subdir.mk>
