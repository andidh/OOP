#include "gui.h"
#include "ui_gui.h"
#include <QString>
#include <QWidget>
#include <QListWidget>
#include <QMessageBox>

GUI::GUI(Controller* ctr, User& us, QWidget *parent) : ctr{ctr}, user{us},
    QWidget(parent),
    ui(new Ui::GUI)
{
    ui->setupUi(this);
    QWidget::setWindowTitle(QString::fromStdString(us.getName() + " - " + us.getType()));
    this->populateList();
    this->connectAll();
}

GUI::~GUI()
{
    delete ui;
}

void GUI::connectAll() {
    QObject::connect(ui->addBtn, SIGNAL(clicked()), this, SLOT(reportIssue()));
    QObject::connect(ui->resolveBtn, SIGNAL(clicked()), this, SLOT(solveIssue()));
    QObject::connect(ui->removeBtn, SIGNAL(clicked()), this, SLOT(removeIssue()));
}

void GUI::populateList() {

    ui->list->clear();
    for( auto it : ctr->getIssues()){
        QString item = QString::fromStdString(it.getDesc() + " -" + it.getStatus() + " -" +  it.getReporter() + " -" + it.getSolver());
        ui->list->addItem(item);
    }
    ui->list->setCurrentRow(0);
}

void GUI::reportIssue() {
    if(this->user.getType() != "tester"){
        QMessageBox::critical(this, "ERROR", "You are not a tester!");
        return;
    }
    string reporter = this->user.getName();
    string descr = ui->descTest->text().toStdString();
    try {
        this->ctr->report(descr, reporter);
    }
    catch(Exception& ex){
        QMessageBox::critical(this, "ERROR", QString::fromStdString(ex.what()));
    }
}

int GUI::getIndex(){
    auto v = ui->list->selectedItems();
    return ui->list->row(v[0]);
}


void GUI::solveIssue() {
    if( this->user.getType() != "programmer"){
        QMessageBox::critical(this, "ERROR", "You are not a programmer!");
        return;
    }
    int idx = this->getIndex();
    Issue is = this->ctr->getIssues()[idx];
    try {
        ctr->solveIssue(is, this->user.getName());
    }
    catch(Exception& ex){
        QMessageBox::critical(this, "ERROR", QString::fromStdString(ex.what()));
    }
}

void GUI::removeIssue(){
    int idx = this->getIndex();
    Issue is = ctr->getIssues()[idx];
    try {
        ctr->removeIssue(is);
    }
    catch(Exception& ex){
        QMessageBox::critical(this, "ERROR", QString::fromStdString(ex.what()));
    }
}
