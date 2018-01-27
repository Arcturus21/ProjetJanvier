#include "Wall.h"

Wall::Wall(float posX, float posY, int w, int h) : Object("Wall"), _shape(sf::Vector2f(50,20)), _collider(posX,posY,w,h)
{
    //ctor
    _shape.setSize(sf::Vector2f(w,h));
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
