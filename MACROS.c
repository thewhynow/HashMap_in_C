#pragma once
#include <stdbool.h>

/*
    KEY AND VALUE TYPE MUST BE DEFINED HERE
*/

typedef struct {
    int x, y, z;
} Three;

#define K char
#define V int

typedef bool (*KeyEqual_t) (K*, K*);
typedef uint64_t (*KeyHash_t) (K*);

#define MAX_MAP_BUCKETS 255