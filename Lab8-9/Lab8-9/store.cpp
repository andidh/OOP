//
//  store.cpp
//  Lab8-9
//
//  Created by Dehelean Andrei on 4/7/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#include "store.hpp"

Store::Store() { this->current = 0; }

void Store::add(const Coat& c){
    this->all.push_back(c);
}

Coat Store::getCurrent(){
    if(current == all.size()){
        this->current = 0;
    }
    return this->all[current];
    return Coat{};
}

void Store::start(){
    if(this->all.size() == 0)  {
        return;
    }
    this->current = 0;
    Coat currentCoat = Store::getCurrent();
    currentCoat.show();
}

void Store::next(){
    if(this->all.size() == 0)
        return;
    this->current++;
    Coat currentCoat = Store::getCurrent();
    currentCoat.show();
}


void Store::clear(){
    this->all.clear();
}

void Store::buyCoat(Coat& c){
    this->basket.push_back(c);
    this->total += c.getPrice();
}

float Store::showTotal(){
    return this->total;
}



bool Store::isEmpty(){
    return this->all.empty();
}
