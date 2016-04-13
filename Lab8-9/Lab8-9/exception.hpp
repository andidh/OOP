//
//  exception.hpp
//  Lab8-9
//
//  Created by Dehelean Andrei on 4/7/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#pragma once
#include "domain.hpp"
#include <exception>


class RepoException : public exception
{
protected:
    string msg;
    
public:
    //----------constructor & destructor ----------
    
    RepoException() : exception{}, msg{""} {}
    RepoException(const string& msg);
    virtual ~RepoException() {}
    virtual const char* what();
    
};


class DuplicateCoat : public RepoException {
    const char* what();
};



class FileException : public exception {

protected:
    string msg;
public:
    FileException(const string& msg);
    virtual const char* what(); 
};