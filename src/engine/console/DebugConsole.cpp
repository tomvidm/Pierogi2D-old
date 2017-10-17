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
        textField.setStyle(sf::Text::Bold);
        inputTextField.setFont(font);
        inputTextField.setCharacterSize(14);
        inputTextField.setFillColor(sf::Color::Red);
        inputTextField.setStyle(sf::Text::Bold);
        inputTextField.setPosition(sf::Vector2f(0, consoleQueue.getMaxPrintedLines()*16));
        inputTextField.setString("PLACEHOLDER");
    }

    void DebugConsole::update()
    {
        textField.setString(consoleQueue.getDebugString());
    }

    void DebugConsole::draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        target.draw(textField, states);
        target.draw(inputTextField, states);
    }

    void DebugConsole::addLine(std::string line)
    {
        consoleQueue.addDebugLine(DebugLine(line));
    }
}
}