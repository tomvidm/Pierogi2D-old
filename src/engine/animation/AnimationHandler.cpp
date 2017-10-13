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
            Frame newFrame = getFrameFromSelector(selector, i);
            resourceMap[anim_key].addFrame(newFrame);
            //printFrame(resourceMap[anim_key].getFrame(i - 1));
        }
    }

    void AnimationHandler::loadTestData()
    {
        resourceMap["spritesheet_testsprite"] = FrameData();

        Frame frame;
        frame.duration = 50*1667;
        
        frame.texRect = sf::Rect<int>(sf::Vector2i(0, 0), sf::Vector2i(184, 375));
        resourceMap["spritesheet_testsprite"].addFrame(frame);
        
        frame.texRect = sf::Rect<int>(sf::Vector2i(184, 0), sf::Vector2i(184, 375));
        resourceMap["spritesheet_testsprite"].addFrame(frame);
        
        frame.texRect = sf::Rect<int>(sf::Vector2i(184*2, 0), sf::Vector2i(184, 375));
        resourceMap["spritesheet_testsprite"].addFrame(frame);
        
        frame.texRect = sf::Rect<int>(sf::Vector2i(184*3, 0), sf::Vector2i(184, 375));
        resourceMap["spritesheet_testsprite"].addFrame(frame);
        
        frame.texRect = sf::Rect<int>(sf::Vector2i(184*4, 0), sf::Vector2i(184, 375));
        resourceMap["spritesheet_testsprite"].addFrame(frame);
        
        frame.texRect = sf::Rect<int>(sf::Vector2i(184*5, 0), sf::Vector2i(184, 375));
        resourceMap["spritesheet_testsprite"].addFrame(frame);
        
        frame.texRect = sf::Rect<int>(sf::Vector2i(184*6, 0), sf::Vector2i(184, 375));
        resourceMap["spritesheet_testsprite"].addFrame(frame);
        
        frame.texRect = sf::Rect<int>(sf::Vector2i(184*7, 0), sf::Vector2i(184, 375));
        resourceMap["spritesheet_testsprite"].addFrame(frame);

        /*printFrame(resourceMap["spritesheet_testsprite"].getFrame(0));
        printFrame(resourceMap["spritesheet_testsprite"].getFrame(1));
        printFrame(resourceMap["spritesheet_testsprite"].getFrame(2));
        printFrame(resourceMap["spritesheet_testsprite"].getFrame(3));
        printFrame(resourceMap["spritesheet_testsprite"].getFrame(4));
        printFrame(resourceMap["spritesheet_testsprite"].getFrame(5));
        printFrame(resourceMap["spritesheet_testsprite"].getFrame(6));
        printFrame(resourceMap["spritesheet_testsprite"].getFrame(7));*/
    }

    Frame getFrameFromSelector(sel::Selector& selector, int frameIndex)
    {
        Frame frame;
        frame.duration = static_cast<int>(selector[frameIndex][1]);
        frame.texRect = sf::Rect<int>(sf::Vector2i(static_cast<int>(selector[frameIndex][2]),
                                                   static_cast<int>(selector[frameIndex][3])),
                                      sf::Vector2i(static_cast<int>(selector[frameIndex][4]),
                                                   static_cast<int>(selector[frameIndex][5])));
        return frame;
    }
}