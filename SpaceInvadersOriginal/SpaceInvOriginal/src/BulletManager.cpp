#include "BulletManager.h"
#include "Player.h"
#include "Enemy.h"


BulletManager::BulletManager()
{

}

BulletManager::~BulletManager()
{

}

void BulletManager::addPlayerBullet(PlayerBullet &bullet)
{
    _playerBulletArray.push_back(bullet);
}

void BulletManager::addEnemyBullet(EnemyBullet &bullet)
{
    _enemyBulletArray.push_back(bullet);
}

void BulletManager::drawBullets(sf::RenderWindow &window)
{
    int counter = 0;
    for(_playerBulletIter = _playerBulletArray.begin(); _playerBulletIter != _playerBulletArray.end(); _playerBulletIter++)
    {
        window.draw(_playerBulletArray[counter].getRect());
        counter++;
    }
    int counter2 = 0;
    for(_enemyBulletIter = _enemyBulletArray.begin(); _enemyBulletIter != _enemyBulletArray.end(); _enemyBulletIter++)
    {
        window.draw(_enemyBulletArray[counter2].getRect());
        counter2++;
    }
}

void BulletManager::controlBullets(sf::Time frameTime)
{
    int counter = 0;
    for(_playerBulletIter = _playerBulletArray.begin(); _playerBulletIter != _playerBulletArray.end(); _playerBulletIter++)
    {
        _playerBulletArray[counter].movement(frameTime);
        counter++;
    }

    int counter2 = 0;
    for(_enemyBulletIter = _enemyBulletArray.begin(); _enemyBulletIter != _enemyBulletArray.end(); _enemyBulletIter++)
    {
        _enemyBulletArray[counter2].movement(frameTime);
        counter2++;
    }
}


void BulletManager::checkPlayerCollisions(Player *player)
{
    int counter3 = 0;
    for(_enemyBulletIter = _enemyBulletArray.begin(); counter3 < _enemyBulletArray.size(); _enemyBulletIter++)
    {
        if(_enemyBulletArray[counter3].getRect().getPosition().y  > 650)
        {
            _enemyBulletArray.erase(_enemyBulletIter);
        }
        else if(player->getSprite().getGlobalBounds().intersects(_enemyBulletArray[counter3].getRect().getGlobalBounds()))
        {
            std::cout << "HERE ";

             player->hpDown();
             _enemyBulletArray.erase(_enemyBulletIter);

        }
        counter3++;

    }
}

void BulletManager::checkEnemyCollisions(Enemy *enemy)
{

    int counter = 0;
    for(_playerBulletIter = _playerBulletArray.begin(); counter < _playerBulletArray.size(); _playerBulletIter++)
    {
        if(_playerBulletArray[counter].getRect().getPosition().y  < 0)
        {
            _playerBulletArray.erase(_playerBulletIter);
        }
        else if(enemy->getSprite().getGlobalBounds().intersects(_playerBulletArray[counter].getRect().getGlobalBounds()))
        {
            enemy->setTexture("enemyAfter.png");
            _playerBulletArray.erase(_playerBulletIter);
            enemy->hpDown();
        }
        counter++;
    }
}

void BulletManager::clearAll()
{
    _enemyBulletArray.clear();
    _playerBulletArray.clear();
}



