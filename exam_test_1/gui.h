#ifndef GUI_H
#define GUI_H
#include "controller.h"
#include "observer.h"
#include <QWidget>
#include <QtWidgets/QWidget>
#include <QListWidget>


namespace Ui {
class GUI;
}

class GUIi : public QWidget
{
    Q_OBJECT

public:
    explicit GUIi(Controller& ctr, Programmer& pr, QWidget *parent = 0);


private:
   // Ui::GUIClass ui;
    //int getSelectedItem();
    void populateList();
    //void connectAll();
    Controller ctr;
    Programmer pr;
    QListWidget* list;
    void setUP();
};

#endif // GUI_H
