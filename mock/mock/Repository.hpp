//
//  Repository.hpp
//  mock
//
//  Created by Dehelean Andrei on 4/26/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#pragma once 
#include "Domain.hpp"
#include "Person.hpp"
#include <vector>


class Repository {
    
    vector<Person> all;
    
public:
    
    Repository() {}
    
    void addAnalysis(Person& p);
    Person getPerson(const string& name);
    
    vector<Medical*> getAnalysis(const string& name);
    
    
};