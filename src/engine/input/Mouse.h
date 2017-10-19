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

    class Mouse 
    {
    public:
        static MouseEvent getMouseEvent(sf::Event& event);

        static inline sf::Vector2i getMousePos(sf::Window& window) 
        { 
            return sf::Mouse::getPosition(window); 
        }

        static inline sf::Vector2f getMouseFloatPos(sf::Window& window) 
        { 
            sf::Vector2i mpos = sf::Mouse::getPosition(window);
            return sf::Vector2f(static_cast<float>(mpos.x), static_cast<float>(mpos.y)) ;
        }

    
        static MouseEvent mouseEvent;

        static bool leftIsPressed;
        static bool rightIsPressed;

        static sf::Clock leftHoldTimer;
        static sf::Clock rightHoldTimer;

        static sf::Time leftClickTimeThreshold;
        static sf::Time rightClickTimeThreshold;

        static void processEvent(sf::Event& event);
        static void processMouseButtonPress(sf::Event& event);
        static void processMouseButtonRelease(sf::Event& event);
        //static bool leftHold();
        //static bool rightHold();
    };
}}

#endif