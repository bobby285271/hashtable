// hash_table.h

// A key-value pair.
typedef struct
{
    char *key;
    char *value;
} ht_item;

// The hash table.
typedef struct
{
    int size;
    int count;
    ht_item **items;
} ht_hash_table;
