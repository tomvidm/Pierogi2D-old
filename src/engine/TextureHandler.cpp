#include "TextureHandler.h"

namespace engine
{
	void TextureHandler::loadFromFile(std::string filename, std::string id)
	{
		resourceMap[id] = sf::Texture();
		resourceMap[id].loadFromFile(filename);
	}
}