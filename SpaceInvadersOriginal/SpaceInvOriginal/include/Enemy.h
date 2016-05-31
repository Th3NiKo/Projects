#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"
#include "Randomizer.h"
#include "EnemyBullet.h"
#include "BulletManager.h"
#include "TimeManager.h"
#include "Interface.h"

class Enemy : public Entity
{
    public:
        Enemy(float x, float y, int health, float movementSpeed);
        Enemy(float x, float y);
        Enemy();
        virtual ~Enemy();

        //FINCTIONS
        void atack(Randomizer r, BulletManager &bullet, sf::Time time, TimeManager &timeManager);
        void control(sf::Time frameTime);

    protected:

    private:
        short int _direction;
};

#endif // ENEMY_H
