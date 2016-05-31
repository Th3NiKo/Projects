#ifndef PLAYERBULLET_H
#define PLAYERBULLET_H

#include "Bullet.h"


class PlayerBullet : public Bullet
{
    public:
        PlayerBullet(float x, float y);
        PlayerBullet();
        virtual ~PlayerBullet();

    protected:

    private:
};

#endif // PLAYERBULLET_H
