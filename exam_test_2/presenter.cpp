#include "presenter.h"

Presenter::Presenter(Controller* ctr, QWidget *parent) : ctr{ctr}, QWidget(parent)
{
    this->setUp();
    QWidget::setWindowTitle("Presenter");
    this->populateList();
    this->connectAll();
}




void Presenter::setUp() {
    resize(400, 600);

    layout = new QVBoxLayout();
    this->setLayout(layout);

    list = new QListWidget;
    layout->addWidget(list);

    QWidget* formWid = new QWidget();
    QFormLayout* formLay = new QFormLayout(formWid);
    idText = new QLineEdit();
    questText = new QLineEdit();
    answText = new QLineEdit();
    scoreText = new QLineEdit();
    formLay->addRow("ID: ", idText);
    formLay->addRow("Question: ", questText);
    formLay->addRow("Answer: ", answText);
    formLay->addRow("Score: ", scoreText);
    layout->addWidget(formWid);

    QWidget* btnWid = new QWidget();
    QHBoxLayout* btnLay = new QHBoxLayout(btnWid);
    addBtn = new QPushButton("Add");
    removeBtn = new QPushButton("Remove");
    btnLay->addWidget(addBtn);
    btnLay->addWidget(removeBtn);
    layout->addWidget(btnWid);

}


void Presenter::connectAll(){

    QObject::connect(addBtn, SIGNAL(clicked()), this, SLOT(addQuestion()));
    QObject::connect(removeBtn, SIGNAL(clicked()), this, SLOT(removeQuestion()));

}

void Presenter::populateList(){
    this->list->clear();

    for(auto it : ctr->getQuestions()){
        QString item = QString::fromStdString(to_string(it.getId()) + " - " + it.getText() + " - " + it.getAnswer() + " - " + to_string(it.getScore()));
        list->addItem(item);
    }

    list->setCurrentRow(0);
}


int Presenter::getIndex() {

    auto v = list->selectedItems();
    return list->row(v[0]);
}

void Presenter::addQuestion() {

    int id = idText->text().toInt();
    string text = questText->text().toStdString();
    string answ = answText->text().toStdString();
    int score = scoreText->text().toInt();
    try {
        ctr->addQuestion(id, text, answ, score);
    }
    catch(Exception& exc){
         QMessageBox::critical(this,"ERROR", exc.what());
    }
    this->populateList();
}

void Presenter::removeQuestion() {
    int index = this->getIndex();
    Question q = this->ctr->getQuestions()[index];
    int id = q.getId();
    this->ctr->removeQuestion(id);
    this->populateList();
}
