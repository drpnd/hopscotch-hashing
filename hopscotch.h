/*_
 * Copyright (c) 2016 Hirochika Asai <asai@jar.jp>
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef _HOPSCOTCH_H
#define _HOPSCOTCH_H

#include <stdint.h>
#include <stdlib.h>

#define HOPSCOTCH_INIT_BSIZE_FACTOR     10
#define HOPSCOTCH_HOPINFO_SIZE          32

struct hopscotch_bucket {
    void *key;
    void *data;
    uint32_t hopinfo;
    uint32_t rsvd;
};
struct hopscotch_hash_table {
    size_t pfactor;
    size_t keylen;
    struct hopscotch_bucket *buckets;
    int _allocated;
};

#ifdef __cplusplus
extern "C" {
#endif

    /* in hopscotch.c */
    struct hopscotch_hash_table *
    hopscotch_init(struct hopscotch_hash_table *, size_t);
    void hopscotch_release(struct hopscotch_hash_table *);
    void * hopscotch_lookup(struct hopscotch_hash_table *, void *);
    int hopscotch_insert(struct hopscotch_hash_table *, void *, void *);
    void * hopscotch_remove(struct hopscotch_hash_table *, void *);
    int hopscotch_resize(struct hopscotch_hash_table *, int);

#ifdef __cplusplus
}
#endif


#endif /* _KERNEL_H */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=4 fdm=marker
 * vim<600: sw=4 ts=4
 */
