#include "controller.h"
#include "exception.h"

Controller::Controller(Repository* repo) : repo{repo} {}

void Controller::report(const string &desc, const string &reporter){
    if ( desc == "")
        throw Exception("Description cannot be empty");
    Issue is(desc, "open", reporter, "None");
    this->repo->report(is);
}

void Controller::solveIssue(Issue &is, const string& name){
    if( is.getStatus() != "open"){
        throw Exception("Issues is currently closed");
    }
    repo->resolve(is.getDesc(), name);
}
