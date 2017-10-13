#include "Sprite.h"

namespace engine {
namespace graphics {
    void Sprite::update() 
    {
        if (frameTimer.getElapsedTime().asMicroseconds() > spriteAnimation.getFrameDuration())
        {
            frameTimer.restart();

            spriteAnimation.update();
            setTextureRect(spriteAnimation.getFrameRect());
        }
    }

    void Sprite::setAnimation(SpriteAnimation anim)
    {
        spriteAnimation = anim;
    }
}
}