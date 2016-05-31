#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class AudioManager
{
    public:
        AudioManager();
        virtual ~AudioManager();

        //FUNCTIONS
        void playShoot();
        void playMusic();
        void playMenu();
        void stopMenu();
        void stopMusic();

    protected:

    private:
        sf::SoundBuffer _shootBuffer;
        sf::Sound _shootSound;
        sf::Music _mainMusic;
        sf::Music _menuMusic;

};

#endif // AUDIOMANAGER_H
