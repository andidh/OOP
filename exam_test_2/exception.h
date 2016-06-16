#pragma once
#include<string>
#include <exception>
using namespace std;

class Exception : public exception
{
    string message;
public:
    Exception(const string& msg);
    const char* what() { return this->message.c_str(); }
};


