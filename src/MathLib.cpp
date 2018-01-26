#include "../include/MathLib.h"

MathLib::MathLib()
{
    //ctor
}

MathLib::~MathLib()
{
    //dtor
}

Vector MathLib::NegativVector(const Vector& u)
{
    Vector r;
    r.x = -u.x;
    r.y = -u.y;
    r.z = -u.z;
    return r;
}

float MathLib::SquareDistance(float x1, float y1, float x2, float y2)
{
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

float MathLib::Distance(float x1, float y1, float x2, float y2)
{
    return sqrt(SquareDistance(x1,y1,x2,y2));
}

float MathLib::VectorNorm(const Vector& u)
{
    return sqrt(VectorNorm(u));
}

float MathLib::SquareVectorNorm(const Vector& u)
{
    return u.x*u.x+u.y*u.y;
}

float MathLib::VectorDeterminant(const Vector& u, const Vector& v)
{
    return (u.x*v.y)-(u.y*v.x);
}

Vector MathLib::CrossProduct(const Vector& u, const Vector& v)
{
    Vector r;
    r.x = 0;
    r.y = 0;
    r.z = VectorDeterminant(u,v);
    return r;
}

int MathLib::Round(float value)
{
    return int(value+0.5);
}

float MathLib::ScalarProduct(const Vector& u, const Vector& v)
{
    return (u.x*v.x)+(u.y*v.y);
}

bool MathLib::ProjectionOnSegment(const Point& C, const Point& A, const Point& B)
{
    Vector AC,AB,BC;
    float s1, s2;

    AC.x=C.x-A.x;
    AC.y=C.y-A.y;
    AB.x=B.x-A.x;
    AB.y=B.y-A.y;
    BC.x=C.x-B.x;
    BC.y=C.y-B.y;

    s1 = MathLib::ScalarProduct(AC,AB);
    s2 = MathLib::ScalarProduct(BC,AB);
    return s1*s2<=0;
}
