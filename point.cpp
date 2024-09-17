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

    parent->connect(button_, &QPushButton::clicked, [this](){
        auto selected_piece = manager::getInstance().dialog.selected_piece();
        if(selected_piece != nullptr)
        {
            selected_piece->setGeometry(x_,y_);
            selected_piece->getPiece()->setEnabled(false);
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
