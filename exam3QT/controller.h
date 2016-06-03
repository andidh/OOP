#pragma once
#include<repository.h>
#include<algorithm>

class Controller
{
    Repository repo;

public:
    Controller(const Repository& repo);

    vector<Car> getAll();

    /*
     Function which sorts the list based on the manufacturer
        Input : list - vector containing all the cars
        Output : vector - containing all the cars orderered by the manufacturer
     */
    vector<Car> sortByManuf();


    /*
     Function which shows the number of cars of a given manufacturer
        Input - name : string (the name of the manufacturer)
        Output - int : the number of cars
    */
    int countCars(const string& name);
};

