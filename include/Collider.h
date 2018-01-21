#ifndef COLLIDER_H
#define COLLIDER_H

///AJOUTER GESTION POINT D'IMPACT (+moment?) ET NORMALE POINT?

#include "MathLib.h"

class SegmentCollider;
class AABBCollider;
class CircleCollider;
class ConvexPolygonCollider;

class Collider
{
    public:
        Collider();
        virtual ~Collider();

        virtual bool Collision(Point& c)=0;
        virtual bool Collision(SegmentCollider& c){};
        virtual bool Collision(AABBCollider& c){};
        virtual bool Collision(CircleCollider& c){};
        virtual bool Collision(ConvexPolygonCollider& c){};

        void SetTrigger(bool trigger){_isTrigger=trigger;};
        bool IsTrigger(){return _isTrigger;};

    protected:

    private:
        bool _isTrigger;
        Point _impactPoint;
};

#endif // COLLIDER_H
