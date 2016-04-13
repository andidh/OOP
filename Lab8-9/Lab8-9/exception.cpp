//
//  exception.cpp
//  Lab8-9
//
//  Created by Dehelean Andrei on 4/7/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#include "exception.hpp"




RepoException::RepoException(const string& msg){
    this->msg = msg;
}

const char* RepoException::what(){
    return msg.c_str();
}



FileException::FileException(const string& msg){
    this->msg = msg;
}

const char* FileException::what(){
    return this->msg.c_str();
}