#include "world.h"

namespace LarpClack {
	void World::AddPlayer(ci::vec2& center, float radius, ci::Color& color, ci::Color& outline_col, float outline_size) {
		players[player_index] = std::make_unique<Player>(center, radius, this);
		players[player_index]->SetColor(color);
		players[player_index]->SetOutline(outline_col, outline_size);

		player_index++;
	}

	void World::Update() {
		//for (Player* player : players) player->update();
	}

	void World::Draw() {
		map.DrawWithOutline();
		for (auto& [id, player] : players) player->DrawWithOutline();
	}
}