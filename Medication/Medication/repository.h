//
//  repository.h
//  Medication
//
//  Created by Dehelean Andrei on 3/3/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#pragma once
#include "domain.h"

typedef struct{
    int len, capacity;
    Medication* arr;
}Repo;


//Function which initialize a repo
void repo_init(Repo* repo);

//Function which destroy a repo
void repo_destroy(Repo* repo);

/*
 Find function:
 input: repo, name
 output: pos, if the element is in the list
         -1, otherwise
*/
int find(Repo* repo, const char* name);


/*
 Add function:
 input: Medication type structure
 */
void repo_add(Repo* repo, Medication* m);


//Function which returns a element based on its position
Medication get_elem(Repo* repo, int pos);

//Returns the length of the repo
int getLength(Repo* repo);


/*
 Delete funtion:
 input: name of the element
 */
void repo_delete(Repo* self, const char* name);

//Updates an existing element
void repo_update(Repo* self, Medication* m);

Medication* get_all(Repo* self);