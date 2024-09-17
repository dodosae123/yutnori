#include "maingame.h"
#include "ui_maingame.h"

std::size_t maingame::number_of_players{3};


maingame::maingame(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::maingame)
{
    ui->setupUi(this);

    board.load(":/image/board.PNG");
    int label_width = ui->label->width();
    int label_height = ui->label->height();
    ui->label->setPixmap(board.scaled(label_width,label_height, Qt::IgnoreAspectRatio));

    points_.reserve(29);
    players_.reserve(number_of_players);

    initialize();
    start();
}


maingame::~maingame()
{
    delete ui;
}

void maingame::initialize()
{
    points_.clear();
    players_.clear();

    for(std::size_t i=0 ; i < 29 ; i++)
    {
        if(i == 5 || i == 8 || i == 12 || i == 16 || i == 22)
        {
            points_.emplace_back(point::direction::RIGHT_TO_LEFT, this);
        }
        else if(i == 0 || i == 7 || i == 11 || i == 14 || i == 17 || i == 21)
        {
            points_.emplace_back(point::direction::LEFT_TO_RIGHT, this);
        }
        else
        {
            points_.emplace_back(point::direction::SURFACE, this);
        }
    }

    //point 좌표 계산
    points_[0].setGeometry(30,30,90,50);
    points_[1].setGeometry(180,30,80,50);
    points_[2].setGeometry(330,30,80,50);
    points_[3].setGeometry(480,30,80,50);
    points_[4].setGeometry(630,30,80,50);
    points_[5].setGeometry(770,30,90,50);

    points_[6].setGeometry(40,120,70,50);
    points_[7].setGeometry(170,120,70,50);
    points_[8].setGeometry(640,120,70,50);
    points_[9].setGeometry(780,120,70,50);

    points_[10].setGeometry(40,210,70,50);
    points_[11].setGeometry(300,190,70,50);
    points_[12].setGeometry(520,190,70,50);
    points_[13].setGeometry(780,210,70,50);

    points_[14].setGeometry(400,250,90,60);

    points_[15].setGeometry(40,300,70,50);
    points_[16].setGeometry(300,320,70,50);
    points_[17].setGeometry(520,320,70,50);
    points_[18].setGeometry(780,300,70,50);

    points_[19].setGeometry(40,390,70,50);
    points_[20].setGeometry(170,390,70,50);
    points_[21].setGeometry(640,390,70,50);
    points_[22].setGeometry(780,390,70,50);

    points_[23].setGeometry(30,470,90,50);
    points_[24].setGeometry(180,470,80,50);
    points_[25].setGeometry(330,470,80,50);
    points_[26].setGeometry(480,470,80,50);
    points_[27].setGeometry(630,470,80,50);
    points_[28].setGeometry(770,470,90,50);

    for(std::size_t i=0 ; i < maingame::number_of_players ; i++)
    {
        players_.emplace_back(piece::piece_kind(i), this);
        players_[i].showPieces();
    }

}

void maingame::start()
{

}

void maingame::on_pushButton_clicked()
{
    if(ui->lineEdit->text().isEmpty() == true)
    {
        std::cout << "Please enter number" << std::endl;
    }
    else{
        count_ = 0;
        count_ += ui->lineEdit->text().toInt();
        players_[turn_].activate_pieces();

        std::cout << count_ << std::endl;
        ui->lineEdit->clear();
    }
}

