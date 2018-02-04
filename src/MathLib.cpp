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
    Vector AC(A,C),AB(A,B),BC(B,C);
    float s1, s2;

    /*AC.x=C.x-A.x;
    AC.y=C.y-A.y;
    AB.x=B.x-A.x;
    AB.y=B.y-A.y;
    BC.x=C.x-B.x;
    BC.y=C.y-B.y;*/

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

float MathLib::GetAngleToOrigin(const Point& origine, const Point& target)
{
    if(origine!=target) ///Si la souris est sur le centre de la tourelle, pas la peine de tourner
    {
        Vector OA(origine,target);                                                ///Vecteur tourelle-souris
        Vector OO(origine,Point(target.x, origine.y)); ///Vecteur tourelle-origine

        float angle=0;                         ///Angle entre la souris et l'origine
        if(OA.Norm()>0 && OA.Norm()>=OO.Norm())    ///On test si la norme du vecteur est nulle et si l'axe OA est bien l'hypothénuse du triangle souris-tourelle-origine (plante sinon)
            angle=MathLib::RadToDegree(Vector::GetAngle(OO,OA));


        return MathLib::AcosAngleToRealAngle(angle,origine,target);
    }
    return 0;
}

float MathLib::AcosAngleToRealAngle(float angle, const Point& O, const Point& p)
{
    if(p.x >= O.x)        ///On change l'angle du repère (90-0-90-0) au repère (0-90-180-270)
    {
        if(p.y < O.y)
        {
            angle=360-angle;
        }
    }
    else if(p.x < O.x)
    {
        if(p.y >= O.y)
        {
            angle=180-angle;
        }
        else
        {
            angle=180+angle;
        }
    }
    return angle;
}

float MathLib::ClampAngle(float angle, float min, float max)
{
    if(angle<min)
        angle+=360;
    else if(angle>max)
        angle-=360;
    return angle;
}
