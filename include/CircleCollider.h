#ifndef CIRCLECOLLIDER_H
#define CIRCLECOLLIDER_H

///General library
#include "MathLib.h"

///Collider library
#include "Collider.h"

#include "AABBCollider.h"
#include "SegmentCollider.h"

class CircleCollider : public Collider
{
    public:
        CircleCollider(float x=0, float y=0, float radius=1);
        virtual ~CircleCollider();

        ///Test COLLISION
        bool Collision(float x, float y);       ///Collision avec un point
        bool Collision(Point& p);
        bool Collision(CircleCollider& c);       ///Collision avec un cercle
        bool Collision(Point& a, Point& b);       ///Collision avec une droite
        bool Collision(SegmentCollider& s);      ///Collision avec un segment
        bool Collision(AABBCollider& box);       ///Collision avec une AABBox

        ///Utilitaire
        AABBCollider GetSurroundingAABB();
        Point GetCenter(){return Point{_x,_y};};

    protected:

    private:
        float _x,_y;
        float _radius;
};

#endif // CIRCLECOLLIDER_H
