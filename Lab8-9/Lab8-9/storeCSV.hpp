//
//  storeCSV.hpp
//  Lab8-9
//
//  Created by Dehelean Andrei on 4/9/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#pragma once
#include "storeFile.hpp"


class StoreCSV : public StoreFile {
    
public:
    
    StoreCSV(const string& file);
    
    void display() const override ;
    
    void writeToFile() override;
};