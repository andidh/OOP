//
//  classes.cpp
//  Sales
//
//  Created by Dehelean Andrei on 6/16/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#include "classes.hpp"
#include <vector>


void Sale::addSale(SaleItem& item) {
    this->sales.push_back(item);
}


double ItemDiscount::calc(Sale &s) {
    double sum=0;
    for( auto it : s.getItems()){
        if( it.getCode() == this->code)
            sum += (this->percentage * it.getPrice())/100;
    }
    return sum;
}

void SumDiscount::addDiscount(Discount *d){
    this->discounts.push_back(d);
}

double SumDiscount::calc(Sale &s){
    double total;
    for(auto it : this->discounts){
        total += it->calc(s);
    }
    return total;
}