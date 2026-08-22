#include "suicidal.h"
#include "collisions/collisions.h"

namespace LarpClack {
	void SuicideBall::UpdateMap(float deltatime) {
		ci::vec2 start_dir = this->direction;
		Player::UpdateMap(deltatime);
		/*if (start_dir.x != this->direction.x || start_dir.y != this->direction.y)
			hp -= 1;*/
	}

	void SuicideBall::Update(float deltatime) {
		hitFlag = false;
	}
	bool SuicideBall::InteractWith(Player* other) {
		if (Player::InteractWith(other)) hitFlag = true;

		return hitFlag;
	}

	void SuicideBall::Attack(Player* other) { if(hitFlag) other->TakeDamage(1); }
}