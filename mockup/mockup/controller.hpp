//
//  controller.hpp
//  mockup
//
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#pragma once
#include "repository.hpp"

class Controller{
    Repository repo;
    
public:
    /*-----constructor-------*/
    Controller(Repository& repo);
    
    /*-------methods-----*/
    vector<Fruit>& getAll();
    void contr_deleteFruit(string& name);
    void contr_addFruit(const string& name, const string& nutri, const float& quantity);
    
    /* Function which filter the fruits based on their nutritional properties
            input: nutri - string - the nutritional benefit
            output: v - vector containing the filtered fruits
     */
    vector<Fruit> filterByBenefit(string& nutri);
    vector<Fruit>& sort(vector<Fruit>& v);
};


void testFilter();