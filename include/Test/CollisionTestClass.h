#ifndef COLLISIONTESTCLASS_H
#define COLLISIONTESTCLASS_H

#include <SFML/Graphics.hpp>

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
