#include "PointCollider.h"

PointCollider::PointCollider(float x,float y)
{
    //ctor
    _p.x=x;
    _p.y=y;
}

PointCollider::~PointCollider()
{
    //dtor
}

bool PointCollider::Collision(Point& c)
{
    return _p.x==c.x && _p.y==c.y;
}

/*bool PointCollider::Collision(SegmentCollider& c)
{
    return c.Collision(_p);
}*/

bool PointCollider::Collision(AABBCollider& c)
{
    return c.Collision(_p);
}

bool PointCollider::Collision(CircleCollider& c)
{
    return c.Collision(_p);
}

AABBCollider* PointCollider::GetSurroundingAABB()
{
    AABBCollider *c = new AABBCollider(_p.x, _p.y, 1,1);
    return c;
}
