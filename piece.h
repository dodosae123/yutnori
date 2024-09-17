#pragma once

#ifndef PIECE_H
#define PIECE_H

#include <QPushButton>

class piece
{
public:
    enum piece_kind
    {
        RED,
        GREEN,
        BLUE
    };

    enum State
    {
        READY_TO,
        ON_FIELD,
        FINISHED
    };

    piece(piece_kind kind, int x, int y, QWidget *parent);

    QPushButton* getPiece();

    piece_kind kind()
    {
        return kind_;
    }

    void setInitialGeometry();
    void setGeometry(int x, int y);

    void enabled(bool enabled)
    {
        piece_->setEnabled(enabled);
    }
    void state(piece::State state)
    {
        state_ = state;
    }
    piece::State state()
    {
        return state_;
    }
    void activate()
    {
        if(state_ == State::READY_TO || state_ == State::ON_FIELD)
        {
            piece_->setEnabled(true);
        }
        else
        {
            piece_->setEnabled(false);
        }
    }
    void deactivate()
    {
        piece_->setEnabled(false);
    }


private:
    int initial_x_;
    int initial_y_;
    piece_kind kind_;
    piece::State state_;
    QPushButton *piece_{nullptr};
};

#endif // PIECE_H
