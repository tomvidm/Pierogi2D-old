#include "AnimationHandler.h"

namespace engine {
    void AnimationHandler::loadFromFile(std::string filename, std::string id)
    {   
        ;
    }

    void AnimationHandler::loadFromLuaTable(std::string filename, std::string spritesheet)
    {
        sel::State luaState;
        luaState.Load("filename");

        sel::Selector selector = luaState[spritesheet];
    }

    void AnimationHandler::loadTestData()
    {
        resourceMap["test"] = graphics::FrameData();

        graphics::Frame frame;
        frame.duration = 50*1667;
        
        frame.texRect = sf::Rect<int>(sf::Vector2i(0, 0), sf::Vector2i(184, 375));
        resourceMap["test"].addFrame(frame);
        
        frame.texRect = sf::Rect<int>(sf::Vector2i(184, 0), sf::Vector2i(184, 375));
        resourceMap["test"].addFrame(frame);
        
        frame.texRect = sf::Rect<int>(sf::Vector2i(184*2, 0), sf::Vector2i(184, 375));
        resourceMap["test"].addFrame(frame);
        
        frame.texRect = sf::Rect<int>(sf::Vector2i(184*3, 0), sf::Vector2i(184, 375));
        resourceMap["test"].addFrame(frame);
        
        frame.texRect = sf::Rect<int>(sf::Vector2i(184*4, 0), sf::Vector2i(184, 375));
        resourceMap["test"].addFrame(frame);
        
        frame.texRect = sf::Rect<int>(sf::Vector2i(184*5, 0), sf::Vector2i(184, 375));
        resourceMap["test"].addFrame(frame);
        
        frame.texRect = sf::Rect<int>(sf::Vector2i(184*6, 0), sf::Vector2i(184, 375));
        resourceMap["test"].addFrame(frame);
        
        frame.texRect = sf::Rect<int>(sf::Vector2i(184*7, 0), sf::Vector2i(184, 375));
        resourceMap["test"].addFrame(frame);
    }
}