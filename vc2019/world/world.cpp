#include "world.h"

namespace LarpClack {
	void World::Update() {
		for (Player* player : players) player->update();
	}

	void World::Draw() {
		map.DrawWithOutline();
		for (Player* player : players) player->DrawWithOutline();
	}
}