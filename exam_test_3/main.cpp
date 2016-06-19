#include "gui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Repository* repo = new Repository("/Users/AndiD/Documents/C++/exam_test_3/users.txt");
    Controller* ctr = new Controller(repo);
    vector<GUI*> windows;
    for( auto it : repo->getUsers()){
        GUI* wind = new GUI(ctr, it);
        wind->show();
        repo->addObserver((Observer*) wind);
        windows.push_back(wind);
    }

    return a.exec();
}
