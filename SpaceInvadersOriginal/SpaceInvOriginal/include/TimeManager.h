#ifndef TIMEMANAGER_H
#define TIMEMANAGER_H
#include <SFML/Graphics.hpp>


class TimeManager
{
    public:
        TimeManager();
        virtual ~TimeManager();

        //GETERS
        sf::Time getAccumulator();
        sf::Time getUps();
        sf::Time getShootTimer();
        sf::Time getRandomShootTimer();

        //FUNCTIONS
        void updateAccumulator();
        void updateShoot();
        void updateRandomShoot();
        void restartAccumulator();
        void restartShootClock();
        void restartRandomShootClock();
        void clearAll();

    protected:

    private:
        sf::Clock _clock;            //MAIN CLOCK FOR FPS
        sf::Clock _shootClock;       //CLOCK FOR PLAYER SHOOTING
        sf::Clock _randomShootClock; //CLOCK FOR ENEMY SHOOTING
        sf::Time _accumulator;
        sf::Time _ups;
        sf::Time _shootTimer;        //TIMER FOR PLAYER SHOOTING
        sf::Time _randomShootTimer;  //TIMER FOR ENEMY SHOOTING
};

#endif // TIMEMANAGER_H
