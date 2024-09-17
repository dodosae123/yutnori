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

    void enabled_pieces(bool enabled)
    {
        for(std::size_t i=0;i<=enabled_index_;++i)
        {
            pieces_[i].enabled(enabled);
        }
    }

    void increase_enabled_index()
    {
        ++enabled_index_;
        enabled_pieces(true);
    }
    void decrease_enabled_index()
    {
        enabled_pieces(false);
        --enabled_index_;
    }

    static std::size_t number_of_pieces;

private:
    piece::piece_kind kind_;
    std::vector<piece> pieces_;
    int enabled_index_{-1};
};

#endif // PLAYER_H
