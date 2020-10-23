#include "heroplane.h"
#include "config.h"
heroplane::heroplane()
{
    hp=100;
    m_plane.load(HERO_PATH);//加载图片
    m_x=GAME_WIDTH/2-m_plane.width()/2;
    m_y=GAME_HEIGHT-m_plane.height()-20;

    //矩形边框
    m_Rect.setWidth(m_plane.width());
    m_Rect.setHeight(m_plane.height());
    m_Rect.moveTo(m_x,m_y);

    recorder=0;
}

void heroplane::shoot()
{
    recorder++;
    //如果未达到发射间隔
    if(recorder<BULLET_INTERVAL)
        return;

    recorder=0;

    for(int i=0;i<BULLET_NUM;i++)
    {
        if(bullets[i].m_free)
        {
            bullets[i].m_free=false;//修改状态为非空闲
            //设置坐标
            bullets[i].m_x=m_x+m_Rect.width()/2-10;
            bullets[i].m_y=m_y-25;
            break;
        }
    }
}

void heroplane::setPosition(int x, int y)
{
    m_x=x;
    m_y=y;
    m_Rect.moveTo(m_x,m_y);
}
