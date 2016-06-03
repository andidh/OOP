#include "repository.h"
#include<fstream>

Repository::Repository(const string& file) : file{file} { this->loadFromFile();}

vector<Car> Repository::getAll() { return this->list;}


void Repository::loadFromFile(){

    ifstream file(this->file);

    Car c("","",0,"");
    while(file>>c)
        this->list.push_back(c);
    file.close();

}
