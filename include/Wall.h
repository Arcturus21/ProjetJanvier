#ifndef WALL_H
#define WALL_H

#include <SFML/Graphics.hpp>

#include "AABBCollider.h"

#include "Object.h"

class Wall : public sf::Drawable, public sf::Transformable, public Object
{
    public:
        Wall(float posX=0, float posY=0, int w=1, int h=1);
        virtual ~Wall();

        void Update(float elapsedTime);

        const AABBCollider& GetCollider() const;

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
            target.draw(_shape, states);
        }

    private:
        sf::RectangleShape _shape;

        AABBCollider _collider;
};

#endif // WALL_H
