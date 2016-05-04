#include "storeCSV.h"
#include <fstream>
#include "exception.h"


StoreCSV::StoreCSV(const string& file) {
    this->filename = file;
}
void StoreCSV::display() const {
    string cmd = "open " + this->filename;
    system(cmd.c_str());
}

void StoreCSV::writeToFile() {
    ofstream f(this->filename);

    if(!f.is_open())
        throw FileException("This file could not be opened!");

    for ( auto c : this->basket)
        f << c;

    f.close();

}
