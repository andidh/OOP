#include "repository.h"
#include <algorithm>
#include <fstream>


Repository::Repository() { this->loadFromFile();
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

void Repository::loadFromFile(){


   ifstream f("Users/AndiD/Documents/C++/exam_test_1/progs.in");
//    Programmer p("", 0);
//    while(f>>p)
//        this->prog.push_back(p);
//    f.close();

//    ifstream f1("Users/AndiD/Documents/C++/exam_test_1/tasks.txt");
//    Task t("","", 0);
//    while(f1>>t)
//        this->task.push_back(t);
//    f1.close();

 //    getline(is, line);
 //    vector<string> tokens;
 //    stringstream ss(line);
 //    string token;

 //    while(getline(ss, token,'|'))
 //        tokens.push_back(token);

 //    t.desc = tokens[0];
 //    t.status = tokens[1];
 //    t.id = stoi(tokens[2]);ifstream fin("programmers.in");

    string line;
    while (getline(f, line)) {
        stringstream get(line);
        vector <string> all;
        string act;
        while(getline(get, act, '|')) {
            all.push_back(act);
        }
        prog.push_back(Programmer(all[0], stoi(all[1])));
    }
    f.close();
    f.open("Users/AndiD/Documents/C++/exam_test_1/tasks.txt");
    while (getline(f, line)) {
        stringstream get(line);
        vector <string> all;
        string act;
        while (getline(get, act, '|')) {
            all.push_back(act);
        }
        if (all.size() < 3)
            all.push_back("-1");
        task.push_back(Task(all[0], all[1], stoi(all[2])));
    }
   // sortData();

}

void Repository::writeToFile(){
//    ofstream file("Users/AndiD/Documents/C++/exam_test_1/tasks.txt");
//    for( auto t : this->task)
//            file<<t;
//    file.close();
}

void Repository::sortData() {

    sort(task.begin(), task.end(), [](Task& t1, Task& t2){
        return t1.getStatus() < t2.getStatus();
    });
}
