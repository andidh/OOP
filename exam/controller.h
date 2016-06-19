#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "repository.h"
#include "exception.h"

class Controller
{
    Repository* repo;
public:
    Controller(Repository* repo);

    vector<Programmer> getProgrammers() { return repo->getProgs(); }
    vector<Source> getSourceFiles() { return repo->getSourceFile(); }
    /*
     * Function to add a source file
     * Input : fileName - the name of the Source file s
     *          creator - the name of the creator
     * Output : -
     * PostCondition: s is added to the list
     */
    void addFile(const string& fileName, const string& creator);

    /*
     * Function to remove a source file
     * Input : s - object of type SourceFile
     * Output : -
     * Post condition: s is remove from the list
     */
    void removeFile(Source& s) { this->repo->removeFile(s); }

    /*
     * Function to revise a source file
     * Input : file - the name of the file
     *          name - the name of the reviewer
     * Output : -
     * Post condition : Source file is revised
     */
    void revise(Source& s, const string& name);

};

#endif // CONTROLLER_H
