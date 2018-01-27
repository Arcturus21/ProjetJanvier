#include "../../include/Test/CollisionTestClass.h"

#include <iostream>

using namespace std;

CollisionTestClass::CollisionTestClass()
{
    //ctor
}

CollisionTestClass::~CollisionTestClass()
{
    //dtor
}

int CollisionTestClass::testCollision(sf::RenderWindow& window)
{
    SquareTest sq(50,50,100,100);
    CircleTest cr(300,300,50);

    std::vector<Point> listPoint;
    listPoint.push_back(Point(450,50));
    listPoint.push_back(Point(550,50));
    listPoint.push_back(Point(580,150));
    listPoint.push_back(Point(530,220));
    listPoint.push_back(Point(420,300));
    listPoint.push_back(Point(390,250));
    ConvexPolygonTest cp(listPoint);

    AABBCollider* crAABB=cr.GetSurroundingAABB();
    SquareTest crsq(crAABB->GetX(),crAABB->GetY(),crAABB->GetW(),crAABB->GetH());
    delete crAABB;

    //SquareTest colliderTest(0,0,50,50);
    //CircleTest colliderTest(0,0,15);
    PointTest colliderTest(0,0);

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

        sf::Vector2f mousePos=(sf::Vector2f)sf::Mouse::getPosition(window);
        colliderTest.SetPosition(mousePos);

        if(sq.Collision(colliderTest))
            sq.SetColor(sf::Color::Green);
        else
            sq.SetColor(sf::Color::Red);
        if(cr.Collision(colliderTest))
            cr.SetColor(sf::Color::Green);
        else
            cr.SetColor(sf::Color::Red);
        if(cp.Collision(colliderTest))
            cp.SetColor(sf::Color::Green);
        else
            cp.SetColor(sf::Color::Red);

        if(colliderTest.Collision(sq) || colliderTest.Collision(cr) || colliderTest.Collision(cp))
            colliderTest.SetColor(sf::Color::Green);
        else
            colliderTest.SetColor(sf::Color::Red);

        window.clear();

        window.draw(sq);
        window.draw(cr);
        window.draw(crsq);
        window.draw(cp);

        window.draw(colliderTest);

        window.display();
    }

    return 0;
}
