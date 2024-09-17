/********************************************************************************
** Form generated from reading UI file 'yutnori.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_YUTNORI_H
#define UI_YUTNORI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_yutnori
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *yutnori)
    {
        if (yutnori->objectName().isEmpty())
            yutnori->setObjectName("yutnori");
        yutnori->resize(800, 600);
        centralwidget = new QWidget(yutnori);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(330, 320, 75, 24));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(330, 380, 75, 24));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(120, 50, 521, 201));
        yutnori->setCentralWidget(centralwidget);
        menubar = new QMenuBar(yutnori);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        yutnori->setMenuBar(menubar);
        statusbar = new QStatusBar(yutnori);
        statusbar->setObjectName("statusbar");
        yutnori->setStatusBar(statusbar);

        retranslateUi(yutnori);

        QMetaObject::connectSlotsByName(yutnori);
    } // setupUi

    void retranslateUi(QMainWindow *yutnori)
    {
        yutnori->setWindowTitle(QCoreApplication::translate("yutnori", "yutnori", nullptr));
        pushButton->setText(QCoreApplication::translate("yutnori", "\352\262\214\354\236\204 \354\213\234\354\236\221", nullptr));
        pushButton_2->setText(QCoreApplication::translate("yutnori", "\354\242\205\353\243\214", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class yutnori: public Ui_yutnori {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_YUTNORI_H
