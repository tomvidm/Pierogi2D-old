#include "SFML/Graphics.hpp"
#include <vector>

namespace engine {
    typedef unsigned int uint;
namespace graphics {

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