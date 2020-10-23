#ifndef BULLET_H
#define BULLET_H
#include "config.h"
#include <QPixmap>

class Bullet
{
public:
    Bullet();
    void updatePosition();
    void E_updatePosition();
    QPixmap m_Bullet;

    int m_x,m_y,m_speed;

    bool m_free;//是否闲置

    QRect m_Rect;
};

#endif // BULLET_H
