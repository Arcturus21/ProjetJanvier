#include "ConvexPolygonTest.h"

ConvexPolygonTest::ConvexPolygonTest(std::vector<Point>& listPoint):ConvexPolygonCollider(listPoint),m_vertices(sf::LinesStrip, listPoint.size()+1)
{
    //ctor
    for(unsigned int i=0;i<listPoint.size();i++)
    {
        m_vertices[i].position = sf::Vector2f(listPoint[i].x,listPoint[i].y);
        m_vertices[i].color = sf::Color::Red;
        //std::cout << m_vertices[i].position.x << ' ' << m_vertices[i].position.y << std::endl;
        std::cout << listPoint[i].x << ' ' << listPoint[i].y << std::endl;
    }
    m_vertices[listPoint.size()].position=m_vertices[0].position;
        m_vertices[listPoint.size()].color = sf::Color::Red;
}

ConvexPolygonTest::~ConvexPolygonTest()
{
    //dtor
}

void ConvexPolygonTest::SetPosition(const sf::Vector2f& position)
{
    ///ConvexPolygonCollider::SetPosition(position.x,position.y);
    /*m_vertices[0].position=position;
    m_vertices[1].position=sf::Vector2f(position.x+GetW(),position.y);
    m_vertices[2].position=sf::Vector2f(position.x+GetW(),position.y+GetH());
    m_vertices[3].position=sf::Vector2f(position.x,position.y+GetH());
    m_vertices[4].position=position;*/
};

void ConvexPolygonTest::SetColor(sf::Color c)
{
    for(unsigned int i=0;i<m_vertices.getVertexCount();i++)
    {
        m_vertices[i].color = c;
    }
}
