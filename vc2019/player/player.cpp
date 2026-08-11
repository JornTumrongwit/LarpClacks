#include "player.h"
#include "collisions/collisions.h"

namespace LarpClack {
	void Player::update(float deltatime) {
		center += direction * velocity * deltatime;
		//check this player ball against the map. If it hits a map wall, bounce the ball
	}
}