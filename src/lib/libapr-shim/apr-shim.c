/*
 * Copyright 2010 Mathieu Rene <mrene@avgs.ca>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/* Copyright 2000-2005 The Apache Software Foundation or its licensors, as
 * applicable.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
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

#include <apr.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <apu.h>
#include <apr_portable.h>
#include <apr_thread_mutex.h>
#include <apr_thread_cond.h>
#include <apr_errno.h>
#include <apr_queue.h>

struct apr_queue_t {
    void **data;
    unsigned int nelts; /**< # elements */
    unsigned int in; /**< next empty location */
    unsigned int out; /**< next filled location */
    unsigned int bounds;/**< max size of queue */
    unsigned int full_waiters;
    unsigned int empty_waiters;
    apr_thread_mutex_t *one_big_mutex;
    apr_thread_cond_t *not_empty;
    apr_thread_cond_t *not_full;
    int terminated;
};

#ifdef QUEUE_DEBUG
static void Q_DBG(char*msg, apr_queue_t *q) {
    fprintf(stderr, "%ld\t#%d in %d out %d\t%s\n",
                    apr_os_thread_current(),
                    q->nelts, q->in, q->out,
                    msg
                    );
}
#else
#define Q_DBG(x,y)
#endif

/**
* Detects when the apr_queue_t is full. This utility function is expected
* to be called from within critical sections, and is not threadsafe.
*/
#define apr_queue_full(queue) ((queue)->nelts == (queue)->bounds)

/**
* Detects when the apr_queue_t is empty. This utility function is expected
* to be called from within critical sections, and is not threadsafe.
*/
#define apr_queue_empty(queue) ((queue)->nelts == 0)

/**
* Retrieves the next item from the queue. If there are no
* items available, it will block until one becomes available, or
* until timeout is elapsed. Once retrieved, the item is placed into
* the address specified by'data'.
*/
APU_DECLARE(apr_status_t) apr_queue_pop_timeout(apr_queue_t *queue, void **data, apr_interval_time_t timeout)
{
    apr_status_t rv;

    if (queue->terminated) {
        return APR_EOF; /* no more elements ever again */
    }

    rv = apr_thread_mutex_lock(queue->one_big_mutex);
    if (rv != APR_SUCCESS) {
        return rv;
    }

    /* Keep waiting until we wake up and find that the queue is not empty. */
    if (apr_queue_empty(queue)) {
        if (!queue->terminated) {
            queue->empty_waiters++;
            rv = apr_thread_cond_timedwait(queue->not_empty, queue->one_big_mutex, timeout);
            queue->empty_waiters--;
/* In the event of a timemout, APR_TIMEUP will be returned */
            if (rv != APR_SUCCESS) {
                apr_thread_mutex_unlock(queue->one_big_mutex);
                return rv;
            }
        }
        /* If we wake up and it's still empty, then we were interrupted */
        if (apr_queue_empty(queue)) {
            Q_DBG("queue empty (intr)", queue);
            rv = apr_thread_mutex_unlock(queue->one_big_mutex);
            if (rv != APR_SUCCESS) {
                return rv;
            }
            if (queue->terminated) {
                return APR_EOF; /* no more elements ever again */
            }
            else {
                return APR_EINTR;
            }
        }
    }

    *data = queue->data[queue->out];
    queue->nelts--;

    queue->out = (queue->out + 1) % queue->bounds;
    if (queue->full_waiters) {
        Q_DBG("signal !full", queue);
        rv = apr_thread_cond_signal(queue->not_full);
        if (rv != APR_SUCCESS) {
            apr_thread_mutex_unlock(queue->one_big_mutex);
            return rv;
        }
    }

    rv = apr_thread_mutex_unlock(queue->one_big_mutex);
    return rv;
}
