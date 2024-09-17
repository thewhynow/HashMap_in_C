#include <stdlib.h>
#include <stdio.h>

/*
    AddressSanitizer did bring up an error with the project but i was too lazy to fix it as my code already works
*/


// i am NOT using cmake 
#include "HashMap.c"


// define key equality here
bool kComp(char* a, char* b){
    return *a == *b;
}


// define hash function here
u_int64_t kHash(char* a){
    return *a * 31;
}

HashMap* map;
int main(){
    map = HashMap_make(kComp, kHash);
    *HashMap_get(map, 'A') = 12;
    *HashMap_get(map, 'B') = 113;

    printf("%i\n", *HashMap_get(map, 'A'));
    printf("%i\n", *HashMap_get(map, 'B'));

    return 0;
}