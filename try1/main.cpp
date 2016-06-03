#include "mainwindow.h"
#include <QApplication>
#include <controller.h>
#include <QtWidgets>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Repository repo("/Users/AndiD/Documents/C++/try1/store.txt");
    StoreFile *s;
    /*
    QWidget* popup = new QWidget;
    QVBoxLayout* popLay = new QVBoxLayout(popup);
    QLabel* quest = new QLabel("Do you want a CSV or HTML store?");
    QLineEdit* answ = new QLineEdit();
    QPushButton* btn = new QPushButton("Ok");
    popLay->addWidget(quest);
    popLay->addWidget(answ);
    popLay->addWidget(btn);
    popup->show();
    string file = answ->text().toStdString();

    if( file == "csv")
        s = new StoreCSV("/Users/AndiD/Documents/C++/try1/csv.txt");
    */


    Controller* ctrl;
    s = new StoreCSV("/Users/AndiD/Documents/C++/try1/csv.txt");

    ctrl = new Controller(repo, s, Validator{});
    MainWindow w(ctrl);
    w.show();

    return a.exec();
}
