#pragma once
#include "cinder/gl/gl.h"
#include "shape/shape.h"

namespace LarpClack {
	class Rect: public ci::Rectf, public Shape {
	protected:
		ci::Color color = ci::Color(1, 1, 1);
		ci::Color outline_col = ci::Color(0, 0, 0);
		double outline_size = 1;

	public:
		Rect() : ci::Rectf() {};
		Rect(float x1, float y1, float x2, float y2) : ci::Rectf(x1, y1, x2, y2) {
		};

		void SetOutline(ci::Color outline, float outline_size) {
			this->outline_col = outline; 
			this->outline_size = outline_size; 
		}

		void SetColor(ci::Color color) { 
			this->color = color; 
		}

		void Draw();
		void DrawWithOutline();
	};
}