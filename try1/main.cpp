#include "mainwindow.h"
#include <QApplication>
#include <controller.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Repository repo("/Users/AndiD/Documents/C++/try1/store.txt");
    StoreFile *s;
    s = new StoreCSV("/Users/AndiD/Documents/C++/try1/csv.txt");
    Controller* ctrl;
    ctrl = new Controller(repo, s, Validator{});
    MainWindow w(ctrl);
    w.show();

    return a.exec();
}
