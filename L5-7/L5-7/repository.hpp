//
//  repository.hpp
//  L5-7
//
//  Created by Dehelean Andrei on 3/19/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#pragma once
#include "utils.hpp"
#include "Store.hpp"

class Repository{
    Vector<Coat> coats;
    
public:
    Repository();
    
    void addCoat(const Coat& item);
    Vector<Coat> getCoats() const { return coats; }
    int find(const string& link);
    void deleteCoat(const string& link);
    void update(const Coat& item);
};

