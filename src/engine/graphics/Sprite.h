#ifndef SPRITE_H
#define SPRITE_H

#include "SFML/Graphics.hpp"

#include "../animation/AnimationController.h"

namespace engine { namespace graphics {
    typedef unsigned int uint;

    // The Sprite class is an extension of sf::Sprite with the added
    // fuctionality implemented by AnimationController.
    // The purpose of this class is to give a simple interface for
    // creating animated sprites and switching between stored animations.
    // See AnimationController, AnimationHandler and FrameData.

    class Sprite : public sf::Sprite
    {
        public:
            void update();
            void updateRect();

            void setAnimation(animation::FrameData& anim);
        private:
            animation::AnimationController animationController;
    };
}}

#endif