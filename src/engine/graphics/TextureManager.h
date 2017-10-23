#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <map>
#include <string>
#include <set>

#include "SFML/Graphics.hpp"

#include "engine/Directories.h"
#include "engine/console/Logger.h"


namespace engine { namespace graphics {
    class TextureManager
    {
    public:
        static TextureManager* getInstancePtr();

        sf::Texture* loadFromFile(std::string texturename);
        sf::Texture* get(std::string id);

        bool isAlreadyLoaded(std::string texturename) const;
    protected:
        TextureManager();

        std::map<std::string, sf::Texture> resourceMap;
        std::set<std::string> alreadyLoadedFiles;

        static TextureManager* instancePtr;
    };
}}

#endif