#include "SpriteAnimation.h"

namespace engine {
namespace graphics {
    sf::Rect<int> SpriteAnimation::getFrameRect() 
    {
        if (frameTimer.getElapsedTime().asMicroseconds() > frames[currentFrame].duration)
        {
            frameTimer.restart();

            currentFrame = (currentFrame + 1) % frames.size();
            currentFrame++;
        }

        return frames[currentFrame].texRect;
    }

    void SpriteAnimation::reset()
    {
        currentFrame = 0;
    }
}
}