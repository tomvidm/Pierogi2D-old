#include "TextureHandler.h"

namespace engine { namespace graphics {
	void TextureHandler::loadFromFile(std::string filename)
	{	
        if (!isAlreadyLoaded(filename))
        {
            alreadyLoadedFiles.insert(filename);
            resourceMap[filename] = sf::Texture();
            resourceMap[filename].loadFromFile(directories::relativePathToResources + "images/" + filename + ".png");
        }
	}

    bool TextureHandler::isAlreadyLoaded(std::string filename) const 
    {
        return static_cast<bool>(alreadyLoadedFiles.count(filename));
    }
}}