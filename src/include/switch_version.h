/* 
 * FreeSWITCH Modular Media Switching Software Library / Soft-Switch Application
 * Copyright (C) 2005/2012, Anthony Minessale II <anthm@freeswitch.org>
 *
 * Version: MPL 1.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is FreeSWITCH Modular Media Switching Software Library / Soft-Switch Application
 *
 * The Initial Developer of the Original Code is
 * Anthony Minessale II <anthm@freeswitch.org>
 * Portions created by the Initial Developer are Copyright (C)
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 * 
 * Anthony Minessale II <anthm@freeswitch.org>
 * Michael Jerris <mike@jerris.com>
 *
 * switch_version.h -- Version Number Header
 *
 */

#ifndef SWITCH_VERSION_H
#define SWITCH_VERSION_H

#ifdef __cplusplus
extern "C" {
#endif

#define SWITCH_VERSION_MAJOR			"1"
#define SWITCH_VERSION_MINOR			"2"
#define SWITCH_VERSION_MICRO			"x"
#define SWITCH_VERSION_REVISION			""
#define SWITCH_VERSION_REVISION_HUMAN		"; For OpenBSD"
#define SWITCH_VERSION_FULL			SWITCH_VERSION_MAJOR "." SWITCH_VERSION_MINOR "." SWITCH_VERSION_MICRO SWITCH_VERSION_REVISION
#define SWITCH_VERSION_FULL_HUMAN		SWITCH_VERSION_MAJOR "." SWITCH_VERSION_MINOR "." SWITCH_VERSION_MICRO " " SWITCH_VERSION_REVISION_HUMAN

#ifdef __cplusplus
}
#endif

#endif
