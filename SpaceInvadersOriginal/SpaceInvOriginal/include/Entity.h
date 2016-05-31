#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

/*
*******************************
VIRTUAL CLASS FOR SIMPLE ENTITY
*******************************
*/
class Entity
{
    public:
        Entity(float x, float y, int health, float movementSpeed);
        Entity(float x, float y);
        virtual ~Entity();
        //GETTERS
        int getHealth();
        float getMovementSpeed();
        sf::Sprite &getSprite();
        sf::Vector2f getStartingPosition();

        //SETTERS
        void setTexture(std::string name);
        void setHealth(int value);


        //FUNCTIONS
        void movement(sf::Time frameTime, short int direction); //1-LEFT  2-RIGHT  3-UP  4-DOWN
        void hpDown();
        bool isDead();

    protected:
        sf::Vector2f _startingPosition;
        sf::Texture _texture;
        sf::Sprite _sprite;
        float _movementSpeed;
        int _health;

    private:
};

#endif // ENTITY_H
