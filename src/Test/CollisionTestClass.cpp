#include "CollisionTestClass.h"

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

    while (window.isOpen())
    {
        sf::Event event;
        while (window.waitEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if(event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Escape)
                    window.close();
            }
        }

        window.display();
    }

    return 0;
}
