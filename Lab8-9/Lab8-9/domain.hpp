//
//  domain.hpp
//  Lab8-9
//
//  Created by Dehelean Andrei on 4/7/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#pragma once
#include <string>
#include<iostream>

using namespace std;

class Coat {
    int quantity;
    string color, link, size;
    float price;
public:
    
    //----constructors------
    Coat() : size(""), color(""), price(0), quantity(0), link("") {}
    Coat( const string& size, const string& color , const float& price , const int& quantity , const string& link);
    
    //-----GETTERS-----
    string getSize() const;
    string getColor() const;
    float getPrice() const;
    int getQuantity() const;
    string getLink() const;
    
    void setQuantity(int& n);
    
    void toString() const;
    void show();
    //--------overload eual op-------
    //bool operator==(Coat& c) { return this->link == c.link; };

    
    
    friend istream& operator>>(istream& is, Coat& c);
    friend ostream& operator<<(ostream& os, const Coat& c);
};


inline bool operator==(const Coat& c1,const Coat& c2){
    return c1.getLink() == c2.getLink();
}