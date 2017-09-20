#include "Pool.h"
#include "Tree.h"

#define MAX_OBJECTS 64
#define MAX_SPRITES 64

namespace engine
{
    typedef unsigned int uint;
    typedef int SomeObject;
    typedef int Sprite;
    typedef Pool<SomeObject, MAX_OBJECTS> ObjectPool; 
    typedef Pool<Sprite, MAX_SPRITES> SpritePool;

    class SceneManager
    {
    public:
        
    private:
        utils::Tree<uint> objectTree_;
        ObjectPool objectPool_;
        SpritePool spritePool_;
    };
}