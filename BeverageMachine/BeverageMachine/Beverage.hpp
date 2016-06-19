//
//  Beverage.hpp
//  BeverageMachine
//
//  Created by Dehelean Andrei on 6/17/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#pragma once
#include <string>

using namespace std;

class Beverage {
    string description;
    
public:
    Beverage() : description{""} {}
    Beverage(const string& description);
    virtual double price() = 0;
    virtual void print();
    virtual ~Beverage() {};

};

class Coffee : public Beverage {
    
public:
    Coffee() : Beverage("Coffee") {}
    double price() { return 2.5; }
};

class Tea : public Beverage {
    
public:
    Tea() : Beverage("Coffee") {}
    double price() { return 1.5; }
};

class BeverageWithMilk : public Beverage {
    
    Beverage* b;
    int milk;
    
public:
    BeverageWithMilk(Beverage* b, int milk) : b{b}, milk{milk} {}
    double price();
    void print();
    
};


class BeverageMachine{
    
    
public:
    BeverageMachine() {}
    
    void prepare(const string& type,const int& milk){
        if(type != "coffee" && type != "tea")
            return;
        
        Beverage* bev = nullptr;
        if( type == "coffee")
            bev = new Coffee();
        else
            bev = new Tea();
        Beverage* bevMilk = new BeverageWithMilk{bev, milk};
        bevMilk->print();
        
        delete bev;
        delete bevMilk;
        
    }
};