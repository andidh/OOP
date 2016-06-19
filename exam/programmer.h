#ifndef PROGRAMMER_H
#define PROGRAMMER_H
#include <vector>
#include <string>

using namespace std;

class Programmer
{
   string name;
   int files;
public:
    Programmer(const string& name, const int& files);
    string getName() const { return this->name; }
    int getNoFiles() const { return this->files; }
    void incFiles() { this->files++; }

};

#endif // PROGRAMMER_H
