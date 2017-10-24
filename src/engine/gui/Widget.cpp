#include "Widget.h"

namespace engine { namespace gui {
    Widget::Widget()
    {
        rectShape.setFillColor(sf::Color::Blue);
        setSize(sf::Vector2f(300, 200));
        setPosition(sf::Vector2f(0, 0));
    }

    bool Widget::isMouseOver() const
    {
        return boundingBox.contains(engine::input::Mouse::getMouseFloatPos());
    }

    bool Widget::snapsToLeftEdge() const
    {
        sf::FloatRect snapTarget(sf::Vector2f(boundingBox.left - snapSize, 
                                              boundingBox.top + snapSize),
                                 sf::Vector2f(2*snapSize, 
                                              boundingBox.height - 2*snapSize));
        return snapTarget.contains(engine::input::Mouse::getMouseFloatPos());
    }

    void Widget::setSize(sf::Vector2f size)
    {
        boundingBox = sf::FloatRect(boundingBox.left, boundingBox.top, size.x, size.y);
        rectShape.setSize(size);
    }

    void Widget::setPosition(sf::Vector2f pos)
    {
        if (isAttachedToView())
        {
            boundingBox = sf::FloatRect(pos.x + attachedView->getCenter().x, 
                                        pos.y + attachedView->getCenter().y, 
                                        boundingBox.width, 
                                        boundingBox.height);
            rectShape.setPosition(pos + attachedView->getCenter());
        }
        else
        {
            boundingBox = sf::FloatRect(pos.x, 
                                        pos.y, 
                                        boundingBox.width, 
                                        boundingBox.height);
            rectShape.setPosition(pos);
        }
    }

    void Widget::setView(sf::View& view)
    {
        attachedView = &view;
    }

    void Widget::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= getTransform();

        target.draw(rectShape);
    }
}}