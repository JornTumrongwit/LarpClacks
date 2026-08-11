#include "../circle/circle.h"
#include "../rect/rect.h"
#include "cinder/gl/gl.h"

namespace LarpClack{
	struct Collision { bool collide; ci::vec2 norm; ci::vec2 pen_depth; };

	Collision CollisionCheck(Circle* circle1, Circle* circle2);
	Collision CollisionCheck(Rect* square1, Rect* square2);
	Collision CollisionCheck(Rect* square, Circle* circle);
	inline Collision CollisionCheck(Circle* circle, Rect* square) {
		return CollisionCheck(square, circle);
	}

	//Square contains circle
	Collision CollisionsContain(Rect* square, Circle* circle);
}
