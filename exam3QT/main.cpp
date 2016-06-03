#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Repository repo("/Users/AndiD/Documents/C++/exam3QT/data.txt");
    Controller contr(repo);
    MainWindow w(contr);
    w.show();

    return a.exec();
}
