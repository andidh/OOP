#pragma once
#include<string>
#include<iostream>
#include<sstream>
#include<vector>

using namespace std;

class Task
{
    string desc, status;
    int id;

public:
    Task(const string& desc, const string& status, const int& id);

    string getDesc() const { return desc; }
    string getStatus() const { return status; }
    int getTaskId() const { return id; }
    void setStatus(const string& newStatus);
    void setId(const int& newID);


};

inline bool operator ==(const Task& t1, const Task& t2){
    return t1.getTaskId() == t2.getTaskId();
}
