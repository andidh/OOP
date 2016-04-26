//
//  Controller.cpp
//  mock
//
//  Created by Dehelean Andrei on 4/26/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#include "Controller.hpp"


void Controller::addPacient(Person &p){
    this->repo.addAnalysis(p);
}


Person Controller::getPacient(const string &name){
    return this->repo.getPerson(name);
}

vector<Medical*> Controller::getAnalysis(const string &name){
    return this->repo.getAnalysis(name);
}

int Controller::isHealthy(const string &name, const int &month){
    vector<Medical*> m = this->getAnalysis(name);
    for( auto item : m){
        if( stoi(item->getDate().substr(5,2)) == month){
            if(item->isOk() == 0)
                return 0;
            else
                return 1;
        }
    }
    return -1;
}