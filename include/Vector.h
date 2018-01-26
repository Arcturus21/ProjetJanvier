#ifndef VECTOR_H
#define VECTOR_H

#include <math.h>

#include "Point.h"

class Vector
{
    public:
        Vector(float coordX=0,float coordY=0,float coordZ=0);
        Vector(const Point& a, const Point& b);
        virtual ~Vector();

        ///Mathematical function
        float SquareNorm();
        float Norm();
        static float Determinant(const Vector& u, const Vector& v);  ///Produit vectoriel de u et v, renvoit la norme du vecteur produit (sa composante Z)
                                                                    ///Equivalent au déterminant
        static Vector CrossProduct(const Vector& u, const Vector& v);
        static float ScalarProduct(const Vector& u, const Vector& v);

        ///Inner operators
        void operator+=(Vector const& a);
        void operator-=(Vector const& a);

    public:
        float x,y,z;

    protected:

    private:
};

///operators
bool operator==(Vector const& a, Vector const& b);
bool operator!=(Vector const& a, Vector const& b);
Vector operator-(Vector const& a);
Vector operator+(Vector const& a, Vector const& b);
Vector operator-(Vector const& a, Vector const& b);

#endif // VECTOR_H
