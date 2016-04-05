//
//  Coats.hpp
//  L5-7
//
//  Created by Dehelean Andrei on 3/19/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#pragma once
#include "utils.hpp"
#include <cstdlib>

class Store{
    Vector<Coat> coats;
    Vector<Coat> basket;
    int current;
    float sum = 0;
    
public:
    Store();
    void add(const Coat& item);
    void buyCoat(Coat& item);
    void clear();
    Coat getcurrentCoat();
    float getSum() { return this->sum; }
    void next();
    void show();
    bool isEmpty();
    Vector<Coat> getBasket() { return this->basket; }
    
};











