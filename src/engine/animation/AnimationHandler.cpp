#include "AnimationHandler.h"

namespace engine {
    void AnimationHandler::loadFromFile(std::string filename, std::string id)
    {   
        ;
    }

    void AnimationHandler::loadFromLuaTable(std::string filename, const char* spritesheet)
    {
        sel::State luaState;
        luaState.Load("filename");
        sel::Selector selector = luaState[spritesheet]["animations"];
        int numFrames = static_cast<int>(selector["num_frames"]);
        selector = selector["frames"];
        FrameData frameData;

        for (int i = 0; i < numFrames; i++)
        {
            int duration = selector[i][0];
            int xpos = selector[i][1];
            int xsize = selector[i][2];
            int ypos = selector[i][3];
            int ysize = selector[i][4];

            frameData.addFrame(Frame(duration, 
                                     sf::Rect<int>(sf::Vector2i(xpos, ypos),
                                                   sf::Vector2i(xsize, ysize))));

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
}