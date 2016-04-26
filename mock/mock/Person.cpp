//
//  Person.cpp
//  mock
//
//  Created by Dehelean Andrei on 4/26/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#include "Person.hpp"
#include <iostream>

void Person::addAnalysis(Medical *m) {
    this->list.push_back(m);
    if(m->isOk() == 1){
        cout<<"The analysis are OK!"<<endl;}
    else {
        cout<<"You are ill!"<<endl;

    }
}

