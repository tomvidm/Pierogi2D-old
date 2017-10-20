#ifndef WIDGETMANAGER_H
#define WIDGETMANAGER_H

#include <deque>

#include "Widget.h"

namespace engine { namespace gui {
    // The WidgetManager should be responsible for ordering
    // widget draw order by rearranging them. For example, the last clicked
    // widget should be drawn on top.

    class WidgetManager
    {
    private:
        std::deque<std::unique_ptr<Widget>> 
    }
}}

#endif