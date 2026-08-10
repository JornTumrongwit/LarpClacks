#include "../circle/circle.h"
#include "../rect/rect.h"
#include "cinder/gl/gl.h"

namespace LarpClack{
	bool CollisionCheck(Circle circle1, Circle circle2);
	bool CollisionCheck(Rect square1, Rect square2);
	bool CollisionCheck(Rect square, Circle circle);
	bool CollisionCheck(Circle circle, Rect square) {
		CollisionCheck(square, circle);
	}

	//Square contains circle
	bool Contains(Rect square, Circle circle);
}
