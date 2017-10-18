#include "Sprite.h"

namespace engine { namespace graphics {
    void Sprite::update() 
    {
        // This calls the update() function of animationController.
        // In addition, the update() returns a bool to avoid updating the
        // rect multiple times during one frame.
        if (animationController.update())
        {
            updateRect();
        }
    }

    void Sprite::setAnimation(animation::FrameData& anim)
    {
        animationController.setFrameData(anim);
    }

    void Sprite::updateRect()
    {
        setTextureRect(animationController.getFrameRect());
    }
}}