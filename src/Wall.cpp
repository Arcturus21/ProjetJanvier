#include "Wall.h"

Wall::Wall(float posX, float posY, int w, int h) : Object("Wall"), _shape(sf::Vector2f(w,h)), _collider(posX,posY,w,h)
{
    //ctor
    setPosition(posX,posY);
}

Wall::~Wall()
{
    //dtor
}


void Wall::Update(float elapsedTime)
{
    if(!IsActive())
        return;
}

const AABBCollider& Wall::GetCollider() const
{
    return _collider;
}
