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

        ///Getter
        Point getA(){return _a;};
        Point getB(){return _b;};

    protected:

    private:
        Point _a, _b;
};

#endif // SEGMENTCOLLIDER_H
