
#pragma once
#include "store.h"

class StoreFile : public Store {

protected:
    string filename;

public:
    StoreFile();
    StoreFile(const string& file);
    virtual ~StoreFile();

    void setFile(const string& file);
    virtual void display() const = 0 ;
    virtual void writeToFile() = 0;
};
