#ifndef AABBCOLLIDER_H
#define AABBCOLLIDER_H

///General library
#include "MathLib.h"

///Collider library
#include "Collider.h"
#include "CircleCollider.h"

class AABBCollider : public Collider
{
    public:
        AABBCollider(float x=0, float y=0, int w=1, int h=1);
        virtual ~AABBCollider();

        ///Test COLLISION
        bool Collision(float pointX, float pointY);
        bool Collision(Point& p);
        bool Collision(SegmentCollider& c){return false;};
        bool Collision(AABBCollider& c);
        bool Collision(CircleCollider& c);
        bool Collision(ConvexPolygonCollider& c){return false;};

        ///Utilitaire
        Point GetPointTopLeft(){return Point{_x,_y};};
        Point GetPointTopRight(){return Point{_x+_w,_y};};
        Point GetPointBottomLeft(){return Point{_x,_y+_h};};
        Point GetPointBottomRight(){return Point{_x+_w,_y+_h};};

        AABBCollider* GetSurroundingAABB();

        ///Getter&Setter
        void SetX(float x){_x=x;};
        float GetX(){return _x;};
        void SetY(float y){_y=y;};
        float GetY(){return _y;};
        void SetW(float w){_w=w;};
        float GetW(){return _w;};
        void SetH(float h){_h=h;};
        float GetH(){return _h;};

    protected:

    private:
        float _x,_y;
        int _w, _h;
};

#endif // AABBCOLLIDER_H
