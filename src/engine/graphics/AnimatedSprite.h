#pragma once

#include "SFML/Graphics.hpp"
#include "SpriteAnimation.h"

namespace engine {
    typedef unsigned int uint;
namespace graphics {
    class AnimatedSprite : public sf::Sprite
    {
        public:
            void update();
            void setAnimation(SpriteAnimation anim);

            void loadFromLua( /* what arguments? */) = 0;   // load textures and frames from lua chunk.
        private:
            SpriteAnimation spriteAnimation;
    };
} 
}