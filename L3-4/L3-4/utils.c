//
//  utils.c
//  L3-4
//
//  Created by Dehelean Andrei on 3/2/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 10

void vector_init(vector* v){
    v->capacity = CAPACITY;
    v->n = 0;
    v->arr = malloc(sizeof(Product)*v->capacity);
}

void vector_destruct(vector* v){
    free(v->arr);
}

void push_back(vector* v, Product* p){
    /*if(v->n >= v->capacity){
        int new_capacity = 2*v->capacity;
        Product* new_prod = malloc(sizeof(Product)*new_capacity);
        for(int i=0; i< v->n; i++){
            new_prod[i] = v -> arr[i];
            v->capacity = new_capacity;
            free(v->arr);
            v->arr = new_prod;
        }
        */
    v->arr[v->n++] = *p;
}


