#include "SFML/Graphics.hpp"
#include <vector>

namespace engine {
    typedef unsigned int uint;
namespace graphics {

    struct Frame
    {
        sf::Time duration;
        sf::Rect<int> texRect;
    };

    class SpriteAnimation
    {
    public:
        sf::Clock frameTimer;
        sf::Rect<int> getCurrentFrameRect() const;

        void update();
        void reset();
    private:
        uint currentFrame = 0;
        std::vector<Frame> frames;
    }


}
}