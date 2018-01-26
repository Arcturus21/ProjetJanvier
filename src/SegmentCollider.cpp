#include "../include/SegmentCollider.h"

SegmentCollider::SegmentCollider(float x1, float y1, float x2, float y2)
{
    //ctor
    _a.x=x1;
    _a.y=y1;
    _b.x=x2;
    _b.y=y2;
}

SegmentCollider::~SegmentCollider()
{
    //dtor
}

bool SegmentCollider::Collision(const Point& A, const Point& B)
{
    Vector Aa, Ab, AB;
    AB.x = B.x-A.x;
    AB.y = B.y-A.y;
    Aa.x = _a.x-A.x;
    Aa.y = _a.y-A.y;
    Ab.x = _b.x-A.x;
    Ab.y = _b.y-A.y;

    ///VectorDeterminant �quivaut au calcul du d�terminant.
    ///Si les d�terminants ont le m�me signe (produit positif), ils sont du m�me c�t� (pas de collision), sinon non.
    return (MathLib::VectorDeterminant(AB,Ab)*MathLib::VectorDeterminant(AB,Aa)<0);
}

/*bool SegmentCollider::Collision(float x, float y)
{

}

bool SegmentCollider::Collision(Point& p)
{

}

bool SegmentCollider::Collision(PointCollider& c)
{

}*/

bool SegmentCollider::Collision(SegmentCollider& S)   ///A changer pour r�cup�rer le point de contact : https://openclassrooms.com/courses/theorie-des-collisions/formes-plus-complexes
{
    return (Collision(S._a,S._b) &&
             S.Collision(_a,_b));
}

bool SegmentCollider::Collision(AABBCollider& box)
{
    return box.Collision(*this);
}

bool SegmentCollider::Collision(CircleCollider& c)
{
    return c.Collision(*this);
}
