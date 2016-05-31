#ifndef INTERFACE_H
#define INTERFACE_H
#include <SFML/Graphics.hpp>
#include <cstdio>
#include <string>
#include "menu.h"


class Interface
{
    public:
        Interface();
        virtual ~Interface();

        //FUNCTIONS
        void drawText(sf::RenderWindow &window, int health);
        static void addScore();
        static void clearScore();
        static int getScore();
        void checkRecords(Menu &menu);


    protected:

    private:
        sf::Font _retroFont;
        sf::Text _healthText;
        sf::Text _scoreText;
        sf::Text _titleText;
        static int _score;
};

#endif // INTERFACE_H
