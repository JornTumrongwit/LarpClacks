#include "player.h"
#include "collisions/collisions.h"
#include "maps/map_block.h"
#include "world/world.h"

namespace LarpClack {
	void Player::update(float deltatime) {
		center += direction * velocity * deltatime;
		radius += 100 * deltatime;
		//check this player ball against the map. If it hits a map wall, bounce the ball
		MapTile map = world->GetMap();
		Collision collision = CollisionsContain(&map, this);
		if (collision.collide) {
			direction = Reflect(direction, collision.norm);
			center -= collision.pen_depth;
		}
	}
}