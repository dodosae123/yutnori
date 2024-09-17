#pragma once

#ifndef POINT_H
#define POINT_H

#include <QPushButton>
#include "piece.h"

class point
{
public:
    enum direction
    {
        SURFACE,
        RIGHT_TO_LEFT,
        LEFT_TO_RIGHT
    };

    point();
    point(point::direction direction, QWidget *parent);

    void setGeometry(int x, int y, int width, int height);

private:
    int x_;
    int y_;
    int width_;
    int height_;

    //piece
    std::vector<piece> pieces_;

    direction direction_;
    QPushButton *button_{nullptr};
};

#endif // POINT_H
