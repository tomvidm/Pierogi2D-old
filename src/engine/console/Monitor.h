#ifndef MONITOR_H
#define MONITOR_H

#include <vector>

#include "SFML/Graphics.hpp"

#include "DebugLine.h"

namespace engine { namespace console {

    class Monitor
    {
    public:
        void addLine(DebugLine& debugLine);
    private:
        std::vector<DebugLine> lines;

        sf::Font font;
        sf::Text text;
    };
}}

#endif