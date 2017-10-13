#include "SpriteAnimation.h"

namespace engine {
namespace graphics {
    sf::Rect<int> SpriteAnimation::getFrameRect()
    {
        return frames[currentFrame].texRect;
    }

    void SpriteAnimation::update()
    {
        if (frameTimer.getElapsedTime().asMicroseconds() > frames[currentFrame].duration)
        {
            frameTimer.restart();

            currentFrame += 1;
            currentFrame %= frames.size();
        }
    }
}
}