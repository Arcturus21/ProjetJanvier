#include "SegmentCollider.h"

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

bool SegmentCollider::Collision(const Point& A, const Point& B) const
{
    Vector Aa, Ab, AB;
    AB.x = B.x-A.x;
    AB.y = B.y-A.y;
    Aa.x = _a.x-A.x;
    Aa.y = _a.y-A.y;
    Ab.x = _b.x-A.x;
    Ab.y = _b.y-A.y;

    ///CrossProductNorm équivaut au calcul du déterminant.
    ///Si les déterminants ont le même signe (produit positif), ils sont du même côté (pas de collision), sinon non.
    return (MathLib::CrossProductNorm(AB,Ab)*MathLib::CrossProductNorm(AB,Aa)<0);
}

bool SegmentCollider::Collision(const SegmentCollider& S)   ///A changer pour récupérer le point de contact : https://openclassrooms.com/courses/theorie-des-collisions/formes-plus-complexes
{
    return (Collision(S._a,S._b) &&
             S.Collision(_a,_b));
}
