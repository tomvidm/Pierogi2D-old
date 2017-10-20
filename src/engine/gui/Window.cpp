#include "Window.h"

namespace engine { namespace gui {
    Window::Window()
    {
        setSize(sf::Vector2f(400, 300));
        mainBox.setFillColor(sf::Color::Blue);
    }

    void Window::setSize(sf::Vector2f size)
    {
        boundingBox.width = size.x;
        boundingBox.height = size.y;
        mainBox.setSize(size);
    }

    void Window::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(mainBox);
    }
}}