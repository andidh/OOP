//
//  Repository.hpp
//  exam2
//
//  Created by Dehelean Andrei on 4/25/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#pragma once
#include "domain.hpp"
#include <vector>


class Repository {
    vector<Painting> list;
    
public:
    
    void addPainting(const Painting& p);
    void removePainting(const Painting& p);
    vector<Painting> getAll();
    
};

