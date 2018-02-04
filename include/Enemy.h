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

        void move(float offsetX, float offsetY);
        void move(const sf::Vector2f& offset);
        void setPosition(float posX, float posY);
        void setPosition(const sf::Vector2f& pos);

        const CircleCollider& GetCollider() const;

        Vector Lerp(const sf::Vector2f& cible, float step);

        void SetCible(sf::Vector2f* cible);

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
            target.draw(_shape, states);
        }

    private:
        sf::CircleShape _shape;
        sf::Vector2f* _cible;        ///A initialiser

        CircleCollider _collider;


        int _lifePoint;
        float _speed;
        float _recoveringTime;
        float _elapsedTime;

        typedef enum
        {
            idle,
            walking,
            touched,
            recovering,
            dead
        }TurretState;
        TurretState _state;
};

#endif // ENEMY_H
