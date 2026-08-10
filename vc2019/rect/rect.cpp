#include "rect.h"

namespace LarpClack{
    void Rect::Draw() {
        ci::gl::color(color);
        ci::gl::drawSolidRect(*this);
        ci::gl::color(ci::Color(1.0f, 1.0f, 1.0f));
    }

    void Rect::DrawWithOutline() {
        Draw();

        ci::gl::color(outline_col);
        ci::gl::lineWidth(outline_size);
        ci::gl::drawStrokedRect(*this);
        ci::gl::color(ci::Color(1.0f, 1.0f, 1.0f));
        ci::gl::lineWidth(1);
    }
}