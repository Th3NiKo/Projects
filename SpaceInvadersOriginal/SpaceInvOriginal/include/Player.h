#ifndef PLAYER_H
#define PLAYER_H
#include "PlayerBullet.h"
#include "Entity.h"
#include "BulletManager.h"
#include "TimeManager.h"
#include "AudioManager.h"


class Player : public Entity
{
    public:
        Player(float x, float y);
        virtual ~Player();

        //FUNCTIONS
        void keyboardControl(sf::Time frameTime, BulletManager &bulletmanager, sf::Time shootingTimer, TimeManager &timeManager, AudioManager &audioManager);
        void gameOver(AudioManager &audioManager, bool &menu, bool &init);

    protected:

    private:
};

#endif // PLAYER_H
