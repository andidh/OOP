//
//  Repository.cpp
//  mock
//
//  Created by Dehelean Andrei on 4/26/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#include "Repository.hpp"
#include <iostream>
#include <vector>


void Repository::addAnalysis(Person &p){
    this->all.push_back(p);
}

Person Repository::getPerson(const string& name) {
    for ( auto item : this->all){
        if(item.getName() == name )
            return item;
    }
    return Person{""};
}

vector<Medical*> Repository::getAnalysis(const string &name){
    Person p = this->getPerson(name);
    return p.getAnalysis();
}