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

	public:
		World() {};
		World(ci::app::App* app) { this->app = app; };

		MapTile map;
		std::map<int, std::unique_ptr<Player>> players;

		void AddPlayer(ci::vec2& center, float radius, ci::Color& color, ci::Color& outline_col, float outline_size);
		void Update();

		void Draw();
	};
}