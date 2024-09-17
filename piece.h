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
        UNAVAILABLE,
        READY_TO,
        ON_FIELD,
        FINISHED
    };

    piece(piece_kind kind, QWidget *parent);

    QPushButton* getPiece();

    piece_kind kind()
    {
        return kind_;
    }
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


private:
    piece_kind kind_;
    piece::State state_;
    QPushButton *piece_{nullptr};
};

#endif // PIECE_H
