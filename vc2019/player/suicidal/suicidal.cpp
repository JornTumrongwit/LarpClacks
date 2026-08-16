#include "suicidal.h"
#include "collisions/collisions.h"

namespace LarpClack {
	void SuicideBall::UpdateMap(float deltatime) {
		ci::vec2 start_dir = this->direction;
		Player::UpdateMap(deltatime);
		/*if (start_dir.x != this->direction.x || start_dir.y != this->direction.y)
			hp -= 1;*/
	}

	void SuicideBall::InteractWith(Player* other) {
		Collision collision = CollisionCheck(this, other);

		if (!collision.collide)
			return;

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
			return;

		// Equal-mass elastic collision
		float thisNormal = ci::dot(thisVelocity, normal);
		float otherNormal = ci::dot(otherVelocity, normal);

		ci::vec2 newThisVelocity =
			thisVelocity + (otherNormal - thisNormal) * normal;

		ci::vec2 newOtherVelocity =
			otherVelocity + (thisNormal - otherNormal) * normal;

		SetDirection(ci::normalize(newThisVelocity));
		other->SetDirection(ci::normalize(newOtherVelocity));

		other->TakeDamage(2);
		TakeDamage(2);
	}
}