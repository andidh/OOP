//
//  Repository.cpp
//  exam2
//


#include "Repository.hpp"
#include <algorithm>


void Repository::addPainting(const Painting &p){
    this->list.push_back(p);
}

void Repository::removePainting(const Painting &p){
    bool found = false;
    for(auto item : this->list){
        if( item == p ){
            this->list.erase(remove(list.begin(), list.end(), item), list.end());
            found = true;
        }
    }
    
    if(!found)
        throw runtime_error("This paiting does not exists!\n");
    
};

vector<Painting> Repository::getAll() {
    return this->list;
}