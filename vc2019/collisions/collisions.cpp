#include "collisions.h"
namespace LarpClack {
    bool CollisionCheck(LarpClack::Rect square, LarpClack::Circle circle) {
        ci::vec2 circleCenter = circle.GetCenter();
        double radius = circle.GetRadius();

        float closestX = ci::math<float>::clamp(circleCenter.x, square.x1, square.x2);
        float closestY = ci::math<float>::clamp(circleCenter.y, square.y1, square.y2);

        float distanceX = circleCenter.x - closestX;
        float distanceY = circleCenter.y - closestY;

        float distanceSquared = (distanceX * distanceX) + (distanceY * distanceY);

        return distanceSquared < (radius * radius);
    }
}