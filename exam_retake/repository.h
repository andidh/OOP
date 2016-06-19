#pragma once
#include "programmer.h"
#include "task.h"
#include "subject.h"


class Repository : public Subject
{

    vector<Programmer> prog;
    vector<Task> task;

public:
    Repository(string file);
    ~Repository();

    void addTask(Task& t);
    void removeTask(const Task& t);
    void modifyTask(const int& oldID, const int& newID, const string& progress);

    vector<Task> getTasks() { return this->task; }
    vector<Programmer> getProgrammers() { return this->prog; }

private:

    void loadFromFile(string file);
    void writeToFile();
    void sortData();

};

