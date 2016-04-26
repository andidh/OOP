//
//  Person.hpp
//  mock
//
//  Created by Dehelean Andrei on 4/26/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#pragma once
#include "Domain.hpp"
#include <vector>




class Person {
    
    vector<Medical*> list;
    string name;
    
public:
    
    Person(const string& name) : name{name} {}
    
    string getName() const { return name; }
    
    void addAnalysis(Medical* m);
    vector<Medical*> getAnalysis() { return this->list; }
    
};


