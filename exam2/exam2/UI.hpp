//
//  UI.hpp
//  exam2
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