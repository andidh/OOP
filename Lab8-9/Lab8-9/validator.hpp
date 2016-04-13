//
//  validator.hpp
//  Lab8-9
//
//  Created by Dehelean Andrei on 4/7/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#pragma once
#include "domain.hpp"
#include <vector>
#include <string>

using namespace std;


//--------Coat exc class-----------------
class CoatException {
    
    vector<string> errors;
    
public:
    CoatException(vector<string>& errors);
    vector<string> getErrors();
};




//---------Validator class----------------

class Validator{
public:

    static void validate(const Coat& c);
};
