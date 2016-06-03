//
//  Controller.hpp
//  mock
//
//  Created by Dehelean Andrei on 4/26/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#pragma once 
#include "Repository.hpp"


class Controller {
    
    Repository repo;
    
public:
    
    Controller(Repository& repo) : repo{repo} {}
    void addPacient(Person& p);
    Person getPacient(const string& name);
    
    int isHealthy(const string& name, const int& month);
    
    vector<Medical*> getAnalysis(const string& name);
    vector<Person> getAll() { return this->repo.getAll(); }
};