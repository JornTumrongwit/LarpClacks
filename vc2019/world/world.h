#pragma once
#include "maps/map_block.h"
#include "player/player.h"
#include "cinder/app/App.h"

namespace LarpClack {
	class World {
	private:
		ci::app::App* app = nullptr;
		float latest_time = 0.0f;
		int player_index = 0;

		MapTile map;
		std::map<int, std::unique_ptr<Player>> players;

	public:
		ci::Font font = ci::Font("Arial", 100);

		World() {};
		World(ci::app::App* app) { this->app = app; };

		void AddMap(ci::vec2& center, float size,
			ci::Color& color,
			ci::Color& outline_col, float outline_size);

		template<typename T>
		void AddPlayer(ci::vec2& center, float radius, ci::Color& color, ci::Color& outline_col, float outline_size) {
			players[player_index] = std::make_unique<T>(center, radius, this);
			players[player_index]->SetColor(color);
			players[player_index]->SetOutline(outline_col, outline_size);

			player_index++;
		}

		inline MapTile GetMap() { return map; }

		void Update();

		void Draw();

		inline void SetTime() { latest_time = app->getElapsedSeconds(); }
	};
}