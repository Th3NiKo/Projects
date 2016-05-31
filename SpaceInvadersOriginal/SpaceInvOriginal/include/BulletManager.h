#ifndef BULLETMANAGER_H
#define BULLETMANAGER_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "EnemyBullet.h"
#include "PlayerBullet.h"

class Player;
class Enemy;

class BulletManager
{
    public:
        BulletManager();
        virtual ~BulletManager();

        //FUNCTIONS
        void addPlayerBullet(PlayerBullet &bullet);
        void addEnemyBullet(EnemyBullet &bullet);
        void drawBullets(sf::RenderWindow &window);
        void controlBullets(sf::Time frameTime);
        void checkPlayerCollisions(Player *player);
        void checkEnemyCollisions(Enemy *enemy);
        void clearAll();


    private:
        std::vector<PlayerBullet> _playerBulletArray;
        std::vector<EnemyBullet> _enemyBulletArray;
        std::vector<PlayerBullet>::iterator _playerBulletIter;
        std::vector<EnemyBullet>::iterator _enemyBulletIter;
};

#endif // BULLETMANAGER_H
