//
//  main.cpp
//  mockup
//
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#include <iostream>
#include "ui.hpp"

void testing(){
    testAddRepo();
    testFilter();
}

int main() {
    

    Repository repo;
    Controller contr(repo);
    UI ui(contr);
    
    
    ui.run();
    

    return 0;
}
