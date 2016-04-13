//
//  store.hpp
//  Lab8-9
//
//  Created by Dehelean Andrei on 4/7/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#pragma once
#include "domain.hpp"
#include <vector>

class Store{
protected:
    vector<Coat> all, basket;
    int current;
    float total;
    
    
public:
    //----constructor & destructor-------
    Store();
    virtual ~Store() {}
    
    //--------methods-------------
    
    void add(const Coat& c);
    Coat getCurrent();
    void start();
    void next();
    void clear();
    
    void buyCoat(Coat& c);
    float showTotal();
    void clearTotal() { total = 0; }
    
    
    
    bool isEmpty();
};