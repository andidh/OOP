#pragma once
#include "issue.h"
#include "user.h"
#include "exception.h"
#include "subject.h"

class Repository : public Subject
{
    vector<Issue> issues;
    vector<User> users;
    string file;
public:
    Repository(const string& file);

    void report(Issue& is);
    vector<Issue> getIssues() { return this->issues; }
    vector<User> getUsers() { return this->users; }
    void resolve(const string& desc, const string& name);
    void removeIssue(Issue& is);
    ~Repository();

private:
    void loadFromFile();
    void writeToFile();
    void sortData();
};

