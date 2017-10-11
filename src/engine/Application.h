#include <queue>
#include <stack>
#include <memory>
#include <vector>

#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

#include "AnimatedSprite.h"
#include "TextureHandler.h"
#include "Pool.h"
#include "VectorArray.h"

extern "C" 
{
    #include "lua.h"
    #include "lualib.h"
    #include "lauxlib.h"
}

#include "selene.h"


namespace engine
{
    /*
        Very shitty application class so far.
    */

    class Application
    {
    public:
        void enterLoop();
        void testAnimation();
    private:
        void loop();
        void drawSprites();
        void loadConfiguration();

        TextureHandler textureHandler;
        Pool<graphics::AnimatedSprite, 1024> spritePool;
        graphics::VectorArray varr;
        sf::Clock mainClock;
        sf::RenderWindow window; 
        int maxFramePeriod; 

        graphics::AnimatedSprite makeTestSprite();
    };
}