#pragma once
#include "domain.h"
#include <vector>

class Store{
protected:
    vector<Coat> all, basket;
    int current, total;


public:
    //----constructor & destructor-------
    Store();
    virtual ~Store();

    //--------methods-------------

    void add(const Coat& c);
    Coat getCurrent();
    void start();
    void next();
    void clear();

    void buyCoat(Coat& c);
    int showTotal();
    void clearTotal();



    bool isEmpty();
};
