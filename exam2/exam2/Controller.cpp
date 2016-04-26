//
//  Controller.cpp
//  exam2
//
//  Created by Dehelean Andrei on 4/25/16.
//  Copyright © 2016 Dehelean Andrei. All rights reserved.
//

#include "Controller.hpp"


void Controller::remove(const string &artist, const string &title, const int &year) {
    Painting item{artist, title, year};
    this->repo.removePainting(item);
    
    this->undo.push_back(make_unique<UndoRemove>(this->repo, item));
}


void Controller::undoAction(){
    
    if(this->undo.empty())
        throw runtime_error("You cannot undo!\n");
    
    undo.back()->executeUndo();
    undo.pop_back();
}

void Controller::movePainting(const string &artist, const string &title, const int &year){
    
    Painting p{artist, title, year};
    this->repo.removePainting(p);
    
    this->special.addPainting(p);
    this->undo.push_back(make_unique<UndoMove>(this->repo, this->special));
}