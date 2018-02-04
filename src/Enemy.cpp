#include "Enemy.h"

#define ENEMY_RADIUS 20
#define SPEED 100
#define RECOVERING_TIME 1.5
#define LIFE_POINT 3

Enemy::Enemy(float posX, float posY) : Object("Enemy"), _shape(ENEMY_RADIUS),_cible(NULL), _collider(posX+ENEMY_RADIUS,posY+ENEMY_RADIUS,ENEMY_RADIUS),
    _lifePoint(LIFE_POINT), _speed(SPEED), _recoveringTime(RECOVERING_TIME), _elapsedTime(0), _state(idle)
{
    //ctor
    setOrigin(ENEMY_RADIUS,ENEMY_RADIUS);
}

Enemy::~Enemy()
{
    //dtor
}

void Enemy::Update(float elapsedTime)
{
    if(!IsActive())
        return;

    _elapsedTime+=elapsedTime;
    if(_state==idle && _cible!=NULL)
        _state=walking;

    if(_state==walking)
    {
        if(_cible==NULL)
        {
            _state=idle;
            return;
        }
        Transformable::setRotation(MathLib::GetAngleToOrigin(Point(getPosition().x,getPosition().y), Point(_cible->x,_cible->y)));

        //float squareDistanceToDo = MathLib::SquareDistance(getPosition().x,getPosition().y,_cible->x,_cible->y);
        //float squareSpeed=_speed*_speed;

        //if(squareDistanceToDo>=squareSpeed)
        //{
        move(sf::Vector2f(_speed*cos(getRotation()), _speed*sin(getRotation()))*elapsedTime);
        //}


        //std::cout << getRotation() << std::endl;
        std::cout << getPosition().x << " " << getPosition().y << " - " << _speed*cos(getRotation()) << " " << _speed*sin(getRotation()) << std::endl;
        ///move(moveToDo*elapsedTime*_speed);
    }
    else if(_state==touched)
    {

    }
    else if(_state==recovering)
    {

        if(_elapsedTime>=_recoveringTime)
        {
            _elapsedTime=0;
            _state=walking;
        }
    }
}

///Surcharge fonction
void Enemy::move(float offsetX, float offsetY)
{
    Transformable::move(offsetX, offsetY);
}

void Enemy::move(const sf::Vector2f& offset)
{
    Transformable::move(offset);
}

void Enemy::setPosition(float posX, float posY)
{
    Transformable::setPosition(posX,posY);
}

void Enemy::setPosition(const sf::Vector2f& pos)
{
    Transformable::setPosition(pos);
}

Vector Enemy::Lerp(const sf::Vector2f& cible, float step)           ///NAZE
{
    Vector deplacement(cible.x-getPosition().x,cible.y-getPosition().y);
    return deplacement;
}

void Enemy::SetCible(sf::Vector2f* cible)
{
    _cible=cible;
}
