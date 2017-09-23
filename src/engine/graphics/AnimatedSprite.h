#include "SFML/Graphics.hpp"
#include "SpriteAnimation.h"

namespace engine {
    typedef unsigned int uint;
namespace graphics {
    class AnimatedSprite : public sf::Sprite
    {
        public:
            void update();
        private:
            SpriteAnimation spriteAnimation;
    };
} 
}