#pragma once
#include "repository.h"
#include "exception.h"

class Controller
{
public:
    Repository repo;

public:
    Controller(const Repository& repo);

    vector<Task> getTasks() { return repo.getTasks(); }
    vector<Programmer> getProgrammers() { return repo.getProgrammers(); }
    Programmer getProg(const int& id);
    void addTask(Task& t);
    void removeTask(Task& t);
    void startTask(Task& t, Programmer& p);
};


