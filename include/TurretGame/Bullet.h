#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>

#include "Object.h"

#include "CircleCollider.h"

class Bullet : public sf::Drawable, public sf::Transformable, public Object
{
    public:
        Bullet(sf::Vector2f pos, float shootingAngle);
        virtual ~Bullet();

        void Update(float elapsedTime);

        const CircleCollider& GetCollider() const;

    protected:

    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
        {
            if(!IsActive())
                return;
            // on applique la transformation de l'entité -- on la combine avec celle qui a été passée par l'appelant
            states.transform *= getTransform(); // getTransform() est définie par sf::Transformable

            // on applique la texture
            states.texture = NULL;

            // on peut aussi surcharger states.shader ou states.blendMode si nécessaire

            // on dessine le tableau de vertex
            target.draw(_shape, states);
        }

    private:
        float _speed;
        float _lifeSpanInSeconds;

        sf::CircleShape _shape;

        CircleCollider _collider;
};

#endif // BULLET_H
