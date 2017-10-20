#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <map>

#include "SFML/Window.h"

namespace engine { namespace input {
    class Keyboard
    {
        //void processEvent(sf::Event& event);
    private:
        static bool keyState[103] = {false};
        }
    };
}}

#endif