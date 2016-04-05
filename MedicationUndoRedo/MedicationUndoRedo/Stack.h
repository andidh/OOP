//
//  Stack.h
//  MedicationUndoRedo
//
//  Created by Dehelean Andrei on 3/11/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#pragma once
#include "domain.h"

typedef struct {
    Medication meds;
    char operationType[10];
}operation;

operation op_init(Medication m, const char* opType);

char* getType(operation* self);

Medication getMed(operation* self);

typedef struct{
    operation op[100];
    int length;
}stack;

stack createStack();
void push(stack *stack, operation op);
operation pop(stack *stack);
int isEmpty(stack *stack);
int isFull(stack *stack);
