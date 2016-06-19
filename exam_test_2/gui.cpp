#include "gui.h"
#include "ui_gui.h"
#include <QFormLayout>
#include <QLineEdit>
#include <QHboxLayout>
#include <algorithm>

GUI::GUI(Controller* ctr, Participant& p, QWidget *parent) : ctr{ctr}, part{p},
    QWidget(parent)

{
    this->setUp();
    QWidget::setWindowTitle(QString::fromStdString(part.getName()));
    this->populateList();
    this->connectAll();
}


void GUI::setUp(){

    resize(400, 600);
    layout = new QVBoxLayout;
    this->setLayout(layout);

    list = new QListWidget();
    layout->addWidget(list);

    QWidget* formWid = new QWidget;
    QFormLayout* formLay = new QFormLayout(formWid);
    answerLabel = new QLineEdit();
    formLay->addRow("&Answer: ", answerLabel);
    layout->addWidget(formWid);

    QWidget* btnWid = new QWidget;
    QHBoxLayout* btnLay = new QHBoxLayout(btnWid);
    answerBtn = new QPushButton("Answer");
    scoreLabel = new QLabel;
    btnLay->addWidget(answerBtn);
    QLabel* line = new QLabel;
    line->setText("Score: ");
    btnLay->addWidget(line);
    btnLay->addWidget(scoreLabel);

    layout->addWidget(btnWid);

}

void GUI::connectAll() {
    QObject::connect(answerBtn, SIGNAL(clicked()), this, SLOT(answerQuestion()));
}

void GUI::populateList(){
    this->list->clear();

    for( auto q : ctr->getQuestionsParticipant()){
        QString item = QString::fromStdString(to_string(q.getId()) + " - " + q.getText() + " - " + to_string(q.getScore()));
        this->list->addItem(item);
    }

    this->list->setCurrentRow(0);
    scoreLabel->setText(QString::fromStdString(to_string(part.getScore())));
}

int GUI::getIndex() {

    auto v = list->selectedItems();
    return list->row(v[0]);
}


void GUI::answerQuestion(){
    int index = this->getIndex();
    string answ = answerLabel->text().toStdString();
    int res = this->ctr->answerQuestion(index, answ);
    if(res != -1){
        int oldScore = part.getScore();
        int newScore = oldScore +  res;
        part.setScore(newScore);
    }
    else{
        QMessageBox::critical(this,"ERROR", "Wrong answer");
    }
    scoreLabel->setText(QString::fromStdString(to_string(part.getScore())));
    answerLabel->clear();

}
