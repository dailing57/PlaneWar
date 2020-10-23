#include "selectmap.h"
#include "ui_selectmap.h"
#include "config.h"

selectmap::selectmap(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::selectmap)
{
    ui->setupUi(this);
}

selectmap::~selectmap()
{
    delete ui;
}

void selectmap::on_pushButton_clicked()//山谷
{
    choosemap = MAP_PATH;
    enemybullet=BULLET_PATH1;
    eplane = ENEMY_PATH1;
    emit this->choosed();
    this->close();
}


void selectmap::on_pushButton_3_clicked()//沙漠
{
    choosemap = MAP_PATH3;
    enemybullet=BULLET_PATH4;
    eplane = ENEMY_PATH3;

    emit this->choosed();

    this->close();

}

void selectmap::on_pushButton_2_clicked()//天空
{
    choosemap = MAP_PATH2;
    enemybullet=BULLET_PATH5;
    eplane = ENEMY_PATH5;

    emit this->choosed();
    eplane = ENEMY_PATH5;

    this->close();

}

void selectmap::on_pushButton_4_clicked()//工厂
{
    choosemap = MAP_PATH4;
    enemybullet=BULLET_PATH2;
    eplane = ENEMY_PATH7;

    emit this->choosed();

    this->close();

}

void selectmap::on_pushButton_5_clicked()//火山
{
    choosemap = MAP_PATH5;
    enemybullet=BULLET_PATH6;
    eplane = ENEMY_PATH7;

    emit this->choosed();

    this->close();

}
