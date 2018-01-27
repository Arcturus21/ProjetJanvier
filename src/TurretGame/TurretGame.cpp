#include "TurretGame.h"

#include "Turret.h"
#include "Bullet.h"

#include <deque>

#define SPEED 0.1
#define ROTATE_SPEED 0.05

TurretGame::TurretGame()
{
    //ctor
}

TurretGame::~TurretGame()
{
    //dtor
}

int TurretGame::Game(sf::RenderWindow& window)
{
    Turret t(500,500);

    std::deque<Bullet*> listBullet;

    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if(event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Escape)
                    window.close();
            }
        }
        sf::Time elapsed = clock.restart();

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            Bullet* tmpBullet=t.Fire();
            if(tmpBullet!=NULL)
                listBullet.push_back(tmpBullet);
        }

        t.Update(elapsed.asSeconds());
        while(listBullet.size() != 0 && (listBullet[0]==NULL || !listBullet[0]->IsActive()))
        {
            delete listBullet[0];
            listBullet.pop_front();
        }
        for(unsigned int i=0; i<listBullet.size(); i++)
        {
            listBullet[i]->Update(elapsed.asSeconds());
        }

        window.clear();

        window.draw(t);
        for(unsigned int i=0; i<listBullet.size(); i++)
        {
            window.draw(*listBullet[i]);
        }

        window.display();
    }

    for(unsigned int i=0; i<listBullet.size(); i++)
    {
        delete(listBullet[i]);
    }

    return 0;
}
