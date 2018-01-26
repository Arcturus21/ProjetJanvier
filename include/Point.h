#ifndef POINT_H
#define POINT_H


class Point
{
    public:
        Point(float coordX=0, float coordY=0);
        virtual ~Point();

        void operator+=(Point const& a);
        void operator-=(Point const& a);

    public:
        float x,y;

    protected:

    private:
};

bool operator==(Point const& a, Point const& b);
bool operator!=(Point const& a, Point const& b);
Point operator-(Point const& a);
Point operator+(Point const& a, Point const& b);
Point operator-(Point const& a, Point const& b);


#endif // POINT_H
