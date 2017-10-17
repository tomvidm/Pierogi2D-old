#pragma once

#include "ConsoleQueue.h"
#include "InputTextField.h"

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

namespace engine {
namespace console {
    class DebugConsole : public sf::Drawable, public sf::Transformable
    {
    public:
        void handleEvent(sf::Event event);
        void update();
        void draw(sf::RenderTarget &target, sf::RenderStates states) const;
        void initDefaultConsoleFont();
        void addLine(std::string line);
    private:
        InputTextField inputTextField;
        sf::Text consoleText;
        sf::Text inputText;
        sf::Font font;
        ConsoleQueue consoleQueue;
    };
}
}