//
//  domain.cpp
//  mockup
//
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#include "domain.hpp"
#include <cassert>


using namespace std;

Fruit::Fruit(const string& name, const string& nutri, const float& quantity){
    this->name = name;
    this->nutri = nutri;
    this->quantity = quantity;
}

string Fruit::getName() const{
    return this->name;
}
string Fruit::getNutri() const{
    return this->nutri;
}
float Fruit::getQuantity() const{
    return this->quantity;
}
