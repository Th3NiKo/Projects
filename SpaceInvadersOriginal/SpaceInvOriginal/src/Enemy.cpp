#include "Enemy.h"

Enemy::Enemy(float x, float y) : Entity(x, y, 2, 0.1f)
{
    setTexture("enemy.png");
    _direction = 2;
}

Enemy::Enemy() : Entity(0.0f,0.0f,2,0.2f)
{
    setTexture("enemy.png");
    _direction = 2;
};

Enemy::Enemy(float x, float y, int health, float movementSpeed) : Entity(x, y, health, movementSpeed)
{
    setTexture("enemy.png");
    _direction = 2;
}

Enemy::~Enemy()
{
    Interface::addScore();
}

//FUNCTIONS

void Enemy::control(sf::Time frameTime)
{


    if(getSprite().getPosition().x > getStartingPosition().x + 50)
    {
        _direction -= 1;
    }
    else if(getSprite().getPosition().x < getStartingPosition().x - 50)
    {
        _direction += 1;
    }
    movement(frameTime, _direction);



}

void Enemy::atack(Randomizer r, BulletManager &bullet, sf::Time time, TimeManager &timeManager)
{
    int newTime = rand() % 3 + 1;
    int newTimeDelta = rand() % 10;
    float actualTime = newTime + (newTimeDelta / 10);
    if(time.asSeconds() >= actualTime)
    {
        bool didShoot = false;
        int randomNumber;
        if(Interface::getScore() >= 280)
        {
            randomNumber = r.randomize(9,12);
        }
        else
        {
            randomNumber = r.randomize(5,13);
        }

        if(randomNumber == 10 && (didShoot == false))
        {
            didShoot = true;
            int randomSpeed = r.randomize(4,6);
            EnemyBullet temp(_sprite.getPosition().x + 16, _sprite.getPosition().y - 20, randomSpeed / 10.0f);
            std::cout << "Speed = " << randomSpeed << std::endl;
            std::cout << randomSpeed / 10.0f << std::endl;
            bullet.addEnemyBullet(temp);
        }
       timeManager.restartRandomShootClock();
    }
}



