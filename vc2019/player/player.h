#pragma once
#include "circle/circle.h"
#include "cinder/Rand.h"

namespace LarpClack {
    class World;

    class Player : public Circle {
    protected:
        World* world = nullptr;
        float velocity = 800.0;
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

        virtual void UpdateMap(float deltatime);

        virtual void Update(float deltatime) {};

        virtual void Draw();

        virtual void DrawWithOutline();

        virtual void TakeDamage(float damage) { hp -= damage; }

        virtual void ReflectSelf(ci::vec2 normal) { direction = Reflect(direction, normal); }

        void SetHP(float hp) { this->hp = hp; }

        virtual bool IsDead() { return hp <= 0; }

        //how this ball should interact with the other ball
        virtual bool InteractWith(Player* other);

        //attack checking
        virtual void Attack(Player* other) {};

        virtual ci::vec2 GetDirection() { return direction; }

        void SetDirection(ci::vec2 dir) { direction = dir; }
        void SetCenter(ci::vec2 center) { this->center = center; }
    };
}