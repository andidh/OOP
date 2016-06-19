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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GUI
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QListWidget *list;
    QHBoxLayout *horizontalLayout;
    QLabel *descLabel;
    QLineEdit *descTest;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *addBtn;
    QPushButton *resolveBtn;
    QPushButton *removeBtn;

    void setupUi(QWidget *GUI)
    {
        if (GUI->objectName().isEmpty())
            GUI->setObjectName(QStringLiteral("GUI"));
        GUI->resize(432, 497);
        widget = new QWidget(GUI);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 20, 391, 461));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        list = new QListWidget(widget);
        list->setObjectName(QStringLiteral("list"));

        verticalLayout->addWidget(list);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        descLabel = new QLabel(widget);
        descLabel->setObjectName(QStringLiteral("descLabel"));

        horizontalLayout->addWidget(descLabel);

        descTest = new QLineEdit(widget);
        descTest->setObjectName(QStringLiteral("descTest"));

        horizontalLayout->addWidget(descTest);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        addBtn = new QPushButton(widget);
        addBtn->setObjectName(QStringLiteral("addBtn"));

        horizontalLayout_2->addWidget(addBtn);

        resolveBtn = new QPushButton(widget);
        resolveBtn->setObjectName(QStringLiteral("resolveBtn"));

        horizontalLayout_2->addWidget(resolveBtn);

        removeBtn = new QPushButton(widget);
        removeBtn->setObjectName(QStringLiteral("removeBtn"));

        horizontalLayout_2->addWidget(removeBtn);


        verticalLayout_2->addLayout(horizontalLayout_2);


        retranslateUi(GUI);

        QMetaObject::connectSlotsByName(GUI);
    } // setupUi

    void retranslateUi(QWidget *GUI)
    {
        GUI->setWindowTitle(QApplication::translate("GUI", "GUI", 0));
        descLabel->setText(QApplication::translate("GUI", "Description", 0));
        addBtn->setText(QApplication::translate("GUI", "Add", 0));
        resolveBtn->setText(QApplication::translate("GUI", "Resolve issue", 0));
        removeBtn->setText(QApplication::translate("GUI", "Remove", 0));
    } // retranslateUi

};

namespace Ui {
    class GUI: public Ui_GUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
