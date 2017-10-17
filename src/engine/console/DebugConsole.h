#ifndef DEBUGCONSOLE_H
#define DEBUGCONSOLE_H

#include "ConsoleQueue.h"
#include "engine/input/InputTextField.h"

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

namespace engine {
namespace console {

    // The DebugConsole is responsible for handling console messages
    // and user console input. It inherits from sf::Drawable and
    // sf::Transformable so that it acts like any drawable/transformable.
    // The DebugConsole has a member ConsoleQueue for keeping track
    // of messages.

    class DebugConsole : public sf::Drawable, public sf::Transformable
    {
    public:
        DebugConsole::DebugConsole();
        void handleEvent(sf::Event event);
        void update();
        void draw(sf::RenderTarget &target, sf::RenderStates states) const;
        void initDefaultConsoleFont();
        void addLine(std::string line);
    private:
        engine::input::InputTextField inputTextField;
        sf::Text consoleText;
        sf::Text inputText;
        sf::Font font;
        ConsoleQueue consoleQueue;
    };
}
}

#endif