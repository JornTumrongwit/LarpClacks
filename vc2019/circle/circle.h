#include "cinder/gl/gl.h"
#include "shape/shape.h"

namespace LarpClack {
    class Circle: public Shape {
    protected:
        ci::vec2 center = ci::vec2(0, 0);
        double radius = 1;
        ci::Color color = ci::Color(1, 1, 1);
        ci::Color outline_col = ci::Color(0, 0, 0);
        double outline_size = 1.0;

    public:
        Circle() {};
        Circle(ci::vec2 c, float r)
            : center(c), radius(r) {
        }

        void SetColor(ci::Color color) {
            this->color = color;
        }

        void SetOutline(ci::Color outline_col, float outline_size) {
            this->outline_col = outline_col;
            this->outline_size = outline_size;
        }

        void Draw();
        void DrawWithOutline();

        ci::vec2 GetCenter() { return center; };
        double GetRadius() { return radius; };
    };
}