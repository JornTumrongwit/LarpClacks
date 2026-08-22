#include "player/player.h"

namespace LarpClack {
	class SuicideBall : public Player {
    private:
        bool hitFlag = false;
	public:
		SuicideBall() : Player() {}
        SuicideBall(World* world)
            : SuicideBall()
        {
            this->world = world;
        }

        SuicideBall(ci::vec2 center, float radius)
            : Player(center, radius)
        {
            direction = ci::randVec2();
        }

        SuicideBall(ci::vec2 center, float radius, World* world)
            : Player(center, radius)
        {
            this->world = world;
            direction = ci::randVec2();
        }

        void Update(float deltatime);
		void UpdateMap(float deltatime);

        bool InteractWith(Player* other);

        void Attack(Player* other);
	};
}