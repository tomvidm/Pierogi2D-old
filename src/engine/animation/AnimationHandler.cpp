#include "AnimationHandler.h"
#include <iostream>

namespace engine { namespace animation {
    void AnimationHandler::loadFromFile(std::string filename)
    {   
        using std::cout;
        using std::endl;

        if (!isAlreadyLoaded(filename))
        {
            alreadyLoadedFiles.insert(filename);
            sel::State luaState;
            luaState.Load(directories::relativePathToResources + "images/" + filename + ".lua");

            sel::Selector selector = luaState[filename.c_str()];
            int numAnimations = static_cast<int>(selector["num_animations"]);
            selector = selector["animations"];

            for (int i = 1; i <= numAnimations; i++)
            {
                std::string animationName = selector["animation_name"];
                cout << animationName << endl;
                resourceMap[animationName] = getFrameDataFromSelector(selector[i]);
            }
        }
    }

    bool AnimationHandler::isAlreadyLoaded(std::string filename) const 
    {
        return static_cast<bool>(alreadyLoadedFiles.count(filename));
    }

    FrameData getFrameDataFromSelector(sel::Selector selector)
    {
        using std::cout;
        using std::endl;

        FrameData frameData;
        int numFrames = static_cast<int>(selector["num_frames"]);
        for (int i = 1; i <= numFrames; i++)
        {
            Frame newFrame = getFrameFromSelector(selector["frames"], i);
            frameData.addFrame(newFrame);
        }
        return frameData;
    }

    Frame getFrameFromSelector(sel::Selector selector, int frameIndex)
    {
        using std::cout;
        using std::endl;

        Frame frame;
        frame.duration = static_cast<int>(selector[frameIndex][1]);
        frame.texRect = sf::Rect<int>(sf::Vector2i(static_cast<int>(selector[frameIndex][2]),
                                                   static_cast<int>(selector[frameIndex][4])),
                                      sf::Vector2i(static_cast<int>(selector[frameIndex][3]),
                                                   static_cast<int>(selector[frameIndex][5])));
        return frame;
    }
}}