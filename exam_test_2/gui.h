#ifndef GUI_H
#define GUI_H

#include <QMainWindow>
#include "controller.h"
#include "exception.h"
#include "observer.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QListWidget>
#include <QPushButton>
#include <QMessageBox>
#include <sstream>



class GUI : public QWidget, public Observer
{
    Q_OBJECT

public:
    explicit GUI(Controller* ctr, Participant& p, QWidget *parent = 0);

    void update() override {
        this->populateList();
    }

    QVBoxLayout* layout;
    QListWidget* list;

    QLineEdit* answerLabel;
    QPushButton* answerBtn;
    QLabel* scoreLabel;

private:
    void setUp();
    Controller* ctr;
    Participant part;
    void populateList();
    int getIndex();
    void connectAll();

public slots:
    void answerQuestion();

};

#endif // GUI_H
