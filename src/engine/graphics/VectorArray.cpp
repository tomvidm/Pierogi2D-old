#include "VectorArray.h"

namespace engine { namespace graphics {
	VectorArray::VectorArray()
	{
		vertexArray.setPrimitiveType(sf::PrimitiveType::Lines);
	}

	void VectorArray::addVector(const sf::Vector2f& origin, const sf::Vector2f& vec)
	{
		
		vertexArray.append(sf::Vertex(origin, sf::Color::Red));
		vertexArray.append(sf::Vertex(origin + vec, sf::Color::Green));
	}

	void VectorArray::setVector(const int& index, const sf::Vector2f& origin, const sf::Vector2f& vec)
	{
		vertexArray[2*index] = sf::Vertex(origin);
		vertexArray[2*index + 1] = sf::Vertex(origin + vec);
	}

	sf::Vector2f VectorArray::getVector(const int& index) const
	{
		return vertexArray[2*index + 1].position - vertexArray[2*index].position;
	}

	void VectorArray::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(vertexArray);
	}
}
}