#pragma once

#include <string>
#include "SFML/Window.hpp"

namespace engine {
namespace console {


    class InputTextField
    {
    public:
        void handleEvent(sf::Event event);
        inline void clear() { string.clear(); }
        inline std::string getString() const { return string; }
    private:
        std::string string;
    };
}
}