#include "SFML/Graphics.hpp"

#include <math.h>
#include <array>

namespace engine {
namespace graphics {

    /*
        The vector [0, 0, 1] should be the viewport normal.
    */

    sf::Transform getProjectionMatrix(sf::Vector2f screenSize, float theta, float phi);

    class Vector3
    {
    public:
        Vector3(float, float, float);
        Vector3(const Vector3& rhs_vec);
        ~Vector3();

        // Given a projection matrix (view angle of observer),
        // return the vector projected to screenspace
        // TEMPORARY SOLUTION IS TO JUST RETURN THE XY COORDINATES
        sf::Vector2f projectedVector() const;
        sf::Vertex projectedVertex() const;


        // Operator overloads. Any division should be replaced by
        // multiplication of inverse. Division is slooooow
        void operator += (const sf::Vector3& rhs_vec);
        void operator -= (const sf::Vector3& rhs_vec);
        void operator *= (const float& scalar);
        Vector3 operator + (const sf::Vector3& rhs_vec) const;
        Vector3 operator - (const sf::Vector3& rhs_vec) const;
        Vector3 operator * (const float scalar) const;

        float x, y, z;
    };
}
}