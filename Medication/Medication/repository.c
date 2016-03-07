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
void repo_init(Repo* repo){
    repo -> capacity = CAPACITY;
    repo -> len = 0;
    repo -> arr = malloc(sizeof(Medication)*repo->capacity);
}

//--------------DESTROY------------------------
void repo_destroy(Repo* repo){
    free(repo->arr);
    free(repo);
}


//---------------FIND-----------------------
int find(Repo* repo, const char* name){
    for( int i = 0; i < getLength(repo); i++){
        if( strcmp(get_elem(repo, i).name, name) == 0){
            return i;
        }
    }
    return -1;
}


//--------------ADD--------------------------
void repo_add(Repo* repo, Medication* m){
    
    if(repo->len >= repo->capacity) {
        int new_capacity = 2*repo->capacity;
        Medication* new_arr = malloc(sizeof(Medication)*new_capacity);
        for(int i=0; i<=getLength(repo); i++){
            new_arr[i] = repo->arr[i];
            repo -> capacity = new_capacity;
            free(repo->arr);
            repo-> arr = new_arr;
            
        }
        
    }
    if (find(repo, m->name) != -1){
        int pos = find(repo, m->name);
        repo -> arr[pos].quantity += m->quantity;
        //printf("Medication already exists!");
    }
    else{
        repo -> arr[repo->len++] = *m;
    }
    
}


//--------------GET ELEM-----------------------
Medication get_elem(Repo* repo, int pos){
    return repo -> arr[pos];
}

//-------------GET LENGTH----------------------
int getLength(Repo* repo){
    return repo->len;
}


//---------------DELETE-------------------------
void repo_delete(Repo* self, const char* name){
    int pos = find(self, name);
    if (pos == -1){
        printf("Medication does not exist\n");
    }
    int n = getLength(self);
    for(int i=pos; i<n-1; i++){
        self->arr[i] = self->arr[i+1];
    }
    --self->len;
}


//--------------UPDATE------------------------
void repo_update(Repo* self, Medication* m){
    int pos = find(self, m->name);
    if (pos == -1){
        printf("Medication does not exist!\n");
    }
    if (pos != -1){
        self->arr[pos] = *m;
    }
}

//---------------GET ALL---------------------
Medication* get_all(Repo* self){
    return self -> arr;
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
