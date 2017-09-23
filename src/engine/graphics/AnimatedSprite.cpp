#include "AnimatedSprite.h"

namespace engine {
namespace graphics {
    void AnimatedSprite::update() 
    {
    	spriteAnimation.update();
        setTextureRect(spriteAnimation.getFrameRect());
    }

    void AnimatedSprite::setAnimation(SpriteAnimation anim)
    {
        spriteAnimation = anim;
    }
}
}