#include "Entity.h"

Entity::Entity(float x, float y)
{
    _startingPosition.x = x;
    _startingPosition.y = y;
    _health = 1;
    _movementSpeed = 0.2;
    _sprite.setPosition(_startingPosition);
}

Entity::Entity(float x, float y, int health, float movementSpeed)
{
    _startingPosition.x = x;
    _startingPosition.y = y;
    _health = health;
    _movementSpeed = movementSpeed;
    _sprite.setPosition(_startingPosition);
}

Entity::~Entity()
{

}

//GETTERS

int Entity::getHealth()
{
    return _health;
}

float Entity::getMovementSpeed()
{
    return _movementSpeed;
}

sf::Sprite &Entity::getSprite()
{
    return _sprite;
}

sf::Vector2f Entity::getStartingPosition()
{
    return _startingPosition;
}


//SETTERS

void Entity::setTexture(std::string name)
{
    if(!_texture.loadFromFile(name))
    {
        std::cerr << "ERROR, CANNOT LOAD TEXTURE" << std::endl;
        EXIT_FAILURE;
    }
    else
    {
        _sprite.setTexture(_texture);
    }
}

void Entity::setHealth(int value)
{
    _health = value;
}



//FUNCTIONS

void Entity::movement(sf::Time frameTime, short int direction)
{
    switch(direction)
    {
        case 1: //MOVE LEFT
           _sprite.move(-1 * _movementSpeed * frameTime.asMilliseconds(), 0);
           break;
        case 2: //MOVE RIGHT
           _sprite.move(_movementSpeed * frameTime.asMilliseconds(), 0);
           break;
        case 3: // MOVE UP
           _sprite.move(0, -1 * _movementSpeed * frameTime.asMilliseconds());
           break;
        case 4: //MOVE DOWN
           _sprite.move(0, _movementSpeed * frameTime.asMilliseconds());
           break;
    }
}

void Entity::hpDown()
{
    _health = _health - 1;
    std::cout << "HP DOWN = " << _health << std::endl;
}

bool Entity::isDead()
{
    if(_health <= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}


