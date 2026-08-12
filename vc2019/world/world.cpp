#include "world.h"

namespace LarpClack {
	void World::AddMap(ci::vec2& center, float size, ci::Color& color, ci::Color& outline_col, float outline_size) {
		this->map = MapTile(center, size);
		this->map.SetColor(ci::Color(255.0 / 255, 255.0 / 255, 230.0 / 255));
		this->map.SetOutline(ci::Color(0, 0, 0.3), 30);
	}

	void World::Update() {
		double current_time = app->getElapsedSeconds();
		double deltatime = current_time - latest_time;
		latest_time = current_time;

		for (auto it = players.begin(); it != players.end(); ) {
			auto& player = it->second;

			player->Update(deltatime);

			if (player->IsDead()) {
				it = players.erase(it);
			}
			else {
				++it;
			}
		}
	}

	void World::Draw() {
		map.DrawWithOutline();
		for (auto& [id, player] : players) player->DrawWithOutline();
	}
}