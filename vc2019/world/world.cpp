#include "world.h"

namespace LarpClack {
	void World::AddMap(ci::vec2& center, float size, ci::Color& color, ci::Color& outline_col, float outline_size) {
		this->map = MapTile(center, size);
		this->map.SetColor(ci::Color(255.0 / 255, 255.0 / 255, 230.0 / 255));
		this->map.SetOutline(ci::Color(0, 0, 0.3), 30);
	}

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