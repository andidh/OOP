//
//  storeFile.cpp
//  Lab8-9
//
//  Created by Dehelean Andrei on 4/9/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#include "storeFile.hpp"


StoreFile::StoreFile() : Store{}, filename{""} {}

StoreFile::StoreFile(const string& file) {
    filename = file;
}


void StoreFile::setFile(const string &file){
    this->filename = file;
}