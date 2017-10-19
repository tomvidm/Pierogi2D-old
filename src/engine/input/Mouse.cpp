#include "Mouse.h"
#include <iostream>
namespace engine { namespace input {
    void Mouse::registerButtonPressEvent(sf::Event& event)
    {
        if (event.mouseButton.button == sf::Mouse::Button::Left)
        {
            leftHoldTimer.restart();
            leftIsPressed = true;
        }
        else if (event.mouseButton.button == sf::Mouse::Button::Right)
        {
            rightHoldTimer.restart();
            rightIsPressed = true;
        }
    }

    MouseEvent Mouse::returnMouseEventOnRelease(sf::Event& event)
    {
        if (event.mouseButton.button == sf::Mouse::Button::Left)
        {
            leftIsPressed = false;
            if (leftHoldTimer.restart() < leftClickTimeThreshold)
            {
                return MouseEvent::LEFT_CLICKED;
            }
            else
            {
                return MouseEvent::LEFT_RELEASED;
            }
        }

        else if (event.mouseButton.button == sf::Mouse::Button::Right)
        {
            rightIsPressed = false;
            if (rightHoldTimer.restart() < rightClickTimeThreshold)
            {
                return MouseEvent::RIGHT_CLICKED;
            }
            else
            {
                return MouseEvent::RIGHT_RELEASED;
            }
        }
    }

    // STATIC VARIABLE INITIALIZATION
    bool Mouse::leftIsPressed = false;
    bool Mouse::rightIsPressed = false;

    sf::Clock Mouse::leftHoldTimer = sf::Clock();
    sf::Clock Mouse::rightHoldTimer = sf::Clock();

    sf::Time Mouse::leftClickTimeThreshold = sf::milliseconds(100);
    sf::Time Mouse::rightClickTimeThreshold = sf::milliseconds(100);
}}