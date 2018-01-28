#include "TurretGame.h"

#include "Wall.h"

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
    Wall wall(800,100,100,400);
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

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            Bullet* tmpBullet=t.Fire();
            if(tmpBullet!=NULL)
                listBullet.push_back(tmpBullet);
        }


        float mouseAngle=TurretGame::GetMouseAngle(Point(t.getPosition().x,t.getPosition().y),Point(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y));

        t.RotateTo(mouseAngle);
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

        window.draw(wall);

        for(unsigned int i=0; i<listBullet.size(); i++)
        {
            window.draw(*listBullet[i]);
        }
        window.draw(t);

        window.display();
    }

    for(unsigned int i=0; i<listBullet.size(); i++)
    {
        delete(listBullet[i]);
    }

    return 0;
}

float TurretGame::GetMouseAngle(const Point& origine, const Point& mousePos)
{
    if(origine!=mousePos) ///Si la souris est sur le centre de la tourelle, pas la peine de tourner
    {
        Vector OA(origine,mousePos);                                                ///Vecteur tourelle-souris
        Vector OO(origine,Point(mousePos.x, origine.y)); ///Vecteur tourelle-origine

        float mouseAngle=0;                         ///Angle entre la souris et l'origine
        if(OA.Norm()>0 && OA.Norm()>=OO.Norm())    ///On test si la norme du vecteur est nulle et si l'axe OA est bien l'hypothénuse du triangle souris-tourelle-origine (plante sinon)
            mouseAngle=MathLib::RadToDegree(Vector::GetAngle(OO,OA));


        return MathLib::AcosAngleToRealAngle(mouseAngle,origine,mousePos);
    }
    return 0;
}
