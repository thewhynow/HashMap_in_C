#pragma once
#include <stdlib.h>
#include <string.h>

#include "Pairs.c"

typedef struct {
    KVPair* data;
    size_t size;
    size_t capacity;
} Vector;


KVPair* Vector_get(Vector* this, const size_t index){
    return this->data + index;
}

Vector Vector_makeVector(){
    Vector newVector;
    newVector.data = NULL;
    newVector.size = 0;
    newVector.capacity = 0;

    return newVector;
}

void Vector_realloc(Vector* this, size_t newCapacity){
    this->data = realloc(this->data, newCapacity);
    this->capacity = newCapacity;
}

KVPair* Vector_pushBack(Vector* this, KVPair value){
    if (this->size == this->capacity){
        this->capacity++;  // reallocating by one more FOR NOW
        Vector_realloc(this, this->capacity);
    }

    this->data[this->size] = value;

    return &this->data[this->size++];
}

void Vector_destroy(Vector* this){
    free(this->data);
}