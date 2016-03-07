//
//  repository.c
//  L3-4
//
//  Created by Dehelean Andrei on 3/1/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#include "repository.h"
#include <stdio.h>
#include <stdlib.h>
#include<string.h>


#define CAPACITY 10

void repo_init(Repo* r){
    r->capacity = CAPACITY;
    r->len = 0;
    r->arr = malloc(sizeof(Product)*r->capacity);
}

void repo_destruct(Repo* r){
    free(r->arr);
}

int getLength(Repo *r){
    return r->len;
}

void addRepo(Repo* r, Product* p){
    
    if(r->len >= r->capacity){
        int new_capacity = 2*r->capacity;
        Product* new_prod = malloc(sizeof(Product)*new_capacity);
        for(int i=0; i<r->len; i++){
            new_prod[i] = r->arr[i];
            r->capacity = new_capacity;
            free(r->arr);
            r->arr = new_prod;
        }
    }
    if(find(r, p->name)!= -1){
        return;
    }
    r->arr[r->len++] = *p;
}


int size(Repo* r){
    return r->len;
}


Product get_elem(Repo* r, int pos){
    return r->arr[pos];
}


int find(Repo* r, const char* name){
    for( int i = 0; i<r->len; i++){
        if (strcmp(get_elem(r, i).name,name) == 0 )
        {
            return i;
        }
    }
    return -1;
}

 