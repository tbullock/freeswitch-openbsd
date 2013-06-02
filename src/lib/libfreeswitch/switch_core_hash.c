/* 
 * FreeSWITCH Modular Media Switching Software Library / Soft-Switch Application
 * Copyright (C) 2005-2012, Anthony Minessale II <anthm@freeswitch.org>
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
 * Paul D. Tinsley <pdt at jackhammer.org>
 *
 *
 * switch_core_hash.c -- Main Core Library (hash functions)
 *
 */

/*
 * Copyright (c) 2013 Ted Bullock <tbullock@northernartifex.com>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

/*
 * Wrapper to APR hash tables, note this wrapper only supports hash
 * keys made from character strings.
 */

#include <switch.h>
#include <stdbool.h>

#include <apr_general.h>
#include <apr_hash.h>
#include <apr_strings.h>
#include <apr_errno.h>


struct switch_hash {
	apr_hash_t    *ht;
	apr_pool_t    *pool;
	bool           priv; /* private pool, handle accordingly */
};

/*
 * Initialize a hash table, note that pool will be cleared after
 * calling switch_core_hash_destroy, alternatively, a private memory
 * pool will be created and used if pool is NULL
 */
void hash_init(switch_hash_t        **hash,
               switch_memory_pool_t  *pool)
{
	struct switch_hash *h;

	h = malloc(sizeof(struct switch_hash));
	switch_assert(h);

	/* Use existing apr memory pool */
	if (pool != NULL) {
	    h->pool = pool;
	    h->priv = SWITCH_FALSE;
	} else {
	/* No pool specified, make a new private one */
	    switch_memory_pool_t *p = NULL;
	    apr_status_t s = apr_pool_create(&p, NULL);
	    switch_assert(s == APR_SUCCESS);

	    h->pool = p;
	    h->priv = SWITCH_TRUE;
	}

	h->ht = apr_hash_make(h->pool);
	switch_assert(h->ht);

	*hash = h;
}

/* This does nothing useful */
SWITCH_DECLARE(switch_status_t)
switch_core_hash_init_case(switch_hash_t        **hash,
                           switch_memory_pool_t  *pool,
                           switch_bool_t          case_sensitive)
{
	case_sensitive = case_sensitive; /* Avoid compiler warning */
	hash_init(hash, pool);

	/* Why do we even return a result since we exit on any error? */
	return SWITCH_STATUS_SUCCESS;
}

SWITCH_DECLARE(switch_status_t)
switch_core_hash_destroy(switch_hash_t **hash)
{
	struct switch_hash *h;
	switch_assert(hash);
	switch_assert(*hash);

	/* make this easier to read */
	h = *hash;
	
	/* if we have public memory pool */
	if (h->priv == SWITCH_TRUE)
	    apr_pool_destroy(h->pool);

	free(h);

	*hash = NULL;

	/* Why do we even return a result since we exit on any error? */
	return SWITCH_STATUS_SUCCESS;
}

SWITCH_DECLARE(switch_status_t)
switch_core_hash_insert(switch_hash_t *h,
                        const char    *key,
                        const void    *data)
{
	switch_assert(h);
	switch_assert(key);
	switch_assert(data);

	apr_hash_set(h->ht,
	             key,
                 APR_HASH_KEY_STRING,
                 (void *) data);

	/* Why do we even return a result since we exit on any error? */
	return SWITCH_STATUS_SUCCESS;
}

SWITCH_DECLARE(switch_status_t)
switch_core_hash_insert_locked(switch_hash_t  *h, 
                               const char     *key,
                               const void     *data,
                               switch_mutex_t *mutex)
{
	if (mutex != NULL)
	    switch_mutex_lock(mutex);

	switch_core_hash_insert(h, key, data);

	if (mutex != NULL)
	    switch_mutex_unlock(mutex);

	/* Why do we even return a result since we exit on any error? */
	return SWITCH_STATUS_SUCCESS;
}

SWITCH_DECLARE(switch_status_t)
switch_core_hash_insert_wrlock(switch_hash_t          *h,
                               const char             *key,
                               const void             *data,
                               switch_thread_rwlock_t *rwlock)
{
	if (rwlock != NULL)
	    switch_thread_rwlock_wrlock(rwlock);

	switch_core_hash_insert(h, key, data);

	if (rwlock != NULL)
	    switch_thread_rwlock_unlock(rwlock);

	/* Why do we even return a result since we exit on any error? */
	return SWITCH_STATUS_SUCCESS;
}

SWITCH_DECLARE(switch_status_t)
switch_core_hash_delete(switch_hash_t *h,
                        const char    *key)
{
	switch_assert(h);
	switch_assert(key);

	apr_hash_set(h->ht,
	             key,
                 APR_HASH_KEY_STRING,
                 NULL);

	/* Why do we even return a result since we exit on any error? */
	return SWITCH_STATUS_SUCCESS;
}

