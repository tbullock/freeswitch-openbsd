
/*
 * This file is part of the Sofia-SIP package
 *
 * Copyright (C) 2005 Nokia Corporation.
 *
 * Contact: Pekka Pessi <pekka.pessi@nokia.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation; either version 2.1 of
 * the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301 USA
 *
 */

/**@CFILE sip_parser_table.c
 * @brief SIP parser table
 *
 * This file is automatically generated from <sip.h> by msg_parser.awk.
 *
 * @author Pekka Pessi <Pekka.Pessi@nokia.com>.
 *
 * @date Created: Tue Oct  1 20:28:59 2002 ppessi
 */

#include "config.h"

#include <stddef.h>
#include <string.h>

/* Avoid casting sip_t to msg_pub_t and sip_header_t to msg_header_t */
#define MSG_PUB_T       struct sip_s
#define MSG_HDR_T       union sip_header_u

#include <sofia-sip/sip_parser.h>
#include <sofia-sip/sip_extra.h>
#include <sofia-sip/msg_mclass.h>



#define msg_offsetof(s, f) ((unsigned short)offsetof(s ,f))

static msg_href_t const sip_short_forms[MC_SHORT_SIZE] = 
{
  { /* a */ sip_accept_contact_class, msg_offsetof(sip_t, sip_accept_contact),
      sip_mask_pref },
  { /* b */ sip_referred_by_class, msg_offsetof(sip_t, sip_referred_by) },
  { /* c */ sip_content_type_class, msg_offsetof(sip_t, sip_content_type),
      sip_mask_ua },
  { /* d */ sip_request_disposition_class, msg_offsetof(sip_t, sip_request_disposition),
      sip_mask_pref },
  { /* e */ sip_content_encoding_class, msg_offsetof(sip_t, sip_content_encoding),
      sip_mask_ua },
  { /* f */ sip_from_class, msg_offsetof(sip_t, sip_from),
      sip_mask_request | sip_mask_response },
  { NULL },
  { NULL },
  { /* i */ sip_call_id_class, msg_offsetof(sip_t, sip_call_id),
      sip_mask_request | sip_mask_response },
  { /* j */ sip_reject_contact_class, msg_offsetof(sip_t, sip_reject_contact),
      sip_mask_pref },
  { /* k */ sip_supported_class, msg_offsetof(sip_t, sip_supported) },
  { /* l */ sip_content_length_class, msg_offsetof(sip_t, sip_content_length),
      sip_mask_request | sip_mask_response },
  { /* m */ sip_contact_class, msg_offsetof(sip_t, sip_contact),
      sip_mask_ua | sip_mask_proxy | sip_mask_registrar },
  { NULL },
  { /* o */ sip_event_class, msg_offsetof(sip_t, sip_event),
      sip_mask_events },
  { NULL },
  { NULL },
  { /* r */ sip_refer_to_class, msg_offsetof(sip_t, sip_refer_to) },
  { /* s */ sip_subject_class, msg_offsetof(sip_t, sip_subject) },
  { /* t */ sip_to_class, msg_offsetof(sip_t, sip_to),
      sip_mask_request | sip_mask_response },
  { /* u */ sip_allow_events_class, msg_offsetof(sip_t, sip_allow_events) },
  { /* v */ sip_via_class, msg_offsetof(sip_t, sip_via),
      sip_mask_request | sip_mask_response },
  { NULL },
  { /* x */ sip_session_expires_class, msg_offsetof(sip_t, sip_session_expires),
      sip_mask_timer },
  { NULL },
  { NULL }
};

/* Ordinary 65, extra 1, experimental 0 */
struct _d_sip_t {
  sip_t base;
  msg_header_t *extra[1];
};


