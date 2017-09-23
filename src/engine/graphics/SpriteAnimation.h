#include "SFML/Graphics.hpp"
#include <vector>

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
        sf::Clock frameTimer;
        sf::Rect<int> getCurrentFrameRect() const;

        sf::Rect<int> getFrameRect();
        void reset();
        inline void addFrame(Frame& frame) { frames.push_back(frame); }
    private:
        uint currentFrame = 0;
        std::vector<Frame> frames;
    };


}
}