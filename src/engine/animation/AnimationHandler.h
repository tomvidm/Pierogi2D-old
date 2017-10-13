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
    class AnimationHandler : public ResourceHandler<FrameData>
    {
    public:
        void loadFromFile(std::string filename, std::string id);
        void loadFromLuaTable(std::string filename, const char* spritesheet);
        void loadTestData();
    };
}