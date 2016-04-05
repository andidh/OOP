/*

 John is the administrator of the “Smiles” Pharmacy. He needs a software application to help him manage his pharmacy's medication stocks. Each Medication is stored in the following way: name, concentration, quantity and price. John wants his new application to help him in the following ways:
 a. He wants to be able to add, delete or update a medication. A medicine is uniquely identified by its name and concentration. If a product that already exists is added, its quantity will be modified (the new quantity is
 added to the existing one).
 b. He wants to be able to see all the available medications containing a given string (if the string is
 empty, all the available medications will be considered), sorted by ascending medication name
 and price.
 c. He wants to be able to see only those medications that are in short supply (quantity less than X
 items, where the value of X is provided by John).
 d. The application must provide the option to undo and redo the last change.
 
*/

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

