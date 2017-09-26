#include "Vector.h"

namespace engine {
namespace graphics {
    Vector3::Vector3(float x, float y, float z)
    : x(x), y(y), z(z)
    {
        ;
    }

    Vector3::Vector3(const Vector& rhs_vec)
    {
        x = rhs_vec.x;
        y = rhs_vec.y;
        z = rhs_vec.z;
    }

    Vector3::~Vector3()
    {
        ;
    }

    sf::Vector2f projectedVector(std::array<float, 4> projMatrix) const
    {
        return Vector2f(x, y);
    }

    sf::Vertex projectedVector(std::array<float, 4> projMatrix) const
    {
        return Vertex(x, y);
    }

    void operator += (const sf::Vector3& rhs_vec)
    {
        x += rhs_vec.x;
        y += rhs_vec.y;
        z += rhs_vec.z;
    }

    void operator -= (const sf::Vector3& rhs_vec)
    {
        x -= rhs_vec.x;
        y -= rhs_vec.y;
        z -= rhs_vec.z;
    }

    void operator *= (const float& scalar)
    {
        x *= scalar;
        y *= scalar;
        z *= scalar;
    }

    Vector3 operator + (const sf::Vector3& rhs_vec) const
    {
        Vector3 result = *this;
        result += ths_vec;
        return result;
    }

    Vector3 operator - (const sf::Vector3& rhs_vec) const
    {
        Vector3 result = *this;
        result -= ths_vec;
        return result;
    }

    Vector3 operator * (const float scalar) const
    {
        Vector3 result = *this;
        result *= scalar;
        return result;
    }
}
}