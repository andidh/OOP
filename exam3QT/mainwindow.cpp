#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <QString>
#include <QtWidgets>
#include <QGridLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>


MainWindow::MainWindow(Controller& contr, QWidget *parent) :  contr{contr},
    QWidget(parent)
{
    this->setUp();
    this->connectSignalSlot();
    this->populateList();
}

void MainWindow::connectSignalSlot() {
    QObject::connect(this->all, SIGNAL(itemSelectionChanged()), this, SLOT(listItemChanged()));
    QObject::connect(this->sortBtn, SIGNAL(clicked()), this, SLOT(sortByManufact()));
    QObject::connect(this->filterBtn, SIGNAL(clicked()), this, SLOT(showCount()));
}

void MainWindow::setUp() {
    resize(400, 550);

    layout = new QVBoxLayout();
    this->setLayout(layout);

    all = new QListWidget();
    layout->addWidget(all);

    QWidget* formWid = new QWidget;
    QFormLayout* formLay = new QFormLayout(formWid);
    nameLine = new QLineEdit();
    modelLine = new QLineEdit();
    yearLine  = new QLineEdit();
    colorLine = new QLineEdit();
    formLay->addRow("Manufacturer: ", nameLine);
    formLay->addRow("Model: ", modelLine);
    formLay->addRow("Year: ", yearLine);
    formLay->addRow("Color: ", colorLine);
    layout->addWidget(formWid);

    QWidget* btnWid = new QWidget();
    QHBoxLayout* btnLay = new QHBoxLayout(btnWid);
    sortBtn = new QPushButton("Sort");
    filterBtn = new QPushButton("Show cars");
    btnLay->addWidget(sortBtn);
    btnLay->addWidget(filterBtn);
    layout->addWidget(btnWid);
}

void MainWindow::populateList() {
    if(this->all->count() > 0)
            this->all->clear();

    vector<Car> list = this->contr.getAll();
    for ( auto c : list){
        QString item = QString::fromStdString(c.getName() + " - " +  c.getModel());
        this->all->addItem(item);
    }

    if(list.size() > 0) {
        this->all->setCurrentRow(0);
    }
}

int MainWindow::getSelectedElement() {

    if(this->all->count() == 0)
        return -1;

    QModelIndexList index = this->all->selectionModel()->selectedIndexes();
    if(index.size() == 0){
        nameLine->clear();
        modelLine->clear();
        yearLine->clear();
        colorLine->clear();
        return -1;
    }

    int idx = index.at(0).row();
    return idx;
}

void MainWindow::listItemChanged(){

    int idx = this->getSelectedElement();
    if(idx == -1) return;

    vector<Car> list = this->contr.getAll();
    Car c = list.at(idx);

    nameLine->setText(QString::fromStdString(c.getName()));
    modelLine->setText(QString::fromStdString(c.getModel()));
    yearLine->setText(QString::fromStdString(to_string(c.getYear())));
    colorLine->setText(QString::fromStdString(c.getColor()));

}


void MainWindow::sortByManufact() {

    if(this->all->count() > 0)
        this->all->clear();

    vector<Car> sorted = this->contr.sortByManuf();

    for ( auto c : sorted){
        QString item = QString::fromStdString(c.getName() + " - " +  c.getModel());
        this->all->addItem(item);
    }

    if(sorted.size() > 0) {
        this->all->setCurrentRow(0);
    }

}


void MainWindow::showCount() {

    QWidget* countWid = new QWidget;
    QHBoxLayout* countLay = new QHBoxLayout(countWid);
    QFormLayout* countForm = new QFormLayout();
    nameField = new QLineEdit();
    countForm->addRow("Manufacturer", nameField);
    QPushButton* go = new QPushButton("Go");
    countLay->addLayout(countForm);
    countLay->addWidget(go);
    layout->addWidget(countWid);

    QObject::connect(go, SIGNAL(clicked()), this, SLOT(getCount()));
}

void MainWindow::getCount() {

    string manuf = nameField->text().toStdString();
    QString count = QString::fromStdString(to_string(this->contr.countCars(manuf)));
    QMessageBox::information(this, "INFO", "Number of cars: "+ count);
}

