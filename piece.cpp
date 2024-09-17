#include "piece.h"

#include <iostream>
#include "manager.h"

piece::piece(piece_kind kind, int x, int y, QWidget *parent)
    : kind_{kind}, state_{piece::State::READY_TO},
    initial_x_{x}, initial_y_{y}
{
    QColor *color = nullptr;
    piece_ = new QPushButton("1", parent);
    if(kind_ == piece_kind::RED)
    {
        color = new QColor(Qt::red);
    }
    else if(kind_ == piece_kind::GREEN)
    {
        color = new QColor(Qt::green);
    }
    else if(kind_ == piece_kind::BLUE)
    {
        color = new QColor(Qt::blue);
    }

    piece_->setStyleSheet(QString("background-color: %1").arg(color->name()));
    piece_->setEnabled(false);

    parent->connect(piece_, &QPushButton::clicked, [this](){
        std::cout << "Piece is clicked!!" << std::endl;
        manager::getInstance().dialog.selected_piece(this);
    });
}


QPushButton* piece::getPiece()
{
    return piece_;
}

void piece::setInitialGeometry()
{
    piece_->setGeometry(initial_x_, initial_y_, 50, 50);
}

void piece::setGeometry(int x, int y)
{
    piece_->setGeometry(x, y, 50, 50);
}
