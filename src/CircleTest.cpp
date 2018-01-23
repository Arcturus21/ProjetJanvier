#include "CircleTest.h"

CircleTest::CircleTest(float x, float y, float radius): CircleCollider(x,y,radius), m_vertices(radius)
{
    //ctor
    m_vertices.setPosition(x-GetRadius(),y-GetRadius());
    m_vertices.setFillColor(sf::Color::Black);
    m_vertices.setOutlineThickness(2);
    m_vertices.setOutlineColor(sf::Color::Red);
}

CircleTest::~CircleTest()
{
    //dtor
}

void CircleTest::SetPosition(const sf::Vector2f& position)
{
    CircleCollider::SetPosition(position.x+GetRadius(),position.y+GetRadius());
    m_vertices.setPosition(position);
};

void CircleTest::SetColor(sf::Color c)
{
    m_vertices.setOutlineColor(c);
}
