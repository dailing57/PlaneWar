#include "enemyplane.h"
#include "config.h"

QString enemybullet;
QString eplane;

enemyplane::enemyplane()
{
    enemy.load(eplane);

    x=0;
    y=0;

    free=true;

    speed=ENEMY_SPEED;

    rect.setWidth(enemy.width());
    rect.setHeight(enemy.height());
    rect.moveTo(x,y);
}

void enemyplane::updatePosition()
{
    if(free)
        return;
    y+=speed+tt;

    rect.moveTo(x,y);

    if(y>=GAME_HEIGHT + rect.height())
        free=true,runaway++;
}
