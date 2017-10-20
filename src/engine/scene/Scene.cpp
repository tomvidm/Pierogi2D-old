#include "Scene.h"

#include "engine/input/Mouse.h"

namespace engine { namespace scene {
    void Scene::update()
    {
        for (auto s = sprites.begin(); s != sprites.end(); s++)
        {
            s->update();
        }
    }

    void Scene::render(sf::RenderWindow* window)
    {
        window->clear(sf::Color::White);
        for (auto s : sprites)
        {
            window->draw(s);
        }
        window->display();
    }

    void Scene::addObject(std::string objectName, sf::Window& window)
    {
        sel::State luaState;
        luaState.Load(directories::relativePathToResources + "objects/" + objectName + ".lua");

        sel::Selector selector = luaState["properties"]["sprite"];
        std::string spritename = selector["texture"];
        std::string animation = "standing"; // HACK
        //sf::Vector2f spriteScale = lua::getVector2f(selector);

        animationHandler.loadFromFile(spritename);
        textureHandler.loadFromFile(spritename);
        graphics::Sprite sprite;
        sprite.setTexture(textureHandler.get(spritename));
        sprite.setAnimation(animationHandler.get(spritename + "_" + animation));
        sprite.updateRect();
        //sprite.setScale(spriteScale);
        sprite.setScale(3.f, 3.f);
        sprite.setPosition(input::Mouse::getMouseFloatPos(window) - sf::Vector2f(1.5*48.f, 1.5*48.f));

        entities.push_back(gameobject::Entity());
        sprites.push_back(sprite);
    }
}}