#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <string>
#include <exception>

using namespace std;

class Exception : public exception
{
    string message;

public:
    Exception(const string& message);
    const char* what(){ return message.c_str();}
};

#endif // EXCEPTION_H


