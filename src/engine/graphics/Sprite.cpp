#include "Sprite.h"

namespace engine {
namespace graphics {
    void Sprite::update() 
    {
    	spriteAnimation.update();
        setTextureRect(spriteAnimation.getFrameRect());
    }

    void Sprite::setAnimation(SpriteAnimation anim)
    {
        spriteAnimation = anim;
    }
}
}