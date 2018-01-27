#include "../include/ConvexPolygonCollider.h"

ConvexPolygonCollider::ConvexPolygonCollider(const std::vector<Point>& listPoint):_listPoint(listPoint)
{
    //ctor
}

ConvexPolygonCollider::~ConvexPolygonCollider()
{
    //dtor
}

bool ConvexPolygonCollider::Collision(float pointX, float pointY)
{
    Point p;
    p.x=pointX;
    p.y=pointY;
    return Collision(p);
}

bool ConvexPolygonCollider::Collision(Point& p)  ///Test si le point est toujours à gauche des points du polygone
{
    unsigned int i;
    for(i=0; i<_listPoint.size();i++)
    {
        Point A=_listPoint[i];
        Point B;

        if(i==_listPoint.size()-1)   ///Si c'est le dernier point, on relie au premier
            B=_listPoint[0];
        else
            B=_listPoint[i+1];      ///Sinon on relie au suivant

        Vector D(A,B),T(A,p);

        float d = Vector::Determinant(D,T);
        if(d<0)
            return false;   ///Si un point est à droite le point testé est en dehors du polygone
    }
    return true;    ///Tous les points sont à gauche : le point testé est dans le polygone
}

bool ConvexPolygonCollider::Collision(PointCollider& c)
{
    Point p=c.GetPoint();
    return Collision(p);
}
