#pragma once
#include<domain.h>

class Repository
{
    string file;
    vector<Car> list;
public:
    Repository(const string& file);
    vector<Car> getAll();

private:
    void loadFromFile();
};

