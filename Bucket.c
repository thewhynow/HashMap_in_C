#pragma once
#include "MACROS.c"
#include "Vector.c"
#include "Pairs.c"

typedef struct {
    Vector data;
} Bucket;

Bucket Bucket_makeBucket(){
    return (Bucket){.data = Vector_makeVector()};
}

KVPair* Bucket_getPair(Bucket* this, K key, KeyEqual_t KEY_EQUAL) {
    for (int i = 0; i < this->data.size; i++)
        if (KEY_EQUAL(&this->data.data[i].key, &key)) 
            return this->data.data + i;
    return NULL;
}; 

KVPair* Bucket_Insert(Bucket* this, K key, V value){
    return Vector_pushBack(&this->data, (KVPair){.key = key, .value = value});
}

// leaves value unitialized
KVPair* Bucket_Insert_Noinitialize (Bucket* this, K key){
    return Vector_pushBack(&this->data, (KVPair){.key = key});
}

void Bucket_destroy(Bucket* this){
    Vector_destroy(&this->data);
}