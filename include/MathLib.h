#ifndef MATHLIB_H
#define MATHLIB_H

#include <math.h>

#include "Point.h"
#include "Vector.h"

#define PI 3.14159265

class MathLib
{
    public:
        MathLib();
        virtual ~MathLib();

        ///General Function
        static float SquareDistance(float x1, float y1, float x2, float y2);
        static float Distance(float x1, float y1, float x2, float y2);
        static int Round(float value);

        static bool ProjectionOnSegment(const Point& C, const Point& A, const Point& B);

        ///Conversion Function
        static double RadToDegree(double angle);
        static double DegreeToRad(double angle);

        ///Vector Function
        //static Vector NegativVector(const Vector& u);
        static float SquareVectorNorm(const Vector& u);
        static float VectorNorm(const Vector& u);
        static float VectorDeterminant(const Vector& u, const Vector& v);    ///Produit vectoriel de u et v, renvoit la norme du vecteur produit (sa composante Z)
                                                                            ///Equivalent au déterminant
        static Vector CrossProduct(const Vector& u, const Vector& v);
        static float ScalarProduct(const Vector& u, const Vector& v);

        ///Trygonometrique Function
        static float GetAngleToOrigin(const Point& origine, const Point& target);
        static float AcosAngleToRealAngle(float angle, const Point& O, const Point& p); ///renvoit la valeur réel de l'angle entre les vecteurs OP et Oo (o étant un vecteur sur l'axe des abscisses)
        static float ClampAngle(float angle, float min, float max);

    protected:

    private:
};

#endif // MATHLIB_H
