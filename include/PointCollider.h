#ifndef POINTCOLLIDER_H
#define POINTCOLLIDER_H

#include "Collider.h"
#include "AABBCollider.h"
#include "SegmentCollider.h"
#include "CircleCollider.h"
#include "ConvexPolygonCollider.h"

class PointCollider : public Collider
{
    public:
        PointCollider(float x=0,float y=0);
        virtual ~PointCollider();

        bool Collision(float pointX, float pointY);
        bool Collision(Point& c);
        bool Collision(PointCollider& c);
        bool Collision(SegmentCollider& c){return false;};
        bool Collision(AABBCollider& c);
        bool Collision(CircleCollider& c);
        bool Collision(ConvexPolygonCollider& c);

        ///Utilitaire
        AABBCollider* GetSurroundingAABB();
        void SetPosition(float x, float y);

        ///Getter&Setter
        Point GetPoint();
        void SetPoint(float x, float y){_x=x;_y=y;};
        void SetPoint(Point p){_x=p.x;_y=p.y;};

    protected:

    private:
        float _x,_y;
};

#endif // POINTCOLLIDER_H
