#ifndef ANIMATIONCONTROLLER_H
#define ANIMATIONCONTROLLER_H

#include "FrameData.h"

#include <memory>

namespace engine { namespace animation {

    // The AnimationController is a class used by Sprite to simplify
    // the process of getting a Rect of a spritesheet and to update this
    // rect for each frame. Several Sprites can share a texture, but
    // the AnimationController ensures that each Sprite can be in different
    // frames of an animation.

    class AnimationController
    {
    public:
        bool update();
        void setFrameData(FrameData& anim);
        sf::Rect<int> getFrameRect() const;
    private:
        sf::Clock frameTimer;
        FrameData* frameData = nullptr;
        int currentFrameIndex = 0;
        int numFrames = 0;
        bool isStatic = true;
    };
}}

#endif