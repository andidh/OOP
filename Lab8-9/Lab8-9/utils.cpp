//
//  utils.cpp
//  Lab8-9
//
//  Created by Dehelean Andrei on 4/7/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#include "utils.hpp"
#include <sstream>

vector<string> tokenize(const string& str, char delimiter){
    vector<string> result;
    stringstream ss(str);
    string token;
    while(getline(ss, token, delimiter))
        result.push_back(token);
    return result;
}




