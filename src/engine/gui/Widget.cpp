#include "Widget.h"

namespace engine { namespace gui {
    bool Widget::isMouseOver() const
    {
        return boundingBox.contains(engine::input::Mouse::getMouseFloatPos());
    }
}}