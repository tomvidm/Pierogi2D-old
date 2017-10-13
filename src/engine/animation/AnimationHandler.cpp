#include "AnimationHandler.h"
#include <iostream>
namespace engine {
    void AnimationHandler::loadFromFile(std::string filename, std::string id)
    {   
        ;
    }

#include "assert.h"

    void AnimationHandler::loadFromLuaTable(std::string filename, const char* spritesheet)
    {
        using std::cout;
        using std::endl;

        sel::State luaState;
        luaState.Load(filename);
        sel::Selector selector = luaState[spritesheet]["animations"][1];
        std::string anim_name = selector["animation_name"];
        std::string anim_key = static_cast<std::string>(spritesheet);

        int numFrames = static_cast<int>(selector["num_frames"]);
        selector = selector["frames"];
        resourceMap[anim_key] = FrameData();
        

        for (int i = 1; i <= numFrames; i++)
        {
            resourceMap[anim_key].addFrame(getFrameFromSelector(selector, i));
        }
    }

    void AnimationHandler::loadTestData()
    {
        resourceMap["test"] = FrameData();

        Frame frame;
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

    Frame getFrameFromSelector(sel::Selector& selector, int frameIndex)
    {
        Frame frame;
        frame.duration = selector[frameIndex][1];
        frame.texRect = sf::Rect<int>(sf::Vector2i(static_cast<int>(selector[frameIndex][2]),
                                                   static_cast<int>(selector[frameIndex][3])),
                                      sf::Vector2i(static_cast<int>(selector[frameIndex][4]),
                                                   static_cast<int>(selector[frameIndex][5])));
        return frame;
    }
}