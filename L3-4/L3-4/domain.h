
//
//  Header.h
//  L3-4
//
//  Created by Dehelean Andrei on 3/1/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#pragma once


typedef struct {
    char *name;
    char *supplier;
    int quantity;
    char *date;
}Product;

Product* new_product(const char* name, const char* supplier, int quantity, const char* date);

void destroy_product(Product* prod);

int equal_prod(Product* prod1, Product* prod2);

void print_prod(Product* prod);

char* getName(Product* prod);

char* getSupplier(Product* prod);

int getQuant(Product* prod);

char* getDate(Product* prod);

void setName(Product* prod, const char* name);

void setDate(Product* prod, const char* date);

void setSupplier(Product* prod, const char* supplier);

void setQuantity(Product* prod, int quantity);
