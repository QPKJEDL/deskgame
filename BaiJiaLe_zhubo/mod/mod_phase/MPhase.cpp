#include "mod/mod_phase/MPhase.h"
#include "ui_MPhase.h"

MPhase::MPhase(MPhaseArg *arg, QWidget *parent)
    : QWidget(parent),
    ui(new Ui::MPhase)
{
    ui->setupUi(this);

    this->arg = new MPhaseArg();
    this->arg->tie = arg->tie;
    this->arg->init = arg->init;
    this->arg->enter = arg->enter;
    this->arg->leave = arg->leave;
    this->arg->start = arg->start;
    this->arg->banker = arg->banker;
    this->arg->cancel = arg->cancel;
    this->arg->player = arg->player;
    this->arg->useless = arg->useless;
    this->arg->bankerPair = arg->bankerPair;
    this->arg->changeBoot = arg->changeBoot;
    this->arg->playerPair = arg->playerPair;

    this->move(800,400);

    this->timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(on_timeout()));

}

void disabled(std::initializer_list<QPushButton*> list){
    for(auto button : list){
        button->setEnabled(false);
    }
}

void enabled(std::initializer_list<QPushButton*> list){
    for(auto button : list){
        button->setEnabled(true);
    }
}

void MPhase::on_timeout()
{
    if(--times < 1){
        timer->stop();
        this->hide();

        emit timeout();

        enabled({arg->enter,arg->cancel,arg->leave,arg->banker,arg->bankerPair,arg->player,arg->playerPair,arg->bankerPair,arg->tie,arg->useless});
    }
    else{
        ui->label->setText(QString::number(times));
        this->show();
    }
}

void MPhase::to_phase(int phase, int start, int end, int countDown)
{
    count_down = countDown;
    switch (phase) {
    case 0:{
        enabled({arg->start,arg->changeBoot,arg->leave});
        break;
    }
    case 1:{
        unsigned int time = end - start;
        times = count_down - time + 1;
        timer->start(1000);
        this->setWindowFlags(Qt::FramelessWindowHint);
        break;
    }
    case 2:{
        enabled({arg->leave,arg->banker,arg->bankerPair,arg->player,arg->playerPair,arg->tie,arg->enter,arg->cancel,arg->useless});
        //emit timeout();
        break;
    }
    case 3:{
        enabled({arg->start,arg->changeBoot,arg->leave,arg->init});
        break;
    }
    }
}

void MPhase::on_started()
{
    to_phase(1,0,0,count_down);
}

void MPhase::on_finished()
{
    enabled({arg->start});
}

void MPhase::on_useless()
{
    disabled({arg->enter,arg->cancel,arg->banker,arg->bankerPair,arg->player,arg->playerPair,arg->tie,arg->useless});
    enabled({arg->start});
}
