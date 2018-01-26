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

        bool Collision(Point p);

    protected:

    private:
        std::vector<Point> _listPoint;
};

#endif // CONVEXPOLYGONCOLLIDER_H
