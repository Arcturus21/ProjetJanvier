#ifndef CIRCLETEST_H
#define CIRCLETEST_H

#include <SFML/Graphics.hpp>
#include "CircleCollider.h"

class CircleTest : public sf::Drawable, public sf::Transformable
{
    public:
        CircleTest(float x, float y, float radius);
        virtual ~CircleTest();

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
        sf::CircleShape m_vertices;
        CircleCollider _collider;
};

#endif // CIRCLETEST_H
