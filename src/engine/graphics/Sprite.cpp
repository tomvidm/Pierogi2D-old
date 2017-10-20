#include "Sprite.h"

namespace engine { namespace graphics {
    Sprite::Sprite(engine::animation::AnimationHandler& animHandler)
    {
        animationController.setAnimationHandler(animHandler);
    }

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

    void Sprite::setAnimation(std::string animationName)
    {
        animationController.setAnimation(animationName);
        updateRect();
    }

    void Sprite::updateRect()
    {
        setTextureRect(animationController.getFrameRect());
    }
}}