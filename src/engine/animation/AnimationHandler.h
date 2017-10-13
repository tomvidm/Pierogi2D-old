#pragma once

#include "ResourceHandler.h"

#include "FrameData.h"

namespace engine {
    class AnimationHandler : public ResourceHandler<graphics::FrameData>
    {
    public:
        void loadFromFile(std::string filename, std::string id);
        void loadTestData();
    };
}