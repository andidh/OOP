//
//  controller.hpp
//  L5-7
//
//  Created by Dehelean Andrei on 3/19/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#pragma once
#include "repository.hpp"
#include <string>


class Controller{
    Repository repo;
    Store store;
    
public:
    //-----CONSTRUCTOR-------
    Controller(const Repository& r) : repo(r) { }
    
    //----GETTERS-------
    Repository getRepo() const { return repo;}
    Store getStore() const { return store; };
    
    void addCoatToRepo(const string& size, const string& color, const float& price, const int& quantity, const string& link );
    void addCoatToStore(const Coat& item);
    void addCoatToBasket( Coat& item);
    
    void deleteCoat(string& link);
    
    void update(const string& size, const string& color, const float& price, const int& quantity, const string& link);
    
    void startStore();
    void nextCoat();
    Vector<Coat> getAllCoats();
    Coat getCurrentCoat();
    
};


