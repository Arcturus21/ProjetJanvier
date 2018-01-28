#include "Vector.h"

Vector::Vector(float coordX, float coordY, float coordZ):x(coordX),y(coordY),z(coordZ)
{
    //ctor
    norm=sqrt(SquareNorm());
}

Vector::Vector(const Point& a, const Point& b)
{
    x=b.x-a.x;
    y=b.y-a.y;
    z=0;
    norm=sqrt(SquareNorm());
}

Vector::~Vector()
{
    //dtor
}

///operations
float Vector::Norm() const
{
    return norm;
}

float Vector::SquareNorm()
{
    return x*x+y*y+z*z;
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

double Vector::GetAngle(const Vector& adjacent, const Vector& hyppotenuse)
{
    if(hyppotenuse.Norm()!=0 && hyppotenuse.Norm()>=adjacent.Norm())   ///On test si la norme du denominateur n'est pas nulle et si v>u
        return acos(adjacent.Norm()/hyppotenuse.Norm());
    return 0;
}

///operators
bool operator==(Vector const& a, Vector const& b)
{
    return a.X()==b.X() && a.Y()==b.Y() && a.Z()==b.Z();
}

bool operator!=(Vector const& a, Vector const& b)
{
    return !(a==b);
}

Vector operator-(Vector const& a)
{
    Vector b(-a.X(),-a.Y(),-a.Z());
    return b;
}

Vector operator+(Vector const& a, Vector const& b)
{
    Vector r(a.X()+b.X(),a.Y()+b.Y(),a.Z()+b.Z());
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
    Vector r(a.X()-b.X(),a.Y()-b.Y(),a.Z()-b.Z());
    return r;
}

void Vector::operator-=(Vector const& a)
{
    x-=a.x;
    y-=a.y;
    z=a.z;
}

///Getter&Setter
void Vector::SetX(float x)
{
    this->x=x;
    norm=sqrt(SquareNorm());
}

void Vector::SetY(float y)
{
    this->y=y;
    norm=sqrt(SquareNorm());
}

void Vector::SetZ(float z)
{
    this->z=z;
    norm=sqrt(SquareNorm());
}

void Vector::SetValue(float x, float y, float z)
{
    this->x=x;
    this->y=y;
    this->z=z;
    norm=sqrt(SquareNorm());
}
