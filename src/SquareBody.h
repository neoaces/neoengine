#include "Body.h"
#include "Vector.h"
#include "ext/vector_float2.hpp"
#include "glad.h"
#include "vec2.hpp"
using neoengine::Vector;

namespace neoengine {
    struct SquareBody {
        float m_length{0.0f};
        std::array<Vector, 6> relCoordinates;  /// Map each 3 coordinates to a specific triangle.
        glm::vec2 position{};

        explicit SquareBody(float length);
    };

}