msg_mclass_t const sip_mclass[1] = 
{{
# if defined (SIP_HCLASS)
  SIP_HCLASS,
#else
  {{ 0 }},
#endif
  SIP_VERSION_CURRENT,
  SIP_PROTOCOL_TAG,
#if defined (SIP_PARSER_FLAGS)
  SIP_PARSER_FLAGS,
#else
  0,
#endif
  sizeof (struct _d_sip_t),
  sip_extract_body,
  {{ sip_request_class, msg_offsetof(sip_t, sip_request) }},
  {{ sip_status_class, msg_offsetof(sip_t, sip_status) }},
  {{ sip_separator_class, msg_offsetof(sip_t, sip_separator) }},
  {{ sip_payload_class, msg_offsetof(sip_t, sip_payload) }},
  {{ sip_unknown_class, msg_offsetof(sip_t, sip_unknown) }},
  {{ sip_error_class, msg_offsetof(sip_t, sip_error) }},
  {{ NULL, 0 }},
  sip_short_forms, 
  127, 
  66,
  {
    { sip_in_reply_to_class, msg_offsetof(sip_t, sip_in_reply_to) },
    { sip_from_class, msg_offsetof(sip_t, sip_from),
      sip_mask_request | sip_mask_response },
    { sip_proxy_authenticate_class, msg_offsetof(sip_t, sip_proxy_authenticate) },
    { sip_refer_sub_class,
      msg_offsetof(struct _d_sip_t, extra[0]) },
    { NULL, 0 },
    { sip_content_language_class, msg_offsetof(sip_t, sip_content_language) },
    { NULL, 0 },
    { sip_accept_class, msg_offsetof(sip_t, sip_accept) },
    { sip_min_se_class, msg_offsetof(sip_t, sip_min_se),
      sip_mask_timer },
    { sip_reject_contact_class, msg_offsetof(sip_t, sip_reject_contact),
      sip_mask_pref },
    { NULL, 0 },
    { sip_to_class, msg_offsetof(sip_t, sip_to),
      sip_mask_request | sip_mask_response },
    { NULL, 0 },
    { sip_reason_class, msg_offsetof(sip_t, sip_reason) },
    { sip_rseq_class, msg_offsetof(sip_t, sip_rseq),
      sip_mask_100rel },
    { NULL, 0 },
    { sip_via_class, msg_offsetof(sip_t, sip_via),
      sip_mask_request | sip_mask_response },
    { sip_user_agent_class, msg_offsetof(sip_t, sip_user_agent) },
    { NULL, 0 },
    { sip_event_class, msg_offsetof(sip_t, sip_event),
      sip_mask_events },
    { sip_proxy_require_class, msg_offsetof(sip_t, sip_proxy_require),
      sip_mask_proxy },
    { sip_proxy_authentication_info_class, msg_offsetof(sip_t, sip_proxy_authentication_info) },
    { sip_authentication_info_class, msg_offsetof(sip_t, sip_authentication_info) },
    { sip_content_length_class, msg_offsetof(sip_t, sip_content_length),
      sip_mask_request | sip_mask_response },
    { sip_security_verify_class, msg_offsetof(sip_t, sip_security_verify) },
    { sip_mime_version_class, msg_offsetof(sip_t, sip_mime_version) },
    { sip_refer_to_class, msg_offsetof(sip_t, sip_refer_to) },
    { NULL, 0 },
    { sip_contact_class, msg_offsetof(sip_t, sip_contact),
      sip_mask_ua | sip_mask_proxy | sip_mask_registrar },
    { NULL, 0 },
    { NULL, 0 },
    { NULL, 0 },
    { NULL, 0 },
    { NULL, 0 },
    { NULL, 0 },
    { sip_proxy_authorization_class, msg_offsetof(sip_t, sip_proxy_authorization),
      sip_mask_proxy },
    { NULL, 0 },
    { NULL, 0 },
    { sip_route_class, msg_offsetof(sip_t, sip_route),
      sip_mask_proxy },
    { sip_request_disposition_class, msg_offsetof(sip_t, sip_request_disposition),
      sip_mask_pref },
    { sip_date_class, msg_offsetof(sip_t, sip_date) },
    { sip_organization_class, msg_offsetof(sip_t, sip_organization) },
    { NULL, 0 },
    { NULL, 0 },
    { sip_replaces_class, msg_offsetof(sip_t, sip_replaces) },
    { sip_content_type_class, msg_offsetof(sip_t, sip_content_type),
      sip_mask_ua },
    { NULL, 0 },
    { NULL, 0 },
    { sip_accept_language_class, msg_offsetof(sip_t, sip_accept_language) },
    { sip_call_id_class, msg_offsetof(sip_t, sip_call_id),
      sip_mask_request | sip_mask_response },
    { sip_allow_events_class, msg_offsetof(sip_t, sip_allow_events) },
    { sip_if_match_class, msg_offsetof(sip_t, sip_if_match),
      sip_mask_publish },
    { NULL, 0 },
    { sip_max_forwards_class, msg_offsetof(sip_t, sip_max_forwards),
      sip_mask_proxy },
    { NULL, 0 },
    { NULL, 0 },
    { sip_error_info_class, msg_offsetof(sip_t, sip_error_info) },
    { NULL, 0 },
    { NULL, 0 },
    { sip_timestamp_class, msg_offsetof(sip_t, sip_timestamp) },
    { sip_call_info_class, msg_offsetof(sip_t, sip_call_info) },
    { NULL, 0 },
    { NULL, 0 },
    { NULL, 0 },
    { sip_record_route_class, msg_offsetof(sip_t, sip_record_route),
      sip_mask_ua | sip_mask_proxy },
    { sip_security_client_class, msg_offsetof(sip_t, sip_security_client) },
    { sip_warning_class, msg_offsetof(sip_t, sip_warning) },
    { NULL, 0 },
    { NULL, 0 },
    { sip_allow_class, msg_offsetof(sip_t, sip_allow) },
    { NULL, 0 },
    { sip_content_encoding_class, msg_offsetof(sip_t, sip_content_encoding),
      sip_mask_ua },
    { NULL, 0 },
    { NULL, 0 },
    { NULL, 0 },
    { sip_authorization_class, msg_offsetof(sip_t, sip_authorization),
      sip_mask_registrar },
    { sip_cseq_class, msg_offsetof(sip_t, sip_cseq),
      sip_mask_request | sip_mask_response },
    { sip_content_disposition_class, msg_offsetof(sip_t, sip_content_disposition),
      sip_mask_ua },
    { NULL, 0 },
    { NULL, 0 },
    { NULL, 0 },
    { sip_server_class, msg_offsetof(sip_t, sip_server) },
    { sip_security_server_class, msg_offsetof(sip_t, sip_security_server) },
    { sip_priority_class, msg_offsetof(sip_t, sip_priority) },
    { NULL, 0 },
    { NULL, 0 },
    { NULL, 0 },
    { NULL, 0 },
    { sip_www_authenticate_class, msg_offsetof(sip_t, sip_www_authenticate) },
    { sip_etag_class, msg_offsetof(sip_t, sip_etag),
      sip_mask_publish },
    { NULL, 0 },
    { sip_rack_class, msg_offsetof(sip_t, sip_rack),
      sip_mask_100rel },
    { sip_unsupported_class, msg_offsetof(sip_t, sip_unsupported) },
    { sip_require_class, msg_offsetof(sip_t, sip_require),
      sip_mask_ua | sip_mask_registrar | sip_mask_timer },
    { NULL, 0 },
    { NULL, 0 },
    { NULL, 0 },
    { NULL, 0 },
    { NULL, 0 },
    { NULL, 0 },
    { sip_referred_by_class, msg_offsetof(sip_t, sip_referred_by) },
    { NULL, 0 },
    { NULL, 0 },
    { NULL, 0 },
    { sip_subject_class, msg_offsetof(sip_t, sip_subject) },
    { sip_expires_class, msg_offsetof(sip_t, sip_expires),
      sip_mask_registrar | sip_mask_events },
    { NULL, 0 },
    { NULL, 0 },
    { sip_service_route_class, msg_offsetof(sip_t, sip_service_route) },
    { sip_accept_contact_class, msg_offsetof(sip_t, sip_accept_contact),
      sip_mask_pref },
    { sip_session_expires_class, msg_offsetof(sip_t, sip_session_expires),
      sip_mask_timer },
    { NULL, 0 },
    { NULL, 0 },
    { NULL, 0 },
    { NULL, 0 },
    { sip_subscription_state_class, msg_offsetof(sip_t, sip_subscription_state),
      sip_mask_events },
    { sip_supported_class, msg_offsetof(sip_t, sip_supported) },
    { sip_path_class, msg_offsetof(sip_t, sip_path),
      sip_mask_registrar },
    { sip_accept_encoding_class, msg_offsetof(sip_t, sip_accept_encoding) },
    { sip_privacy_class, msg_offsetof(sip_t, sip_privacy),
      sip_mask_privacy },
    { NULL, 0 },
    { NULL, 0 },
    { NULL, 0 },
    { sip_retry_after_class, msg_offsetof(sip_t, sip_retry_after) },
    { NULL, 0 },
    { sip_min_expires_class, msg_offsetof(sip_t, sip_min_expires),
      sip_mask_registrar },
    { NULL, 0 }
  }
}};

msg_hclass_t * const sip_extensions[] = {
  sip_alert_info_class,
  sip_reply_to_class,
  sip_remote_party_id_class,
  sip_p_asserted_identity_class,
  sip_p_preferred_identity_class,
#if SU_HAVE_EXPERIMENTAL
  sip_suppress_body_if_match_class,
  sip_suppress_notify_if_match_class,
#endif
  NULL
};

