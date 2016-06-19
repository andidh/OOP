#include "gui.h"
#include "ui_gui.h"

GUIi::GUIi(Controller& ctr, Programmer& pr, QWidget *parent) : ctr{ctr}, pr{pr},
    QWidget(parent)
{
    setUP();
    QWidget::setWindowTitle(QString::fromStdString(pr.getName()));
   // connectAll();
    populateList();
}

void GUIi::setUP() {
    this->list = new QListWidget();
}

void GUIi::populateList() {
    this->list->clear();
    for( auto t : ctr.getTasks()){
        QString item = QString::fromStdString(t.getDesc() + " - " + t.getStatus());
        this->list->addItem(item);
    }
    this->list->setCurrentRow(0);
}
