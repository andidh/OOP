//
//  Beverage.cpp
//  BeverageMachine
//
//  Created by Dehelean Andrei on 6/17/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#include "Beverage.hpp"
#include <iostream>

Beverage::Beverage(const string& description) : description{description} {}

void Beverage::print(){
    cout<<description<<" : "<<price();
}


double BeverageWithMilk::price() {
    if(this->b == nullptr)
        return 0;
    return b->price() + 0.5*milk;
}

void BeverageWithMilk::print() {
    if(this->b ==  nullptr)
        return;
    b->print();
    if(milk > 0)
        cout<<" "<<milk<<" portion of milk"<<endl;
    cout<<"Total: "<<this->price();
}