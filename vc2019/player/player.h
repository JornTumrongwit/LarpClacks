#pragma once
#include "circle/circle.h"
#include "cinder/Rand.h"

namespace LarpClack {
    class World;

    class Player : public Circle {
    private:
        World* world = nullptr;
        double   velocity = 10.0;
        ci::vec2 direction;

    public:
        Player() {
            direction = ci::randVec2();
        }

        Player(World* world)
            : Player() 
        {
            this->world = world;
        }

        Player(ci::vec2 center, double radius)
            : Circle(center, radius) 
        {
            direction = ci::randVec2();
        }

        Player(ci::vec2 center, double radius, World* world)
            : Circle(center, radius)
        {
            this->world = world;
            direction = ci::randVec2();
        }

        void update();
    };
}