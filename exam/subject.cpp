#include "subject.h"

Subject::Subject()
{

}

void Subject::attachObserver(Observer *ob){
    obs.push_back(ob);
}

void Subject::notify(){
    for(auto it : obs)
        it->update();
}
