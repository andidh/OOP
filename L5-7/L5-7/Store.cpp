//
//  Coats.cpp
//  L5-7
//
//  Created by Dehelean Andrei on 3/19/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#include "Store.hpp"


Store::Store(){
    this->current = 0;
}

void Store::add(const Coat& item){
    this->coats.add(item);
}

void Store::clear(){
    
}

Coat Store::getcurrentCoat(){
    if (this->current == this->coats.getSize())
        this->current = 0;
    Coat* arr = this->coats.getAll();
    if(arr !=NULL)
        return arr[this->current];
    return Coat{};
}

void Store::show(){
    if(this->coats.getSize() == 0)
        return;
    this->current = 0;
    Coat currentCoat = this->getcurrentCoat();
    currentCoat.show();
    
}

void Store::next(){
    if(this->coats.getSize() == 0)
        return;
    this->current++;
    Coat currentCoat = this->getcurrentCoat();
    currentCoat.show();
}

bool Store::isEmpty(){
    return this->coats.getSize() == 0;
    
}

void Store::buyCoat( Coat& item){
    this->basket.add(item);
    this->sum += item.getPrice();
    int n = item.getQuantity();
    --n;
    item.setQuantity(n);
}
