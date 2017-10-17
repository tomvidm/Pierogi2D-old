#ifndef INPUTTEXTFIELD_H
#define INPUTTEXTFIELD_H

#include <string>
#include "SFML/Window.hpp"

namespace engine {
namespace input {

    // This is a class representing the content of the user input
    // field in the console. Given a TextInput event, this class
    // takes care of updating the string.

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

#endif