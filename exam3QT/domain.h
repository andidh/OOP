#pragma once
#include<string>
#include<vector>
#include<sstream>

using namespace std;

class Car
{
    string name, model, color;
    int year;

public:
    Car(const string& name, const string& model, const int& year, const string& color);

    string getName() const;
    string getModel() const;
    int getYear() const;
    string getColor() const;

    bool operator==(const Car& d);

    friend istream& operator>>(istream& is, Car& p);
    friend ostream& operator<<(ostream& os, const Car& p);


};

