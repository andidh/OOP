//
//  controller.c
//  Medication
//
//  Created by Dehelean Andrei on 3/3/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#include "controller.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void contr_init(Contr* contr, Repo* repo){
    contr -> repo = repo;
}

void contr_destroy(Contr* contr){
    free(contr);
}


//-----------------ADD--------------------

void contr_add(Contr* contr, char* name, float concentration, int quantity, float price){
    Medication* m = malloc(sizeof(Medication));
    new_medication(m, name, concentration, quantity, price);
    repo_add(contr->repo, m);
}


//----------------GET ALL------------------
Medication* getAll(Contr* contr){
    return get_all(contr->repo);
}

//---------------DELETE--------------------
void contr_delete(Contr* contr, const char* name){
    repo_delete(contr->repo, name);
}


//----------------UPDATE--------------------
void contr_update(Contr* contr, char* name, float concentration, int quantity, float price ){
    Medication* m = malloc(sizeof(Medication));
    new_medication(m, name, concentration, quantity, price);
    repo_update(contr->repo, m);
}


//-------------FILTER BY NAME---------------
Repo* filterByName(Contr* contr, const char* name){
    Repo* r = contr -> repo;
    Repo* new_v = malloc(sizeof(Repo));
    repo_init(new_v);
    if(strcmp("null", name) ==  0){
        r = sort(r);
        return r;
    }
    int i, len = getLength(r);
    for( i=0; i<len; i++){
        Medication m = get_elem(r, i);
        if(strstr(r->arr[i].name,name)){
            repo_add(new_v, &m);
        }
    }
    new_v = sort(new_v);
    repo_destroy(r);
    return new_v;
}


//--------------FILTER BY SUPPLY--------------
Repo* filterSupply(Contr* contr, int quantity){
    Repo* filtered = malloc(sizeof(Repo));
    repo_init(filtered);
    int pos = getLength(contr->repo);
    for(int i =0; i<pos; i++){
        Medication m = get_elem(contr -> repo, i);
        if( m.quantity < quantity ){
            repo_add(filtered,&m);
        }
    }
    return filtered;
}

//--------------SORTING-------------------------
Repo* sort(Repo* v){
    int i,j;
    Medication aux;
    for(i=0;i<getLength(v)-1;i++)
        for(j=i+1;j<getLength(v);j++)
            if(strcmp(v->arr[i].name,v->arr[j].name)>0){
                aux=v->arr[i];
                v->arr[i]=v->arr[j];
                v->arr[j]=aux;
            }
            else if(strcmp(v->arr[i].name,v->arr[j].name) == 0)
                if(v->arr[i].price > v->arr[j].price){
                    aux=v->arr[i];
                    v->arr[i]=v->arr[j];
                    v->arr[j]=aux;
                }
    destroy_medication(&aux);
    return v;
}