#ifndef TURRETGAME_H
#define TURRETGAME_H

#include <SFML/Graphics.hpp>
#include "MathLib.h"

class TurretGame
{
    public:
        TurretGame();
        virtual ~TurretGame();

        static int Game(sf::RenderWindow& window);

        static float GetMouseAngle(const Point& origine, const Point& mousePos);

    protected:

    private:
};

#endif // TURRETGAME_H
