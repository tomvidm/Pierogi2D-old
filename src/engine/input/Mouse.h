#ifndef MOUSE_H
#define MOUSE_H

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

namespace engine { namespace input {
    enum MouseEvent : int
    {
        NONE, LEFT_CLICKED, LEFT_RELEASED,
        RIGHT_CLICKED, RIGHT_RELEASED
    };

    // This is a wrapper for mouse input. The purpose of this
    // is for simplifying the detection of single/double click or hold,
    // and getting relative mouse position by requiring the user
    // to set a window context.

    class Mouse 
    {
    public:
        static void setWindowContext(sf::Window& window);

        static inline sf::Vector2i getMousePos() 
        { 
            return sf::Mouse::getPosition(*windowContext); 
        }

        static inline sf::Vector2f getMouseFloatPos() 
        { 
            sf::Vector2i mpos = sf::Mouse::getPosition(*windowContext);
            return sf::Vector2f(static_cast<float>(mpos.x), static_cast<float>(mpos.y)) ;
        }

        static bool isLeftHold();
        static bool isRightHold();
        static bool isLeftClick(sf::Event& event);
        static bool isRightClick(sf::Event& event);

        static void registerButtonPressEvent(sf::Event& event);
        static MouseEvent returnMouseEventOnRelease(sf::Event& event);
    private:
        static sf::Window* windowContext;

        static bool leftIsPressed;
        static bool rightIsPressed;

        static sf::Clock leftHoldTimer;
        static sf::Clock rightHoldTimer;

        static sf::Time leftClickTimeThreshold;
        static sf::Time rightClickTimeThreshold;
        
        //static bool leftHold();
        //static bool rightHold();
    };
}}

#endif