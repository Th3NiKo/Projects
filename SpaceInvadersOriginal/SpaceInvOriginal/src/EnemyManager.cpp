#include "EnemyManager.h"

EnemyManager::EnemyManager()
{

}
EnemyManager::~EnemyManager()
{

}

//FUNCTIONS

void EnemyManager::addEnemies()
{
    for(int i = 1; i < 29; i++)
    {
        if(i > 14)
        {
            _enemyArray.push_back(new Enemy((i - 14) * 50.0, 150.0));
        }
        else
        {
            _enemyArray.push_back(new Enemy(i * 50.0, 100.0));
        }
    }
}

void EnemyManager::addEnemiesMedium()
{
    for(int i = 1; i < 29; i++)
    {
        if(i > 14)
        {
            _enemyArray.push_back(new Enemy((i - 14) * 50.0, 150.0, 3, 0.23f));
        }
        else
        {
            _enemyArray.push_back(new Enemy(i * 50.0, 100.0, 3, 0.23f));
        }
    }
}
void EnemyManager::controlEnemies(Randomizer random, BulletManager &bulletManager, TimeManager &time)
{
    int counter = 0;
    for(_enemyArrayIter = _enemyArray.begin(); counter < _enemyArray.size(); _enemyArrayIter++)
    {
        _enemyArray[counter]->control(time.getUps()); //ENEMY MOVEMENT
        _enemyArray[counter]->atack(random, bulletManager, time.getRandomShootTimer(), time);
        counter++;
    }
}

void EnemyManager::drawEnemies(sf::RenderWindow &window)
{
    int counter2 = 0;
    for(_enemyArrayIter = _enemyArray.begin(); counter2 < _enemyArray.size(); _enemyArrayIter++)
    {
        window.draw(_enemyArray[counter2]->getSprite());
        counter2++;
    }
}


void EnemyManager::updateDead(BulletManager &bulletManager)
{
    int counter3 = 0;
    for(_enemyArrayIter = _enemyArray.begin(); counter3 < _enemyArray.size(); _enemyArrayIter++)
    {
        bulletManager.checkEnemyCollisions(_enemyArray[counter3]);
        if(_enemyArray[counter3]->isDead())
        {
            delete _enemyArray[counter3];
            _enemyArray.erase(_enemyArray.begin() + counter3);
        }
        counter3++;
    }
}


void EnemyManager::clearAll()
{
    _enemyArray.clear();
}
