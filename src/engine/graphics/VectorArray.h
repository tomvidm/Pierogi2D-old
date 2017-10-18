#ifndef VECTORARRAY_H
#define VECTORARRAY_H

#include <vector>
#include <math.h> 

#include "SFML/Graphics.hpp"

namespace engine { namespace graphics {
	class VectorArray : public sf::Drawable
	{
	public:
		VectorArray();
		void addVector(const sf::Vector2f& vec, const sf::Vector2f& origin);
		void setVector(const int& index, const sf::Vector2f& vec, const sf::Vector2f& origin);
		sf::Vector2f getVector(const int& index) const;
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	private:
		sf::VertexArray vertexArray;
	};
}
}

#endif