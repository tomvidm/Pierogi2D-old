#include "AnimatedSprite.h"

namespace engine {
namespace graphics {
    void AnimatedSprite::update() 
    {
        setTextureRect(spriteAnimation.getFrameRect());
    }
}
}