#include "circle.h"

namespace LarpClack{
    void Circle::Draw() {
        ci::gl::color(color);
        ci::gl::drawSolidCircle(center, radius);
        ci::gl::color(ci::Color(1.0f, 1.0f, 1.0f));
    }

    void Circle::DrawWithOutline() {
        Draw();

        ci::gl::color(outline_col);
        ci::gl::lineWidth(outline_size);
        ci::gl::drawStrokedCircle(center, radius);
        ci::gl::color(ci::Color(1.0f, 1.0f, 1.0f));
        ci::gl::lineWidth(1);
    }
}
