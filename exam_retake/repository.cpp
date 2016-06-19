#include "repository.h"
#include <algorithm>
#include <fstream>


Repository::Repository(string file) {
    this->loadFromFile(file);
}

Repository::~Repository() { this->writeToFile(); }

void Repository::addTask(Task &t){
    this->task.push_back(t);
    this->sortData();
    notify();
}

void Repository::removeTask(const Task& t){
    task.erase(remove(task.begin(), task.end(), t), task.end());
    sortData();
    notify();

}

void Repository::modifyTask(const int & oldID, const int& newID,  const string &progress) {
    for( auto it=task.begin(); it!= task.end(); it++){
        if( (*it).getTaskId() == oldID){
            (*it).setId(newID);
            (*it).setStatus(progress);
        }
    }
    sortData();
    notify();
}



//------------------------------

void Repository::loadFromFile(string file){


    ifstream f("/Users/AndiD/Documents/C++/exam_retake/progs.txt");
    string line;
    while (getline(f, line)) {
        stringstream ss(line);
        vector <string> tokens;
        string token;
        while(getline(ss, token, '|')) {
            tokens.push_back(token);
        }
        string name=tokens[0];
        int id = stoi(tokens[1]);
        Programmer p(name, id);
        prog.push_back(p);
    }
    f.close();

    f.open(file);
    while (getline(f, line)) {
        stringstream ss(line);
        vector <string> tokens;
        string token;
        while (getline(ss, token, '|')) {
            tokens.push_back(token);
        }
        if (tokens.size() < 3)
            tokens.push_back("-1");
        Task t(tokens[0], tokens[1], stoi(tokens[2]));
        task.push_back(t);
    }
    sortData();

}

void Repository::writeToFile(){
    ofstream file("Users/AndiD/Documents/C++/exam_retake/tasks.txt");
    for( auto t : this->task)
            file<<t.getDesc()<<"|"<< t.getStatus()<<"|"<<t.getTaskId()<<"\n";
    file.close();
}

void Repository::sortData() {

    sort(task.begin(), task.end(), [](Task& t1, Task& t2){
        return t1.getStatus() < t2.getStatus();
    });
}
