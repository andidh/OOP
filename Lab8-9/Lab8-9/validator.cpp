//
//  validator.cpp
//  Lab8-9
//
//  Created by Dehelean Andrei on 4/7/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#include "validator.hpp"


CoatException::CoatException(vector<string>& errors){
    this->errors = errors;
}

vector<string> CoatException::getErrors(){
    return errors;
}


void Validator::validate(const Coat &c){
    
    vector<string> errors;
    
    if(c.getPrice() < 0)
        errors.push_back("Price must be positive!");
    if(c.getQuantity() < 0)
        errors.push_back("Quantity must be positive!");
    unsigned long http = c.getLink().find("http");
    if(http != 0)
        errors.push_back("Link must start with http://");
    
    if(errors.size() > 0 )
        throw CoatException(errors);
}