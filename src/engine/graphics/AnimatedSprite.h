#include "SFML/Graphics.hpp"
#include "SpriteAnimation.h"

namespace engine {
    typedef unsigned int uint;
namespace graphics {
    class AnimatedSprite : public sf::Sprite
    {
        public:
            void update();
            void setAnimation(SpriteAnimation& anim);
        private:
            SpriteAnimation spriteAnimation;
    };
} 
}