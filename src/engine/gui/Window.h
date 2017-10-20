#ifndef WINDOW_H
#define WINDOW_H

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

namespace engine { namespace gui {
    class Window : public sf::Drawable, public sf::Transformable
    {
    public:
        Window();
        void setSize(sf::Vector2f size);
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    private:
        sf::FloatRect boundingBox;
        sf::RectangleShape mainBox;
    };
}}

#endif