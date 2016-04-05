//
//  controller.cpp
//  L5-7
//
//  Created by Dehelean Andrei on 3/19/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#include "controller.hpp"

void Controller::addCoatToRepo(const string& size, const string& color, const float& price, const int& quantity, const string& link ){
    Coat c{ size, color, price, quantity, link};
    this->repo.addCoat(c);
}

void Controller::addCoatToStore(const Coat& item){
    this->store.add(item);
}

void Controller::addCoatToBasket( Coat& item){
    this->store.buyCoat(item);
}

void Controller::startStore(){
    this->store.show();
}
void Controller::nextCoat(){
    this->store.next();
}


void Controller::deleteCoat(string& link){
    this->repo.deleteCoat(link);
}


void Controller::update(const string& size, const string& color, const float& price, const int& quantity, const string& link){
    Coat ex{size, color, price, quantity, link};
    this->repo.update(ex);
}


Vector<Coat> Controller::getAllCoats(){
    return this->repo.getCoats();
}
Coat Controller::getCurrentCoat(){
    return this->store.getcurrentCoat();
}


