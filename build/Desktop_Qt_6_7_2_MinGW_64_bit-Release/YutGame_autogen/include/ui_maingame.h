/********************************************************************************
** Form generated from reading UI file 'maingame.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINGAME_H
#define UI_MAINGAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_maingame
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QLineEdit *lineEdit;

    void setupUi(QDialog *maingame)
    {
        if (maingame->objectName().isEmpty())
            maingame->setObjectName("maingame");
        maingame->resize(1105, 560);
        maingame->setModal(true);
        label = new QLabel(maingame);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 881, 541));
        pushButton = new QPushButton(maingame);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(1020, 70, 75, 24));
        lineEdit = new QLineEdit(maingame);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(900, 70, 113, 22));

        retranslateUi(maingame);

        QMetaObject::connectSlotsByName(maingame);
    } // setupUi

    void retranslateUi(QDialog *maingame)
    {
        maingame->setWindowTitle(QCoreApplication::translate("maingame", "Game", nullptr));
        label->setText(QString());
        pushButton->setText(QCoreApplication::translate("maingame", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class maingame: public Ui_maingame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINGAME_H
