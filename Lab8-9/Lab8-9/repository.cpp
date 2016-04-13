//
//  repository.cpp
//  Lab8-9
//
//  Created by Dehelean Andrei on 4/7/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#include "repository.hpp"
#include "exception.hpp"
#include <fstream>
#include <algorithm>



Repository::Repository( const string& filename){
    this->file = filename;
    this->readFromFile();
}

void Repository::addCoat(const Coat& c){
    if( this->findByLink(c.getLink()).getSize() != "" ){
        throw RepoException("The coat already exists!");
    }
    this->list.push_back(c);
    this->writeToFile();
}


Coat Repository::findByLink(const string& link){
    for( auto c : this->list){
        if ( c.getLink() == link)
            return c;
    }
    return Coat{};
}


void Repository::removeCoat(const string& link){
    if(this->findByLink(link).getSize() == ""){
        throw RepoException("There is no such coat!");
    }
    Coat c = this->findByLink(link);
    list.erase(remove(list.begin(), list.end(), c), list.end());
    this->writeToFile();
}


void Repository::update(const Coat& c){
    if(this->findByLink(c.getLink()).getSize() =="")
        throw RepoException("There is no such coat!");
    string link = c.getLink();
    for(int i=0; i<this->list.size(); i++){
        if( list[i].getLink() == link)
            list[i] = c;
    }
    this->writeToFile();
}





//------FILE METHODS-------------

void Repository::readFromFile(){
    
    
    ifstream file(this->file);

    
    if(!file.is_open())
        throw FileException("This file could not be opened");

    Coat c;
    while(file>>c)
        this->list.push_back(c);
    file.close();
    
}


void Repository::writeToFile(){
    
    
    ofstream file(this->file);
    
   
    if ( !file.is_open())
        throw FileException("This file could not be opened");
    
    for ( auto c: list)
        file <<c;
    
    file.close();
}