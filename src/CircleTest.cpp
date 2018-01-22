#include "CircleTest.h"

CircleTest::CircleTest(float x, float y, float radius): CircleCollider(x,y,radius), m_vertices(radius)
{
    //ctor
    m_vertices.setPosition(x,y);
    m_vertices.setFillColor(sf::Color::Black);
    m_vertices.setOutlineThickness(2);
    m_vertices.setOutlineColor(sf::Color::Red);
}

CircleTest::~CircleTest()
{
    //dtor
}
