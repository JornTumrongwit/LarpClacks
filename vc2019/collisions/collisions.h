#include "../circle/circle.h"
#include "../rect/rect.h"
#include "cinder/gl/gl.h"

using namespace LarpClack;

bool Collide(Circle circle1, Circle circle2) {
	
}

bool Collide(Rect square, Circle circle);
bool Collide(Rect square1, Rect square2);
bool Collide(Circle circle, Rect square) {
	Collide(square, circle);
}

//Square contains circle
bool Contains(Rect square, Circle circle);
