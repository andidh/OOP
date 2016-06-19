#include "gui.h"
#include <QString>
#include "ui_gui.h"
#include <QMessageBox>

GUI::GUI(Controller* ctr, Programmer& p, QWidget *parent) : ctr{ctr}, p{p},
    QWidget(parent),
    ui(new Ui::GUI)
{
    ui->setupUi(this);
    QWidget::setWindowTitle(QString::fromStdString(p.getName()));
    this->populateList();
    this->connectAll();
    ui->countLabel->setText(QString::fromStdString(to_string(p.getNoFiles())));
}

GUI::~GUI()
{
    delete ui;
}


void GUI::connectAll() {
    connect(ui->addButton, SIGNAL(clicked()), this, SLOT(addSource()));
    connect(ui->removeButton, SIGNAL(clicked()), this, SLOT(removeSource()));
    connect(ui->reviseButton, SIGNAL(clicked()), this, SLOT(reviseSource()));
}


void GUI::populateList() {
    ui->list->clear();
    for ( auto it : ctr->getSourceFiles()){
        QString item = QString::fromStdString(it.getName() + " - " + it.getStatus() + " - " + it.getCreator() + " - " + it.getReviewer());
        ui->list->addItem(item);
    }
    ui->list->setCurrentRow(0);
}



int GUI::getIndex() {
    auto v = ui->list->selectedItems();
    return ui->list->row(v[0]);
}


void GUI::addSource() {
    string fileName = ui->fileLine->text().toStdString();
    string creator = p.getName();
    try {
        ctr->addFile(fileName, creator);
    }
    catch(Exception& exc){
        QMessageBox::critical(this, "ERROR", QString::fromStdString(exc.what()));
    }
    ui->fileLine->clear();
}

void GUI::removeSource() {
    int idx = this->getIndex();
    Source s = ctr->getSourceFiles()[idx];
    try {
        ctr->removeFile(s);
    }
    catch(Exception& exc){
        QMessageBox::critical(this, "ERROR", QString::fromStdString(exc.what()));
    }
}


void GUI::reviseSource() {
    int idx = this->getIndex();
    Source s = ctr->getSourceFiles()[idx];
    string name = p.getName();
    try{
        ctr->revise(s,name);
        p.incFiles();
    }
    catch(Exception& exc){
        QMessageBox::critical(this, "ERROR", QString::fromStdString(exc.what()));
    }
    ui->countLabel->setText(QString::fromStdString(to_string(p.getNoFiles())));

}





