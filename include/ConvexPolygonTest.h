#ifndef CONVEXPOLYGONTEST_H
#define CONVEXPOLYGONTEST_H

#include <SFML/Graphics.hpp>
#include "ConvexPolygonCollider.h"

class ConvexPolygonTest : public sf::Drawable, public sf::Transformable, public ConvexPolygonCollider
{
    public:
        ConvexPolygonTest(std::vector<Point>& listPoint);
        virtual ~ConvexPolygonTest();

        void SetPosition(const sf::Vector2f& position);
        void SetColor(sf::Color c);

    protected:

    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
        {
            // on applique la transformation de l'entit� -- on la combine avec celle qui a �t� pass�e par l'appelant
            states.transform *= getTransform(); // getTransform() est d�finie par sf::Transformable

            // on applique la texture
            states.texture = NULL;

            // on peut aussi surcharger states.shader ou states.blendMode si n�cessaire

            // on dessine le tableau de vertex
            target.draw(m_vertices, states);
        }

    private:
        sf::VertexArray m_vertices;
};

#endif // CONVEXPOLYGONTEST_H
