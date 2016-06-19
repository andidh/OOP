#include "subject.h"

Subject::Subject()
{

}

void Subject::addObserver(Observer *obs){
    this->list.push_back(obs);
}

void Subject::notify(){
    for ( auto it : list){
        it->update();
    }
}