SWITCH_DECLARE(switch_status_t)
switch_core_hash_delete_locked(switch_hash_t  *h, 
                               const char     *key,
                               switch_mutex_t *mutex)
{
	if (mutex != NULL)
	    switch_mutex_lock(mutex);

	switch_core_hash_delete(h, key);

	if (mutex != NULL)
	    switch_mutex_unlock(mutex);

	/* Why do we even return a result since we exit on any error? */
	return SWITCH_STATUS_SUCCESS;
}

SWITCH_DECLARE(switch_status_t)
switch_core_hash_delete_wrlock(switch_hash_t          *h,
                               const char             *key,
                               switch_thread_rwlock_t *rwlock)
{
	if (rwlock != NULL)
	    switch_thread_rwlock_wrlock(rwlock);

	switch_core_hash_delete(h, key);

	if (rwlock != NULL)
	    switch_thread_rwlock_unlock(rwlock);

	/* Why do we even return a result since we exit on any error? */
	return SWITCH_STATUS_SUCCESS;
}

/*
 * This function is just re-adapted to apr from upstreams delete_multi
 * 
 * To be entirely straight, I have no idea what this thing is doing
 * -Ted
 * this is a huge candidate for re-implementation
 */
SWITCH_DECLARE(switch_status_t)
switch_core_hash_delete_multi(switch_hash_t                 *h,
                              switch_hash_delete_callback_t  callback,
                              void                          *data)
{
	apr_hash_index_t      *hi;
	switch_event_t        *event = NULL;
	switch_event_header_t *header = NULL;
	switch_status_t        status = SWITCH_STATUS_GENERR;

	switch_event_create_subclass(&event, SWITCH_EVENT_CLONE, NULL);
	switch_assert(event);
	
	/*
	 * iterate through the hash, call callback, if callback 
	 * returns NULL or true, put the key on the list (event)
	 * When done, iterate through the list deleting hash entries
	 */
	
	for (hi = apr_hash_first(NULL, h->ht); hi; hi = apr_hash_next(hi)) {
		const void *k;
		void *v;

		apr_hash_this(hi, &k, NULL, &v);
		if (!callback || callback(k, v, data)) {
			switch_event_add_header_string(event,
                                           SWITCH_STACK_BOTTOM,
                                           "delete",
                                           (const char *) k);
		}
	}
	
	/* now delete them */
	for (header = event->headers; header; header = header->next) {
		if (switch_core_hash_delete(h, header->value) == SWITCH_STATUS_SUCCESS) {
			status = SWITCH_STATUS_SUCCESS;
		}
	}

	switch_event_destroy(&event);
	
	return status;
}


SWITCH_DECLARE(void *)
switch_core_hash_find(switch_hash_t *h, const char *key)
{
	switch_assert(h);
	switch_assert(key);
 
	return apr_hash_get(h->ht, key, APR_HASH_KEY_STRING);
}

SWITCH_DECLARE(void *)
switch_core_hash_find_locked(switch_hash_t  *h,
                             const char     *key,
                             switch_mutex_t *mutex)
{
	void *v;

	if (mutex != NULL)
	    switch_mutex_lock(mutex);

	v = switch_core_hash_find(h, key);

	if (mutex != NULL)
	    switch_mutex_unlock(mutex);

	return v;
}

SWITCH_DECLARE(void *)
switch_core_hash_find_rdlock(switch_hash_t          *h,
                             const char             *key,
                             switch_thread_rwlock_t *rwlock)
{
	void *v;

	if (rwlock != NULL)
	    switch_thread_rwlock_rdlock(rwlock);

	v = switch_core_hash_find(h, key);

	if (rwlock != NULL)
	    switch_thread_rwlock_unlock(rwlock);

	return v;
}

SWITCH_DECLARE(switch_hash_index_t *)
switch_core_hash_first(switch_hash_t *h)
{
	switch_assert(h);

	return apr_hash_first(h->pool, h->ht);
}

SWITCH_DECLARE(switch_hash_index_t *)
switch_core_hash_next(switch_hash_index_t *hi)
{
	switch_assert(hi);

	return apr_hash_next(hi);
}

SWITCH_DECLARE(void)
switch_core_hash_this(switch_hash_index_t  *hi,
                      const void          **key,
                      switch_ssize_t       *klen,
                      void                **val)
{
	switch_assert(hi);

	apr_hash_this(hi, key, klen, val);
}

/* Deprecated */
SWITCH_DECLARE(switch_hash_index_t *)
switch_hash_first(char *deprecate_me, switch_hash_t *hash)
{
	return switch_core_hash_first(hash);
}

/* Deprecated */
SWITCH_DECLARE(switch_hash_index_t *)
switch_hash_next(switch_hash_index_t *hi)
{
	return switch_core_hash_next(hi);
}

/* Deprecated */
SWITCH_DECLARE(void)
switch_hash_this(switch_hash_index_t  *hi,
                 const void          **key,
                 switch_ssize_t       *klen,
                 void                **val)
{
	switch_core_hash_this(hi, key, klen, val);
}

/* For Emacs:
 * Local Variables:
 * mode:c
 * indent-tabs-mode:t
 * tab-width:4
 * c-basic-offset:4
 * End:
 * For VIM:
 * vim:set softtabstop=4 shiftwidth=4 tabstop=4:
 */
