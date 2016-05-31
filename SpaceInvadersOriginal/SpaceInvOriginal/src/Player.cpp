#include "Player.h"

Player::Player(float x, float y) : Entity(x, y, 3, 0.5f)
{
    setTexture("player.png");
}

Player::~Player()
{

}

//FUNCTIONS



void Player::keyboardControl(sf::Time frameTime, BulletManager &bulletmanager, sf::Time shootingTimer, TimeManager &timeManager, AudioManager &audioManager)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        if(getSprite().getPosition().x > 0)
        {
            movement(frameTime, 1);
        }
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        if(getSprite().getPosition().x < 760)
        {
            movement(frameTime, 2);
        }
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {

        if(shootingTimer.asSeconds() > 0.3f)
        {
            audioManager.playShoot();
            PlayerBullet temp(_sprite.getPosition().x + 16, _sprite.getPosition().y + 2);
            bulletmanager.addPlayerBullet(temp);
            timeManager.restartShootClock();
        }
    }
}

void Player::gameOver(AudioManager &audioManager, bool &menu, bool &init)
{
    if(isDead())
    {
        init = false;
        menu = true;
        audioManager.stopMusic();
        std::cout << "GAME OVER" << std::endl;
    }
}
