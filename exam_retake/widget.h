#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "controller.h"
#include <QListWidget>
#include <QVBoxLayout>



class Widget : public QWidget, public Observer
{
    Q_OBJECT

public:
    explicit Widget(Controller& ctr, Programmer& pr, QWidget *parent = 0);
    QListWidget* list;
    QVBoxLayout* layout;
    void update() {
        this->populateList();
    }


private:
    Controller ctr;
    Programmer pr;
    void setUp();
    void populateList();
};

#endif // WIDGET_H
