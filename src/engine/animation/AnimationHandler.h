#ifndef ANIMATIONHANDLER_H
#define ANIMATIONHANDLER_H

#include <set>

#include "../Directories.h"
#include "../ResourceHandler.h"
#include "FrameData.h"

extern "C" 
{
    #include "lua.h"
    #include "lualib.h"
    #include "lauxlib.h"
}

#include "selene.h"


namespace engine { namespace animation {

    // The AnimationHandler is a simple template specialization of
    // the ResourceHandler. The purpose is to load frame data from
    // a file or lua table and store them by string keys in a map.

    class AnimationHandler : public ResourceHandler<FrameData>
    {
    public:
        void loadFromFile(std::string filename);
        bool isAlreadyLoaded(std::string filename) const;
    private:
        std::set<std::string> alreadyLoadedFiles;
    };

    Frame getFrameFromSelector(sel::Selector selector, int frameIndex);
    FrameData getFrameDataFromSelector(sel::Selector selector);
}}

#endif