#pragma once

#include "SFML/Graphics.hpp"
#include <vector>

namespace engine {
namespace graphics {
	class VectorArray : public sf::Drawable
	{
	public:
		VectorArray();
		void addVector(const sf::Vector2f& vec, const sf::Vector2f& origin);
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	private:
		sf::VertexArray vertexArray;
	};
}
}