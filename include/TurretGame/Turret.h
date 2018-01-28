#ifndef TURRET_H
#define TURRET_H

#include <SFML/Graphics.hpp>

#include "CircleCollider.h"

#include "Object.h"
#include "Bullet.h"

class Turret : public sf::Drawable, public sf::Transformable, public Object
{
    public:
        Turret(float posX=0, float posY=0);
        virtual ~Turret();

        void Update(float elapsedTime);

        Bullet* Fire();

        const CircleCollider& GetCollider() const;

        void RotateTo(float angle=0);

        float Slerp(float angle, float step);

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
            target.draw(_turretBase, states);
            target.draw(_gun, states);
        }

    private:

        sf::CircleShape _turretBase;
        sf::RectangleShape _gun;

        CircleCollider _collider;

        ///Constante
        float _rotateSpeed;
        float _angleToReach;
        float _shootingDelay;
        float _reloadDelay;
        float _elapsedTime;

        int _cardrigeSize;
        int _nbBulletLeft;

        typedef enum
        {
            idle,
            shooting,
            reloading,
            dead
        }TurretState;
        TurretState _state;
};

#endif // TURRET_H
