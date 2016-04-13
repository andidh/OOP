//
//  repository.hpp
//  Lab8-9
//
//  Created by Dehelean Andrei on 4/7/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#pragma once
#include "domain.hpp"
#include <vector>

class Repository {
    vector<Coat> list;
    string file;
    
public:
    
    Repository( const string& filename);
    
    void addCoat(const Coat& c);
    void removeCoat(const string& link);
    void update(const Coat& c);
    
    
    
    vector<Coat> getAll() { return list; }
    Coat findByLink(const string& link);
    
    
private:
    void readFromFile();
    void writeToFile();
};