#include "menue.h"
#include <config.h>
#include <QApplication>
#include <QResource>//注册二进制文件

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QResource::registerResource(GAME_RES_PATH);//二进制注册
    menue m;
    m.show();
    return a.exec();
}
