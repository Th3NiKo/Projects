#ifndef BULLET_H
#define BULLET_H
#include <SFML/Graphics.hpp>
/*
*****************************
VIRTUAL CLASS FOR PROJECTILES
*****************************
*/

class Bullet
{
    public:
        Bullet(float x, float y, short int direction, sf::Color color, float movementSpeed);
         Bullet(float x, float y, short int direction, sf::Color color);
        Bullet();
        virtual ~Bullet();

        //GETTERS
        float getMovementSpeed();
        sf::RectangleShape getRect();
        short int getDirection();

        //SETTERS


        //FUNCTIONS
        void movement(sf::Time frameTime);

    protected:
        float _movementSpeed;
        sf::RectangleShape _rect;
        sf::Color _color;
        short int _direction; // 1-UP 2-DOWN


    private:
};

#endif // BULLET_H
