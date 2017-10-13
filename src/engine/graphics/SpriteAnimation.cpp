#include "SpriteAnimation.h"

namespace engine {
namespace graphics {
    sf::Rect<int> SpriteAnimation::getFrameRect()
    {
        return frames[currentFrame].texRect;
    }

    void SpriteAnimation::update()
    {
        currentFrame += 1;
        currentFrame %= frames.size();
    }
}
}