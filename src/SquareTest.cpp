#include "SquareTest.h"

SquareTest::SquareTest(float x, float y, int w, int h) : AABBCollider(x,y,w,h), m_vertices(sf::LinesStrip, 5)
{
    //ctor
    m_vertices[0].position = sf::Vector2f(x,y);
    m_vertices[1].position = sf::Vector2f(x+w,y);
    m_vertices[2].position = sf::Vector2f(x+w,y+h);
    m_vertices[3].position = sf::Vector2f(x,y+h);
    m_vertices[4].position = sf::Vector2f(x,y);

    m_vertices[0].color = sf::Color::Red;
    m_vertices[1].color = sf::Color::Red;
    m_vertices[2].color = sf::Color::Red;
    m_vertices[3].color = sf::Color::Red;
    m_vertices[4].color = sf::Color::Red;
}

SquareTest::~SquareTest()
{
    //dtor
}
