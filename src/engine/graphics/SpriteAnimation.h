#pragma once

extern "C" 
{
    #include "lua.h"
    #include "lualib.h"
    #include "lauxlib.h"
}

#include "selene.h"

#include "SFML/Graphics.hpp"
#include <vector>
#include <string>

namespace engine {
    typedef unsigned int uint;
namespace graphics {

    /*
        A sprite holds a texture. What part of the texture that is shown is
        determined by the Rect<int> in it. The Frame holds information about duration
        of the frame and which part of the texture is shown.
    */

    struct Frame
    {
        int duration;
        sf::Rect<int> texRect;
        Frame() {;}
        Frame(int dur, sf::Rect<int> rect) 
        {
            duration = dur;
            texRect = rect;
        }
    };

    /*
        The spriteAnimation is responsible for updating the rect. It contains a vector
        of Frames. AnimatedSprite can get the frame by calling getFrameRect.
        TODO: Move time handling out of SpriteAnimation. The user (AnimatedSprite) should
        determine the timing, not the animation itself.
    */

    class SpriteAnimation
    {
    public:
        sf::Rect<int> getFrameRect();

        void update();
        void loadFrameData(/* some arguments? */) = 0;   // SpriteAnimation only stores rects and frame durations!!!

        inline void addFrame(Frame frame) { frames.push_back(frame); }
    private:
        sf::Clock frameTimer;
        int currentFrame = 0;
        std::vector<Frame> frames;
    };


}
}