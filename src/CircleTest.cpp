#include "CircleTest.h"

CircleTest::CircleTest(float x, float y, float radius):m_vertices(radius), _collider(x,y,radius)
{
    //ctor
    m_vertices.setPosition(x,y);
    m_vertices.setFillColor(sf::Color::Red);
}

CircleTest::~CircleTest()
{
    //dtor
}
