#include "Bullet.h"

#include <math.h>
#include <iostream>

#include "MathLib.h"

#define BULLET_SPEED 500
#define BULLET_LIFESPAN 2

#define RADIUS 5

Bullet::Bullet(sf::Vector2f pos, float shootingAngle) : Object("Bullet"), _speed(BULLET_SPEED), _lifeSpanInSeconds(BULLET_LIFESPAN), _shape(RADIUS), _collider(pos.x+RADIUS,pos.y+RADIUS,RADIUS)
{
    //ctor
    setOrigin(_shape.getRadius(), _shape.getRadius());
    setPosition(pos);
    setRotation(shootingAngle);
}

Bullet::~Bullet()
{
    //dtor
}

void Bullet::Update(float elapsedTime)
{
    if(!IsActive())
        return;

    _lifeSpanInSeconds-=elapsedTime;
    if(_lifeSpanInSeconds<=0)
    {
        SetActive(false);
        return;
    }

    move(cos(MathLib::DegreeToRad(getRotation()))*_speed*elapsedTime,sin(MathLib::DegreeToRad(getRotation()))*_speed*elapsedTime);
}

const CircleCollider& Bullet::GetCollider() const
{
    return _collider;
}
