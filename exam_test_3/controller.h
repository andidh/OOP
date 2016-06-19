#pragma once
#include "repository.h"

class Controller
{
    Repository* repo;

public:
    Controller(Repository* repo);
    void report(const string& desc, const string& reporter);
    vector<Issue> getIssues() { return repo->getIssues(); }
    void solveIssue(Issue& is, const string& name);
    void removeIssue(Issue& is) {
        if(is.getStatus() != "closed"){
            throw Exception("Issue is currently open");
            return;
        }
        return repo->removeIssue(is); }
};

