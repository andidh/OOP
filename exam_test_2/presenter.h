#ifndef PRESENTER_H
#define PRESENTER_H

#include <QWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QHboxLayout>
#include "controller.h"
#include "exception.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QListWidget>
#include <QPushButton>
#include <QMessageBox>
#include <sstream>


class Presenter : public QWidget
{
    Q_OBJECT
public:
    explicit Presenter(Controller* ctr, QWidget *parent = 0);

    QVBoxLayout* layout;
    QListWidget* list;
    QLineEdit* idText;
    QLineEdit* questText;
    QLineEdit* answText;
    QLineEdit* scoreText;

    QPushButton* addBtn;
    QPushButton* removeBtn;


private:
    void setUp();
    Controller* ctr;
    void populateList();
    int getIndex();
    void connectAll();

public slots:
    void addQuestion();
    void removeQuestion();

};

#endif // PRESENTER_H
