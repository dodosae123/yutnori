#pragma once

#ifndef MAINGAME_H
#define MAINGAME_H

#include <QDialog>
#include <QPainter>
#include "player.h"
#include "point.h"
#include "piece.h"

namespace Ui {
class maingame;
}

class maingame : public QDialog
{
    Q_OBJECT

public:
    explicit maingame(QWidget *parent = nullptr);
    ~maingame();

    static std::size_t number_of_players;

    void selected_piece(piece *piece)
    {
        selected_piece_ = piece;
    }
    piece* selected_piece()
    {
        return selected_piece_;
    }

    void count(std::size_t count)
    {
        count_ = count;
    }
    std::size_t count()
    {
        return count_;
    }

    void turn_over()
    {
        players_[turn_].deactive_pieces();
        turn_ = (turn_ + 1) % number_of_players;

    }

private slots:
    void on_pushButton_clicked();

private:
    void initialize();
    void start();

    Ui::maingame *ui;
    QPixmap board;

    std::vector<point> points_;
    std::vector<player> players_;

    bool finished_{false};

    std::size_t turn_{0};
    piece *selected_piece_{nullptr};

    std::size_t count_{0};
};

#endif // MAINGAME_H
