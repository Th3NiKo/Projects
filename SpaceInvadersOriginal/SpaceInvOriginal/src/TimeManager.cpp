#include "TimeManager.h"

TimeManager::TimeManager()
{
    _accumulator = sf::Time::Zero;
    _shootTimer = sf::Time::Zero;
    _randomShootTimer = sf::Time::Zero;
    _ups = sf::seconds(1.f / 60.f);
}

TimeManager::~TimeManager()
{

}

//GETTERS

sf::Time TimeManager::getAccumulator()
{
    return _accumulator;
}

sf::Time TimeManager::getUps()
{
    return _ups;
}

sf::Time TimeManager::getShootTimer()
{
    return _shootTimer;
}

sf::Time TimeManager::getRandomShootTimer()
{
    return _randomShootTimer;
}



//FUNCTIONS

void TimeManager::updateAccumulator()
{
    _accumulator -= _ups;
}

void TimeManager::updateShoot()
{
    _shootTimer = _shootClock.getElapsedTime();
}

void TimeManager::updateRandomShoot()
{
    _randomShootTimer = _randomShootClock.getElapsedTime();
}

void TimeManager::restartAccumulator()
{
    _accumulator += _clock.restart();
}

void TimeManager::restartShootClock()
{
    _shootClock.restart();
}

void TimeManager::restartRandomShootClock()
{
    _randomShootClock.restart();
}

void TimeManager::clearAll()
{
    _randomShootClock.restart();
    _randomShootTimer = sf::Time::Zero;
}
