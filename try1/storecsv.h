#pragma once
#include "storeFile.h"


class StoreCSV : public StoreFile {

public:

    StoreCSV(const string& file);

    void display() const override ;

    void writeToFile() override;
};
