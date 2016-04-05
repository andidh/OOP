//
//  ui.cpp
//  mockup
//
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#include "ui.hpp"
#include <iostream>



void UI::menu(){
    cout<<"1. Show all\n";
    cout<<"2. Add Fruit\n";
    cout<<"3. Delete Fruit\n";
    cout<<"4. Filter\n";
    cout<<"0. Exit\n";
}

void UI::addFruit(){
    string name;
    cout<<"Give name: ";
    cin>>name;
    string nutri;
    cout<<"Give nutrition benefits: ";
    cin>>nutri;
    float quantity;
    cout<<"Give quantity: ";
    cin>>quantity;
    cout<<"----------------------"<<endl;

    this->contr.contr_addFruit(name, nutri, quantity);
    cout<<"----------------------"<<endl;
}

void UI::deleteFruit(){
    string name;
    cout<<"Give name: ";
    cin>>name;
    cout<<"----------------------"<<endl;
    this->contr.contr_deleteFruit(name);
    cout<<"----------------------"<<endl;

}

void UI::getAll(){
    cout<<"----------------------"<<endl;
    for(auto f : this->contr.getAll()){
        cout<<f.getName()<<"|"<<f.getNutri()<<"|"<<f.getQuantity()<<endl;
    }
    cout<<"----------------------"<<endl;

}

void UI::filter(){
    string nutri;
    cout<<"Enter nutrition benefits: ";
    cin>> nutri;
    cout<<"----------------------"<<endl;
    for( auto f : this->contr.filterByBenefit(nutri)){
        cout<<f.getName()<<"|"<<f.getNutri()<<"|"<<f.getQuantity()<<endl;
    }
    cout<<"----------------------"<<endl;

}

void UI::run(){
    
    while(true){
        UI::menu();
        int cmd;
        cout<<"Enter command: ";
        cin>>cmd;
        if (cmd == 0)
            break;
        switch (cmd) {
                
            case 1:
                UI::getAll();
                break;
                
            case 2:
                UI::addFruit();
                break;
                
            case 3:
                UI::deleteFruit();
                break;
                
            case 4:
                UI::filter();
                break;
                
            default:
                cout<<"You entered a wrong command";
                break;
        }
        
    }
    
}
