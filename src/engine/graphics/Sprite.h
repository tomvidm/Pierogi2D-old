#pragma once

#include "SFML/Graphics.hpp"
#include "SpriteAnimation.h"

namespace engine {
    typedef unsigned int uint;
namespace graphics {
    class Sprite : public sf::Sprite
    {
        public:
            void update();
            void setAnimation(SpriteAnimation anim);
        private:
            SpriteAnimation spriteAnimation;
    };
} 
}