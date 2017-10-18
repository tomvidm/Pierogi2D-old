#include "TextureHandler.h"

namespace engine
{
	void TextureHandler::loadFromFile(std::string filename)
	{	
        std::cout << "Loading texture from images/" + filename + ".png" << "... success!" << std::endl;
		resourceMap[filename] = sf::Texture();
		resourceMap[filename].loadFromFile(directories::relativePathToResources + "images/" + filename + ".png");
	}
}