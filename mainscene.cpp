#include "mainscene.h"
#include "config.h"
#include "backgroundmusic.h"
#include <QIcon>
#include <QPainter>
#include "bullet.h"
#include <ctime>
#include <QSound>
#include <QThread>
#include <QDebug>

QTimer timer;
QString choosemap=MAP_PATH;
int runaway=0;
int killed=0;
int tt = 0;
using namespace std;

MainScene::MainScene(QWidget *parent)
    : QWidget(parent)
{
    initScene();
}
MainScene::~MainScene()
{
}

void MainScene::initScene()
{
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);
    setWindowTitle(GAME_TITLE);
    setWindowIcon(QIcon(GAME_ICON));
    m_Timer.setInterval(GAME_RATE);//时间间隔
    runaway =0;
    tt=0;
    killed=0;
    PlayGame();

    recorder=0;

    //随机种子
    srand((unsigned int)time(NULL));
}

void MainScene::PlayGame()
{
    m_Timer.start();//启动定时器
    timer.start(5000);
    connect(&timer,&QTimer::timeout,[=](){
        tt++;
    });
    connect(&m_Timer,&QTimer::timeout,[=](){
        //检测结束
        if(checkend())
            return;
        //更新坐标
        updatePosition();
        //绘制元素
        update();//调用paintevent
        //敌机出场
        enemytosence();
        //碰撞检测
        collisiondetection();
        //启动背景音乐
        //QSound player(SOUND_BACKGROUND);
        // player.play();
        ttmax=max(ttmax,tt);
        killedmax=max(killedmax,killed);
    });//lambda表达式实现捕获信号，监听定时器信号
}

void MainScene::updatePosition()
{
    m_map.mapPosition();
    m_hero.shoot();//发子弹

    for(int i=0;i<BULLET_NUM;i++)
    {
        if(!m_hero.bullets[i].m_free)
        {
            m_hero.bullets[i].updatePosition();
        }
    }

    for(int i=0;i<ENEMY_NUM;i++)
    {
        //qDebug()<<"enemys000 "<<i<<endl;
        if(enemys[i].free==false)
        {
            enemys[i].updatePosition();
            //enemys[i].shoot();
        }
    }

    //计算爆炸播放的图片
    for(int i = 0 ; i < BOMB_NUM;i++)
    {
        if(m_bombs[i].m_Free == false)
        {
           m_bombs[i].updateInfo();
        }
    }
}

void MainScene::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);//画图,this 是在当前窗口中画画
    //绘制地图
    painter.drawPixmap(0,m_map.m_map1_posY,m_map.m_map1);
    painter.drawPixmap(0,m_map.m_map2_posY,m_map.m_map2);
    painter.drawPixmap(m_hero.m_x,m_hero.m_y,m_hero.m_plane);

    //画血条
    painter.setPen(QColor(255, 99, 71));
    QFont font;
    font.setPointSize(15);
    font.bold();
    //font.setItalic(true);
    painter.setFont(font);
    // 绘制文本
    /*
    painter.drawText(10,40,tr("HP:"));
    painter.setBrush(QColor(255, 99, 71));
    painter.drawRect(60,20,m_hero.hp,20);
    */
    painter.drawText(10,40,tr("击杀敌机:%1").arg(QString::number(killed)));
    painter.drawText(300,40,tr("遗漏敌机:%1").arg(QString::number(runaway)));
    //绘制英雄子弹
    for(int i=0;i<BULLET_NUM;i++)
    {
        if(!m_hero.bullets[i].m_free)
        {
            painter.drawPixmap(m_hero.bullets[i].m_x,m_hero.bullets[i].m_y,m_hero.bullets[i].m_Bullet);
        }
    }
    //画敌机
    for(int i=0;i<ENEMY_NUM;i++)
    {
        if(enemys[i].free==false)
        {
            painter.drawPixmap(enemys[i].x,enemys[i].y,enemys[i].enemy);
        }
    }
    //绘制爆炸图片
    for(int i = 0 ; i < BOMB_NUM;i++)
    {
        if(m_bombs[i].m_Free == false)
        {
           painter.drawPixmap(m_bombs[i].m_X,m_bombs[i].m_Y,m_bombs[i].m_pixArr[m_bombs[i].m_index]);
        }
    }
}

void MainScene::mouseMoveEvent(QMouseEvent *event)
{
    int x=event->x()-m_hero.m_Rect.width()/2;
    int y=event->y()-m_hero.m_Rect.height()/2;

    //检测边界
    if(x<=0)
        x=0;
    if(x >= GAME_WIDTH - m_hero.m_Rect.width())
    {
        x = GAME_WIDTH - m_hero.m_Rect.width();
    }
    if(y <= 0)
    {
        y = 0;
    }
    if(y >= GAME_HEIGHT - m_hero.m_Rect.height())
    {
        y = GAME_HEIGHT - m_hero.m_Rect.height();
    }
    m_hero.setPosition(x,y);
}

void MainScene::enemytosence()
{
    recorder++;
    if(recorder<ENEMY_INTERVAL)
    {
        return;
    }

    recorder=0;

    for(int i=0;i<ENEMY_NUM;i++)
    {
        if(enemys[i].free)
        {
            enemys[i].free=false;
            enemys[i].x=rand()%(GAME_WIDTH-enemys[i].rect.width());
            enemys[i].y=-enemys[i].rect.height();
            break;
        }
    }
}

void MainScene::collisiondetection()
{
    for(int i=0;i<ENEMY_NUM;i++)
    {
        if(enemys[i].free)
            continue;
        //播放爆炸效果

        for(int j=0;j<BULLET_NUM;j++)
        {
            if(m_hero.bullets[j].m_free)
                continue;
            if(enemys[i].rect.intersects((m_hero.bullets[j].m_Rect)))
            {
                //QSound:: play(SOUND_BOMB);
                if(enemys[i].y>=0 && enemys[i].y<=GAME_HEIGHT)
                {   //击杀的敌机
                    killed++;
                }
                qDebug()<<killed<<endl;
                enemys[i].free=true;
                m_hero.bullets[j].m_free=true;
                for(int k = 0 ; k < BOMB_NUM;k++)
                {
                    if(m_bombs[k].m_Free)
                    {
                        //爆炸状态设置为非空闲
                        m_bombs[k].m_Free = false;
                        //更新坐标

                        m_bombs[k].m_X =enemys[i].x;
                        m_bombs[k].m_Y =enemys[i].y;
                        break;
                    }
                }
            }

        }
    }
}

bool MainScene::checkend()
{
    if(runaway>=10)
    {
        QMessageBox a;
        a.warning(this,"","游戏结束！_");
        runaway=0;
        this->close();
        emit this->ended();
        return 1;
    }
    return 0;
}
