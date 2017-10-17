#pragma once

#include "SFML/Graphics.hpp"
#include "../animation/AnimationController.h"

namespace engine {
    typedef unsigned int uint;
namespace graphics {

    // The Sprite class is an extension of sf::Sprite with the added
    // fuctionality implemented by AnimationController.
    // The purpose of this class is to give a simple interface for
    // creating animated sprites and switching between stored animations.
    // See AnimationController, AnimationHandler and FrameData.

    class Sprite : public sf::Sprite
    {
        public:
            void update();

            void setAnimation(FrameData& anim);
        private:
            AnimationController animationController;
    };
} 
}