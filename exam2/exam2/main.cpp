//
//  main.cpp
//  exam2
//


#include <iostream>
#include "UI.hpp"


int main(){
    
    Repository repo;
    Painting a{"Andi", "Flori", 2010};
    Painting b{"Van Gogh", "The weird", 1970};
    
    repo.addPainting(a);
    repo.addPainting(b);
    
    Repository special;
    
    Controller contr(repo, special);
    UI ui(contr);
    
    ui.run();
    
    
    return 0;
}
