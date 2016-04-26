//
//  Domain.hpp
//  mock
//
//  Created by Dehelean Andrei on 4/26/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#pragma once
#include "analysis.hpp"




class BMI : public Medical {
    
    double value;
    
public:
    
    BMI(const string& date, const double& value) : Medical{date}, value{value} {}
    
    bool isOk() override;
    
    void toString() override ;
    
};



class BP : public Medical {
    
    int sist, diast;
    
public:
    
    BP(const string& date, const int& sist, const int& diast) : Medical{date}, sist{sist}, diast{diast} {}
    bool isOk() override;
    void toString() override;
};