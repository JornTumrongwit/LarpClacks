#pragma once

namespace LarpClack {
	class Shape {
	public:
		//Does the necessary steps to update this shape
		void update();
		
		//Returns whether this object should be destroyed
		void isDead();
	};
}