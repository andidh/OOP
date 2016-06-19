/********************************************************************************
** Form generated from reading UI file 'gui.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_H
#define UI_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GUI
{
public:
    QListWidget *list;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *addBtn;
    QPushButton *startBtn;
    QPushButton *RemoveBtn;
    QPushButton *doneBtn;

    void setupUi(QWidget *GUI)
    {
        if (GUI->objectName().isEmpty())
            GUI->setObjectName(QStringLiteral("GUI"));
        GUI->resize(553, 488);
        list = new QListWidget(GUI);
        list->setObjectName(QStringLiteral("list"));
        list->setGeometry(QRect(50, 10, 461, 381));
        layoutWidget = new QWidget(GUI);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 400, 481, 71));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        addBtn = new QPushButton(layoutWidget);
        addBtn->setObjectName(QStringLiteral("addBtn"));

        horizontalLayout->addWidget(addBtn);

        startBtn = new QPushButton(layoutWidget);
        startBtn->setObjectName(QStringLiteral("startBtn"));

        horizontalLayout->addWidget(startBtn);

        RemoveBtn = new QPushButton(layoutWidget);
        RemoveBtn->setObjectName(QStringLiteral("RemoveBtn"));

        horizontalLayout->addWidget(RemoveBtn);

        doneBtn = new QPushButton(layoutWidget);
        doneBtn->setObjectName(QStringLiteral("doneBtn"));

        horizontalLayout->addWidget(doneBtn);


        retranslateUi(GUI);

        QMetaObject::connectSlotsByName(GUI);
    } // setupUi

    void retranslateUi(QWidget *GUI)
    {
        GUI->setWindowTitle(QApplication::translate("GUI", "GUI", 0));
        addBtn->setText(QApplication::translate("GUI", "Add", 0));
        startBtn->setText(QApplication::translate("GUI", "Start", 0));
        RemoveBtn->setText(QApplication::translate("GUI", "Remove", 0));
        doneBtn->setText(QApplication::translate("GUI", "Done", 0));
    } // retranslateUi

};

namespace Ui {
    class GUI: public Ui_GUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
