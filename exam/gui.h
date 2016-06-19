#ifndef GUI_H
#define GUI_H

#include <QWidget>
#include "controller.h"
#include "observer.h"

namespace Ui {
class GUI;
}

class GUI : public QWidget, public Observer
{
    Q_OBJECT

public:
    explicit GUI(Controller* ctr, Programmer& p, QWidget *parent = 0);
    void update(){
        this->populateList();
    }

    ~GUI();

private:
    Ui::GUI *ui;
    Controller* ctr;
    Programmer p;
    void connectAll();
    void populateList();
    int getIndex();

public slots:
    void addSource();
    void removeSource();
    void reviseSource();

};

#endif // GUI_H
