#include "gui.h"
#include <QApplication>
#include "tester.h"
#include <cassert>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Tester t;
    t.test1();
    Repository* repo = new Repository("/Users/AndiD/Documents/C++/exam/prog.txt");
    Controller* ctr = new Controller(repo);
    vector<GUI*> widgets;

    for ( auto it : repo->getProgs()){
        GUI* window = new GUI(ctr, it);
        window->show();
        repo->attachObserver((Observer*) window);
        widgets.push_back(window);
    }

    int rez = a.exec();
    for( auto it : widgets ){
        delete it;
    }
    delete repo;
    delete ctr;
    return rez;
}
