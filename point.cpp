#include "point.h"

#include <iostream>
#include "manager.h"

point::point()
{
}

point::point(point::direction direction, QWidget* parent)
{
    direction_ = direction;

    button_ = new QPushButton(parent);

    button_->setFlat(true);
    button_->setFocusPolicy(Qt::NoFocus);
    //button_->setEnabled(false);

    pieces_.reserve(player::number_of_pieces);

    parent->connect(button_, &QPushButton::clicked, [this](){
        auto selected_piece = manager::getInstance().dialog.selected_piece();
        if(selected_piece != nullptr)
        {
            if(pieces_.empty() == false) // 기존에 말이 있다면
            {
                if(selected_piece->kind() != pieces_[0].kind()) //말 종류가 다르다면
                {
                    for(std::size_t i = 0;i<pieces_.size();++i)
                    {
                        pieces_[i].setInitialGeometry();    //말 잡히니까 원래 위치로
                        pieces_[i].state(piece::State::READY_TO);
                        pieces_[i].getPiece()->setText("1");
                    }
                    pieces_.clear();
                }
                else
                {
                    int cnt = (selected_piece->getPiece()->text().toInt()+1);
                    selected_piece->getPiece()->setText(QString::number(cnt));
                }
            }

            selected_piece->setGeometry(x_,y_);
            selected_piece->state(piece::State::ON_FIELD);
            pieces_.push_back(*selected_piece);

            manager::getInstance().dialog.turn_over();
        }
        std::cout << "Button is Clicked!!" << std::endl;
    });
}


void point::setGeometry(int x, int y, int width, int height)
{
    x_ = x;
    y_ = y;
    width_ = width;
    height_ = height;

    button_->setGeometry(x_,y_,width_,height_);
}
