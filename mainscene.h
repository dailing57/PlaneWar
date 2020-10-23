#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QWidget>
#include <QTimer>
#include "map.h"
#include "heroplane.h"
#include <QMouseEvent>
#include <enemyplane.h>
#include "bomb.h"
class MainScene : public QWidget
{
    Q_OBJECT

public:

    MainScene(QWidget *parent = nullptr);
    ~MainScene();
    void initScene();

    QTimer m_Timer;//定时器对象

    void PlayGame();//启动游戏
    void updatePosition();//更新坐标
    void paintEvent(QPaintEvent *event);//绘图事件
    Map m_map;

    heroplane m_hero;//英雄飞机

    void mouseMoveEvent(QMouseEvent *event);

    void enemytosence();

    enemyplane enemys[ENEMY_NUM];

    int recorder;

    void collisiondetection();

    Bomb m_bombs[BOMB_NUM];

    bool checkend();
signals:
    void ended();

};
#endif // MAINSCENE_H
