//
//  UI.hpp
//  exam2
//
//  Created by Dehelean Andrei on 4/25/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#pragma once
#include "Controller.hpp"


class UI {
    Controller& contr;
    
public:
    UI(Controller& c) : contr(c) {}
    
    void remove();
    void move();
    void getAll();
    void getSpecial();
    void undo();
    void run();
    
private:
    static void menu();
};