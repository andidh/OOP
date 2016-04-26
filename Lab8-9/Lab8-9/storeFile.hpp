//
//  storeFile.hpp
//  Lab8-9
//
//  Created by Dehelean Andrei on 4/9/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#pragma once
#include "store.hpp"

class StoreFile : public Store {
    
protected:
    string filename;
    
public:
    StoreFile();
    StoreFile(const string& file);
    virtual ~StoreFile() {}
    
    void setFile(const string& file);
    virtual void display() const = 0 ;
    virtual void writeToFile() = 0;
};