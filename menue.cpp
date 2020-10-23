#include "menue.h"
#include "ui_menue.h"

int ttmax=0,killedmax=0;

menue::menue(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::menue)
{
    ui->setupUi(this);
    setWindowTitle(GAME_TITLE);
    setWindowIcon(QIcon(GAME_ICON));
}

menue::~menue()
{
    delete ui;
}

void menue::on_pushButton_2_clicked()//选择地图
{
    //this->hide();
    setWindowTitle(GAME_TITLE);
    setWindowIcon(QIcon(GAME_ICON));
    selectmap *s=new selectmap;
    s->show();
    //监听选择信号
    connect(s,&selectmap::choosed,this,[=](){
        s->close();
        //delete(s);
        this->show();
    });
}

void menue::on_pushButton_clicked()//历史成就
{
    setWindowTitle(GAME_TITLE);
    setWindowIcon(QIcon(GAME_ICON));
    QMessageBox a;
    a.warning(this,"","存活时间:"+QString::number(ttmax)+"击败敌机:"+QString::number(killedmax));
}

void menue::on_pushButton_3_clicked()//开始游戏
{
    this->hide();
    MainScene *w = new MainScene;
    w->show();
    connect(w,&MainScene::ended,this,[=](){
        delete(w);
        this->show();

    });

}
