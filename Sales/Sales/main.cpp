//
//  main.cpp
//  Sales
//
//  Created by Dehelean Andrei on 6/16/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#include <iostream>
#include "classes.hpp"

int main(int argc, const char * argv[]) {
    
    SaleItem s1{001, 200};
    SaleItem s2{001, 150};
    SaleItem s3{002, 300};
    
    Sale s;
    s.addSale(s1);
    s.addSale(s2);
    s.addSale(s3);
    
    Discount* d1 = new ItemDiscount{001, 10};
    Discount* d2 = new ItemDiscount{002, 15};
    SumDiscount sum;
    sum.addDiscount(d1);
    sum.addDiscount(d2);
    
    double total = sum.calc(s);
    cout<<total<<endl;
    
    
    
   
    return 0;
}
