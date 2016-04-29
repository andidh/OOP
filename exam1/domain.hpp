//
//  domain.hpp
//  mockup
//
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#pragma once
#include <string>

using namespace std;

class Fruit {
    string name, nutri;
    float quantity;

public:
    /*----constructor-----*/
    Fruit() : name{""}, nutri {""}, quantity{0} {}
    
    Fruit(const string& name, const string& nutri, const float& quantity);
    
    /*------methods-------*/
    string getName() const;
    string getNutri() const;
    float getQuantity() const;
    
};

inline bool operator ==(Fruit& f1, Fruit& f2){
    return f1.getName() == f2.getName();
}