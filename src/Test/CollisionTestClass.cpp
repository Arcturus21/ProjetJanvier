#include "../../include/Test/CollisionTestClass.h"


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
    CircleTest cr(200,200,75);

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

        window.clear();

        window.draw(sq);
        window.draw(cr);

        window.display();
    }

    return 0;
}
