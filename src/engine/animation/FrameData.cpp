#include "FrameData.h"

namespace engine {
    sf::Rect<int> FrameData::getFrameRect(int index) const
    {
        return frames[index].texRect;
    }

    int FrameData::getFrameDuration(int index) const
    {
        return frames[index].duration;
    }
}
