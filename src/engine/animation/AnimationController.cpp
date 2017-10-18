#include "AnimationController.h"

namespace engine {
namespace graphics {
    // Return true if update happened
    bool AnimationController::update()
    {
        if (frameTimer.getElapsedTime().asMicroseconds() > frameData->getFrameDuration(currentFrameIndex))
        {
            frameTimer.restart();
            currentFrameIndex += 1;
            currentFrameIndex %= numFrames;
            return true;
        }
        return false;
    }

    void AnimationController::setFrameData(FrameData& anim)
    {
        frameData = &anim;
        numFrames = frameData->getNumFrames();
    }

    sf::Rect<int> AnimationController::getFrameRect() const 
    {
        return frameData->getFrameRect(currentFrameIndex); 
    }
}
}