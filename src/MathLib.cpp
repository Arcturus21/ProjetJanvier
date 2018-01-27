#include "../include/MathLib.h"

MathLib::MathLib()
{
    //ctor
}

MathLib::~MathLib()
{
    //dtor
}


float MathLib::SquareDistance(float x1, float y1, float x2, float y2)
{
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

float MathLib::Distance(float x1, float y1, float x2, float y2)
{
    return sqrt(SquareDistance(x1,y1,x2,y2));
}

int MathLib::Round(float value)
{
    return int(value+0.5);
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

    s1 = Vector::ScalarProduct(AC,AB);
    s2 = Vector::ScalarProduct(BC,AB);
    return s1*s2<=0;
}

double MathLib::RadToDegree(double angle)
{
    return angle*180/PI;
}

double MathLib::DegreeToRad(double angle)
{
    return angle*PI/180;
}
