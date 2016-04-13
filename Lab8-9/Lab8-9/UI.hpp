//
//  UI.hpp
//  Lab8-9
//
//  Created by Dehelean Andrei on 4/7/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#pragma once
#include "controller.hpp"


class UI {
    Controller contr;
    
public:
    UI(Controller& c) : contr{c} {}
    void run();
    
private:
    static void menu();
    static void menuAdmin();
    static void menuUser();
    
    //------ADMIN------
    void addRepo();
    void getAll();
    void remove();
    void update();
    
    
    //------USER--------
    void addStore();
    void start();
    void next();
    void buyCoat();
    void saveBasket();
};
