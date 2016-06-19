#include "controller.h"

Controller::Controller(Repository* repo) : repo{repo}
{

}



void Controller::addFile(const string &fileName, const string &creator) {
    if(fileName == "")
        throw Exception("Please input the name of the file!");
    for ( auto it : this->getSourceFiles()){
        if ( it.getName() == fileName)
            throw Exception("This file is already added!");
    }

    Source s{fileName, "not_revised", creator, "None"};
    this->repo->addFile(s);
}

void Controller::revise(Source &s, const string& name) {
    if( s.getStatus() != "not_revised"){
        throw Exception("This file cannot be revised!");
    }
    if( s.getCreator() == name)
        throw Exception("You are not allowed to revise this file!");

    string fileName = s.getName();
    repo->reviseFile(fileName, name);
}
