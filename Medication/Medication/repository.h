//
//  repository.h
//  Medication
//
//  Created by Dehelean Andrei on 3/3/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#pragma once
#include "domain.h"
#include "vector.h"

typedef struct{
    vector* arr;
    vector* undo;
    vector* redo;
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

/*
 Delete funtion:
 input: name of the element
 */
void repo_delete(Repo* self, const char* name);

//Updates an existing element
void repo_update(Repo* self, Medication* m);

int repo_undo(Repo ** self);

/**
 Method for the Redo feature
 Returns 1 if Redo was done
 0 if it cannot be don
 */
int repo_redo(Repo ** self);

/// private
/**
 Method to prepare the Undo and Redo feature. It makes a deep copy of the Repository
 */
void repo__saveRepo(Repo ** self);


vector* get_all(Repo* self);

void testRepo();