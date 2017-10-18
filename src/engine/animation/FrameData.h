#ifndef FRAMEDATA_H
#define FRAMEDATA_H

#include <vector>

#include "SFML/Graphics.hpp"

namespace engine { namespace animation {
    
    // Frame is plain old data representing a frame of an animation.
    // The frame has no knowledge of a texture. It only stores the duration
    // and a Rect.

    typedef unsigned int uint;
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

    void printFrame(Frame frame);

    // FrameData is a vector of Frame object, representing one
    // animation.

    class FrameData
    {
    public:
        int getFrameDuration(int index) const;
        sf::Rect<int> getFrameRect(int index) const;
        inline int getNumFrames() const { return frames.size(); }
        inline Frame getFrame(int index) const { return frames[index]; }
        inline void addFrame(Frame frame) { frames.push_back(frame); }
    private:
        std::vector<Frame> frames;
    };
}}

#endif