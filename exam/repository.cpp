#include "repository.h"
#include <string>
#include <algorithm>

Repository::Repository(const string& file) : file{file}
{
    this->loadFromFile();
}

void Repository::removeFile(Source &s){
    this->files.erase(remove(files.begin(), files.end(), s), files.end());
    notify();
}


void Repository::reviseFile(const string& file,const string &name) {
    for(auto it = files.begin(); it != files.end(); it++) {
        if( (*it).getName() == file){
            (*it).changeStatus("revised");
            (*it).changeReviewer(name);
        }
    }
    notify();
}

Repository::~Repository() {
    this->writeToFile();
}

//------------------------------------------------


void Repository::loadFromFile() {
    ifstream f(file);
    string line;
    while(getline(f, line)){
        stringstream ss(line);
        vector<string> tokens;
        string token;
        while(getline(ss, token, ','))
            tokens.push_back(token);
        progs.push_back(Programmer(tokens[0], stoi(tokens[1])));
    }
    f.close();
    f.open("/Users/AndiD/Documents/C++/exam/source.txt");
    while(getline(f, line)){
        stringstream ss(line);
        vector<string> tokens;
        string token;
        while(getline(ss, token ,','))
            tokens.push_back(token);
        files.push_back(Source(tokens[0], tokens[1], tokens[2], tokens[3]));
    }
    f.close();
    this->sortData();
    notify();
}


void Repository::sortData() {
    sort(files.begin(), files.end(), [](const Source& a,const  Source& b){
        return a.getName() < b.getName();
    });
}

void Repository::writeToFile(){
    ofstream f("/Users/AndiD/Documents/C++/exam/source.txt");
    for(auto it : files)
        f<<it.getName()<<","<<it.getStatus()<<","<<it.getCreator()<<","<<it.getReviewer()<<"\n";
    f.close();
}


