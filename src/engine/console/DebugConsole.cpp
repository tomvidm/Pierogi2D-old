#include "DebugConsole.h"
#include <iostream>

namespace engine {
namespace console {
    DebugConsole::DebugConsole()
    {
        initDefaultConsoleFont();
    }

    void DebugConsole::handleEvent(sf::Event event)
    {
        std::cout << static_cast<int>(event.text.unicode) << std::endl;
        if (static_cast<int>(event.text.unicode) == 13)
        {
            consoleQueue.addDebugLine(DebugLine(inputTextField.getString()));
            inputTextField.clear();
            update();
            return;
        }
        inputTextField.handleEvent(event);
        inputText.setString(inputTextField.getString());
    }

    void DebugConsole::initDefaultConsoleFont()
    {
        font.loadFromFile("../../resources/fonts/cour.ttf");
        consoleText.setFont(font);
        consoleText.setCharacterSize(14);
        consoleText.setFillColor(sf::Color::Red);
        consoleText.setStyle(sf::Text::Bold);
        inputText.setFont(font);
        inputText.setCharacterSize(14);
        inputText.setFillColor(sf::Color::Red);
        inputText.setStyle(sf::Text::Bold);
        inputText.setPosition(sf::Vector2f(0, static_cast<float>(consoleQueue.getMaxPrintedLines()*16)));
        inputText.setString("PLACEHOLDER");
    }

    // The debug console keeps track of console messages through
    // its member consoleQueue. This function asks for a stirng representation
    // of all the messages and put that string into the text object.
    void DebugConsole::update()
    {
        consoleText.setString(consoleQueue.getDebugString());
        inputText.setString(inputTextField.getString());
    }

    void DebugConsole::draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        target.draw(consoleText, states);
        target.draw(inputText, states);
    }

    void DebugConsole::addLine(std::string line)
    {
        consoleQueue.addDebugLine(DebugLine(line));
    }
}
}