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

#include "../hopscotch.h"
#include <stdio.h>

/* Macro for testing */
#define TEST_FUNC(str, func, ret)                \
    do {                                         \
        printf("%s: ", str);                     \
        if ( 0 == func() ) {                     \
            printf("passed");                    \
        } else {                                 \
            printf("failed");                    \
            ret = -1;                            \
        }                                        \
        printf("\n");                            \
    } while ( 0 )

#define TEST_PROGRESS()                              \
    do {                                             \
        printf(".");                                 \
        fflush(stdout);                              \
    } while ( 0 )

/*
 * Initialization test
 */
static int
test_init(void)
{
    struct hopscotch_hash_table *ht;

    /* Initialize */
    ht = hopscotch_init(NULL, 8);
    if ( NULL == ht ) {
        return -1;
    }

    TEST_PROGRESS();

    /* Release */
    hopscotch_release(ht);

    return 0;
}

/*
 * Lookup test
 */
static int
test_lookup(void)
{
    struct hopscotch_hash_table *ht;
    uint8_t key0[] = {0x01, 0x23, 0x45, 0x67, 0x89, 0x01, 0x23, 0x45};
    uint8_t key1[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
    int ret;
    void *val;

    /* Initialize */
    ht = hopscotch_init(NULL, 8);
    if ( NULL == ht ) {
        return -1;
    }

    /* No entry */
    val = hopscotch_lookup(ht, key0);
    if ( NULL != val ) {
        /* Failed */
        return -1;
    }

    TEST_PROGRESS();

    /* Insert */
    ret = hopscotch_insert(ht, key1, key1);
    if ( ret < 0 ) {
        /* Failed to insert */
        return -1;
    }

    /* Lookup */
    val = hopscotch_lookup(ht, key1);
    if ( val != key1 ) {
        /* Failed */
        return -1;
    }

    /* Lookup */
    val = hopscotch_remove(ht, key1);
    if ( val != key1 ) {
        /* Failed */
        return -1;
    }

    /* Lookup */
    val = hopscotch_lookup(ht, key1);
    if ( NULL != val ) {
        /* Failed */
        return -1;
    }

    /* Release */
    hopscotch_release(ht);

    return 0;
}

/*
 * Main routine for the basic test
 */
int
main(int argc, const char *const argv[])
{
    int ret;

    /* Reset */
    ret = 0;

    /* Run tests */
    TEST_FUNC("init", test_init, ret);
    TEST_FUNC("lookup", test_lookup, ret);

    return 0;
}


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=4 fdm=marker
 * vim<600: sw=4 ts=4
 */
