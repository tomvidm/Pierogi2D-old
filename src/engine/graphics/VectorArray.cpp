#include "VectorArray.h"

namespace engine {
namespace graphics {
	VectorArray::VectorArray()
	{
		vertexArray.setPrimitiveType(sf::PrimitiveType::Lines);
	}

	void VectorArray::addVector(const sf::Vector2f& vec, const sf::Vector2f& origin)
	{
		
		vertexArray.append(sf::Vertex(origin));
		vertexArray.append(sf::Vertex(vec + origin));
	}

	void VectorArray::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(vertexArray);
	}
}
}