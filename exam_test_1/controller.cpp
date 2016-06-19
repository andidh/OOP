#include "controller.h"

Controller::Controller(const Repository& repo) : repo{repo}
{

}

void Controller::addTask(Task& t){
    repo.addTask(t);
}

void Controller::removeTask(Task& t){
    repo.removeTask(t);
}


void Controller::startTask(Task &t, Programmer &p) {
    if(t.getStatus() != "open")
        throw Exception{"Task is not currently open"};
    int oldId=t.getTaskId();
    int newId= p.getId();
    this->repo.modifyTask(oldId, newId,"open");
}

Programmer Controller::getProg(const int &id){
    for( auto prog : this->getProgrammers()){
        if(prog.getId() == id)
            return prog;
    }
    return Programmer("", 0);
}
