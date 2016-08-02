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

