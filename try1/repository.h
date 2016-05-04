#pragma once
#include "domain.h"
#include <vector>

class Repository {
    vector<Coat> list;
    string file;

public:

    Repository( const string& filename);

    void addCoat(const Coat& c);
    void removeCoat(const string& link);
    void update(const Coat& c);



    vector<Coat> getAll();
    Coat findByLink(const string& link);


private:
    void readFromFile();
    void writeToFile();
};
