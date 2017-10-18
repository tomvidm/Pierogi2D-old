#include "Vector.h"

namespace engine { namespace graphics {
    Vector3::Vector3(float x, float y, float z)
    : x(x), y(y), z(z)
    {
        ;
    }

    Vector3::Vector3(const Vector3& rhs_vec)
    {
        x = rhs_vec.x;
        y = rhs_vec.y;
        z = rhs_vec.z;
    }

    Vector3::~Vector3()
    {
        ;
    }

    sf::Vector2f Vector3::projectedVector() const
    {
        return sf::Vector2f(x, y);
    }

    sf::Vertex Vector3::projectedVertex() const
    {
        return sf::Vertex(sf::Vector2f(x, y));
    }

    void Vector3::operator += (const Vector3& rhs_vec)
    {
        x += rhs_vec.x;
        y += rhs_vec.y;
        z += rhs_vec.z;
    }

    void Vector3::operator -= (const Vector3& rhs_vec)
    {
        x -= rhs_vec.x;
        y -= rhs_vec.y;
        z -= rhs_vec.z;
    }

    void Vector3::operator *= (const float& scalar)
    {
        x *= scalar;
        y *= scalar;
        z *= scalar;
    }

    Vector3 Vector3::operator + (const Vector3& rhs_vec) const
    {
        Vector3 result = *this;
        result += rhs_vec;
        return result;
    }

    Vector3 Vector3::operator - (const Vector3& rhs_vec) const
    {
        Vector3 result = *this;
        result -= rhs_vec;
        return result;
    }

    Vector3 Vector3::operator * (const float scalar) const
    {
        Vector3 result = *this;
        result *= scalar;
        return result;
    }
}
}