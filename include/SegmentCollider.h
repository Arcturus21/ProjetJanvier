#ifndef SEGMENTCOLLIDER_H
#define SEGMENTCOLLIDER_H

#include "MathLib.h"

#include "Collider.h"

class SegmentCollider : public Collider
{
    public:
        SegmentCollider(float x1, float y1, float x2, float y2);
        virtual ~SegmentCollider();

        bool Collision(const Point& A, const Point& B) const;
        bool Collision(const SegmentCollider& S);

        bool Collision(PointCollider& c){return false;};

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
