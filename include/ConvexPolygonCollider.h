#ifndef CONVEXPOLYGONCOLLIDER_H
#define CONVEXPOLYGONCOLLIDER_H

#include <iostream>
#include <vector>

#include "MathLib.h"
#include "Collider.h"
#include "PointCollider.h"
#include "SegmentCollider.h"
#include "AABBCollider.h"
#include "CircleCollider.h"

class ConvexPolygonCollider : public Collider
{
    public:
        ConvexPolygonCollider(const std::vector<Point>& listPoint);
        virtual ~ConvexPolygonCollider();

        bool Collision(float pointX, float pointY);
        bool Collision(Point& p);
        bool Collision(PointCollider& c);
        bool Collision(SegmentCollider& c){return false;};
        bool Collision(AABBCollider& c){return false;};
        bool Collision(CircleCollider& c){return false;};
        bool Collision(ConvexPolygonCollider& c){return false;};

        AABBCollider* GetSurroundingAABB(){return NULL;};
        void SetPosition(float x, float y){};

    protected:

    private:
        std::vector<Point> _listPoint;
};

#endif // CONVEXPOLYGONCOLLIDER_H
