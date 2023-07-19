#pragma once
#include <queue>
#include "Vector.h"
class Body {
public:
    neoengine::Vector v;
    Coordinates pos;

    Body(float i, float j, float x, float y) : v(i, j), pos(x, y) {};

    Body* update(float delta);

    friend std::ostream& operator<<(std::ostream& os, const Body& bd) {
        os << "Velocity state: (" << bd.v.getI() << ", " << bd.v.getJ() << ")" << std::endl
            << "Coordinates: (" << bd.pos.x << ", " << bd.pos.y << ")" << std::endl;
        return os;
    };

    void log() const;
};
