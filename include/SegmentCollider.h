#ifndef SEGMENTCOLLIDER_H
#define SEGMENTCOLLIDER_H

#include "MathLib.h"

#include "Collider.h"
#include "PointCollider.h"
#include "AABBCollider.h"
#include "CircleCollider.h"
class SegmentCollider : public Collider
{
    public:
        SegmentCollider(float x1, float y1, float x2, float y2);
        virtual ~SegmentCollider();

        ///Test COLLISION
        bool Collision(float x, float y){return false;};        ///Collision avec un point
        bool Collision(Point& p){return false;};
        bool Collision(PointCollider& c){return false;};
        bool Collision(SegmentCollider& s);      ///Collision avec un segment
        bool Collision(AABBCollider& box);       ///Collision avec une AABBox
        bool Collision(CircleCollider& c);       ///Collision avec un cercle
        bool Collision(ConvexPolygonCollider& c){return false;};

        bool Collision(const Point& A, const Point& B);

        ///Getter
        Point GetA(){return _a;};
        void SetA(float x, float y){_a.x=x;_a.y=y;};
        void SetA(Point a){_a=a;};
        Point GetB(){return _b;};
        void SetB(float x, float y){_b.x=x;_b.y=y;};
        void SetB(Point b){_b=b;};

    protected:

    private:
        Point _a, _b;
};

#endif // SEGMENTCOLLIDER_H
