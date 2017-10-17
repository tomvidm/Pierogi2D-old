#include "DebugConsole.h"

namespace engine {
namespace console {
    void DebugConsole::handleInput()
    {
        ;
    }

    void DebugConsole::initDefaultConsoleFont()
    {
        font.loadFromFile("../../resources/fonts/cour.ttf");
        textField.setFont(font);
        textField.setCharacterSize(14);
        textField.setFillColor(sf::Color::Red);
    }

    void DebugConsole::update()
    {
        textField.setString(consoleQueue.getDebugString());
    }

    void DebugConsole::draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        target.draw(textField, states);
    }

    void DebugConsole::addLine(std::string line)
    {
        consoleQueue.addDebugLine(DebugLine(line));
    }
}
}