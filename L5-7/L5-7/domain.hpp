//
//  domain.hpp
//  L5-7
//
//  Created by Dehelean Andrei on 3/19/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#pragma once
#include <string>

using namespace std;


class Coat {
    int quantity;
    string color, link, size;
    float price;
public:
    
    //-----CONSTRUCTORS-----
    Coat() : size {""}, color {""}, price {0}, quantity {0}, link {""} {}
    Coat( const string& size, const string& color , const float& price , const int& quantity , const string& link);
    
    //-----GETTERS-----
    string getSize() const;
    string getColor() const;
    float getPrice() const;
    int getQuantity() const;
    string getLink() const;
    
    //-----SETTERs------
    void setQuantity(int n);

    void show();
};

inline bool operator ==(Coat&x, Coat& y){
    return x.getLink() == y.getLink();
}
    

