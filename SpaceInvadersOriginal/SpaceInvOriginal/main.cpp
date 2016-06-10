#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "TimeManager.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "BulletManager.h"
#include "Randomizer.h"
#include "EnemyManager.h"
#include "Interface.h"
#include "AudioManager.h"
#include "menu.h"
#include <vector>


int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Space Invaders");
    //STARTING SETTINGS

    AudioManager audioManager;
    BulletManager bulletManager;
    EnemyManager enemyManager;
    Randomizer random;
    TimeManager time;
    Menu mainMenu;
    Interface mainInterface;
    Player player(400, 500);
    Player *playerWsk = &player;

    //CONTROL VARIABLES
    bool menu = true;
    bool init = false;
    bool menuMusic = false;
    bool stageTwo = false;


    mainMenu.loadData();

    while (window.isOpen())
    {
        if(menu == false)
        {

            if(init == false)
            {
                audioManager.stopMenu();
                menuMusic = false;

                player.setHealth(3);


                //CREATING ENEMIES and INITILIAZING
                enemyManager.addEnemies(); //2 ROWS


                random.initialize();
                audioManager.playMusic();
                init = true;
            }
        if((stageTwo == false) && (mainInterface.getScore() >= 280))
        {
            enemyManager.addEnemiesMedium();
            stageTwo = true;

        }
        if((mainInterface.getScore() >= 560))
        {
            audioManager.stopMusic();
            init = false;
            menu = true;
        }

        time.updateShoot();
        time.updateRandomShoot();
        // REFRESHING WINDOW
        // ALL PHYSICS HERE

        while(time.getAccumulator() > time.getUps())
        {
            time.updateAccumulator();
            player.keyboardControl(time.getUps(), bulletManager, time.getShootTimer(), time, audioManager);
            enemyManager.controlEnemies(random, bulletManager, time);
            bulletManager.controlBullets(time.getUps());


            //COLLISIONS
            bulletManager.checkPlayerCollisions(playerWsk);
            enemyManager.updateDead(bulletManager);
            player.gameOver(audioManager, menu, init);

        }


        //SIMPLE EVENTS
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        mainInterface.checkRecords(mainMenu);

        //DRAWING
        window.clear();
        mainInterface.drawText(window, player.getHealth());
        enemyManager.drawEnemies(window);
        window.draw(player.getSprite());
        bulletManager.drawBullets(window);
        window.display();

         if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                window.close();
            }

        time.restartAccumulator();
        }
        else
        {

            if(menuMusic == false)
            {
                audioManager.playMenu();
                menuMusic = true;
            }

            enemyManager.clearAll();
            bulletManager.clearAll();
            time.clearAll();
            mainInterface.clearScore();

            mainMenu.keyboardControl(window, menu);

            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                window.close();
            }
            window.clear();
            mainMenu.drawMenu(window);
            window.display();

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                window.close();
            }
        }


    }

    return EXIT_SUCCESS;
}
