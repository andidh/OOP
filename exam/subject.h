#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
#include "observer.h"

using namespace std;

class Subject
{
    vector<Observer*> obs;
public:
    Subject();
    void attachObserver(Observer* ob);
    void notify();
};

#endif // SUBJECT_H
