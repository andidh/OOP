#pragma once
#include "repository.h"
#include "validator.h"
#include "store.h"
#include "storeFile.h"
#include "storeCSV.h"


class Controller {
    Repository repo;
    StoreFile* store;
    Validator val;


public:

    //------constructor---------
    Controller(const Repository& r, StoreFile* s, Validator v) : repo {r}, store {s}, val {v} {}

    //--------ADMIN---------
    void addToRepo(const string& size, const string& color, const int& price, const int& quantity, const string& link);
    vector<Coat> getAll();
    void removeCoat(const string& link);
    void updateCoat(const string& size, const string& color, const int& price, const int& quantity, const string& link);



    //--------USER---------
    void addToStore(const string& size);
    void start();
    void next();
    void buyCoat(Coat& c);
    int showTotal();

    void saveToFile();
    void openStore();



    Store* getStore()  { return store; }


};
