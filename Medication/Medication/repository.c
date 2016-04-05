//
//  repository.c
//  Medication
//
//  Created by Dehelean Andrei on 3/3/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#include "repository.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define CAPACITY 10


//-----------------INIT-----------------------
void repo_init(Repo* self){
    self -> arr = malloc(sizeof(vector));
    self -> undo = (vector*) NULL;
    self -> redo = (vector*) NULL;
    vector_init(self->arr);
}




//--------------DESTROY------------------------
void repo_destroy(Repo* self){
    free(self->arr);
    free(self);
}


//----------------FIND-------------------------
int find(Repo* self, const char* name){
    int len = vector_getLen(self -> arr);
    for( int i = 0; i < len; i++){
        if( strcmp(vector_getAt(self->arr, i).name, name) == 0){
            return i;
        }
    }
    return -1;
}


//--------------ADD--------------------------
void repo_add(Repo* self, Medication* m){
    repo__saveRepo(&self);
    vector_pushBack(self->arr, *m);
}



//---------------DELETE-------------------------
void repo_delete(Repo* self, const char* name){
    repo__saveRepo(&self);
    int pos = find(self, name);
    if (pos == -1){
        printf("Medication does not exist\n");
    }
    vector_removeAt(self->arr, pos);
}


//--------------UPDATE------------------------
void repo_update(Repo* self, Medication* m){
    repo__saveRepo(&self);
    int pos = find(self, m->name);
    if (pos == -1){
        printf("Medication does not exist!\n");
    }
    if (pos != -1){
        vector_setAt(self->arr, pos, *m);
    }
}




//---------------GET ALL---------------------
vector* get_all(Repo* self){
    return self -> arr;
}




//--------------UNDO-------------------------
int repo_undo(Repo **self) {
    if((*self)->undo == (vector *)NULL)
        return 0;
    if((*self)->redo != (vector *) NULL)
        vector_destroy((*self)->redo);
    (*self)->redo = (vector *)malloc(sizeof(vector));
        vector_init((*self)->redo);
    for(int i = 0 ; i < vector_getLen((*self)->arr) ; ++ i)
        vector_pushBack((*self)->redo, vector_getAt((*self)->arr, i));
    vector_destroy((*self)->arr);
    (*self)->arr = (*self)->undo;
    (*self)->undo = (vector *)NULL;
    return 1;
}

//--------------REDO-------------------------
int repo_redo(Repo **self) {
    if((*self)->redo == (vector *) NULL)
        return 0;
    if((*self)->undo != (vector *) NULL)
        vector_destroy((*self)->undo);
    (*self)->undo = (vector *)malloc(sizeof(vector));
    vector_init((*self)->undo);
    for(int i = 0 ; i < vector_getLen((*self)->arr) ; ++ i)
        vector_pushBack((*self)->undo, vector_getAt((*self)->arr, i));
    vector_destroy((*self)->arr);
    (*self)->arr = (*self)->redo;
    (*self)->redo = (vector * )NULL;
    return 1;
}

void repo__saveRepo(Repo **self) {
    if((*self)->redo != (vector *) NULL)
        vector_destroy((*self)->redo);
    (*self)->redo = (vector *)NULL;
    if((*self)->undo != (vector *) NULL)
        vector_destroy((*self)->undo);
    (*self)->undo = (vector *)malloc(sizeof(vector));
    vector_init((*self)->undo);
    for(int i = 0 ; i < vector_getLen((*self)->arr) ; ++ i)
        vector_pushBack((*self)->undo, vector_getAt((*self)->arr, i));
}



 void testRepo() {
    Repo* repo = malloc(sizeof(Repo));
    repo_init(repo);
    assert(getLength(repo)==0);
    Medication* m = malloc(sizeof(Medication));
    new_medication(m, "Nurofen", 3.2, 100, 11.5);
    repo_add(repo, m);
    assert(getLength(repo)==1);
    repo_delete(repo, get_name(m));
    assert(getLength(repo)==0);
    
}
 
