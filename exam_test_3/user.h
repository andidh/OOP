#pragma once
#include <vector>
#include <string>

using namespace std;

class User
{
    string name, type;
public:
    User(const string& name, const string& type);
    string getName() const  { return name; }
    string getType() const { return type; }

};

