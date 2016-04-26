//
//  UI.hpp
//  mock
//
//  Created by Dehelean Andrei on 4/26/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#pragma once
#include "Controller.hpp"

class UI {
    
    Controller contr;
    
public:
    
    UI(Controller& contr) : contr{contr} {}
    void add();
    void getAnalysis();
    void isHealthy();
    void run();
    
private:
    static void menu();
};