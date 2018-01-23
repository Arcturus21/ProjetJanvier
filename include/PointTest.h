#ifndef POINTTEST_H
#define POINTTEST_H

#include <SFML/Graphics.hpp>
#include "PointCollider.h"

class PointTest : public sf::Drawable, public sf::Transformable, public PointCollider
{
    public:
        PointTest(float x, float y, float size=30);
        virtual ~PointTest();

        void SetPosition(const sf::Vector2f& position);
        void SetColor(sf::Color c);
    protected:

    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
        {
            // on applique la transformation de l'entité -- on la combine avec celle qui a été passée par l'appelant
            states.transform *= getTransform(); // getTransform() est définie par sf::Transformable

            // on applique la texture
            states.texture = NULL;

            // on peut aussi surcharger states.shader ou states.blendMode si nécessaire

            // on dessine le tableau de vertex
            target.draw(m_vertices, states);
        }

    private:
        sf::VertexArray m_vertices;
        float _size;
};

#endif // POINTTEST_H
