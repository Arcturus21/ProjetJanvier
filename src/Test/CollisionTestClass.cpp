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
    CircleTest cr(200,200,75);

    vector<Collider*> listCollider;
    listCollider.push_back(new SquareTest(0,0,10,20));
    listCollider.push_back(new CircleTest(0,0,15));

    int actualCollider=0;

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
            else if(event.type == sf::Event::MouseButtonPressed)
            {
                actualCollider = (actualCollider+1)%listCollider.size();
            }
        }

        //listCollider[actualCollider]->setPosition(sf::Mouse::getPosition()(window));
        //listCollider[actualCollider]->Set(sf::Mouse::getPosition()(window));

        window.clear();

        window.draw(sq);
        window.draw(cr);

        window.display();
    }

    for(int i=0;i<listCollider.size();i++)
        delete(listCollider[i]);


    return 0;
}
