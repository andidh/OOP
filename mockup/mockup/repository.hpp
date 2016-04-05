//
//  repository.hpp
//  mockup
//
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#pragma once
#include "domain.hpp"
#include <vector>


class Repository{
    vector<Fruit> list;
    
public:
    /*-----constructor-----*/
    Repository();
    
    /*----methods-------*/
    
    /*
     Function which adds a fruit to the repository
        input: f - object of type Fruit
        output: 0 - if it was succesfull
                1 - otherwise
     */
    int addFruit(Fruit& f);
    void deleteFruit(string& name);
    vector<Fruit>& getAll();
    int findFruit(string& name);
    long getLength();
    
    
};

void testAddRepo();