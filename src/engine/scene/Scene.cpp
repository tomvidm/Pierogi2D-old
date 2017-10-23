#include "Scene.h"

#include "engine/input/Mouse.h"

namespace engine { namespace scene {
    Scene::Scene()
    {
        tmap.setSize(16, 16);
        tmap.setGridVisibility(true);
        tmap.setPosition(sf::Vector2f(1024/2, 0));
        tmap.setTexture("wood_tileset");
    }

    void Scene::update()
    {
        for (auto s = sprites.begin(); s != sprites.end(); s++)
        {
            s->update();
        }
    }

    void Scene::render(sf::RenderWindow* window)
    {
        tmap.update();
        window->clear(sf::Color::White);
        window->draw(tmap);
        for (auto s : sprites)
        {
            window->draw(s);
        }
        window->display();
    }
}}