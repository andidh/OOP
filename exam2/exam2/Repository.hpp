//
//  Repository.hpp
//  exam2
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

