# Hopscotch Hashing

## About
An implementation of Hopscotch hashing [1].

[1] M. Herlihy, N. Shavit, and M. Tzafrir, "Hopscotch hashing", in Proceedings of the 22nd International Symposium on Distributed Computing, 2008

## APIs

### Initialization

    NAME
         hopscotch_init -- initialize a hash table
         
    SYNOPSIS
         struct hopscotch_hash_table *
         hopscotch_init(struct hopscotch_hash_table *ht, size_t keylen);
         
    DESCRIPTION
         The hopscotch_init() function initializes a hash table specified by the
         ht argument with the key length parameter, keylen.
         
         If the ht argument is NULL, a new data structure is allocated and
         initialized.  Otherwise, the data structure specified by the ht
         argument is initialized.
         
         The keylen parameter specifies the fixed length of keys for this hash
         table in bytes.

    RETURN VALUES
         Upon successful completion, the hopscotch_init() function returns the
         pointer to the initialized hash table data structure.  Otherwise, it
         returns a NULL value and set errno.  If a non-NULL ht argument is
         specified, the returned value shall be the original value of the
         ht argument if successful, or a NULL value otherwise.


### Release

    NAME
         hopscotch_release -- release the hash table
         
    SYNOPSIS
         void
         hopscotch_release(struct hopscotch_hash_table *ht);
         
    DESCRIPTION
         The hopscotch_release() function releases the hash table data structure
         specified by the ht argument.

    RETURN VALUES
         The hopscotch_release() function does not return a value.


### Operations

    NAME
        hopscotch_insert, hopscotch_lookup, hopscotch_remove, hopscotch_resize
        -- operate the hash table
         
    SYNOPSIS
         int
         hopscotch_insert(struct hopscotch_hash_table *ht, uint8_t *key,
	 void *data);
         
         void *
         hopscotch_lookup(struct hopscotch_hash_table *ht, uint8_t *key);
         
         void *
         hopscotch_remove(struct hopscotch_hash_table *ht, uint8_t *key);
         
         int
         hopscotch_resize(struct hopscotch_hash_table *ht, int delta);
         
    DESCRIPTION
         The hopscotch_insert(), and hopscotch_remove() functions insert, and
         remove data specified by the data argument corresponding to the key
	 specified by the key argument.
         
         The hopscotch_resize() function increases the hash table by 2^delta times.
         
         The hopscotch_lookup() function looks up the hash table by the specified
         argument of key.
         
    RETURN VALUES
         On successful, the hopscotch_insert() function returns a value of 0.
         Otherwise, they return a value of -1.
         
         The hopscotch_lookup() and hopscotch_remove() functions return data
         corresponding to the key argument.  If no matching entry is found,
	 a NULL value is returned.
