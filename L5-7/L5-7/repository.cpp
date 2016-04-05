//
//  repository.cpp
//  L5-7
//
//  Created by Dehelean Andrei on 3/19/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#include "repository.hpp"

Repository::Repository(){}

void Repository::addCoat(const Coat& item){
    this->coats.add(item);
    
}

int Repository::find(const string& link){
    for(int i=0; i<this->coats.getSize(); i++){
        if(this->coats.getAt(i).getLink() == link){
            return i;
        }
    }
    return -1;
}


void Repository::deleteCoat(const string& link){
    int pos = Repository::find(link);
    this->coats.remove(pos);
}

void Repository::update(const Coat& item){
    string link = item.getLink();
    for(int i=0; i<this->coats.getSize(); i++){
        if( this->coats.getAt(i).getLink() == link)
            this->coats.getAt(i) = item;
    }
}

