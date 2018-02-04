#include <iostream>
#include <SFML/Graphics.hpp>

#include "include/Test/CollisionTestClass.h"
#include "include/TurretGame/TurretGame.h"

void clamp(sf::CircleShape& shape, sf::RenderWindow& window);

int main()
{


    sf::RenderWindow window(sf::VideoMode(1200, 800), "Janvier");
    //sf::CircleShape shape(50.f);
    //shape.setFillColor(sf::Color::Green);

    //CollisionTestClass::testCollision(window);
    TurretGame::Game(window);
    //TurretGame::TestTurret(window);

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

                if(event.key.code == sf::Keyboard::C)
                    CollisionTestClass::testCollision(window);
            }
        }

        /*shape.setPosition((sf::Vector2f)(sf::Mouse::getPosition(window))-sf::Vector2f(shape.getRadius(), shape.getRadius()));
        clamp(shape,window);

        window.clear();
        window.draw(shape);*/
        window.display();
    }

    return 0;
}

void clamp(sf::CircleShape& shape, sf::RenderWindow& window)
{
    float xTemp,yTemp;
    xTemp=shape.getPosition().x;
    yTemp=shape.getPosition().y;

    if(xTemp<0)
        xTemp=0;
    else if(xTemp+shape.getLocalBounds().width>window.getSize().x)
        xTemp=window.getSize().x-shape.getLocalBounds().width;

    if(yTemp<0)
        yTemp=0;
    else if(yTemp+shape.getLocalBounds().height>window.getSize().y)
        yTemp=window.getSize().y-shape.getLocalBounds().height;

    shape.setPosition(xTemp,yTemp);
}
