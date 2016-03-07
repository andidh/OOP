//
//  domain.h
//  Medication
//
//  Created by Dehelean Andrei on 3/3/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#pragma once

typedef struct{
    char* name;
    float concentration;
    int quantity;
    float price;
}Medication;

//Function which constructs a Medication type structure (as a pointer)
void new_medication(Medication* self,  char* name, float concentration, int , float price);

//Function which destroy a structure
void destroy_medication(Medication* self);

//Function which checks if two medications are the same
int equal(Medication* m1, Medication* m2);

//Function which returns the name of a medication
char* get_name(Medication* self);

//Function which returns the concentration
float get_concentration(Medication* self);

//Function which returns the quantity
int get_quantity(Medication* self);

//Function which returns the price
float get_price(Medication* self);


