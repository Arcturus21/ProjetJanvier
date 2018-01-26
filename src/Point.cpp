#include "Point.h"

Point::Point(float coordX, float coordY)
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

bool operator-(Point const& a)
{
    Point b;
    b.x=-a.x;
    b.y=-a.y;
    return b;
}

bool operator+(Point const& a, Point const& b)
{
    Point r;
    r.x=a.x+b.x;
    r.y=a.y+b.y;
    return r;
}
/*
bool operator+=(Point const& a, Point const& b)
{

}
*/
bool operator-(Point const& a, Point const& b)
{
    Point r;
    r.x=a.x-b.x;
    r.y=a.y-b.y;
    return r;
}
/*
bool operator-=(Point const& a, Point const& b)
{

}
*/
