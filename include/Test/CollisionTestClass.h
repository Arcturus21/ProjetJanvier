#ifndef COLLISIONTESTCLASS_H
#define COLLISIONTESTCLASS_H

#include <SFML/Graphics.hpp>

#include "../SquareTest.h"
#include "../CircleTest.h"
#include "../PointTest.h"
#include "../ConvexPolygonTest.h"

class CollisionTestClass
{
    public:
        CollisionTestClass();
        virtual ~CollisionTestClass();

        static int testCollision(sf::RenderWindow& window);

    protected:

    private:
};

#endif // COLLISIONTESTCLASS_H
