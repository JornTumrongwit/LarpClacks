#include "player.h"
#include "collisions/collisions.h"
#include "maps/map_block.h"
#include "world/world.h"

namespace LarpClack {
	void Player::Update(float deltatime) {
		center += direction * velocity * deltatime;
		//check this player ball against the map. If it hits a map wall, bounce the ball
		MapTile map = world->GetMap();
		Collision collision = CollisionsContain(&map, this);
		if (collision.collide) {
			direction = Reflect(direction, collision.norm);
			center -= collision.pen_depth;
		}
	}

	void Player::Draw() {
		Circle::Draw();
		ci::gl::drawStringCentered(
			std::to_string(int(this->hp)),
			center,
			ci::Color(0, 0, 0),
			world->font
		);
	}

	void Player::DrawWithOutline() {
		Circle::DrawWithOutline();
		ci::gl::drawStringCentered(
			std::to_string(int(this->hp)),
			center,
			ci::Color(0, 0, 0),
			world->font
		);
	}
}