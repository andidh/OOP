//
//  controller.c
//  L3-4
//
//  Created by Dehelean Andrei on 3/2/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#include "controller.h"
#include<stdio.h>
#include <stdlib.h>
#include "domain.h"


void contr_init(Contr* c, Repo* r){
    c -> repo = r;
}

void contr_destroy(Contr *self){
    free(self);
    self = NULL;
}

int addProd(Contr* c,const  char* name, const char* supplier, double quantity, p_time date){
    Product *prod;
    prod = malloc(sizeof(Product));
    new_product(prod, name, supplier, quantity, date);
    addRepo(c->repo, prod);
    return 0;
}
