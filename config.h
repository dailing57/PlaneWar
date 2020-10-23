#ifndef CONFIG_H
#define CONFIG_H
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <QTimer>
#define GAME_WIDTH  512  //宽度
#define GAME_HEIGHT 768  //高度
#define GAME_TITLE "打飞机_" //标题
#define GAME_ICON ":/res/app.ico"//图标路径
#define GAME_RES_PATH "./plane.rcc" //二进制资源路径
#define GAME_RATE 10 //帧率，单位毫秒

#define MAP_PATH  ":/res/img_bg_level_1.jpg" //地图图片路径
#define MAP_PATH2  ":/res/img_bg_level_2.jpg"
#define MAP_PATH3  ":/res/img_bg_level_3.jpg"
#define MAP_PATH4  ":/res/img_bg_level_4.jpg"
#define MAP_PATH5  ":/res/img_bg_level_5.jpg"
#define MAP_SCROLL_SPEED 2  //地图滚动速度
#endif // CONFIG_H

#define HERO_PATH ":/res/hero2.png"

#define BULLET_PATH ":/res/bullet_11.png"   //子弹图片路径
#define BULLET_PATH1 ":/res/bullet_1.png"
#define BULLET_PATH2 ":/res/bullet_2.png"
#define BULLET_PATH3 ":/res/bullet_3.png"
#define BULLET_PATH4 ":/res/bullet_4.png"
#define BULLET_PATH5 ":/res/bullet_5.png"
#define BULLET_PATH6 ":/res/bullet_6.png"
#define BULLET_PATH7 ":/res/bullet_7.png"
#define BULLET_PATH8 ":/res/bullet_8.png"
#define BULLET_PATH9 ":/res/bullet_9.png"
#define BULLET_PATH10 ":/res/bullet_10.png"
#define BULLET_PATH12 ":/res/bullet_12.png"
#define BULLET_PATH13 ":/res/bullet_13.png"
#define BULLET_PATH14 ":/res/bullet_14.png"
#define BULLET_PATH15 ":/res/hero_bullet_7.png"
#define BULLET_SPEED 5  //子弹移动速度
#define E_BULLET_SPEED 5 //敌机子弹速度
#define BULLET_NUM 30   //弹匣中子弹总数

#define BULLET_INTERVAL 20 //发射子弹时间间隔
#define BULLET_INTERVAL_E 20 //发射子弹时间间隔

#define ENEMY_PATH1  ":/res/img-plane_1.png"
#define ENEMY_PATH2  ":/res/img-plane_2.png"
#define ENEMY_PATH3  ":/res/img-plane_3.png"
#define ENEMY_PATH4  ":/res/img-plane_4.png"
#define ENEMY_PATH5  ":/res/img-plane_5.png"
#define ENEMY_PATH6  ":/res/img-plane_6.png"
#define ENEMY_PATH7  ":/res/img-plane_7.png"

#define ENEMY_SPEED 3  //敌机移动速度
#define ENEMY_NUM   20  //敌机总数量
#define ENEMY_INTERVAL  30  //敌机出场时间间隔

#define BOMB_PATH  ":/res/bomb-%1.png"   //爆炸资源图片
#define BOMB_NUM  20     //爆炸数量
#define BOMB_MAX  7      //爆炸图片最大索引
#define BOMB_INTERVAL 10   //爆炸切图时间间隔

extern QString enemybullet;
extern QString choosemap;
extern QString eplane;
extern QTimer timer;
extern int herobullet;
extern int killed,runaway,tt,ttmax,killedmax;
#define SOUND_BACKGROUND ":/res/bg.wav"
#define SOUND_BOMB ":/res/bomb.wav"
