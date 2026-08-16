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

		//player - player interactions
		for (auto it1 = players.begin(); it1 != players.end(); ++it1) {

			for (auto it2 = std::next(it1); it2 != players.end(); ++it2) {

				Player* player1 = it1->second.get();
				Player* player2 = it2->second.get();

				// Interaction between player1 and player2
				player1->InteractWith(player2);
			}
		}

		//player - map interactions + death check
		for (auto it = players.begin(); it != players.end(); ) {
			auto& player = it->second;

			player->UpdateMap(deltatime);

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