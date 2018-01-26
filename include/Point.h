#ifndef POINT_H
#define POINT_H


class Point
{
    public:
        Point(float coordX=0, float coordY=0);
        virtual ~Point();

    public:
        float x,y;

    protected:

    private:
};

bool operator==(Point const& a, Point const& b);
bool operator!=(Point const& a, Point const& b);
bool operator-(Point const& a, Point const& b);
bool operator+(Point const& a, Point const& b);
bool operator+=(Point const& a, Point const& b);
bool operator-(Point const& a, Point const& b);
bool operator-=(Point const& a, Point const& b);


#endif // POINT_H
