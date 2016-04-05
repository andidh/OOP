//
//  vector.h
//  Medication
//
//  Created by Dehelean Andrei on 3/11/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//


#pragma once
#include "domain.h"

typedef struct{
    Medication* arr;
    int len, capacity;
}vector;

void vector_init(vector* self);

void vector_destroy(vector* self);

void resize(vector* self);

void vector_pushBack(vector *self, Medication m) ;

void vector_removeAt(vector *self, int pos);

int vector_getLen(vector *self);

Medication vector_getAt(vector *self, int pos);

void vector_setAt(vector *self, int pos, Medication m);