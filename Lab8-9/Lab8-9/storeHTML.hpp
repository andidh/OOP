//
//  storeHTML.hpp
//  Lab8-9
//
//  Created by Dehelean Andrei on 4/14/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#pragma once
#include "storeFile.hpp"

class StoreHTML : public StoreFile
{
    
public:
    StoreHTML(const string& file);
    void display() const override ;
    
    void writeToFile() override;

    
};