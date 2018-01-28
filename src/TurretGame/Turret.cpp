#include "Turret.h"

#define TURRET_RADIUS 30

using namespace std;

Turret::Turret(float posX, float posY) : Object("Turret"), _turretBase(TURRET_RADIUS), _gun(sf::Vector2f(50,20)), _collider(posX+TURRET_RADIUS,posY+TURRET_RADIUS,TURRET_RADIUS),
    _rotateSpeed(150), _shootingDelay(0.2), _reloadDelay(2), _elapsedTime(1000), _cardrigeSize(30), _nbBulletLeft(10), _state(idle)
{
    //ctor
    setOrigin(_turretBase.getRadius(),_turretBase.getRadius());
    sf::Vector2f posGun(_turretBase.getLocalBounds().width/2, _turretBase.getLocalBounds().height/2-_gun.getLocalBounds().height/2);
    _gun.setPosition(posGun);
    setPosition(posX,posY);

    _turretBase.setFillColor(sf::Color::Blue);
    _gun.setFillColor(sf::Color::Green);
}

Turret::~Turret()
{
    //dtor
}

void Turret::Update(float elapsedTime)
{
    if(!IsActive())
        return;

    _elapsedTime+=elapsedTime;

    if(_state==reloading)
    {
        if(_elapsedTime>=_reloadDelay)
        {
            _state=idle;
            _nbBulletLeft=_cardrigeSize;
        }
        else
        {
            _nbBulletLeft=_elapsedTime/_reloadDelay*_cardrigeSize;
        }
    }

    if(_angleToReach!=getRotation())
        rotate(Slerp(_angleToReach, _rotateSpeed)*elapsedTime);
}

Bullet* Turret::Fire()
{
    if(_state!=shooting)
    {
        if(_state==idle)
            _state=shooting;
        else
            return NULL;
    }

    Bullet* b = new Bullet(getPosition(),getRotation());

    if(_elapsedTime<_shootingDelay)
        return NULL;
    else
        _elapsedTime=0;

    _nbBulletLeft--;
    if(_nbBulletLeft<=0)
        _state=reloading;

    return b;
}

const CircleCollider& Turret::GetCollider() const
{
    return _collider;
}

void Turret::RotateTo(float angle)
{
    _angleToReach=angle;
}

float Turret::Slerp(float angle, float step)
{
    float angleToDo=angle-getRotation();
    angleToDo=MathLib::ClampAngle(angleToDo,-180,180);

    if(angleToDo<0 && -angleToDo>step)
    {
        angleToDo=-step;
    }
    else if(angleToDo>0 && angleToDo>step)
    {
        angleToDo=step;
    }
    return angleToDo;
}
