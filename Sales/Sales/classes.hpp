//
//  classes.hpp
//  Sales
//
//  Created by Dehelean Andrei on 6/16/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#pragma once
#include <vector>
#include<string>

using namespace std;

class SaleItem {
    
    int code;
    double price;
    
public:
    SaleItem(const int& code,const double& price) : code{code}, price{price} {}
    int getCode() const { return code; }
    double getPrice() const { return price;}
    
};



class Sale{
    vector<SaleItem> sales;
    
public:
    Sale() {}
    void addSale(SaleItem& item);
    vector<SaleItem> getItems() { return this->sales; }
};



class Discount {
    
public:
    
    virtual double calc(Sale& s) = 0;
    virtual ~Discount() {}
};


class ItemDiscount : public Discount {
    
    int code, percentage;
    
public:
    ItemDiscount(const int& code,const int& percentage) : code{code}, percentage{percentage} {}
    
    double calc(Sale& s);
};


class SumDiscount : public Discount {
    
    vector<Discount*> discounts;
public:
    SumDiscount() {}
    
    void addDiscount(Discount* d);
    double calc(Sale& s);
};