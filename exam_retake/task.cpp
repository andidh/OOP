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
