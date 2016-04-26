//
//  controller.hpp
//  Lab8-9
//
//  Created by Dehelean Andrei on 4/7/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#pragma once
#include "repository.hpp"
#include "validator.hpp"
#include "store.hpp"
#include "storeFile.hpp"
#include "storeCSV.hpp"
#include "storeHTML.hpp"


class Controller {
    Repository repo;
    StoreFile* store;
    Validator val;
    
    
public:
    
    //------constructor---------
    Controller(const Repository& r, StoreFile* s, Validator v) : repo {r}, store {s}, val {v} {}
    
    //--------ADMIN---------
    void addToRepo(const string& size, const string& color, const float& price, const int& quantity, const string& link);
    vector<Coat> getAll();
    void removeCoat(const string& link);
    void updateCoat(const string& size, const string& color, const float& price, const int& quantity, const string& link);
    
    
    
    //--------USER---------
    void addToStore(const string& size);
    void start();
    void next();
    void buyCoat(Coat& c);
    float showTotal();
    
    void saveToFile();
    void openStore();
    
    
    
    Store* getStore()  { return store; }


};

