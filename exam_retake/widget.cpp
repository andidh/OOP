#include "widget.h"
#include "ui_widget.h"
#include <string>
#include <QString>
#include <QtWidgets>
#include <QGridLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>

Widget::Widget(Controller& ctr, Programmer& pr, QWidget *parent) : ctr{ctr}, pr{pr},
    QWidget(parent)
{
    this->setUp();
    QWidget::setWindowTitle(QString::fromStdString(pr.getName()));
    populateList();
}


void Widget::setUp() {
    resize(400, 550);

    layout = new QVBoxLayout();
    this->setLayout(layout);

    list = new QListWidget();
    layout->addWidget(list);

}


void Widget::populateList() {
    this->list->clear();
    vector<Task> all = ctr.getTasks();
    for( auto t : all){
        QString item = QString::fromStdString(t.getDesc() + " - " + t.getStatus());
        this->list->addItem(item);
    }
    this->list->setCurrentRow(0);

}
