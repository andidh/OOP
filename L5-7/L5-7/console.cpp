//
//  console.cpp
//  L5-7
//
//  Created by Dehelean Andrei on 3/19/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#include "console.hpp"
#include <string>
#include<iostream>

using namespace std;



void UI::menu(){
    cout<<endl;
    cout<<"1 - Manage shop repository"<<endl;
    cout<<"2 - Visit store"<<endl;
    cout<<"0 - Exit"<<endl;
    
}

void UI::RepoMenu(){
    cout << "\t 1 - Add coat"<<endl;
    cout << "\t 2 - Show all coats"<<endl;
    cout << "\t 3 - Delete coat"<<endl;
    cout << "\t 4 - Update"<<endl;
    cout<< "\t 0 - Go back"<<endl;
    
}


void UI::StoreMenu(){
    cout<<"\t 1 - Show coats by size"<<endl;
    cout<<"\t 2 - Buy the coat"<<endl;
    cout<<"\t 3 - Next"<<endl;
    cout<<"\t 4 - Show total"<<endl;
    cout<<"\t 5 - Show basket"<<endl;
    cout<<"\t 0 - Go back"<<endl;
}

void UI::addCoatToRepo(){
    cout<<"Enter size: ";
    string size;
    cin>>size;
    cout<<"Enter color: ";
    string color;
    cin>>color;
    cout<<"Enter price ";
    float price;
    cin>>price;
    cout<<"Enter quantity: ";
    int quantity;
    cin>>quantity;
    cout<<"Enter link: ";
    string link;
    cin>>link;
    this->contr.addCoatToRepo(size, color, price, quantity, link);
    
}

void UI::displayRepo(){
    Vector<Coat> v = this->contr.getAllCoats();
    Coat* coats = v.getAll();
    if (coats == NULL)
        return;
    if (v.getSize() == 0){
        cout<<"There are no coats available."<<endl;
        return;
    }
    for (int i=0; i<v.getSize(); i++){
        Coat c = coats[i];
        cout<< c.getSize()<<" | "<<c.getColor()<< " | " <<c.getPrice()<< " | " << c.getQuantity() << " | " << c.getLink() <<endl;
    }
}


void UI::addCoatToStore(){
    cout<<"Enter size: ";
    string size;
    cin>>size;
    Vector<Coat> v = this->contr.getAllCoats();
    Coat* coats = v.getAll();
    for (int i=0; i<v.getSize(); i++){
        Coat c = coats[i];
        if ( c.getSize() == size)
            this->contr.addCoatToStore(c);
    }
}


void UI::removeCoat(){
    string link;
    cout<<"Enter link: ";
    cin>>link;
    this->contr.deleteCoat(link);
}

void UI::updateCoat(){
    cout<<"Enter size: ";
    string size;
    cin>>size;
    cout<<"Enter color: ";
    string color;
    cin>>color;
    cout<<"Enter price ";
    float price;
    cin>>price;
    cout<<"Enter quantity: ";
    int quantity;
    cin>>quantity;
    cout<<"Enter link: ";
    string link;
    cin>>link;
    this->contr.update(size, color, price, quantity, link);
}


void UI::showStore(){
    this->contr.startStore();
    Coat c = this->contr.getCurrentCoat();
    cout<<"Size: "<<c.getSize()<<"| Color: "<<c.getColor()<< " | Price: " <<c.getPrice()<< " | Quantity: " << c.getQuantity() <<endl;
}

void UI::buyCoat(){
    Coat c = this->contr.getCurrentCoat();
    this->contr.addCoatToBasket(c);
    cout<<"Item added to basket!"<<endl;
}

void UI::showNext(){
    this -> contr.nextCoat();
    Coat c = this->contr.getCurrentCoat();
    cout<<"Size: "<<c.getSize()<<"| Color: "<<c.getColor()<< " | Price: " <<c.getPrice()<< " | Quantity: " << c.getQuantity() <<endl;
}

void UI::showCost(){
    cout <<"Total cost: "<< this->contr.getStore().getSum()<<endl;;
}

void UI::showBasket(){
    Vector<Coat> v = this->contr.getStore().getBasket();
    Coat* coats = v.getAll();
    for( int i=0; i<v.getSize(); i++){
        Coat c = coats[i];
        cout<<"Size: "<<c.getSize()<<"| Color: "<<c.getColor()<< " | Price: " <<c.getPrice()<< " | Quantity: " << c.getQuantity() <<endl;
    }
}


void UI::run()
{
    while (true)
    {
        UI::menu();
        int command{ 0 };
        cout << "Input the command: ";
        cin >> command;
        if (command == 0)
            break;
        
        // admin
        if (command == 1)
        {
            while (true)
            {
                UI::RepoMenu();
                int commandRepo{0};
                cout << "Input the command: ";
                cin >> commandRepo;
                if (commandRepo == 0)
                    break;
                switch (commandRepo)
                {
                    case 1:
                        this->addCoatToRepo();
                        break;
                    case 2:
                        this->displayRepo();
                        break;
                    case 3:
                        this->removeCoat();
                        break;
                        
                    case 4:
                        this->updateCoat();
                        break;
            
                }
            }
        }
        
        // user
        if (command == 2)
        {
            while (true)
            {
                UI::StoreMenu();
                int commandStore{0};
                cout << "Input the command: ";
                cin >> commandStore;
                if (commandStore == 0)
                    break;
                switch (commandStore)
                {
                    case 1:
                        this->addCoatToStore();
                        this->showStore();
                        break;
                        
                    case 2:
                        this->buyCoat();
                        break;
                        
                    case 3:
                        this->showNext();
                        break;
                        
                    case 4:
                        this->showCost();
                        break;
                    
                    case 5:
                        this->showBasket();
                        break;
                        
                }
            }
        }
    }
}
