//
//  controller.h
//  Medication
//
//  Created by Dehelean Andrei on 3/3/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#pragma once
#include "repository.h"

typedef struct {
    Repo* repo;
}Contr;

void contr_init(Contr* contr, Repo* repo);

void contr_destroy(Contr* contr);

void contr_add(Contr* contr, char* name, float concentration, int quantity, float price);

vector* getAll(Contr* contr);

void contr_delete(Contr* contr, const char* name);

void contr_update(Contr* contr, char* name, float concentration, int quantity, float price );

Repo* sort(Repo* v);

Repo* filterByName(Contr* contr, const char* name);

Repo* filterSupply(Contr* contr, int quantity);

int controller_undo(Contr *self);

int controller_redo(Contr *self);