//
//  vector.c
//  Medication
//
//  Created by Dehelean Andrei on 3/11/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#include "vector.h"
#include <stdio.h>
#include<stdlib.h>
#define CAPACITY 10

void vector_init(vector* self){
    self -> capacity = CAPACITY;
    self -> len = 0;
    self -> arr = malloc(sizeof(Medication)*self->capacity);

}

void vector_destroy(vector* self){
    free(self -> arr);
    self -> len = 0;
    self -> capacity = 0;
}

void vector_pushBack(vector *self, Medication m) {
   /* if(self->capacity >= self->len)
    {
        resize(self);
    }*/
    self->arr[self->len] = m;
    self->len++;
}


void resize(vector* self){
    int new_capacity = 2*self->capacity;
    Medication* new_arr = malloc(sizeof(Medication)*new_capacity);
    for(int i=0; i<= vector_getLen(self); i++){
        new_arr[i] = self->arr[i];
        self -> capacity = new_capacity;
        free(self->arr);
        self-> arr = new_arr;
    }
}

void vector_removeAt(vector *self, int pos) {
    int len = vector_getLen(self);
    if(pos > len - 1) {
        printf(" Attempt to remove from invalid position. Vector len (%d) at position: %d!\n", len, pos);
        return ;
    }
    int i;
    for(i = pos ; i < len - 1 ; ++ i)
        self->arr[i] = self->arr[i + 1];
    
    --self->len;
}

int vector_getLen(vector *self){
    return self->len;
}

Medication vector_getAt(vector *self, int pos){
    int len = vector_getLen(self);
    if(pos > len - 1) {
        printf("Attempt to access invalid position. Vector size %d, position %d!\n", len, pos);
    }
    return self->arr[pos];
}


void vector_setAt(vector *self, int pos, Medication m) {
    int len = vector_getLen(self);
    if(pos > len - 1) {
        printf("Attempt to access invalid position. Vector size %d, position %d!\n", len, pos);
        return ;
    }
    self->arr[pos] = m;
}