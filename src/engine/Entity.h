#include <utility>
#include <set>

/*
    basic idea:
    Sprites, tilemaps and other objects are stored in preallocated 
    arrays. The Entity class only points to these by storing their
    indexes in a set. These sets will be fairly small, so iterating
    over these small binary trees will be fast, and this allows
    to dynamically store the indexes instead of the objects.
    
    Property: A pair that holds property type and an index.

    Should be owned by an entity manager, not directly by Application.
*/

namespace engine {
    enum class PropertyType 
    {
        SPRITE,
        TILEMAP
    };

    typedef unsigned int uint;
    typedef std::pair<PropertyType, uint> Property;

    class Entity
    {
    public:
        void update() const;
    private:
        std::set<Property> Properties;
    };
}