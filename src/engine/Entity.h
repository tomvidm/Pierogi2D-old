
#include <map>

namespace engine {

    enum class ComponentType
    {
        SPRITE,
        BEHAVIOUR
    };

    class Entity
    {
    public:
        inline int getIndexOf(ComponentType compType) const { return componentMap[compType]; }
        inline int setIndexOf(ComponentType compType, int index) { componentMap[compType] = index; }
    private:
        std::map<ComponentType, int> componentMap;  // maps some component to its corresponding index
    }

}