//
//  console.hpp
//  L5-7
//
//  Created by Dehelean Andrei on 3/19/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#pragma once
#include "controller.hpp"

class UI
{
    Controller contr;
public:
    UI(const Controller& c) : contr(c) {}
    void run();

private:
    static void menu();
    static void RepoMenu();
    static void StoreMenu();
    
    void addCoatToRepo();
    void displayRepo();
    void addCoatToStore();
    
    
    void removeCoat();
    
    void updateCoat();
    
    void showStore();
    void buyCoat();
    void showNext();
    void showCost();
    void showBasket();
};






