#include "Interface.h"

Interface::Interface()
{
    _retroFont.loadFromFile("retro.ttf");

    _healthText.setPosition(10,10);
    _healthText.setScale(0.5, 0.5);
    _healthText.setColor(sf::Color::Red);
    _healthText.setFont(_retroFont);

    _titleText.setPosition(280, 10);
    _titleText.setScale(0.7, 0.7);
    _titleText.setColor(sf::Color::White);
    _titleText.setFont(_retroFont);
    _titleText.setString("Space Invaders");

    _scoreText.setPosition(680, 10);
    _scoreText.setColor(sf::Color::Green);
    _scoreText.setScale(0.5, 0.5);
    _scoreText.setFont(_retroFont);

}

Interface::~Interface()
{

}


//FUNCTIONS

void Interface::drawText(sf::RenderWindow &window, int health)
{
    std::string healthTmp;
    std::string scoreTmp;
    sprintf((char*)healthTmp.c_str(), "%d", health);
    sprintf((char*)scoreTmp.c_str(), "%d", _score);
    std::string realHealth = healthTmp.c_str();
    std::string realScore = scoreTmp.c_str();
    _healthText.setString("Health: " + realHealth);
    _scoreText.setString("Score: " + realScore);
    window.draw(_healthText);
    window.draw(_scoreText);
    window.draw(_titleText);
}

int Interface::_score = 0;

void Interface::addScore()
{
    _score += 10;
}

void Interface::clearScore()
{
    _score = 0;
}

int Interface::getScore()
{
    return _score;
}

void Interface::checkRecords(Menu &menu)
{
    menu.setLast(_score);
    if(_score > menu.getHigh())
    {
        menu.setHigh(_score);
    }
}
