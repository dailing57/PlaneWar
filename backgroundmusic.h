#ifndef BACKGROUNDMUSIC_H
#define BACKGROUNDMUSIC_H
#include <QThread>
#include <QSound>
#include "config.h"
class backgroundmusic: public QThread
{
public:
    void run()
    {
        QSound::play(SOUND_BACKGROUND);
    }
};

#endif // BACKGROUNDMUSIC_H
