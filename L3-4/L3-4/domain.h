
//
//  Header.h
//  L3-4
//
//  Created by Dehelean Andrei on 3/1/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#pragma once
#include <time.h>
#include <stdio.h>

typedef struct tm p_time;
typedef struct {
    char *name;
    char *supplier;
    float quantity;
    p_time date;
}Product;


static const Product NULL_PRODUCT;

void new_product(Product* prod,char* name,char* supplier, float quantity, p_time date);

void destroy_product(Product* prod);

int equal_prod(Product* prod1, Product* prod2);

//void print_prod(Product* prod);

char* getName(Product* prod);

char* getSupplier(Product* prod);

int getQuant(Product* prod);

p_time getDate(Product* prod);

int Expiration(Product* prod);

