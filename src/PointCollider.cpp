#include "PointCollider.h"

PointCollider::PointCollider(float x,float y):_x(x),_y(y)
{
    //ctor
}

PointCollider::~PointCollider()
{
    //dtor
}

bool PointCollider::Collision(Point& c)
{
    return _x==c.x && _y==c.y;
}

bool PointCollider::Collision(PointCollider& c)
{
    return (_x==c._x) && (_y==c._y);
}

bool PointCollider::Collision(AABBCollider& c)
{
    return c.Collision(_x,_y);
}

bool PointCollider::Collision(CircleCollider& c)
{
    return c.Collision(_x,_y);
}

AABBCollider* PointCollider::GetSurroundingAABB()
{
    AABBCollider *c = new AABBCollider(_x, _y, 1,1);
    return c;
}

void PointCollider::SetPosition(float x, float y)
{
    _x=x;
    _y=y;
}

Point PointCollider::GetPoint()
{
    Point p;
    p.x=_x;
    p.y=_y;
    return p;
}
