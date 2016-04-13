//
//  storeCSV.cpp
//  Lab8-9
//
//  Created by Dehelean Andrei on 4/9/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#include "storeCSV.hpp"
#include <fstream>
#include "exception.hpp"



void StoreCSV::display() const {
    string cmd = "open " + this->filename;
    system(cmd.c_str());
}

void StoreCSV::writeToFile() {
    ofstream f(this->filename);
    
    if(!f.is_open())
        throw FileException("This file could not be opened!");

    for ( auto c : this->basket)
        f << c;
    
    f.close();

}
