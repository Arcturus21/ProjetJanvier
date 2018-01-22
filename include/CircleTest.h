#ifndef CIRCLETEST_H
#define CIRCLETEST_H

#include <SFML/Graphics.hpp>
#include "CircleCollider.h"

class CircleTest : public sf::Drawable, public sf::Transformable, public CircleCollider
{
    public:
        CircleTest(float x, float y, float radius);
        virtual ~CircleTest();

        void setPosition(const sf::Vector2f& position){CircleCollider::SetX(position.x);
                                                    CircleCollider::SetY(position.y);
                                                    setPosition(position);};

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
        sf::CircleShape m_vertices;
};

#endif // CIRCLETEST_H
