#pragma once
#include "maps/map_block.h"
#include "player/player.h"

namespace LarpClack {
	class World {
	public:
		World() {};

		MapTile map;
		std::vector<Player*> players;

		void Update();

		void Draw();
	};
}