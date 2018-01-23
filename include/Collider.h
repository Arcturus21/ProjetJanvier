#ifndef COLLIDER_H
#define COLLIDER_H

///AJOUTER GESTION POINT D'IMPACT (+moment?) ET NORMALE POINT?

#include "MathLib.h"

class PointCollider;
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
        virtual bool Collision(PointCollider& c)=0;
        virtual bool Collision(SegmentCollider& c)=0;
        virtual bool Collision(AABBCollider& c)=0;
        virtual bool Collision(CircleCollider& c)=0;
        virtual bool Collision(ConvexPolygonCollider& c){return false;};

        ///Utilitaire
        virtual AABBCollider* GetSurroundingAABB()=0;
        virtual void SetPosition(float x, float y)=0;

        ///Getter & Setter
        void SetTrigger(bool trigger){_isTrigger=trigger;};
        bool IsTrigger(){return _isTrigger;};


    protected:

    private:
        bool _isTrigger;
        Point _impactPoint;
};

#endif // COLLIDER_H
