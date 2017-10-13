#pragma once

#include "SFML/Graphics.hpp"
#include <vector>

namespace engine {
    typedef unsigned int uint;
namespace graphics {
    struct Frame
    {
        int duration;
        sf::Rect<int> texRect;
        Frame() {;}
        Frame(int dur, sf::Rect<int> rect) 
        {
            duration = dur;
            texRect = rect;
        }
    };

    class FrameData
    {
    public:
       //FrameData();

        int getFrameDuration(int index) const;
        sf::Rect<int> getFrameRect(int index) const;
        inline int getNumFrames() const { return frames.size(); }

        inline void addFrame(Frame frame) { frames.push_back(frame); }
    private:
        std::vector<Frame> frames;
    };


}
}