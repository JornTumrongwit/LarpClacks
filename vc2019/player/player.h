#pragma once
#include "circle/circle.h"
#include "cinder/Rand.h"

namespace LarpClack {
    class World;

    class Player : public Circle {
    protected:
        World* world = nullptr;
        float velocity = 400.0;
        float hp = 5;
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

        Player(ci::vec2 center, float radius)
            : Circle(center, radius) 
        {
            direction = ci::randVec2();
        }

        Player(ci::vec2 center, float radius, World* world)
            : Circle(center, radius)
        {
            this->world = world;
            direction = ci::randVec2();
        }

        virtual void Update(float deltatime);

        virtual void Draw();

        virtual void DrawWithOutline();

        void SetHP(float hp) { this->hp = hp; }

        virtual bool IsDead() { return hp <= 0; }
    };
}