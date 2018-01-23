#ifndef CIRCLECOLLIDER_H
#define CIRCLECOLLIDER_H

///General library
#include "MathLib.h"

///Collider library
#include "Collider.h"

#include "PointCollider.h"
#include "AABBCollider.h"
#include "SegmentCollider.h"

class CircleCollider : public Collider
{
    public:
        CircleCollider(float x=0, float y=0, float radius=1);
        virtual ~CircleCollider();

        ///Test COLLISION
        bool Collision(float x, float y);        ///Collision avec un point
        bool Collision(Point& p);
        bool Collision(PointCollider& c);
        bool Collision(CircleCollider& c);       ///Collision avec un cercle
        bool Collision(Point& a, Point& b);      ///Collision avec une droite
        bool Collision(SegmentCollider& s);      ///Collision avec un segment
        bool Collision(AABBCollider& box);       ///Collision avec une AABBox

        ///Utilitaire
        AABBCollider* GetSurroundingAABB();
        Point GetCenter();
        void SetPosition(float x, float y);

        ///Getter & Setter
        void SetX(float x){_x=x;};
        float GetX(){return _x;};
        void SetY(float y){_y=y;};
        float GetY(){return _y;};
        void SetRadius(float radius){_radius=radius;};
        float GetRadius(){return _radius;};

    protected:

    private:
        float _x,_y;
        float _radius;
};

#endif // CIRCLECOLLIDER_H
