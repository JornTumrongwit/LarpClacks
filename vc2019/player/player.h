#pragma once
#include "circle/circle.h"

namespace LarpClack {
    class World;

    class Player : public Circle {
    private:
        World* world = nullptr;

    public:
        Player() {}

        Player(World* world) : world(world) {}

        Player(ci::vec2 center, double radius) : Circle(center, radius) {}

        Player(ci::vec2 center, double radius, World* world)
            : Circle(center, radius), world(world)
        {
        }
    };
}