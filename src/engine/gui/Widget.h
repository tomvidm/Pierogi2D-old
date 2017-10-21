#ifndef WIDGET_H
#define WIDGET_H

#include <vector>
#include <memory>

#include "SFML/Graphics.hpp"

#include "engine/input/Mouse.h"

namespace engine { namespace gui {

    class WidgetManager;
    class Widget;
    
    enum class WidgetType
    {
        WINDOW,
        BUTTON,
        TEXT_INPUT,
        TEXT,
        IMAGE,
        CLOSE
    };

    struct WidgetTypePair
    {
        WidgetType widgetType;
        std::unique_ptr<Widget> windgetPtr;
    }; 

    // The Widget is a base class for representing windows,
    // buttons, text fields and more.

    class Widget : public sf::Drawable, public sf::Transformable
    {
    public:
        bool isMouseOver() const;   

        inline bool isResizable() const { return isResizable_; }
        inline bool isMovable() const { return isMovable_; }

        bool snapsToLeftEdge() const;

        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    protected:
        WidgetManager* widgetManager;
        WidgetType widgetType = WidgetType::WINDOW;

        Widget* parent = nullptr;
        std::vector<WidgetTypePair> widgets;

        sf::FloatRect boundingBox;
        sf::RectangleShape rectShape;

        bool isResizable_;
        bool isMovable_;

        float snapSize = 4;
    };
}}

#endif