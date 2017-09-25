#include "SFML/Graphics.hpp"

namespace engine {
namespace graphics {

    /*
        The vector [0, 0, 1] should be the viewport normal.
    */

    class Vector3
    {
    public:
        Vector3(float, float, float);
        Vector3(const Vector3& rhs_vec);
        ~Vector3();

        // Given a projection matrix (view angle of observer),
        // return the vector projected to screenspace
        sf::Vector2f projectedVector(const Vector3& projector) const;
        sf::Vertex projectedVertex(const Vector3& projector) const;

        // Operator overloads. Any division should be replaced by
        // multiplication of inverse. Division is slooooow
        void operator += (const sf::Vector3& rhs_vec);
        void operator -= (const sf::Vector3& rhs_vec);
        void operator *= (const float& scalar);
        Vector3 operator + (const sf::Vector3& rhs_vec) const;
        Vector3 operator - (const sf::Vector3& rhs_vec) const;
        Vector3 operator * (const float scalar) const;

    private:
        float coordinates[3];
    }
}
}