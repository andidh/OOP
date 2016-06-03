#include "controller.h"
#include<cassert>

Controller::Controller(const Repository& repo) : repo{repo} {}

vector<Car> Controller::getAll() { return this->repo.getAll(); }

vector<Car> Controller::sortByManuf() {

    vector<Car> all = this->getAll();
    sort(all.begin(), all.end(), [](const Car& a, const Car& b){
        return a.getName() < b.getName();
    });

    return all;
}


int Controller::countCars(const string& name) {

    int count = 0;
    vector<Car> all = this->getAll();
    for( auto c : all){
        if( c.getName() == name)
            count++;
    }

    return count;
}


void testShowNumbersOfCars(){
    Repository repo("/Users/AndiD/Documents/C++/exam3QT/data.txt");
    Controller contr(repo);
    int count1 = contr.countCars("Fiat");
    assert(count1 == 3);
    int count2 = contr.countCars("Mercedes");
    assert(count2 == 0);
    int count3 = contr.countCars("Audi");
    assert(count3 == 2);
}
