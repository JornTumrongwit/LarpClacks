#include "collisions.h"
#define eps 2

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

    Collision CollisionCheck(Circle* circle1, Circle* circle2)
    {
        ci::vec2 center1 = circle1->GetCenter();
        ci::vec2 center2 = circle2->GetCenter();

        float radius1 = circle1->GetRadius() + eps;
        float radius2 = circle2->GetRadius() + eps;

        ci::vec2 difference = center1 - center2;
        float distanceSquared = ci::length2(difference);

        float radiusSum = radius1 + radius2;

        // No collision
        if (distanceSquared >= radiusSum * radiusSum) {
            return Collision{
                false,
                ci::vec2(0),
                ci::vec2(0)
            };
        }

        // Avoid normalizing a zero-length vector
        if (distanceSquared == 0.0f) {
            return Collision{
                true,
                ci::vec2(1, 0),
                ci::vec2(0)
            };
        }

        float distance = std::sqrt(distanceSquared);

        ci::vec2 normal = difference / distance;

        // How much the circles overlap
        float penetration = radiusSum - distance;

        // Push circle1 away from circle2
        ci::vec2 depth = normal * penetration;

        return Collision{
            true,
            normal,
            depth
        };
    }
}