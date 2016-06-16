#include "gui.h"
#include <QApplication>
#include "presenter.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Repository* repo = new Repository("/Users/AndiD/Documents/C++/exam_test_2/participants.txt");
    Controller* ctr = new Controller(repo);
    vector<GUI*> windows;
    Presenter pres(ctr);
    pres.show();
    for(auto it: repo->getParticipants()){
        GUI* w = new GUI(ctr, it);
        w->show();
        repo->addObserver((Observer* ) w);
        windows.push_back(w);
    }

    int res = a.exec();

    delete repo;
    delete ctr;
    for( auto it : windows){
        delete it;
    }

    return res;
}
