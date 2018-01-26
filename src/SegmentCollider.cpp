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
    Vector Aa(A,_a), Ab(A,_b), AB(A,B);

    ///VectorDeterminant équivaut au calcul du déterminant.
    ///Si les déterminants ont le même signe (produit positif), ils sont du même côté (pas de collision), sinon non.
    return (Vector::Determinant(AB,Ab)*Vector::Determinant(AB,Aa)<0);
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

bool SegmentCollider::Collision(SegmentCollider& S)   ///A changer pour récupérer le point de contact : https://openclassrooms.com/courses/theorie-des-collisions/formes-plus-complexes
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
