//
//  Controller.hpp
//  exam2
//


#pragma once
#include "Repository.hpp"
#include "undo.hpp"
#include <memory>


class Controller {
    Repository repo;
    Repository special;
    vector<unique_ptr<Undo>> undo;
    
public:
    
    Controller(Repository& repo, Repository& special) : repo{repo}, special{special} {}
    Controller(const Controller& ctrl) = delete;		
    void operator=(const Controller& ctrl) = delete;
    
    void remove(const string& artist, const string& title, const int& year);
    void movePainting(const string& artist, const string& title, const int& year);
    
    vector<Painting> getAll() { return this->repo.getAll(); }
    vector<Painting> getSpecial() { return this->special.getAll(); }
    
    void undoAction();

};