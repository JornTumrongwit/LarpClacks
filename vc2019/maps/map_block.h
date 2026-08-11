#pragma once

#include "cinder/gl/gl.h"
#include "../rect/rect.h"

namespace LarpClack {
	class MapTile: public Rect {
	public:
		MapTile() {}
		MapTile(ci::vec2 center, float size);
	};
}