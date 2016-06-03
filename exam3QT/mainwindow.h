#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<controller.h>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QListWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <sstream>

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(Controller& contr, QWidget *parent = 0);
    QVBoxLayout* layout;
    QListWidget* all;
    QLineEdit* nameLine;
    QLineEdit* modelLine;
    QLineEdit* yearLine;
    QLineEdit* colorLine;

    QPushButton* sortBtn;
    QPushButton* filterBtn;

    QLineEdit* nameField;

private:
    Controller contr;
    void setUp();
    void connectSignalSlot();


public slots:

    void populateList();
    int getSelectedElement();
    void listItemChanged();
    void sortByManufact();
    void showCount();
    void getCount();

};

#endif // MAINWINDOW_H
