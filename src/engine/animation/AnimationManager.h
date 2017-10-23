#ifndef ANIMATIONMANAGER_H
#define ANIMATIONMANAGER_H

#include <map>
#include <string>
#include <set>

#include "SFML/Graphics.hpp"

#include "engine/Directories.h"
#include "engine/console/Logger.h"
#include "engine/animation/FrameData.h"

extern "C" 
{
    #include "lua.h"
    #include "lualib.h"
    #include "lauxlib.h"
}

#include "selene.h"


namespace engine { namespace animation {
    class AnimationManager
    {
    public:
        static AnimationManager* getInstancePtr();

        void loadFromFile(std::string filename);
        FrameData get(std::string id);

        bool isAlreadyLoaded(std::string animationName) const;
    protected:
        AnimationManager();

        std::map<std::string, FrameData> resourceMap;

        static AnimationManager* instancePtr;
    };

    Frame getFrameFromSelector(sel::Selector selector, int frameIndex);
    FrameData getFrameDataFromSelector(sel::Selector selector);
}}

#endif