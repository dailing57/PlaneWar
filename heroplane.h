#ifndef HEROPLANE_H
#define HEROPLANE_H
#include <QPixmap>
#include "bullet.h"
class heroplane
{
public:
    heroplane();
    void shoot();
    void setPosition(int x, int y);
    QPixmap m_plane;//飞机资源

    int m_x;//初始坐标
    int m_y;
    int hp;
    QRect m_Rect;//矩形框

    Bullet bullets[BULLET_NUM];

    int recorder;

};

#endif // HEROPLANE_H
