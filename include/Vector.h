#ifndef VECTOR_H
#define VECTOR_H


class Vector
{
    public:
        Vector(float coordX=0,float coordY=0,float coordZ=0);
        virtual ~Vector();

    public:
        float x,y,z;

    protected:

    private:
};

#endif // VECTOR_H
