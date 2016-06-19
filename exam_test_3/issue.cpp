#include "issue.h"

Issue::Issue(const string& desc,const string& status, const string& reporter,const string&solver) :
    desc{desc}, status{status}, reporter{reporter}, solver{solver} {}

void Issue::setStatus(const string& status) {
    this->status = status;
}

void Issue::setReporter(const string& reporter){
    this->reporter = reporter;
}

void Issue::setSolver(const string& solver){
    this->solver = solver;
}
