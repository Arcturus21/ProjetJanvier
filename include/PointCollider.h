#ifndef POINTCOLLIDER_H
#define POINTCOLLIDER_H

#include "Collider.h"
#include "AABBCollider.h"
#include "SegmentCollider.h"
#include "CircleCollider.h"

class PointCollider : public Collider
{
    public:
        PointCollider(float x=0,float y=0);
        virtual ~PointCollider();

        bool Collision(Point& c);
        bool Collision(SegmentCollider& c){return false;};
        bool Collision(AABBCollider& c);
        bool Collision(CircleCollider& c);
        bool Collision(ConvexPolygonCollider& c){return false;};

        ///Utilitaire
        AABBCollider* GetSurroundingAABB();

        ///Getter&Setter
        Point GetPoint(){return _p;};
        void SetPoint(float x, float y){_p=Point{x,y};};
        void SetPoint(Point p){_p=p;};

    protected:

    private:
        Point _p;
};

#endif // POINTCOLLIDER_H
