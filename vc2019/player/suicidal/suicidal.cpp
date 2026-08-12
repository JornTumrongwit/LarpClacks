#include "suicidal.h"

namespace LarpClack {
	void SuicideBall::Update(float deltatime) {
		ci::vec2 start_dir = this->direction;
		Player::Update(deltatime);
		if (start_dir.x != this->direction.x || start_dir.y != this->direction.y)
			hp -= 1;
	}
}