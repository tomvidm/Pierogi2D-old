#ifndef ENTITY_H
#define ENTITY_H

#include <map>
#include <string>

namespace engine {

    enum class ComponentType
    {
        SPRITE
    };

    class Entity
    {
    public:
        inline int getIndexOf(ComponentType compType) const { return componentMap.at(compType); }
        inline int setIndexOf(ComponentType compType, int index) { componentMap[compType] = index; }
        inline std::string getObjectName() const { return objectName; }

    private:
        std::string objectName;
        std::map<ComponentType, int> componentMap;  // maps some component to its corresponding index
    };

}

#endif