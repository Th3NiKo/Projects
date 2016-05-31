#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics.hpp>
#include <fstream>
#include <conio.h>
#include <iostream>
#include <cstdlib>
#include <string>

class  Menu
{
    public:
        Menu();
        virtual ~Menu();


        //GETTERS
        int getLast();
        int getHigh();

        //SETTERS
        void setLast(int last);
        void setHigh(int high);

        //FUNCTIONS
        void drawMenu(sf::RenderWindow &window);
        void loadData();
        void keyboardControl(sf::RenderWindow &window, bool &menu);

    protected:

    private:
        sf::Font _retroFont;
        sf::Texture _backgroundTexture;
        sf::Sprite _backgroundSprite;
        sf::Text _highScore;
        sf::Text _lastScore;
        sf::Text _highScoreNumber;
        sf::Text _lastScoreNumber;
        std::fstream _scoreFile;
        std::string _high;
        std::string _last;

};

#endif // MENU_H
