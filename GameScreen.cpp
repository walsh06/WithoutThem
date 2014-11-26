#include "GameScreen.h"
#include "ui_GameScreen.h"

GameScreen::GameScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameScreen)
{
    ui->setupUi(this);
}

GameScreen::~GameScreen()
{
    delete ui;
}

void GameScreen::updateMoney(double money)
{
    ui->money->setText(QString::number(money));
}
