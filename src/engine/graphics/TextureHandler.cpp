#include "TextureHandler.h"

namespace engine
{
	void TextureHandler::loadFromFile(std::string filename)
	{	
        std::cout << "Loading texture from images/" + filename + ".png";
        if (!isAlreadyLoaded(filename))
        {
            alreadyLoadedFiles.insert(filename);
            resourceMap[filename] = sf::Texture();
            resourceMap[filename].loadFromFile(directories::relativePathToResources + "images/" + filename + ".png");
            std::cout << "... success!!!" << std::endl;
        }
        else
        {
            std::cout << "... Already loaded!!!" << std::endl;
        }
		
	}

    bool TextureHandler::isAlreadyLoaded(std::string filename) const 
    {
        return static_cast<bool>(alreadyLoadedFiles.count(filename));
    }
}