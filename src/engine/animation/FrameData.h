#pragma once

#include "SFML/Graphics.hpp"
#include <vector>
#include <iostream>

namespace engine {
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

    class FrameData
    {
    public:
       //FrameData();

        int getFrameDuration(int index) const;
        sf::Rect<int> getFrameRect(int index) const;
        inline int getNumFrames() const { return frames.size(); }
        inline Frame getFrame(int index) const { return frames[index]; }
        inline void addFrame(Frame frame) { frames.push_back(frame); }
    private:
        std::vector<Frame> frames;
    };


}