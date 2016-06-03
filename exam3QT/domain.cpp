#include "domain.h"

Car::Car(const string&name, const string& model, const int& year, const string& color) : name{name}, model{model}, year{year}, color{color} {}

string Car::getName() const { return this->name;}

string Car::getModel() const { return this->model;}

int Car::getYear() const { return this->year; }

string Car::getColor() const { return this->color; }

bool Car::operator==(const Car& c) {
    return this->model == c.getModel();
}

istream& operator>>(istream& is, Car& c) {
    string line;
    getline(is, line);

    vector<string> tokens;
    stringstream ss(line);
    string token;
    while(getline(ss, token, '|' ))
        tokens.push_back(token);
    if (tokens.size() != 4)
        return is;
    c.name = tokens[0];
    c.model = tokens[1];
    c.year = stoi(tokens[2]);
    c.color = tokens[3];

    return is;
}

ostream& operator<<(ostream& os, const Car& c){
    os << c.getName() << "|" << c.getModel() << "|" << c.getYear()<< "|" << c.getColor() << "\n";
    return os;
}
