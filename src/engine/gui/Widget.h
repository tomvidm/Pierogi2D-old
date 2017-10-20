#ifndef WIDGET_H
#define WIDGET_H

#include <vector>
#include <memory>

#include "engine/input/Mouse.h"

namespace engine { namespace gui {

    // The Widget is a base class for representing windows,
    // buttons, text fields and more.

    class Widget
    {
    public:
        bool isMouseOver() const;   

        inline bool isResizable() const { return isResizable_; }
        inline bool isMovable() const { return isMovable_; }
    protected:
        Widget* parent = nullptr;
        std::vector<std::unique_ptr<Widget>> widgets;

        sf::FloatRect boundingBox;

        bool isResizable_;
        bool isMovable_;
    };
}}

#endif