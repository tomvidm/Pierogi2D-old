#include "Mouse.h"
#include <iostream>
namespace engine { namespace input {
    MouseEvent Mouse::getMouseEvent(sf::Event& event)
    {
        processEvent(event);
        
        return mouseEvent;
    }

    void Mouse::processEvent(sf::Event& event)
    {
        switch (event.type)
        {
            case sf::Event::MouseButtonPressed:
                processMouseButtonPress(event);
                break;
            case sf::Event::MouseButtonReleased:
                processMouseButtonRelease(event);
                break;
        }
    }

    void Mouse::processMouseButtonPress(sf::Event& event)
    {
        if (!leftIsPressed && event.mouseButton.button == sf::Mouse::Button::Left)
        {
            leftHoldTimer.restart();
            leftIsPressed = true;
            mouseEvent = MouseEvent::NONE;
        }
        else if (!rightIsPressed  && event.mouseButton.button == sf::Mouse::Button::Right)
        {
            rightHoldTimer.restart();
            rightIsPressed = true;
            mouseEvent = MouseEvent::NONE;
        }
    }

    void Mouse::processMouseButtonRelease(sf::Event& event)
    {
        if (event.mouseButton.button == sf::Mouse::Button::Left)
        {
            leftIsPressed = false;
            if (leftHoldTimer.restart() < leftClickTimeThreshold)
            {
                mouseEvent = MouseEvent::LEFT_CLICKED;
            }
            else
            {
                mouseEvent = MouseEvent::LEFT_RELEASED;
            }
        }

        else if (event.mouseButton.button == sf::Mouse::Button::Right)
        {
            rightIsPressed = false;
            if (rightHoldTimer.restart() < rightClickTimeThreshold)
            {
                mouseEvent = MouseEvent::RIGHT_CLICKED;
            }
            else
            {
                mouseEvent = MouseEvent::RIGHT_RELEASED;
            }
        }
    }

    // STATIC VARIABLE INITIALIZATION

    MouseEvent Mouse::mouseEvent = MouseEvent::NONE;

    bool Mouse::leftIsPressed = false;
    bool Mouse::rightIsPressed = false;

    sf::Clock Mouse::leftHoldTimer = sf::Clock();
    sf::Clock Mouse::rightHoldTimer = sf::Clock();

    sf::Time Mouse::leftClickTimeThreshold = sf::milliseconds(100);
    sf::Time Mouse::rightClickTimeThreshold = sf::milliseconds(100);
}}