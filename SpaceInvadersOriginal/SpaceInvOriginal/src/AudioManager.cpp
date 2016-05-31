#include "AudioManager.h"

AudioManager::AudioManager()
{
    _shootBuffer.loadFromFile("shoot.wav");
    _shootSound.setBuffer(_shootBuffer);
    _mainMusic.openFromFile("music.ogg");
    _mainMusic.setLoop(true);

    _menuMusic.openFromFile("menuMusic.wav");
    _menuMusic.setLoop(true);

}

AudioManager::~AudioManager()
{

}

//FUNCTIONS

void AudioManager::playShoot()
{
    _shootSound.play();
}

void AudioManager::playMusic()
{
    _mainMusic.play();
}

void AudioManager::stopMusic()
{
    _mainMusic.stop();
}

void AudioManager::playMenu()
{
    _menuMusic.play();
}

void AudioManager::stopMenu()
{
    _menuMusic.stop();
}
