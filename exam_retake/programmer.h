#pragma once
#include<string>
#include<iostream>
#include<sstream>
#include<vector>

using namespace std;

class Programmer
{
    string name;
    int id;
public:
    Programmer(const string& name, const int& id);
    string getName() const { return name; }
    int getId() const { return id; }

};

