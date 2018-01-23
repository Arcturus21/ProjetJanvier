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

void SquareTest::SetPosition(const sf::Vector2f& position)
{
    AABBCollider::SetPosition(position.x,position.y);
    m_vertices[0].position=position;
    m_vertices[1].position=sf::Vector2f(position.x+GetW(),position.y);
    m_vertices[2].position=sf::Vector2f(position.x+GetW(),position.y+GetH());
    m_vertices[3].position=sf::Vector2f(position.x,position.y+GetH());
    m_vertices[4].position=position;
};

void SquareTest::SetColor(sf::Color c)
{
    for(unsigned int i=0;i<m_vertices.getVertexCount();i++)
    {
        m_vertices[i].color = c;
    }
}
