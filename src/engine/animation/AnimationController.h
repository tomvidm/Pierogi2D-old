#pragma once

#include "FrameData.h"

#include <memory>

namespace engine {
namespace graphics {
    class AnimationController
    {
    public:
        bool update();
        void setFrameData(FrameData& anim);
        inline sf::Rect<int> getFrameRect() const { return frameData->getFrameRect(currentFrameIndex); }
    private:
        sf::Clock frameTimer;
        FrameData* frameData = nullptr;
        int currentFrameIndex = 0;
        int numFrames = 0;
        bool isStatic = true;
    };
}
}