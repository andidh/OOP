#pragma once
#include "domain.h"
#include <exception>


class RepoException : public exception
{
protected:
    string msg;

public:
    //----------constructor & destructor ----------

    RepoException();
    RepoException(const string& msg);
    virtual ~RepoException();
    virtual const char* what();

};



class FileException : public exception {

protected:
    string msg;
public:
    FileException(const string& msg);
    virtual const char* what();
};
