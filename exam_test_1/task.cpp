#include "task.h"
#include<istream>
#include <string>
#include<cstdlib>


Task::Task(const string& desc, const string& status, const int& id) : desc{desc}, status{status}, id{id} {}

void Task::setStatus(const string& newStatus) {
    this->status = newStatus;
}

void Task::setId(const int &newID) {
    this->id = newID;
}

//istream& operator>> (istream& is, Task& t){
//    string line;
//    getline(is, line);
//    vector<string> tokens;
//    stringstream ss(line);
//    string token;

//    while(getline(ss, token,'|'))
//        tokens.push_back(token);

//    t.desc = tokens[0];
//    t.status = tokens[1];
//    t.id = stoi(tokens[2]);

//    return is;
//}

//ostream& operator<< (ostream& os, Task& t){

//    os<<t.desc<<"|"<<t.status<<"|"<<t.id<<"|"<<"\n";
//    return os;
//}


