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
        float Norm() const;
        static float Determinant(const Vector& u, const Vector& v);  ///Produit vectoriel de u et v, renvoit la norme du vecteur produit (sa composante Z)
                                                                    ///Equivalent au déterminant
        static Vector CrossProduct(const Vector& u, const Vector& v);
        static float ScalarProduct(const Vector& u, const Vector& v);

        static double GetAngle(const Vector& adjacent, const Vector& hyppotenuse);    ///Calcul l'angle entre deux vecteurs

        ///Inner operators
        void operator+=(Vector const& a);
        void operator-=(Vector const& a);

        ///Getter&Setter
        float X() const{return x;};
        void SetX(float x);
        float Y() const{return x;};
        void SetY(float y);
        float Z() const{return z;};
        void SetZ(float z);
        void SetValue(float x, float y, float z=0);

    protected:

    private:
        float x,y,z;
        float norm;
};

///operators
bool operator==(Vector const& a, Vector const& b);
bool operator!=(Vector const& a, Vector const& b);
Vector operator-(Vector const& a);
Vector operator+(Vector const& a, Vector const& b);
Vector operator-(Vector const& a, Vector const& b);

#endif // VECTOR_H
