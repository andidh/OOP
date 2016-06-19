#pragma once
#include <vector>
#include <string>

using namespace std;

class Issue
{
    string desc, status, reporter, solver;
public:
    Issue(const string& desc,const string& status, const string& reporter,const string&solver);
    string getDesc() const { return desc; }
    string getStatus() const { return status; }
    string getReporter() const { return reporter; }
    string getSolver() const { return solver; }
    void setStatus(const string& status);
    void setReporter(const string& reporter);
    void setSolver(const string& solver);
};

inline bool operator==(const Issue& a, const Issue& b){
    return a.getDesc() == b.getDesc();
}
