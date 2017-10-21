#include "Mouse.h"
#include <iostream>
namespace engine { namespace input {
    void Mouse::setWindowContext(sf::RenderWindow& window)
    {
        windowContext = &window;
    }

    bool Mouse::isLeftHold() 
    {
        return leftIsPressed;
    }

    bool Mouse::isRightHold()
    {
        return rightIsPressed;
    }

    bool Mouse::isLeftClick(sf::Event& event)
    {
        if (event.type == sf::Event::MouseButtonReleased &&
            returnMouseEventOnRelease(event) == MouseEvent::LEFT_CLICKED)
        {
            return true;
        }
        else 
        {
            return false;
        }
    }

    bool Mouse::isRightClick(sf::Event& event)
    {
        if (event.type == sf::Event::MouseButtonReleased &&
            returnMouseEventOnRelease(event) == MouseEvent::RIGHT_CLICKED)
        {
            return true;
        }
        else 
        {
            return false;
        }
    }

    void Mouse::registerButtonPressEvent(sf::Event& event)
    {
        if (event.mouseButton.button == sf::Mouse::Button::Left)
        {
            leftHoldTimer.restart();
            leftIsPressed = true;
            leftPressPosition = getMouseFloatPos();
        }
        else if (event.mouseButton.button == sf::Mouse::Button::Right)
        {
            rightHoldTimer.restart();
            rightIsPressed = true;
            rightPressPosition = getMouseFloatPos();
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

        else 
        {
            return MouseEvent::NONE;
        }
    }

    // STATIC VARIABLE INITIALIZATION
    sf::RenderWindow* Mouse::windowContext = nullptr;

    sf::Vector2f Mouse::leftPressPosition;
    sf::Vector2f Mouse::rightPressPosition;

    bool Mouse::leftIsPressed = false;
    bool Mouse::rightIsPressed = false;

    sf::Clock Mouse::leftHoldTimer = sf::Clock();
    sf::Clock Mouse::rightHoldTimer = sf::Clock();

    sf::Time Mouse::leftClickTimeThreshold = sf::milliseconds(200);
    sf::Time Mouse::rightClickTimeThreshold = sf::milliseconds(200);
}}