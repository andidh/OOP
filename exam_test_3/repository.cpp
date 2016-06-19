#include "repository.h"
#include <fstream>
#include <sstream>
#include <algorithm>



Repository::Repository(const string& file) : file{file} { this->loadFromFile(); }

Repository::~Repository() {};

void Repository::report(Issue& is){
    for ( auto it : issues){
        if(it.getDesc() == is.getDesc())
            throw Exception("Issue already exists!");
    }
    this->issues.push_back(is);
    sortData();
    notify();
}


void Repository::resolve(const string &desc, const string &name){
    for( auto it=issues.begin(); it != issues.end(); it++){
        if ( (*it).getDesc() == desc ){
            (*it).setSolver(name);
        }
    }
    notify();
}

void Repository::removeIssue(Issue &is){
    issues.erase(remove(issues.begin(), issues.end(), is), issues.end());
    sortData();
    notify();
}


//------------------------------------------

void Repository::loadFromFile() {

    ifstream f(this->file);
    string line;
    while(getline(f, line)){
        stringstream ss(line);
        vector<string> tokens;
        string token;
        while(getline(ss, token,','))
            tokens.push_back(token);
        users.push_back(User(tokens[0], tokens[1]));
    }
    f.close();
    f.open("/Users/AndiD/Documents/C++/exam_test_3/issues.txt");
    while(getline(f,line)){
        stringstream ss(line);
        vector<string> tokens;
        string token;
        while(getline(ss, token, ','))
            tokens.push_back(token);
        issues.push_back(Issue(tokens[0], tokens[1], tokens[2], tokens[3]));
    }
    f.close();
    sortData();
}

void Repository::sortData() {
    sort(issues.begin(), issues.end(), [](const Issue& a, const Issue& b){
     return a.getStatus() < b.getStatus() || (a.getStatus() == b.getStatus() && a.getDesc() < b.getDesc());
    } );
}

