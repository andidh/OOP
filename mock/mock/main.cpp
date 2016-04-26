//
//  main.cpp
//  mock
//
//  Created by Dehelean Andrei on 4/26/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#include <iostream>
#include "UI.hpp"

int main() {
    
    Repository repo;
    Controller contr(repo);
    
    UI ui(contr);
    ui.run();
    
    
    return 0;
}
