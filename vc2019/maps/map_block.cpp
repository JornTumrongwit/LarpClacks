#include "map_block.h"

namespace LarpClack {
	MapTile::MapTile(ci::vec2 center, double size) {
        float halfSize = static_cast<float>(size) * 0.5f;

        this->x1 = center.x - halfSize; // Left
        this->y1 = center.y - halfSize; // Top
        this->x2 = center.x + halfSize; // Right
        this->y2 = center.y + halfSize; // Bottom

        Rect(x1, y1, x2, y2);
	}
}