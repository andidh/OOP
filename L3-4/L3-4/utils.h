//
//  utils.h
//  L3-4
//
//  Created by Dehelean Andrei on 3/2/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#pragma once
#include "domain.h"


typedef struct{
    Product* arr;
    int n, capacity;
}vector;

void vector_init(vector* v);
void vector_destruct(vector*);

void vector_incLen(vector* v);
void vector_setLen(vector* v);
int vector_getCapacity(vector* v);
void vector_setCapacity(vector* v);


void push_back(vector* v, Product* p);
void vector_putAt(vector* v, int i);
int vector_getLen(vector* v);
void vector_setAt(vector* v, int i, Product* p);
Product vector_getAt(vector* v, int i);