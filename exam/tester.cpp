#include "tester.h"
#include "gui.h"
#include <cassert>

Tester::Tester()
{

}


void Tester::test1() {
    Repository* repo = new Repository("/Users/AndiD/Documents/C++/exam/prog.txt");
    Controller* ctr = new Controller(repo);

    assert(repo->getProgs().size() == 3);
    assert(repo->getSourceFile().size() == 5);
    Source s{"xml", "not_revised", "Andi","None"};
    repo->addFile(s);
    assert(repo->getSourceFile().size() == 6);
    assert(repo->getSourceFile()[5] == s);

    Source s1{"","not_revised","Mike","None"};
    try {
        ctr->addFile("","Andi");
        assert(false);
    }catch(Exception& ex){
        ;
    }

    repo->removeFile(s);
    assert(repo->getSourceFile().size()==5);
    Source s2{"dataText","not_revised","Ecaterina", "None"};
    repo->addFile(s2);
    try{
        ctr->revise(s2, "Ecaterina");
        assert(false);
    }catch(Exception& exc){
        ;
    }

    delete repo;
    delete ctr;


}



