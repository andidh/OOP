#pragma once
#include "domain.h"
#include <vector>
#include <string>

using namespace std;


//--------Coat exc class-----------------
class CoatException {

    vector<string> errors;

public:
    CoatException(vector<string>& errors);
    vector<string> getErrors();
};




//---------Validator class----------------

class Validator{
public:

    static void validate(const Coat& c);
};
