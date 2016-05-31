#ifndef ENEMYMANAGER_H
#define ENEMYMANAGER_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "Enemy.h"
#include "Randomizer.h"
#include "BulletManager.h"
#include "TimeManager.h"


class EnemyManager
{
    public:
        EnemyManager();
        virtual ~EnemyManager();

    //GETTERS
    Enemy *getEnemy();

    //FUNCTIONS
    void addEnemies();
    void addEnemiesMedium();
    void controlEnemies(Randomizer random, BulletManager &bulletManager, TimeManager &time);
    void updateDead(BulletManager &bulletManager); //DELETING DEAD ONES
    void drawEnemies(sf::RenderWindow &window);
    void clearAll();

    protected:

    private:
        std::vector<Enemy*> _enemyArray;
        std::vector<Enemy*>::iterator _enemyArrayIter;
};

#endif // ENEMYMANAGER_H
