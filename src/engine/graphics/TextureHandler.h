#include "ResourceHandler.h"

#include "SFML/Graphics.hpp"

namespace engine
{
    // This is a simple template specialization of the ResourceHandler.
    // It stores textures in a map by string keys.

	class TextureHandler : public ResourceHandler<sf::Texture>
	{
	public:
		void loadFromFile(std::string filename, std::string id);
	};
}