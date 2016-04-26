//
//  UI.cpp
//  mock
//
//  Created by Dehelean Andrei on 4/26/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#include "UI.hpp"
#include <iostream>
#include <exception>
#include <string>


void UI::menu() {
    cout<<"1 - Add analysis"<<endl;
    cout<<"2 - Get analysis for pacient"<<endl;
    cout<<"3 - Check if pacient is ill"<<endl;
    cout<<"0 - Exit"<<endl;
}



void UI::run(){
    
    while(true){
        this->menu();
        int cmd;
        cout<<"Enter command: "; cin>>cmd;
        if(cmd == 0)
            break;
        
        switch(cmd){
                
            case 1:
                try{
                    this->add();}
                catch(runtime_error& err){
                    cout<<err.what();
                }
                
                
                break;
                
                
            case 2:
        
                this->getAnalysis();
                
                break;
                
            case 3:
                this->isHealthy();
                break;
                
            default:
                cout<<"Wrong option!"<<endl;
                break;
        }
    }
}


void UI::add(){
    
    string cmd;
    cout<<"Enter type of analysis: ";
    cin>>cmd;
    
    if ( cmd == "BMI" ){
        
        string date;
        string name;
        cout<<"Enter name: "; cin>>name;
        cout<<"Enter date: ";cin>>date;
        if( date.size() != 10){
            throw runtime_error("Invalid data!\n");
        }
        double value;
        cout<<"Enter value: ";cin>>value;
        Medical* m = new BMI(date, value);
        if(this->contr.getPacient(name).getName() == "") {
            Person p{name};
            p.addAnalysis(m);
            this->contr.addPacient(p);}
        else {
            Person p = this->contr.getPacient(name);
            p.addAnalysis(m);
        }

    }
    
    else if (cmd == "BP") {
        string date;
        string name;
        cout<<"Enter name: "; cin>>name;
        cout<<"Enter date: ";cin>>date;
        if( date.size() != 10){
            throw runtime_error("Invalid data!\n");
        }
        int diast, sist;
        cout<<"Enter sist: ";cin>>sist;
        cout<<"Enter diast: ";cin>>diast;

        Medical* m = new BP(date, sist, diast);
        Person p{name};
        p.addAnalysis(m);
        this->contr.addPacient(p);

    } else {
        throw runtime_error("ERROR at adding\n");
    }
    
}



void UI::getAnalysis(){
    
    string name;
    cout<<"Enter name: ";cin>>name;
    vector<Medical*> m = this->contr.getAnalysis(name);
    for ( auto item : m){
        item->toString();
    }
}

void UI::isHealthy(){
    string name;
    int month;
    cout<<"Enter name: "; cin>>name;
    cout<<"Enter month: "; cin>>month;
    int n = this->contr.isHealthy(name, month);
    
    if(n == 0 )
        cout<<name<<" is ill"<<endl;
    else if(n == 1)
        cout<<name<<" is OK"<<endl;
    
    
}