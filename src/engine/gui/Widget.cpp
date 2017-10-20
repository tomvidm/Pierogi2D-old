#include "Widget.h"

namespace engine { namespace gui {
    bool Widget::isMouseOver() const
    {
        return boundingBox.contains(engine::input::Mouse::getMouseFloatPos());
    }

    bool Widget::snapsToLeftEdge() const
    {
        sf::FloatRect snapTarget(sf::Vector2f(boundingBox.left - snapSize, 
                                              boundingBox.top + snapSize),
                                 sf::Vector2f(2*snapSize, 
                                              boundingBox.height - 2*snapSize));
        return snapTarget.contains(engine::input::Mouse::getMouseFloatPos());
    }
}}