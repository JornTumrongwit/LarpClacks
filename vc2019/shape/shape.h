#pragma once

namespace LarpClack {
	class Shape {
	public:
		//Does the necessary steps to update this shape
		void update();
		
		//Returns whether this object should be destroyed
		void isDead();
		inline ci::vec2 Reflect(ci::vec2 direction, ci::vec2 normal)
		{
			normal = ci::normalize(normal);
			return direction - 2.0f * ci::dot(direction, normal) * normal;
		}
	};
}