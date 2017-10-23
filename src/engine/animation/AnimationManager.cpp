#include "AnimationManager.h"

namespace engine { namespace animation {
    AnimationManager* AnimationManager::instancePtr = nullptr;

    AnimationManager* AnimationManager::getInstancePtr()
    {
        if (instancePtr = nullptr)
        {
            instancePtr = new AnimationManager;
        }

        return instancePtr;
    }

    void AnimationManager::loadFromFile(std::string filename)
    {   
        if (!isAlreadyLoaded(filename))
        {
            sel::State luaState;
            luaState.Load(directories::relativePathToResources + "images/" + filename + ".lua");
            engine::console::Logger::getInstancePtr()->log("Loading animations from " + filename + ".lua\n");

            sel::Selector selector = luaState[filename.c_str()];
            int numAnimations = static_cast<int>(selector["num_animations"]);
            selector = selector["animations"];

            for (int i = 1; i <= numAnimations; i++)
            {
                std::string animationName = selector[i]["animation_name"];
                resourceMap[animationName] = getFrameDataFromSelector(selector[i]);
            }
        }

    }

    FrameData AnimationManager::get(std::string id)
    {
        return resourceMap.at(id);
    }

    bool AnimationManager::isAlreadyLoaded(std::string animationName) const 
    {
        return static_cast<bool>(resourceMap.count(animationName));
    }

    AnimationManager::AnimationManager()
    {
        ;
    }

    FrameData getFrameDataFromSelector(sel::Selector selector)
    {
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
        Frame frame;
        frame.duration = static_cast<int>(selector[frameIndex][1]);
        frame.texRect = sf::Rect<int>(sf::Vector2i(static_cast<int>(selector[frameIndex][2]),
                                                   static_cast<int>(selector[frameIndex][4])),
                                      sf::Vector2i(static_cast<int>(selector[frameIndex][3]),
                                                   static_cast<int>(selector[frameIndex][5])));
        return frame;
    }
}}