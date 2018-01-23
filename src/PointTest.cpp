#include "PointTest.h"

PointTest::PointTest(float x, float y, float size) : PointCollider(x,y), m_vertices(sf::Lines, 4)
{
    //ctor
    m_vertices[0].position = sf::Vector2f(x-size/2,y);
    m_vertices[1].position = sf::Vector2f(x+size/2,y);
    m_vertices[2].position = sf::Vector2f(x,y-size/2);
    m_vertices[3].position = sf::Vector2f(x,y+size/2);

    m_vertices[0].color = sf::Color::Red;
    m_vertices[1].color = sf::Color::Red;
    m_vertices[2].color = sf::Color::Red;
    m_vertices[3].color = sf::Color::Red;

    _size=size;
}

PointTest::~PointTest()
{
    //dtor
}

void PointTest::SetPosition(const sf::Vector2f& position)
{
    PointCollider::SetPosition(position.x,position.y);
    m_vertices[0].position = sf::Vector2f(position.x-_size/2,position.y);
    m_vertices[1].position = sf::Vector2f(position.x+_size/2,position.y);
    m_vertices[2].position = sf::Vector2f(position.x,position.y-_size/2);
    m_vertices[3].position = sf::Vector2f(position.x,position.y+_size/2);
}

void PointTest::SetColor(sf::Color c)
{
    for(unsigned int i=0;i<m_vertices.getVertexCount();i++)
    {
        m_vertices[i].color = c;
    }
}
