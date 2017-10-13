#include "Sprite.h"

namespace engine {
namespace graphics {
    void Sprite::update() 
    {
        if (animationController.update())
        {
            setTextureRect(animationController.getFrameRect());
        }
    }

    void Sprite::setAnimation(FrameData& anim)
    {
        animationController.setFrameData(anim);
    }
}
}