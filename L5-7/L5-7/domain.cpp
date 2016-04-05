//
//  domain.cpp
//  L5-7
//
//  Created by Dehelean Andrei on 3/19/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#include "domain.hpp"
#include <cstdlib>

Coat::Coat( const string& size, const string& color , const float& price , const int& quantity , const string& link){
    this->size = size;
    this->color = color;
    this->price = price;
    this->quantity = quantity;
    this->link = link;
}

string Coat::getSize() const{
    return size;
}
string Coat::getColor() const{
    return color;
}

float Coat::getPrice() const{
    return price;
}

int Coat::getQuantity() const{
    return quantity;
}

string Coat::getLink() const{
    return link;
}

void Coat::show(){
    string cmd = "open " + link;
    system(cmd.c_str());
}

void Coat::setQuantity(int n){
    this->quantity = n;
}

