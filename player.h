#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include "piece.h"

class player
{
public:
    player(piece::piece_kind kind, QWidget *parent);
    ~player();

    void showPieces();

    void activate_pieces()
    {
        for(std::size_t i=0;i<number_of_pieces;++i)
        {
            pieces_[i].activate();
        }
    }
    void deactive_pieces()
    {
        for(std::size_t i=0;i<number_of_pieces;++i)
        {
            pieces_[i].deactivate();
        }
    }

    static std::size_t number_of_pieces;

private:
    piece::piece_kind kind_;
    std::vector<piece> pieces_;
    int enabled_index_{-1};
};

#endif // PLAYER_H
