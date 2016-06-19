#include "programmer.h"
#include<istream>

Programmer::Programmer(const string& name, const int& id) : name{name}, id{id} {}


//istream& operator>> (istream& is, Programmer& p){
//    string line;

//    getline(is, line);

//    vector<string> tokens;
//    stringstream ss(line);
//    string token;

//    while(getline(ss, token, '|'))
//        tokens.push_back(token);

//    p.name = tokens[0];
//    p.id = stoi(tokens[1]);

//    return is;

//}

//ostream& operator<< (ostream& os, Programmer& p){
//    os << p.name<<"|"<<p.id<<"|"<<"\n";
//    return os;

//}
