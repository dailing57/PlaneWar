#include "map.h"
#include "config.h"
Map::Map()
{
    //initialize loading object
    m_map1.load(choosemap);
    m_map2.load(choosemap);

    //setting position
    m_map1_posY=-GAME_HEIGHT;
    m_map2_posY=0;

    //setting scrollspeed
    m_scroll_speed=MAP_SCROLL_SPEED;
}

void Map::mapPosition()
{
    m_map1_posY +=m_scroll_speed;
    if(m_map1_posY>=0)
    {
        m_map1_posY=-GAME_HEIGHT;
    }
    m_map2_posY +=m_scroll_speed;
    if(m_map2_posY>=GAME_HEIGHT)
    {
        m_map2_posY=0;
    }
}
