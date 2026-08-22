#include "player.h"
#include "collisions/collisions.h"
#include "maps/map_block.h"
#include "world/world.h"

namespace LarpClack {
	void Player::UpdateMap(float deltatime) {
		center += direction * velocity * deltatime;
		//check this player ball against the map. If it hits a map wall, bounce the ball
		MapTile map = world->GetMap();
		Collision collision = CollisionsContain(&map, this);
		if (collision.collide) {
			ReflectSelf(collision.norm);
			center -= collision.pen_depth;
		}

		//check this player ball against another player. If it hits another player, bounce

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

	bool Player::InteractWith(Player* other) {
		Collision collision = CollisionCheck(this, other);

		if (!collision.collide)
			return false;

		// Separate overlapping players
		SetCenter(
			GetCenter() + collision.pen_depth * 0.5f
		);

		other->SetCenter(
			other->GetCenter() - collision.pen_depth * 0.5f
		);

		// Actual velocities
		ci::vec2 thisVelocity = GetDirection();
		ci::vec2 otherVelocity = other->GetDirection();

		ci::vec2 normal = collision.norm;

		// Relative velocity along collision normal
		float relativeNormal =
			ci::dot(thisVelocity - otherVelocity, normal);

		// They're already moving apart
		if (relativeNormal >= 0.0f)
			return false;

		// Equal-mass elastic collision
		float thisNormal = ci::dot(thisVelocity, normal);
		float otherNormal = ci::dot(otherVelocity, normal);

		ci::vec2 newThisVelocity =
			thisVelocity + (otherNormal - thisNormal) * normal;

		ci::vec2 newOtherVelocity =
			otherVelocity + (thisNormal - otherNormal) * normal;

		SetDirection(ci::normalize(newThisVelocity));
		other->SetDirection(ci::normalize(newOtherVelocity));

	}
}