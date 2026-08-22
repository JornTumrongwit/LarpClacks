#include "whacker.h"
#include "collisions/collisions.h"

namespace LarpClack {
	void WhackBall::SetWeapon() {
		ci::vec2 weaponCenter =
			GetCenter() +
			ci::vec2(std::cos(rotation), std::sin(rotation)) * offset;

		weapon = Rect(
			weaponCenter.x - weap_width * 0.5f,
			weaponCenter.y - weap_height * 0.5f,
			weaponCenter.x + weap_width * 0.5f,
			weaponCenter.y + weap_height * 0.5f
		);

		weapon.SetColor(ci::Color(0, 0, 1));
		weapon.SetOutline(ci::Color(0, 0, 0), 5);
	}
	void WhackBall::Update(float deltatime) {
		rotation += rotation_speed * deltatime;
		ci::vec2 weaponCenter =
			GetCenter() +
			ci::vec2(std::cos(rotation), std::sin(rotation)) * offset;

		weapon.x1 = weaponCenter.x - weap_width * 0.5f;
		weapon.y1 = weaponCenter.y - weap_height * 0.5f;
		weapon.x2 = weaponCenter.x + weap_width * 0.5f;
		weapon.y2 = weaponCenter.y + weap_height * 0.5f;
	}

	void WhackBall::UpdateMap(float deltatime) {
		ci::vec2 start_dir = this->direction;
		Player::UpdateMap(deltatime);
		/*if (start_dir.x != this->direction.x || start_dir.y != this->direction.y)
			hp -= 1;*/
	}

	bool WhackBall::InteractWith(Player* other)
	{
		Player::InteractWith(other);

		return true;
	}

	void WhackBall::Attack(Player* other)
	{
		Collision collision = CollisionCheck(&this->weapon, other);

		if (collision.collide && weaponHitData.find(other) == weaponHitData.end()) {
			weaponHitData.insert(other);
			other->TakeDamage(atk);
		}
		else if (!collision.collide){
			weaponHitData.erase(other);
		}
	}

	void WhackBall::DrawWithOutline() {
		Player::DrawWithOutline();
		weapon.DrawWithOutline();
	}
}