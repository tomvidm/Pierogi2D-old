#ifndef TEXTUREHANDLER_H
#define TEXTUREHANDLER_H

#include <set>

#include "engine/ResourceHandler.h"
#include "../Directories.h"

#include "SFML/Graphics.hpp"

namespace engine
{
    // This is a simple template specialization of the ResourceHandler.
    // It stores textures in a map by string keys.

	class TextureHandler : public ResourceHandler<sf::Texture>
	{
	public:
		void loadFromFile(std::string filename);
        bool isAlreadyLoaded(std::string filename) const;
    private:
        std::set<std::string> alreadyLoadedFiles;
	};
}

#endif