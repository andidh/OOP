#pragma once
#include<exception>
#include "programmer.h"

class Exception : public exception
{
    string message;
public:

    Exception(const string& msg);
    const char* what() { return this->message.c_str(); }
};

