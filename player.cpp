#include "player.h"

std::size_t player::number_of_pieces{3};

player::player(piece::piece_kind kind, QWidget *parent)
{
    pieces_.reserve(number_of_pieces);
    kind_ = kind;
    for(int i = 0; i < player::number_of_pieces ; i++)
    {
        pieces_.emplace_back(kind_, parent);
        pieces_[i].setGeometry(871 + 50 * (i+1) , 350 + 50 * (kind_ + 1));
    }
    pieces_[0].state(piece::state::READY_TO);
}

player::~player()
{
}

void player::showPieces()
{
    for(std::size_t i = 0; i< pieces_.size(); i++)
    {
        pieces_[i].getPiece()->show();
    }
}
