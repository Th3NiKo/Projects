#include "menu.h"

Menu::Menu()
{
    _backgroundTexture.loadFromFile("menu.png");
    _backgroundSprite.setTexture(_backgroundTexture);
    _retroFont.loadFromFile("retro.ttf");

    _highScore.setScale(0.5, 0.5);
    _highScore.setColor(sf::Color::White);
    _highScore.setString("HIGHSCORE:");
    _highScore.setPosition(10,10);
    _highScore.setFont(_retroFont);

    _lastScore.setScale(0.5, 0.5);
    _lastScore.setColor(sf::Color::White);
    _lastScore.setString("LASTSCORE:");
    _lastScore.setPosition(620,10);
    _lastScore.setFont(_retroFont);

    _highScoreNumber.setScale(0.5, 0.5);
    _highScoreNumber.setColor(sf::Color::Blue);
    _highScoreNumber.setPosition(135,10);
    _highScoreNumber.setFont(_retroFont);
    _highScoreNumber.setString("0");

    _lastScoreNumber.setScale(0.5, 0.5);
    _lastScoreNumber.setColor(sf::Color::Blue);
    _lastScoreNumber.setPosition(745,10);
    _lastScoreNumber.setFont(_retroFont);
    _lastScoreNumber.setString("0");
}

Menu::~Menu()
{
    std::cout << "koniec";
    _scoreFile.open("highscore.txt", std::ios::in | std::ios::out);
    _scoreFile << _high << std::endl;
    _scoreFile << _last << std::endl;
    _scoreFile.close();

}

//GETTERS

int Menu::getHigh()
{
    int temp = atoi(_high.c_str());
    return temp;
}

int Menu::getLast()
{
    int temp = atoi(_last.c_str());
    return temp;
}



//SETTERS

void Menu::setHigh(int high)
{
    std::string tempHigh;
    sprintf((char*)tempHigh.c_str(), "%d", high);
    _high = tempHigh.c_str();
    _highScoreNumber.setString(_high);
}

void Menu::setLast(int last)
{
    std::string tempLast;
    sprintf((char*)tempLast.c_str(), "%d", last);
    _last = tempLast.c_str();
    _lastScoreNumber.setString(_last);
}



//FUNCTIONS

void Menu::drawMenu(sf::RenderWindow &window)
{
    window.draw(_backgroundSprite);
    window.draw(_highScore);
    window.draw(_lastScore);
    window.draw(_highScoreNumber);
    window.draw(_lastScoreNumber);
}

void Menu::loadData()
{
    _scoreFile.open("highscore.txt" ,std::ios::out | std::ios::in);
    if(_scoreFile.good() == true)
    {
        getline(_scoreFile, _high);
        getline(_scoreFile, _last);
        _scoreFile.close();
        _highScoreNumber.setString(_high);
        _lastScoreNumber.setString(_last);
    }
    else
    {
        std::ofstream file;
        file.open("highscore.txt", std::ios::out);
        file.close();
        _scoreFile.open("highscore.txt" ,std::ios::out | std::ios::in);
        _scoreFile << "0" << std::endl;
        _scoreFile << "0" << std::endl;
        _scoreFile.close();
    }
}

void Menu::keyboardControl(sf::RenderWindow &window, bool &menu)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
    {
        menu = false;
    }

}
