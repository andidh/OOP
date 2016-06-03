#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <controller.h>
#include <exception.h>
#include <validator.h>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QListWidget>
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
    explicit MainWindow(Controller* ctrl=0, QWidget *parent = 0 );
    ~MainWindow();
    //Overall layout
    QHBoxLayout *hLayout;

    //Left Layout
    QWidget* leftWid;
    QVBoxLayout* leftLay;

    //List widget
    QLabel* all;
    QListWidget* allCoats;

    //Labels and fields
    QLineEdit* sizeText;
    QLineEdit* colorText;
    QLineEdit* priceText;
    QLineEdit* quantText;
    QLineEdit* linkText;

    //Buttons
    QGridLayout* btnLay;
    QPushButton* add;
    QPushButton* remove;
    QPushButton* update;
    QPushButton* filter;

    //Right Layout
    QWidget* rightWid;
    QVBoxLayout* rightLay;
    QListWidget* store;
    QLineEdit* filterEdit;
    QPushButton* go;

    //Right layout buttons
    QPushButton* showCoat;
    QPushButton* nextBtn;
    QPushButton* buyBtn;
    QPushButton* total;
    QPushButton* save;
    QPushButton* open;

private:
    Controller* ctrl;
    void setUp();
    void connectSignals();

    void rightInit();
    void rightConnect();

public slots:

    void getCoats();
    int getSelectedItem();
    void listItemChanged();

    void addCoat();
    void removeCoat();
    void updateCoat();
    void filterCoat();

    void addToStore();
    void showInBrowser();
    void next();
    void buy();
    void showTotal();
    void saveToFile();
    void openFile();

};

#endif // MAINWINDOW_H
