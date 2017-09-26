#include "SFML/Graphics.hpp"

#include <math.h>
#include <array>

namespace engine {
namespace graphics {
    class Vector3
    {
    public:
        Vector3(float x, float y, float z);
        Vector3(const Vector3& rhs_vec);
        ~Vector3();

        // Given a projection matrix (view angle of observer),
        // return the vector projected to screenspace
        // TEMPORARY SOLUTION IS TO JUST RETURN THE XY COORDINATES
        sf::Vector2f projectedVector() const;
        sf::Vertex projectedVertex() const;


        // Operator overloads. Any division should be replaced by
        // multiplication of inverse. Division is slooooow
        void operator+= (const Vector3& rhs_vec);
        void operator-= (const Vector3& rhs_vec);
        void operator*= (const float& scalar);
        Vector3 operator+ (const Vector3& rhs_vec) const;
        Vector3 operator- (const Vector3& rhs_vec) const;
        Vector3 operator* (const float scalar) const;

        float x, y, z;
    };
}
}