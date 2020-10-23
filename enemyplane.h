#ifndef ENEMYPLANE_H
#define ENEMYPLANE_H
#include <QPixmap>
#include "bullet.h"

class enemyplane
{
public:
    enemyplane();

    void updatePosition();
    QPixmap enemy;

    int x,y,speed;

    QRect rect;

    //Bullet bullets[BULLET_NUM];
    //void shoot();

    int recorder;
    bool free;

};

#endif // ENEMYPLANE_H
