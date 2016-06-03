//
//  controller.cpp
//  mockup
//
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#include "controller.hpp"
#include <string.h>
#include<iostream>
#include <cassert>
#include <algorithm>


Controller::Controller(Repository& repo){
    this->repo = repo;
}

vector<Fruit>& Controller::getAll(){
    return this->repo.getAll();
}

void Controller::contr_addFruit(const string& name, const string& nutri, const float& quantity){
    Fruit f{name, nutri, quantity};
    this->repo.addFruit(f);
}

void Controller::contr_deleteFruit(string& name){
    this->repo.deleteFruit(name);
}

vector<Fruit> Controller::filterByBenefit(string& nutri){
    /*
    vector<Fruit> aux;
    for( auto f : Controller::getAll()){
        if(f.getNutri() == nutri)
            aux.push_back(f);
    }
    return Controller::sort(aux);
     */
    vector<Fruit> all = this->getAll();
    std::sort(all.begin(), all.end(), [](const Fruit&a, const Fruit& b) {
        return a.getQuantity() < b.getQuantity();
    });
    return all;
    
}
vector<Fruit>& Controller::sorting(vector<Fruit>& v){
    int i, j;
    Fruit aux;
    for(i=0; i<v.size()-1;i++){
        for(j=i+1;j<v.size();j++){
            if(v[i].getQuantity() > v[j].getQuantity()){
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
    return v;
}




void testFilter(){
    Repository r;
    Controller contr(r);
    contr.contr_addFruit("apple", "fiber", 9.6);
    contr.contr_addFruit("kiwi", "fiber", 2.1);
    string x = "fiber";
    vector<Fruit> ex = contr.filterByBenefit(x);
    vector<Fruit> all = contr.getAll();
    assert(ex.at(1) == all.at(2));
}
