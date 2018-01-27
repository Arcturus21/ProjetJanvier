#ifndef TURRETGAME_H
#define TURRETGAME_H

#include "SFML/Graphics.hpp"

class TurretGame
{
    public:
        TurretGame();
        virtual ~TurretGame();

        static int Game(sf::RenderWindow& window);

    protected:

    private:
};

#endif // TURRETGAME_H
