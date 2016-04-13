//
//  main.cpp
//  Lab8-9
//
//  Created by Dehelean Andrei on 4/7/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#include <iostream>
#include "exception.hpp"
#include "UI.hpp"

int main(){
    
    try{
        Repository repo("store.txt");
        StoreFile* s = new StoreCSV();
        Controller contr(repo, s, Validator{});
        UI ui(contr);
        ui.run();
        delete s;
    }
    catch(FileException& err){
        cout<<"File could not be opened!"<<endl;
        return 1;
    }
    return 0;
}