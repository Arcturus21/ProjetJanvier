#include "../include/AABBCollider.h"

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

bool AABBCollider::Collision(PointCollider& c)
{
    return Collision(c.GetPoint().x,c.GetPoint().y);
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

AABBCollider* AABBCollider::GetSurroundingAABB()
{
    AABBCollider* c = new AABBCollider(_x,_y,_w,_h);
    return c;
}

void AABBCollider::SetPosition(float x, float y)
{
    _x=x;
    _y=y;
}

Point AABBCollider::GetPointTopLeft()
{
    Point p;
    p.x=_x;
    p.y=_y;
    return p;
}

Point AABBCollider::GetPointTopRight()
{
    Point p;
    p.x=_x+_w;
    p.y=_y;
    return p;
}

Point AABBCollider::GetPointBottomLeft()
{
    Point p;
    p.x=_x;
    p.y=_y+_h;
    return p;
}

Point AABBCollider::GetPointBottomRight()
{
    Point p;
    p.x=_x+_w;
    p.y=_y+_h;
    return p;
}
