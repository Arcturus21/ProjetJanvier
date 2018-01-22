#ifndef SQUARETEST_H
#define SQUARETEST_H

#include <SFML/Graphics.hpp>
#include "AABBCollider.h"

class SquareTest : public sf::Drawable, public sf::Transformable, public AABBCollider
{
    public:
        SquareTest(float x, float y, int w, int h);
        virtual ~SquareTest();

        void setPosition(const sf::Vector2f& position){AABBCollider::SetX(position.x);
                                                    AABBCollider::SetY(position.y);
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
        sf::VertexArray m_vertices;
};

#endif // SQUARETEST_H
