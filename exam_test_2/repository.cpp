#include "repository.h"
#include<algorithm>
#include<fstream>
#include<sstream>


Repository::Repository(string file) : file{file} { this->loadFromFile(); }

Repository::~Repository() {
    this->writeToFile();
}

void Repository::addQuestion(Question &q){
    this->quest.push_back(q);
    notify();
}

void Repository::removeQuestion(int &id){
    for(auto q: this->quest){
        if(q.getId() == id)
            quest.erase(remove(quest.begin(), quest.end(), q), quest.end());
    }
    notify();
}

//------------------------------------------------

void Repository::loadFromFile() {
    ifstream f("/Users/AndiD/Documents/C++/exam_test_2/questions.txt");
    string line;
    while(getline(f, line)){
        stringstream ss(line);
        vector<string> tokens;
        string token;
        while(getline(ss, token, ',')){
            tokens.push_back(token);
        }
        quest.push_back(Question(stoi(tokens[0]), tokens[1], tokens[2], stoi(tokens[3])));
    }
    f.close();
    f.open(this->file);
    while(getline(f, line)){
        stringstream ss(line);
        vector<string> tokens;
        string token;
        while(getline(ss, token, ',')){
            tokens.push_back(token);
        }
        part.push_back(Participant(tokens[0], stoi(tokens[1])));
    }
    f.close();
}



void Repository::writeToFile(){
    ofstream f("/Users/AndiD/Documents/C++/exam_test_2/questions.txt");
    for(auto it : this->quest)
        f<<it.toString()<<"\n";
    f.close();
}
