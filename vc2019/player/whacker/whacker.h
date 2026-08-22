#include "player/player.h"
#include "rect/rect.h"
#include <unordered_set>

namespace LarpClack {
    class WhackBall : public Player {
    private:
        Rect weapon;
        float offset = 300;
        float rotation = 0;
        float rotation_speed = 10;
        float atk = 2;
        float weap_width = 100;
        float weap_height = 200;
        std::unordered_set<Player*> weaponHitData;
    public:
        WhackBall() : Player() {}
        WhackBall(World* world)
            : WhackBall()
        {
            this->world = world;
            SetWeapon();
        }

        WhackBall(ci::vec2 center, float radius)
            : Player(center, radius)
        {
            direction = ci::randVec2();
            SetWeapon();
        }

        WhackBall(ci::vec2 center, float radius, World* world)
            : Player(center, radius)
        {
            this->world = world;
            direction = ci::randVec2();
            SetWeapon();
        }

        void SetWeapon();

        void UpdateMap(float deltatime);

        void Update(float deltatime);

        bool InteractWith(Player* other);

        void Attack(Player* other);
        
        void DrawWithOutline();
    };
}