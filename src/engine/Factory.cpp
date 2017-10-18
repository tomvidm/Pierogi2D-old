#include "Factory.h"

namespace engine {
    Entity EntityFactory::createObject(std::string id)
    {
        luaState.Load("../../resources/objects/" + id + ".lua");
        
    }
}