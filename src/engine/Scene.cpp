#include "Scene.h"

namespace engine {
    void update()
    {
        ;
    }

    void render(sf::RenderWindow* window)
    {
        ;
    }

    void Scene::addObject(std::string objectName)
    {
        sel::State luaState;
        luaState.Load(directories::relativePathToResources + "objects/" + objectName + ".lua");

        sel::Selector selector = luaState["properties"]["sprite"];
        std::string spritename = selector["texture"];
        std::string animation = "testsprite2_running"; // HACK
        sf::Vector2f spriteScale = getVector2f(selector);

        animationHandler.loadFromFile(spritename);
        textureHandler.loadFromFile(spritename);
        graphics::Sprite sprite;
        sprite.setTexture(textureHandler.get(spritename));
        sprite.setAnimation(animationHandler.get(spritename + "_" + animation));
        sprite.updateRect();
        sprite.setScale(spriteScale);

        entities.push_back(Entity());
        sprites.push_back(sprite);
    }
}