#ifndef GUI_H
#define GUI_H

#include"controller.h"
#include "observer.h"
#include <QWidget>

namespace Ui {
class GUI;
}

class GUI : public QWidget, public Observer
{
    Q_OBJECT

public:
    explicit GUI(Controller* ctr, User& user, QWidget *parent = 0);
    ~GUI();
    void update() {
        this->populateList();
    }

private:
    Ui::GUI *ui;
    Controller* ctr;
    User user;
    void populateList();
    void connectAll();
    int getIndex();

public slots:
    void reportIssue();
    void solveIssue();
    void removeIssue();

};

#endif // GUI_H
