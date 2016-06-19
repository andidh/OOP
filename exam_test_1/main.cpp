#include "gui.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Repository repo;
    Controller contr{repo};

    Programmer p("Andi", 0);
    GUIi window(contr, p);
     window.show();
    return a.exec();
}
