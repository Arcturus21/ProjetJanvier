#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>

#include "CircleCollider.h"

#include "Object.h"
#include "Bullet.h"

class Enemy : public sf::Drawable, public sf::Transformable, public Object
{
    public:
        Enemy(float posX=0, float posY=0);
        virtual ~Enemy();

        void Update(float elapsedTime);

        const CircleCollider& GetCollider() const;

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
        sf::CircleShape _shape;
        sf::Vector2f _cible;        ///A initialiser

        CircleCollider _collider;

        ///Constante
        float _speed;
};

#endif // ENEMY_H
