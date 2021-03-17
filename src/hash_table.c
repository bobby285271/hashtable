// hash_table.c

#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "hash_table.h"

// initialisation function for ht_item
// static: only ever be called by code internal to the hash table
static ht_item *ht_new_item(const char *k, const char *v)
{
    ht_item *i = malloc(sizeof(ht_item));
    i->key = strdup(k);
    i->value = strdup(v);
    return i;
}

// initialisation function for ht_hash_table
ht_hash_table *ht_new()
{
    ht_hash_table *ht = malloc(sizeof(ht_hash_table));
    ht->size = 53; // TODO: resizing
    ht->count = 0;
    ht->items = calloc((size_t)ht->size, sizeof(ht_item *));
    return ht;
}

// function for deleting ht_item
static void ht_del_item(ht_item *i)
{
    free(i->key);
    free(i->value);
    free(i);
}

// function for deleting ht_hash_table
void ht_del_hash_table(ht_hash_table *ht)
{
    for (int i = 0; i < ht->size; i++)
    {
        ht_item *item = ht->items[i];
        if (item != NULL)
        {
            ht_del_item(item);
        }
    }
    free(ht->items);
    free(ht);
}

// a generic string hashing function
// 1. converts the string to a large integer
// 2. reduces the size of the integer to a fixed range by taking its remainder mod m
static int ht_hash(const char *s, const int a, const int m)
{
    long hash = 0;
    const int len_s = strlen(s);
    for (int i = 0; i < len_s; i++)
    {
        hash += (long)pow(a, len_s - (i + 1)) * s[i];
        hash = hash % m;
    }
    return (int)hash;
}

int main()
{
    ht_hash_table *ht = ht_new();
    ht_del_hash_table(ht);
}