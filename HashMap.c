#pragma once
#include <stdlib.h>
#include <stdbool.h>

#include "MACROS.c"
#include "Bucket.c"
#include "Vector.c"
#include "Pairs.c"

typedef struct {
    Bucket buckets[MAX_MAP_BUCKETS];
    
    KeyEqual_t KEqual;
    KeyHash_t KHash;
} HashMap ;

HashMap* HashMap_make(
    KeyEqual_t KEY_EQUAL, // key comparison
    KeyHash_t KEY_HASH // key hasher
){
    HashMap* obj = malloc(sizeof(HashMap));
    
    // initialize buckets
    for (int i = 0; i < MAX_MAP_BUCKETS; i++)
        obj->buckets[i] = Bucket_makeBucket();

    obj->KEqual = KEY_EQUAL;
    obj->KHash = KEY_HASH;
    
    return obj;
}

V* HashMap_find(HashMap* this, K key){
    // get bucket
    Bucket* bucket = this->buckets + (this->KHash(&key) % MAX_MAP_BUCKETS);
    // get pair from bucket
    KVPair* pair = Bucket_getPair(bucket, key, this->KEqual);
    
    if (pair == NULL) // i know this is redundant but idk how else to do it
        return NULL;
    else 
        return &pair->value;
}

V* HashMap_insert(HashMap* this, K key, V value){
    Bucket* bucket = this->buckets + (this->KHash(&key) % MAX_MAP_BUCKETS);
    return &Bucket_Insert(bucket, key, value)->value;
}

V* HashMap_get(HashMap* this, K key){
    V* find = HashMap_find(this, key);
    if (find == NULL)
        return &Bucket_Insert_Noinitialize(this->buckets + (this->KHash(&key) % MAX_MAP_BUCKETS), key)->value;
    else
        return find;
}

void HashMap_destroy(HashMap* this){
    for (int i = 0; i < MAX_MAP_BUCKETS; i++)
        Bucket_destroy(this->buckets + i);
}