#include "Bullet.h"

Bullet::Bullet()
{
    _rect.setSize(sf::Vector2f(3,5));
    _movementSpeed = 0.5f;
    _color = sf::Color::White;
    _direction = 1;
}

Bullet::Bullet(float x, float y, short int direction, sf::Color color)
{
    _rect.setSize(sf::Vector2f(3,5));
    _rect.setPosition(x, y);
    _movementSpeed = 0.5f;
    _color = color;
    _direction = direction;
}

Bullet::Bullet(float x, float y, short int direction, sf::Color color, float movementSpeed)
{
    _rect.setSize(sf::Vector2f(3,5));
    _rect.setPosition(x, y);
    _movementSpeed = movementSpeed;
    _color = color;
    _direction = direction;
}

Bullet::~Bullet()
{

}

//GETTERS

float Bullet::getMovementSpeed()
{
    return _movementSpeed;
}

short int Bullet::getDirection()
{
    return _direction;
}

sf::RectangleShape Bullet::getRect()
{
    return _rect;
}

//FUNCTIONS

void Bullet::movement(sf::Time frameTime)
{
    switch(_direction)
    {
        case 1: //MOVE UP
           _rect.move(0, -1 * _movementSpeed * frameTime.asMilliseconds());
           break;
        case 2: //MOVE DOWN
           _rect.move(0, _movementSpeed * frameTime.asMilliseconds());
           break;
    }
}
