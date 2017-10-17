#pragma once

#include "ResourceHandler.h"
#include "FrameData.h"

extern "C" 
{
    #include "lua.h"
    #include "lualib.h"
    #include "lauxlib.h"
}

#include "selene.h"


namespace engine {

    // The AnimationHandler is a simple template specialization of
    // the ResourceHandler. The purpose is to load frame data from
    // a file or lua table and store them by string keys in a map.

    class AnimationHandler : public ResourceHandler<FrameData>
    {
    public:
        void loadFromFile(std::string filename, std::string id);
        void loadFromLuaTable(std::string filename, const char* spritesheet);
        void loadTestData();
    };

    Frame getFrameFromSelector(sel::Selector selector, int frameIndex);
    FrameData getFrameDataFromSelector(sel::Selector selector);
}