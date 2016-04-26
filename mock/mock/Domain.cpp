//
//  Domain.cpp
//  mock
//
//  Created by Dehelean Andrei on 4/26/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#include "Domain.hpp"
#include <iostream>

bool BMI::isOk(){
    
    return this->value > 18.5 && this->value<25;
}

void BMI::toString(){
    Medical::toString();
    cout<<"BMI value is: "<<this->value<<endl;
}



bool BP::isOk(){
    
    return this->sist >90 && this->sist < 119 && this->diast > 60 && this->diast < 79;
}



void BP::toString(){
    Medical::toString();
    cout<<"Sist is "<<sist<<" | Diast is "<<diast<<endl;
}

