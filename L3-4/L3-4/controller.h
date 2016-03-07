//
//  controller.h
//  L3-4
//
//  Created by Dehelean Andrei on 3/2/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#pragma once

#include <stdio.h>
#include "repository.h"


typedef struct{
    Repo* repo;
}Contr;

void contr_init(Contr* c, Repo* r);

void contr_destroy(Contr *self);

int addProd(Contr* c, const char* name, const char* supplier, double quantity, p_time date);

