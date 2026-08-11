#include "collisions.h"
namespace LarpClack {
    Collision CollisionsContain(Rect* square, Circle* circle) {
        ci::vec2 circleCenter = circle->GetCenter();
        double radius = circle->GetRadius();

        ci::vec2 norm(0, 0);
        ci::vec2 depth(0, 0);
        //check whether the circle is on/pass the border
        if (square->x1 > circleCenter.x - radius) {
            norm.x = 1;
            depth.x = -(square->x1 - (circleCenter.x - radius));
        }
        else if (square->x2 < circleCenter.x + radius) {
            norm.x = -1;
            depth.x = circleCenter.x + radius - square->x2;
        }

        if (square->y1 > circleCenter.y - radius) {
            norm.y = 1;
            depth.y = -(square->y1 - (circleCenter.y - radius));
        }
        else if (square->y2 < circleCenter.y + radius) {
            norm.y = -1;
            depth.y = circleCenter.y + radius - square->y2 ;
        }

        if (!norm.x && !norm.y) return Collision{ false, norm, ci::vec2(0, 0)};

        return Collision{ true, ci::normalize(norm), depth };
    }
}