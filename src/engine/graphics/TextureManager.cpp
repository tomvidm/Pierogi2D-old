#include "TextureManager.h"

namespace engine { namespace graphics {
    TextureManager* TextureManager::instancePtr = nullptr;

    TextureManager* TextureManager::getInstancePtr()
    {
        if (instancePtr == nullptr)
        {
            instancePtr = new TextureManager;
        }

        return instancePtr;
    }

    sf::Texture* TextureManager::loadFromFile(std::string texturename)
    {   
        engine::console::Logger::getInstancePtr()->log("Loading texture from " + texturename + ".png\n", engine::console::LogLevel::DEBUG);
        
        if (!isAlreadyLoaded(texturename))
        {
            resourceMap[texturename] = sf::Texture();
            resourceMap[texturename].loadFromFile(directories::imagesDirectory + texturename + ".png");
        }
        else
        {
            engine::console::Logger::getInstancePtr()->log("Already loaded...\n", engine::console::LogLevel::DEBUG);
        }

        return get(texturename);
    }

    sf::Texture* TextureManager::get(std::string id)
    {
        return &resourceMap.at(id);
    }

    bool TextureManager::isAlreadyLoaded(std::string texturename) const 
    {
        return static_cast<bool>(resourceMap.count(texturename));
    }

    TextureManager::TextureManager()
    {
        ;
    }
}}