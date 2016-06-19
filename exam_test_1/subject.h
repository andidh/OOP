#pragma once
#include<vector>
#include "observer.h"

using namespace std;

class Subject
{
    vector<Observer*> list;
public:
    Subject();

    void addObserver(Observer* obs);

    void notify();
};

