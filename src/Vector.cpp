#include "Vector.h"

Vector::Vector(float coordX, float coordY, float coordZ):x(coordX),y(coordY),z(coordZ)
{
    //ctor
}

Vector::Vector(const Point& a, const Point& b)
{
    x=b.x-a.x;
    y=b.y-a.y;
    z=0;
}

Vector::~Vector()
{
    //dtor
}

///operations
float Vector::Norm()
{
    return sqrt(SquareNorm());
}

float Vector::SquareNorm()
{
    return x*x+y*y;
}

float Vector::Determinant(const Vector& u, const Vector& v)
{
    return (u.x*v.y)-(u.y*v.x);
}

Vector Vector::CrossProduct(const Vector& u, const Vector& v)
{
    Vector r;
    r.x = 0;
    r.y = 0;
    r.z = Determinant(u,v);
    return r;
}

float Vector::ScalarProduct(const Vector& u, const Vector& v)
{
    return (u.x*v.x)+(u.y*v.y);
}

///operators
bool operator==(Vector const& a, Vector const& b)
{
    return a.x==b.x && a.y==b.y && a.z==b.z;
}

bool operator!=(Vector const& a, Vector const& b)
{
    return !(a==b);
}

Vector operator-(Vector const& a)
{
    Vector b;
    b.x=-a.x;
    b.y=-a.y;
    b.z=-a.z;
    return b;
}

Vector operator+(Vector const& a, Vector const& b)
{
    Vector r;
    r.x=a.x+b.x;
    r.y=a.y+b.y;
    r.z=a.z+b.z;
    return r;
}

void Vector::operator+=(Vector const& a)
{
    x+=a.x;
    y+=a.y;
    z+=a.z;
}

Vector operator-(Vector const& a, Vector const& b)
{
    Vector r;
    r.x=a.x-b.x;
    r.y=a.y-b.y;
    r.z=a.z-b.z;
    return r;
}

void Vector::operator-=(Vector const& a)
{
    x-=a.x;
    y-=a.y;
    z=a.z;
}
