#include "Scene.h"

#include "engine/input/Mouse.h"

namespace engine { namespace scene {
    Scene::Scene()
    {
        tmap.setSize(16, 16);
        tmap.setGridVisibility(true);
        tmap.setPosition(sf::Vector2f(1024/2, 0));
        tmap.setTexture("wood_tileset");
        beam.setEndpoints(sf::Vector2f(0, 0), sf::Vector2f(300, 300));
        beam.setNumVertices(100);
        beam.setThickness(24.f);
        beam.setDynamicResolution(true);
    }

    void Scene::update()
    {
        beam.setEndpoints(sf::Vector2f(0, 0), engine::input::Mouse::getMouseFloatPos(false));
        beam.update();
        for (auto s = sprites.begin(); s != sprites.end(); s++)
        {
            s->update();
        }
    }

    void Scene::render(sf::RenderWindow* window)
    {
        tmap.update();
        window->clear(sf::Color::Black);
        //window->draw(tmap);
        window->draw(beam);
        for (auto s : sprites)
        {
            window->draw(s);
        }
        window->display();
    }
}}