#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H

#include "Bullet.h"


class EnemyBullet : public Bullet
{
    public:
        EnemyBullet(float x, float y, float movementSpeed);
        virtual ~EnemyBullet();

    protected:

    private:
};

#endif // ENEMYBULLET_H
