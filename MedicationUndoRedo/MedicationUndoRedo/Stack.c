//
//  Stack.c
//  MedicationUndoRedo
//
//  Created by Dehelean Andrei on 3/11/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#include "Stack.h"
#include <stdio.h>
#include <string.h>


operation op_init(Medication m, const char* opType){
    operation self;
    self.meds = m;
    strcpy(self.operationType, opType);
    return self;
}

char* getType(operation* self){
    return self->operationType;
}

Medication getMed(operation* self){
    return self->meds;
}



stack createStack()
{
    stack operationsStack;
    operationsStack.length = 0;
    
    return operationsStack;
}

void push(stack *operationsStack, operation operation)
{
    if (isFull(operationsStack))
    {
        return;
    }
    
    operationsStack->op[operationsStack->length++] = operation;
}

operation pop(stack *operationsStack)
{
    if (isEmpty(operationsStack))
    {
        Medication* m = malloc(sizeof(Medication));
        return op_init(new_medication(m,"", -1, -1, -1), "none");;
    }
    
    return operationsStack->operations[--operationsStack->length];
}

int isEmpty(OperationsStack *operationsStack)
{
    return operationsStack->length == 0;
}

int isFull(OperationsStack *operationsStack)
{
    return operationsStack->length == 100;
}
