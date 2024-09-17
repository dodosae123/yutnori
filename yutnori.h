#pragma once

#ifndef YUTNORI_H
#define YUTNORI_H

#include <QMainWindow>
#include <QLabel>
#include "maingame.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class yutnori;
}
QT_END_NAMESPACE

class yutnori : public QMainWindow
{
    Q_OBJECT

public:
    yutnori(QWidget *parent = nullptr);
    ~yutnori();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::yutnori *ui;
    QPixmap image;
};
#endif // YUTNORI_H
