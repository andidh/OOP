#include "widget.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Repository repo("/Users/AndiD/Documents/C++/exam_retake/tasks.txt");
    Controller contr(repo);
    vector <Widget *> windows;
    for (auto it : repo.getProgrammers()) {
            Widget * w = new Widget(contr, it);
            w->show();
            //repo.addObserver((Observer*)w);
            windows.push_back(w);
    }

//    Programmer p("Andi", 1);
//    Widget w(contr, p);
//    w.show();

    return a.exec();
}
