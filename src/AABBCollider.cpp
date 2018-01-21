#include "AABBCollider.h"

AABBCollider::AABBCollider(float x, float y, int w, int h) : _x(x), _y(y), _w(w), _h(h)
{
    //ctor
}

AABBCollider::~AABBCollider()
{
    //dtor
}

bool AABBCollider::Collision(float pointX, float pointY)
{
    return !(pointX<_x || pointX>_x+_w ||
             pointY<_y || pointY>_y+_h);
}

bool AABBCollider::Collision(Point& p)
{
    return Collision(p.x,p.y);
}

bool AABBCollider::Collision(AABBCollider& c)
{
    return !(c._x > _x+_w ||
             c._x +c._w < _x ||
             c._y > _y+_h ||
             c._y +c._h < _y);
}

bool AABBCollider::Collision(CircleCollider& c)
{
    return c.Collision(*this);
}