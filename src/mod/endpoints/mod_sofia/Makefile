LIB=	mod_sofia
LIBDIR=	/usr/local/lib/fs_mod

CFLAGS += -I. -I../../../include

CFLAGS += -Ibnf
CFLAGS += -Ifeatures
CFLAGS += -Ihttp
CFLAGS += -Iipt
CFLAGS += -Iiptsec
CFLAGS += -Imsg
CFLAGS += -Inea
CFLAGS += -Inta
CFLAGS += -Inth
CFLAGS += -Inua
CFLAGS += -Isdp
CFLAGS += -Isip
CFLAGS += -Isoa
CFLAGS += -Isresolv
CFLAGS += -Isu
CFLAGS += -Itport
CFLAGS += -Iurl

SRCS=	mod_sofia.c sofia.c sofia_glue.c sofia_presence.c sofia_reg.c \
		sip-dig.c rtp.c

# bnf
SRCS+=	bnf/bnf.c

# features
SRCS+=	features/features.c

# http
SRCS+=	http/http_tag.c http/http_parser_table.c http/http_tag_ref.c \
		http/http_parser.c http/http_header.c \
		http/http_basic.c http/http_extra.c http/http_inlined.c \
		http/http_status.c http/http_tag_class.c

# ipt
SRCS+=	ipt/base64.c ipt/token64.c

# iptsec
SRCS+=	iptsec/auth_client.c iptsec/auth_common.c iptsec/auth_digest.c \
		iptsec/auth_module.c iptsec/auth_tag.c iptsec/auth_tag_ref.c \
		iptsec/auth_plugin.c iptsec/auth_plugin_delayed.c \
		iptsec/auth_module_sip.c iptsec/iptsec_debug.c

# msg
SRCS+=	msg/msg.c msg/msg_tag.c msg/msg_inlined.c \
		msg/msg_mime.c msg/msg_mime_table.c \
		msg/msg_header_copy.c msg/msg_header_make.c \
		msg/msg_parser.c msg/msg_mclass.c msg/msg_parser_util.c \
		msg/msg_basic.c msg/msg_generic.c msg/msg_date.c msg/msg_auth.c

# nea
SRCS+=	nea/nea.c nea/nea_event.c nea/nea_server.c nea/nea_debug.c \
		nea/nea_tag.c nea/nea_tag_ref.c

# nta
SRCS+=	nta/nta.c nta/nta_check.c nta/nta_tag.c nta/nta_tag_ref.c \
		nta/sl_utils_print.c nta/sl_utils_log.c nta/sl_read_payload.c

# nth
SRCS+=	nth/nth_client.c nth/nth_server.c nth/nth_tag.c nth/nth_tag_ref.c

# nua
SRCS+=	nua/nua.c nua/nua_common.c nua/nua_stack.c \
		nua/nua_server.c nua/nua_client.c \
		nua/nua_extension.c nua/nua_dialog.c \
		nua/outbound.c nua/nua_params.c \
		nua/nua_register.c nua/nua_registrar.c \
		nua/nua_session.c nua/nua_options.c \
		nua/nua_message.c nua/nua_publish.c nua/nua_subnotref.c \
		nua/nua_notifier.c nua/nua_event_server.c \
		nua/nua_tag.c nua/nua_tag_ref.c

# sdp
SRCS+=	sdp/sdp.c sdp/sdp_parse.c sdp/sdp_print.c sdp/sdp_tag.c \
		sdp/sdp_tag_ref.c

# soa
SRCS+=	soa/soa.c soa/soa_static.c soa/soa_tag.c soa/soa_tag_ref.c

# sip
SRCS+=	sip/sip_parser.c sip/sip_header.c sip/sip_util.c sip/sip_pref_util.c \
		sip/sip_basic.c sip/sip_extra.c sip/sip_feature.c sip/sip_mime.c \
		sip/sip_security.c sip/sip_event.c sip/sip_prack.c \
		sip/sip_refer.c sip/sip_session.c \
		sip/sip_caller_prefs.c sip/sip_reason.c \
		sip/sip_status.c sip/sip_time.c \
		sip/sip_tag_class.c sip/sip_inlined.c \
		sip/sip_tag.c sip/sip_parser_table.c sip/sip_tag_ref.c

# sresolv
SRCS+=	sresolv/sres.c sresolv/sres_cache.c sresolv/sres_blocking.c \
		sresolv/sresolv.c sresolv/sres_sip.c

# su
SRCS+=	su/su.c su/su_errno.c su/su_addrinfo.c \
		su/su_alloc.c su/su_alloc_lock.c su/su_strdup.c su/su_sprintf.c \
		su/su_strlst.c su/su_vector.c \
		su/su_time.c su/su_time0.c \
		su/su_wait.c su/su_root.c su/su_timer.c \
		su/su_port.c  \
		su/su_base_port.c su/su_pthread_port.c su/su_socket_port.c \
		su/su_poll_port.c su/su_epoll_port.c su/su_select_port.c \
		su/su_kqueue_port.c su/su_devpoll_port.c \
		su/su_localinfo.c \
		su/su_os_nw.c \
		su/su_taglist.c su/su_tag.c su/su_tag_io.c \
		su/su_log.c su/su_global_log.c su/su_default_log.c \
		su/su_md5.c su/su_uniqueid.c su/su_bm.c su/smoothsort.c \
		su/su_string.c su/string0.c

# tport
SRCS+=	tport/tport.c tport/tport_logging.c tport/tport_stub_sigcomp.c \
		tport/tport_type_udp.c tport/tport_type_tcp.c \
		tport/tport_type_sctp.c tport/tport_tag.c tport/tport_tag_ref.c \
		tport/tport_tls.c tport/tport_type_tls.c tport/tport_type_connect.c

# url
SRCS+=	url/url.c url/url_tag.c url/url_tag_ref.c

.include "${.CURDIR}/../../fs.mod.mk"
