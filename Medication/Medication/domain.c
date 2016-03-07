//
//  domain.c
//  Medication
//
//  Created by Dehelean Andrei on 3/3/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#include "domain.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//-------------CREATE MEDICATION--------------------
void new_medication(Medication* self, char* name, float concentration, int quantity, float price){
    self -> name = malloc(sizeof(*name));
    strcpy(self->name, name);
    self -> concentration = concentration;
    self -> quantity = quantity;
    self -> price = price;
}

//------------DESTROY MEDICATION--------------------
void destroy_medication(Medication* self){
    free(self -> name);
}

//---------------------EQUAL-------------------------
int equal(Medication* m1, Medication* m2){
    return m1->name == m2->name && m1->concentration == m2->concentration;
}

//-------------GET NAME-----------------------------
char* get_name(Medication* self){
    return self -> name;
}

//-------------GET CONCENTRATION--------------------
float get_concentration(Medication* self){
    return self->concentration;
}

//--------------GET QUANTITY------------------------
int get_quantity(Medication* self){
    return self ->  quantity;
}

//-----------------GET PRICE------------------------
float get_price(Medication* self){
    return self -> price;
}

//-----------------TESTING--------------------------
void testCreateMedication() {
    Medication* m = malloc(sizeof(Medication));
    new_medication(m, "Nurofen", 3.2, 100, 11.5);
    assert(strcmp(get_name(m), "Nurofen") == 0);
    assert(get_concentration(m) == 3.2);
    assert(get_quantity(m)==100);
    assert(get_quantity(m) == 11.5);
    destroy_medication(m);
}

