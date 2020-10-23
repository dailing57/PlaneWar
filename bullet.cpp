#include "bullet.h"

int herobullet=0;

Bullet::Bullet()
{
    QString bullets;
    switch(herobullet)
    {
    case 0: bullets=BULLET_PATH;break;
    case 1: bullets=BULLET_PATH10;break;
    case 2: bullets=BULLET_PATH15;break;
    case 3: bullets=BULLET_PATH14;break;
    }

    m_Bullet.load(bullets);

    m_x=GAME_WIDTH/2-m_Bullet.width()/2;
    m_y=GAME_HEIGHT;

    m_free=true;

    m_speed=BULLET_SPEED;

    m_Rect.setWidth(m_Bullet.width());
    m_Rect.setHeight(m_Bullet.height());
    m_Rect.moveTo(m_x,m_y);
}

void Bullet::updatePosition()
{
    //如果是空闲状态，不用算坐标
    if(m_free)
        return;

    m_y-=m_speed;
    m_Rect.moveTo(m_x,m_y);

    if(m_y<=-m_Rect.height())
        m_free=true;
}

void Bullet::E_updatePosition()
{
    //如果是空闲状态，不用算坐标
    if(m_free)
        return;

    m_y+=E_BULLET_SPEED;
    m_Rect.moveTo(m_x,m_y);

    if(m_y>=GAME_HEIGHT)
        m_free=true;
}
