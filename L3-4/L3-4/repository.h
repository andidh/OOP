//
//  repository.h
//  L3-4
//
//  Created by Dehelean Andrei on 3/1/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#pragma once
#include "domain.h"


typedef struct {
    Product* arr;
    int len, capacity;
}Repo;

//dynamically allocates a vector
void repo_init(Repo* v);

//find a product based on a given name
int find(Repo* r, const char* name);

//adds a new element to the vector
void addRepo(Repo* r, Product* p);

//return the length of the vector
int size(Repo* r);

//returns a specific element from the vector
Product get_elem(Repo* r, int pos);

int getLength(Repo *r);

//destroy a vector
void vector_destruct(Repo* r);
