#pragma once

#include "SFML/Graphics.hpp"
#include "AnimationController.h"

namespace engine {
    typedef unsigned int uint;
namespace graphics {
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