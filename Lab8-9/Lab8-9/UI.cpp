//
//  UI.cpp
//  Lab8-9
//
//  Created by Dehelean Andrei on 4/7/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#include "UI.hpp"
#include "exception.hpp"
#include "validator.hpp"


void UI::menu(){
    cout<<endl;
    cout<<"1 - Manage shop repository"<<endl;
    cout<<"2 - Visit store"<<endl;
    cout<<"0 - Exit"<<endl;
}

void UI::menuAdmin(){
    cout << "\t 1 - Add coat"<<endl;
    cout << "\t 2 - Show all coats"<<endl;
    cout << "\t 3 - Delete coat"<<endl;
    cout << "\t 4 - Update"<<endl;
    cout<< "\t 0 - Go back"<<endl;
}


void UI::menuUser(){
    cout<<"\t 1 - Show coats by size"<<endl;
    cout<<"\t 2 - Buy the coat"<<endl;
    cout<<"\t 3 - Next"<<endl;
    cout<<"\t 4 - Show total"<<endl;
    cout<<"\t 5 - Save basket"<<endl;
    cout<<"\t 6 - Show basket"<<endl;
    cout<<"\t 0 - Go back"<<endl;
    
}
//--------RUN------


void UI::run()
{
    while(true){
        this->menu();
        int cmd;
        cout<<"Enter command: ";
        cin>>cmd;
        if(cmd == 0)
            break;
        
        
        //-----admin-----
        if(cmd == 1){
            while(true){
                this->menuAdmin();
                int adminCmd;
                cout<<"Enter command: ";
                cin>>adminCmd;
                if(adminCmd == 0)
                    break;
                
                switch(adminCmd){
                    case 1:
                        this->addRepo();
                        break;
                        
                    case 2:
                        this->getAll();
                        break;
                        
                    case 3:
                        this->remove();
                        break;
                        
                    case 4:
                        this->update();
                        break;
                }
            }
            
        }
        
        if(cmd == 2){
            while(true){
                this->menuUser();
                int userCmd;
                cout<<"Enter command: ";
                cin>>userCmd;
                if(userCmd == 0)
                    break;
                
                switch(userCmd){
                    case 1:
                        this->addStore();
                        this->start();
                        break;
                        
                        
                    case 2:
                        this->buyCoat();
                        break;
                    case 3:
                        this->next();
                        break;
                        
                    case 4:
                        cout<<"Total is: "<<this->contr.showTotal() << endl;
                        break;
                        
                    case 5:
                        this->saveBasket();
                        break;
                        
                    case 6:
                        this->contr.openStore();
                        break;
                }
            }
        }
    }
    
}









//------ADMIN------

void UI::addRepo(){
    cout<<"Enter size: ";
    string size;
    cin>>size;
    cout<<"Enter color: ";
    string color;
    cin>>color;
    cout<<"Enter price: ";
    float price;
    cin>>price;
    cout<<"Enter quantity: ";
    int quantity;
    cin>>quantity;
    cout<<"Enter link: ";
    string link;
    cin>>link;
    
    try {
        this->contr.addToRepo(size, color, price, quantity, link);
        cout<<"--->> Coat succesfully added<<---"<<endl;
    }
    catch (CoatException& err) {
        for( auto msg : err.getErrors())
            cout<< msg<<endl;
    }
    catch(RepoException& err) {
        cout<<err.what()<<endl;
    }
}


void UI::getAll(){
    vector<Coat> all = this->contr.getAll();
    if(all.size() == 0)
    {
        cout<<"There are no coats available!"<<endl;
        return;
    }
    cout<<"----------------------------------"<<endl;
    for ( auto c : all)
        c.toString();
    cout<<"----------------------------------"<<endl;
}

void UI::remove(){
    string link;
    cout<<"Enter link: ";
    cin>>link;
    try{
        this->contr.removeCoat(link);
        cout<<"--->> Coat successfully removed <<---"<<endl;
    }
    catch(RepoException& err){
        cout<<err.what()<<endl;
    }
}

void UI::update(){
    cout<<"Enter size: ";
    string size;
    cin>>size;
    cout<<"Enter color: ";
    string color;
    cin>>color;
    cout<<"Enter price: ";
    float price;
    cin>>price;
    cout<<"Enter quantity: ";
    int quantity;
    cin>>quantity;
    cout<<"Enter link: ";
    string link;
    cin>>link;
    
    try {
        this->contr.updateCoat(size, color, price, quantity, link);
        cout<<"--->> Coat successfully updated<<---"<<endl;
    }
    catch (CoatException& err) {
        for( auto msg : err.getErrors())
            cout<< msg<<endl;
    }
    catch(RepoException& err) {
        cout<<err.what()<<endl;
    }

}

    
    //------USER--------
void UI::addStore(){
    string size;
    cout<<"Enter size: ";
    cin>>size;
        
    this->contr.addToStore(size);
}
    
void UI::start(){
    this->contr.start();
    Coat c = this->contr.getStore()->getCurrent();
    cout<<"----------------------------------"<<endl;
    c.toString();
    cout<<"----------------------------------"<<endl;
        
}

void UI::buyCoat(){
    Coat c = this->contr.getStore()->getCurrent();
    this->contr.buyCoat(c);
    cout<<"Item added to the basket!"<<endl;
}

void UI::next(){
    this->contr.next();
    Coat c = this->contr.getStore()->getCurrent();
    cout<<"----------------------------------"<<endl;
    c.toString();
    cout<<"----------------------------------"<<endl;
    
}

void UI::saveBasket(){
    /*
    string file;
    cout<<"Enter file name: ";
    cin>>file;
     */
    
    try{
        this->contr.saveToFile();
        if(this->contr.getStore() == nullptr){
            cout<<"Basket could not be opened!"<<endl;
            return;
        }
    }
    catch(FileException& err){
        cout<<err.what()<<endl;
    }
}
