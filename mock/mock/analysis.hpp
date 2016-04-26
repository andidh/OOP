//
//  analysis.hpp
//  mock
//
//  Created by Dehelean Andrei on 4/26/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#pragma once

#include <string>

using namespace std;

class Medical {
    
protected:
    string date;
    
   
    
public:
    Medical(const string& date) : date {date} {}
    virtual ~Medical() {}
   
    virtual string getDate() const { return this->date; }
    virtual void toString();
    virtual bool isOk() = 0;

};