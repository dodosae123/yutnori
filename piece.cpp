#include "piece.h"

#include <iostream>
#include "manager.h"

piece::piece(piece_kind kind, QWidget *parent)
    : kind_{kind}, state_{piece::State::UNAVAILABLE}
{
    QColor *color = nullptr;
    if(kind_ == piece_kind::RED)
    {
        piece_ = new QPushButton("RED", parent);
        color = new QColor(Qt::red);
    }
    else if(kind_ == piece_kind::GREEN)
    {
        piece_ = new QPushButton("GREEN", parent);
        color = new QColor(Qt::green);
    }
    else if(kind_ == piece_kind::BLUE)
    {
        piece_ = new QPushButton("BLUE", parent);
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

void piece::setGeometry(int x, int y)
{
    piece_->setGeometry(x, y, 50, 50);
}
