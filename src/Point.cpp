#include "Point.h"

Point::Point(float coordX, float coordY):x(coordX),y(coordY)
{
    //ctor
}

Point::~Point()
{
    //dtor
}

bool operator==(Point const& a, Point const& b)
{
    return a.x==b.x && a.y==b.y;
}

bool operator!=(Point const& a, Point const& b)
{
    return !(a==b);
}

Point operator-(Point const& a)
{
    Point b;
    b.x=-a.x;
    b.y=-a.y;
    return b;
}

Point operator+(Point const& a, Point const& b)
{
    Point r;
    r.x=a.x+b.x;
    r.y=a.y+b.y;
    return r;
}

void Point::operator+=(Point const& a)
{
    x+=a.x;
    y+=a.y;
}

Point operator-(Point const& a, Point const& b)
{
    Point r;
    r.x=a.x-b.x;
    r.y=a.y-b.y;
    return r;
}

void Point::operator-=(Point const& a)
{
    x-=a.x;
    y-=a.y;
}

