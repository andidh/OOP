//
//  UI.cpp
//  exam2
//


#include "UI.hpp"
#include <iostream>

void UI::menu() {
    cout<<"1 - Remove painting"<<endl;
    cout<<"2 - Show all"<<endl;
    cout<<"3 - Show painting from special storage"<<endl;
    cout<<"4 - Move painting"<<endl;
    cout<<"5 - Undo"<<endl;
    cout<<"0 - Exit"<<endl;
}


void UI::run() {
    
    while(true){
        this->menu();
        int cmd;
        cout<<"Enter an option: "; cin>> cmd;
        if(cmd == 0)
            break;
    
        switch(cmd) {
            
            case 1:
                this->remove();
                break;
            
            case 2:
                this->getAll();
                break;
                
            case 3:
                this->getSpecial();
                break;
            
            case 4:
                this->move();
                break;
                
            case 5:
                try{
                    this->contr.undoAction();
                    cout<<"Undo was successful!"<<endl;
                }
                catch(runtime_error& err){
                    cout<<err.what()<<endl;
                }
                break;
                
            default:
                cout<<"You entered a wrong option"<<endl;
                break;
        }
    
    }
}


void UI::remove(){
    string artist, title;
    int year;
    cout<<"Enter artist name: "; cin>>artist;
    cout<<"Enter title: "; cin>>title;
    cout<<"Enter year: "; cin>>year;
    try{
        this->contr.remove(artist, title, year);
        cout<<"--->> Painting successfully removed <<---"<<endl;
    }
    catch(runtime_error& r) {
        cout<<r.what()<<endl;
    }
}

void UI::getAll(){
    for( auto item : this->contr.getAll()){
        item.toString();
    }
}

void UI::getSpecial(){
    for( auto item : this->contr.getSpecial()){
        item.toString();
    }
}

void UI::move() {
    string artist, title;
    int year;
    cout<<"Enter artist name: "; cin>>artist;
    cout<<"Enter title: "; cin>>title;
    cout<<"Enter year: "; cin>>year;
    this->contr.movePainting(artist, title, year);
}

