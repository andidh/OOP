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


MainWindow::MainWindow(Controller *ctrl, QWidget *parent) :
    QWidget(parent), ctrl(ctrl)

{
    this->setUp();
    this->connectSignals();
    this->getCoats();
}


MainWindow::~MainWindow() {}


void MainWindow::setUp() {

    resize(600, 500);

    hLayout = new QHBoxLayout();
    this->setLayout(hLayout);

    leftWid = new QWidget;
    hLayout->addWidget(leftWid);
    leftLay = new QVBoxLayout(leftWid);
    all = new QLabel("All Coats");
    leftLay->addWidget(all);
    allCoats = new QListWidget();
    leftLay->addWidget(allCoats);

    QWidget* formWid = new QWidget;
    QFormLayout* formLay = new QFormLayout(formWid);
    sizeText = new QLineEdit();
    colorText = new QLineEdit();
    priceText = new QLineEdit();
    quantText = new QLineEdit();
    linkText = new QLineEdit();
    formLay->addRow("&Size: ", sizeText);
    formLay->addRow("&Color: ", colorText);
    formLay->addRow("&Price: ", priceText);
    formLay->addRow("&Quantity: ", quantText);
    formLay->addRow("&Link: ", linkText);
    leftLay->addWidget(formWid);

    QWidget* btnWid = new QWidget();
    btnLay = new QHBoxLayout(btnWid);
    add = new QPushButton("Add");
    remove = new QPushButton("Remove");
    update = new QPushButton("Update");
    filter = new QPushButton("Filter");
    btnLay->addWidget(add);
    btnLay->addWidget(remove);
    btnLay->addWidget(update);
    btnLay->addWidget(filter);

    leftLay->addWidget(btnWid);

    rightWid = new QWidget;
    rightLay = new QVBoxLayout(rightWid);



}

void MainWindow::connectSignals() {
    QObject::connect(this->allCoats, SIGNAL(itemSelectionChanged()), this, SLOT(listItemChanged()));
    QObject::connect(this->add, SIGNAL(clicked()), this, SLOT(addCoat()));
    QObject::connect(this->remove, SIGNAL(clicked()), this, SLOT(removeCoat()));
    QObject::connect(this->update, SIGNAL(clicked()), this, SLOT(updateCoat()));
    QObject::connect(this->filter, SIGNAL(clicked()), this, SLOT(filterCoat()));

}





// SLOTS

void MainWindow::getCoats() {

    if(this->allCoats->count() > 0)
        this->allCoats->clear();

    for ( auto c : this->ctrl->getAll()){
        QString item = QString::fromStdString(c.getSize() + " - " + c.getColor() + " - " + to_string(c.getPrice()) + " - " + to_string(c.getQuantity()) + " - " + c.getLink());
        this->allCoats->addItem(item);
    }

    if(this->ctrl->getAll().size() > 0)
        this->allCoats->setCurrentRow(0);
}


int MainWindow::getSelectedItem(){

    if(this->allCoats->count() == 0)
        return -1;

    QModelIndexList index = this->allCoats->selectionModel()->selectedIndexes();
    if(index.size() == 0){
        sizeText->clear();
        colorText->clear();
        priceText->clear();
        quantText->clear();
        linkText->clear();
        return -1;
    }

    int idx = index.at(0).row();
    return idx;
}

void MainWindow::listItemChanged(){


    int idx = this->getSelectedItem();
    if(idx == -1)
        return;

    if(idx >= this->ctrl->getAll().size())
        return;

    vector<Coat> v = this->ctrl->getAll();
    Coat c = v.at(idx);


    sizeText->setText(QString::fromStdString(c.getSize()));
    colorText->setText(QString::fromStdString(c.getColor()));
    priceText->setText(QString::fromStdString(to_string(c.getPrice())));
    quantText->setText(QString::fromStdString(to_string(c.getQuantity())));
    linkText->setText(QString::fromStdString(c.getLink()));

}


void MainWindow::addCoat() {
    string size, color, link;
    int price;
    float quant;

    size = sizeText->text().toStdString();
    color = colorText->text().toStdString();
    price = priceText->text().toInt();
    quant = quantText->text().toFloat();
    link = linkText->text().toStdString();

    try {
        this->ctrl->addToRepo(size, color, price, quant, link);
        QMessageBox::information(this, "Info", "Coat added successfully");
        this->getCoats();
    }
    catch(RepoException& err){
        QMessageBox::critical(this,"ERROR", err.what());
    }
    catch(CoatException& err){
        for(auto msg : err.getErrors())
            QMessageBox::critical(this, "ERROR", QString::fromStdString(msg));
    }
}


