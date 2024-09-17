#include "yutnori.h"
#include "./ui_yutnori.h"
#include <QPainter>

#include "manager.h"

yutnori::yutnori(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::yutnori)
{
    ui->setupUi(this);

    image.load(":/image/yutnori.PNG");
    int label_width = ui->label->width();
    int label_height = ui->label->height();
    ui->label->setPixmap(image.scaled(label_width,label_height, Qt::IgnoreAspectRatio));

}

yutnori::~yutnori()
{
    delete ui;
}

void yutnori::on_pushButton_clicked()
{
    manager::getInstance().maingame_start();
}


void yutnori::on_pushButton_2_clicked()
{
    this->close();
}

