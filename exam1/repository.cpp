//
//  repository.cpp
//  mockup
//
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#include "repository.hpp"
#include <string>
#include <iostream>
#include <cassert>

using namespace std;

Repository::Repository() {}

int Repository::addFruit(Fruit& f){
    for( auto a : this->list){
        if(a.getName() == f.getName())
        {
            cout<<"Fruit already exists!"<<endl;
            return 0;
        }
    }
    this->list.push_back(f);
    cout<<"Fruit was successfully added!\n";
    return 1;
}


void Repository::deleteFruit(string& name){
    int pos = findFruit(name);
    if(pos != -1){
        this->list.erase(this->list.begin()+pos);
        cout<<"The fruit was successfully deleted"<<endl;
    }
    else{
        cout<<"There is no such Fruit!"<<endl;
    }
    
}


int Repository::findFruit(string& name){
    for(int i=0; i<this->list.size(); i++)
    {
        Fruit a = this->list[i];
        if(a.getName()== name)
            return i;
    }
    return -1;
    
}

vector<Fruit>& Repository::getAll(){
    return this->list;
}

long Repository::getLength(){
    return this->list.size();
}



void testAddRepo(){
    Repository ex;
    Fruit f{"apple", "fiber", 3.2};
    assert(ex.getLength() == 0);
    ex.addFruit(f);
    assert(ex.getLength() == 1);
}



