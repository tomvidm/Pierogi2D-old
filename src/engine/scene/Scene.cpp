#include "Scene.h"

#include "engine/input/Mouse.h"

namespace engine { namespace scene {
    Scene::Scene()
    {
        textureHandler.loadFromFile("wood_tileset");
        tmap.setSize(16, 16);
        tmap.setGridVisibility(true);
        tmap.setPosition(sf::Vector2f(1024/2, 0));
        tmap.setTextureHandler(textureHandler);
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

    int Scene::addObject(std::string objectName, sf::RenderWindow& window)
    {
        sel::State luaState;
        luaState.Load(directories::relativePathToResources + "objects/" + objectName + ".lua");

        sel::Selector selector = luaState["properties"]["sprite"];
        std::string spritename = selector["texture"];
        std::string animation = "standing"; // HACK
        //sf::Vector2f spriteScale = lua::getVector2f(selector);

        animationHandler.loadFromFile(spritename);
        textureHandler.loadFromFile(spritename);
        graphics::Sprite sprite(animationHandler);
        sprite.setTexture(textureHandler.get(spritename));
        sprite.setAnimation(spritename + "_" + animation);
        sprite.updateRect();
        //sprite.setScale(spriteScale);
        sprite.setScale(1.f, 1.f);
        sprite.setPosition(200, 200);

        entities.push_back(gameobject::Entity());
        sprites.push_back(sprite);

        return entities.size() - 1;
    }
}}