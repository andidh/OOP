
//  Created by Dehelean Andrei on 3/1/16.


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "domain.h"

Product* new_product(const char* name, const char* supplier, int quantity, const char* date){
    Product* prod = malloc(sizeof *prod);
    prod -> name = malloc(sizeof(*name));
    strcpy(prod -> name, name);
    prod -> supplier = malloc(sizeof(*supplier));
    strcpy(prod -> supplier, supplier);
    prod -> date = malloc(sizeof(*date));
    strcpy(prod->date, date);
    prod -> quantity = quantity;
    return prod;
}

void destroy_product(Product* prod){
    free(prod);
    free(prod->name);
    free(prod->supplier);
    free(prod->date);
}

int equal_prod(Product* prod1, Product* prod2){
    return prod1->name == prod2->name;
}

void print_prod(Product* prod){
    printf("%s %s %d %s \n", prod->name, prod->supplier, prod->quantity, prod->date);
}


char* getName(Product* prod){
    return prod -> name;
}

char* getSupplier(Product* prod){
    return prod->supplier;
}

int getQuant(Product* prod){
    return prod->quantity;
}

char* getDate(Product* prod){
    return prod->date;
}

void setName(Product* prod, const char* name){
    prod -> name = malloc(sizeof(char)*(strlen(name)+ 1));
    strcpy(prod -> name, name);
}

void setDate(Product* prod, const char* date){
    prod -> date = malloc(sizeof(char) * (strlen(date) +1));
    strcpy(prod->date, date);
}

void setSupplier(Product* prod, const char* supplier){
    prod -> supplier = malloc(sizeof(char)*(strlen(supplier) + 1));
    strcpy(prod -> supplier, supplier);
}

void setQuantity(Product* prod, int quantity){
    prod -> quantity = quantity;
}

int main() {
    
    Product* p;
    p = new_product("Bread", "Ali", 100, "Monday");
    print_prod(p);
    return 0;
}