void MainWindow::removeCoat(){

    int idx = this->getSelectedItem();
    Coat c = this->ctrl->getAll()[idx];
    string link = c.getLink();

    try {
        this->ctrl->removeCoat(link);
        QMessageBox::information(this, "Info", "Coat removed successfully");
        this->getCoats();

    } catch(RepoException& err){
        QMessageBox::critical(this,"ERROR", err.what());
    }
}

void MainWindow::updateCoat() {
    string size, color, link;
    int price;
    float quant;

    size = sizeText->text().toStdString();
    color = colorText->text().toStdString();
    price = priceText->text().toInt();
    quant = quantText->text().toFloat();
    link = linkText->text().toStdString();


    try {
        this->ctrl->updateCoat(size, color, price, quant, link);
        QMessageBox::information(this, "Info", "Coat updated successfully");
        this->getCoats();
    } catch(RepoException& err){
        QMessageBox::critical(this,"ERROR", err.what());
    }
    catch(CoatException& err){
        for(auto msg : err.getErrors())
            QMessageBox::critical(this, "ERROR", QString::fromStdString(msg));
    }

}


void MainWindow::filterCoat() {

    QWidget* filtering = new QWidget;
    QHBoxLayout* filterLay = new QHBoxLayout(filtering);
    QFormLayout* size = new QFormLayout;
    filterEdit = new QLineEdit;
    size->addRow("Size: ", filterEdit);
    QPushButton* go = new QPushButton("Go");
    filterLay->addLayout(size);
    filterLay->addWidget(go);
    leftLay->addWidget(filtering);
    leftLay->addStretch();

    connect(go, SIGNAL(clicked()), this, SLOT(addToStore()));

}


void MainWindow::rightInit(){

    resize(900,500);
    // generating Right side
    store = new QListWidget();
    rightLay->addWidget(store);
    hLayout->addWidget(rightWid);

    QWidget* storeBtn = new QWidget;
    QHBoxLayout* strBtnLay = new QHBoxLayout(storeBtn);

    showCoat = new QPushButton("Show");
    nextBtn = new QPushButton("Next");
    buyBtn = new QPushButton("Buy");
    strBtnLay->addWidget(showCoat);
    strBtnLay->addWidget(nextBtn);
    strBtnLay->addWidget(buyBtn);
    rightLay->addWidget(storeBtn);

    QWidget* storeBtn2 = new QWidget;
    QHBoxLayout* strBtnLay2 = new QHBoxLayout(storeBtn2);
    total = new QPushButton("Show Total");
    strBtnLay2->addWidget(total);
    rightLay->addWidget(storeBtn2);
}

void MainWindow::rightConnect() {
    QObject::connect(this->showCoat, SIGNAL(clicked()), this, SLOT(shw()));
    QObject::connect(this->nextBtn, SIGNAL(clicked()), this, SLOT(next()));
    QObject::connect(this->buyBtn, SIGNAL(clicked()), this, SLOT(buy()));
    QObject::connect(this->total, SIGNAL(clicked()), this, SLOT(showTotal()));
}

void MainWindow::addToStore() {


    this->rightInit();
    this->rightConnect();

    //Adding elements to the List


    string size = filterEdit->text().toStdString();
    this->ctrl->addToStore(size);
    this->ctrl->start();
    Coat c = this->ctrl->getStore()->getCurrent();
    QString item = QString::fromStdString( c.getColor() + " - " + to_string(c.getPrice()) +  " - " + c.getLink());
    this->store->addItem(item);

}


void MainWindow::shw() {

    Coat c = this->ctrl->getStore()->getCurrent();
    c.show();
}

void MainWindow::next(){
    this->ctrl->next();
    if(this->store->count() > 0)
        this->store->clear();
    Coat c = this->ctrl->getStore()->getCurrent();
    QString item = QString::fromStdString( c.getColor() + " - " + to_string(c.getPrice()) +  " - " + c.getLink());
    this->store->addItem(item);

}


void MainWindow::buy() {
    Coat c = this->ctrl->getStore()->getCurrent();
    this->ctrl->buyCoat(c);
    QMessageBox::information(this, "Info", "Coat was added to basket!");
}

void MainWindow::showTotal(){

    QString total = QString::fromStdString(to_string(this->ctrl->showTotal()));
    QMessageBox::information(this, "Info", "Total is: "+ total);


}
