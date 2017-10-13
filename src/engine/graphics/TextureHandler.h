#include "ResourceHandler.h"

#include "SFML/Graphics.hpp"

namespace engine
{
	class TextureHandler : public ResourceHandler<sf::Texture>
	{
	public:
		void loadFromFile(std::string filename, std::string id);
	};
}