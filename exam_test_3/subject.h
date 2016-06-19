#pragma once
#include <vector>
#include "observer.h"

class Subject
{
    vector<Observer*> list;

public:
    Subject();
    void addObserver(Observer* obs);
    void notify();
};

