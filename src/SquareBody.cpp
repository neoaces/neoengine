#include "SquareBody.h"
#include "vec3.hpp"
namespace neoengine{
    SquareBody::SquareBody(float length) {
        relCoordinates = {
            Vector(-length / 2, length / 2),
            Vector(-length / 2, -length / 2),
            Vector(length / 2, -length / 2),

            Vector(-length/2, length/2),
            Vector(length/2, -length/2),
            Vector(length/2, length/2),
        };

        position = glm::vec3{0.0f, 0.0f, 0.0f};
    };
}