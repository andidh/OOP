#ifndef REPOSITORY_H
#define REPOSITORY_H
#include "subject.h"
#include <vector>
#include "programmer.h"
#include "source.h"
#include <algorithm>
#include <fstream>
#include <sstream>


class Repository : public Subject
{
    vector<Programmer> progs;
    vector<Source> files;
    string file;

public:
    Repository(const string& file);

    vector<Programmer> getProgs() { return this->progs; }
    vector<Source> getSourceFile() { return this->files; }
    /*
     * Function to add a source file
     * Input : s - object of type SourceFile
     * PostCondition: s is added to the list
     */
    void addFile(Source& s) {
        this->files.push_back(s);
        sortData();
        notify(); }

    /*
     * Function to remove a source file
     * Input : s - object of type SourceFile
     * Post condition: s is remove from the list
     */
    void removeFile(Source& s);

    /*
     * Function to revise a source file
     * Input : file - the name of the file
     *          name - the name of the reviewer
     * Post condition : Source file is revised
     */
    void reviseFile(const string& file, const string& name);
    ~Repository();

private:
    void loadFromFile();
    void writeToFile();
    void sortData();

};




#endif // REPOSITORY_H
