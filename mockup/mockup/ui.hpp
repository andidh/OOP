//
//  ui.hpp
//  mockup
//
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#pragma once 
#include "controller.hpp"


class UI{
    Controller contr;
    
public:
    UI(Controller& c) : contr(c) {}
    void run();
    
private:
    static void menu();
    
    void addFruit();
    void deleteFruit();
    void getAll();
    void filter();
    
};